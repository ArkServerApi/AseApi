#pragma once
#define WIN32_LEAN_AND_MEAN

#include <Requests.h>

#include "../IBaseApi.h"
#include "../Helpers.h"

#include <algorithm>
#include <atomic>
#include <condition_variable>
#include <deque>
#include <intrin.h>
#include <sstream>
#include <unordered_map>

#include <mutex>
#include <thread>

#include <wincrypt.h>

#include <Poco/Net/HTTPSClientSession.h>
#include <Poco/Net/HTTPRequest.h>
#include <Poco/Net/HTTPResponse.h>
#include <Poco/StreamCopier.h>
#include <Poco/Path.h>
#include <Poco/URI.h>
#include <Poco/Exception.h>
#include <Poco/UTF8String.h>
#include <Poco/NullStream.h>
#include <Poco/String.h>
#include <Poco/Net/SSLManager.h>
#include <Poco/Net/InvalidCertificateHandler.h>
#include <Poco/Net/RejectCertificateHandler.h>

#include <openssl/ssl.h>
#include <openssl/x509.h>

namespace API
{
	class Requests::impl
	{
	public:
		uint64_t Register(const std::function<void(bool, std::string)>& callback, void* return_address);
		void Forget(uint64_t id);
		void WriteRequest(uint64_t id, bool success, std::string result);
		int Cancel(HMODULE owner);

		// keep-alive sessions of one worker thread, most recently used last
		using Sessions = std::vector<std::pair<std::string, std::unique_ptr<Poco::Net::HTTPClientSession>>>;
		using Task = std::function<void(Sessions&)>;

		bool Submit(Task task);
		void Shutdown();

		void Execute(uint64_t id, const std::string& url, const std::vector<std::string>& headers,
		             const std::string& request_type, const std::string* content_type, const std::string* body,
		             Sessions& sessions);

		void Update();

		int max_threads_{0};
		bool legacy_status_result_{true};
		bool keep_alive_{false};

	private:
		struct PendingRequest
		{
			std::function<void(bool, std::string)> callback;
			HMODULE owner;
		};

		struct RequestData
		{
			uint64_t id;
			bool success;
			std::string result;
		};

		static Poco::Net::HTTPRequest ConstructRequest(const Poco::URI& uri,
		                                               const std::vector<std::string>& headers,
		                                               const std::string& request_type);

		std::unique_ptr<Poco::Net::HTTPClientSession> CreateSession(const Poco::URI& uri) const;

		std::string GetResponse(Poco::Net::HTTPClientSession* session, Poco::Net::HTTPResponse& response,
		                        bool* received) const;

		void Worker(Task task);

		std::unordered_map<uint64_t, PendingRequest> pending_;
		std::vector<RequestData> RequestsVec_;
		std::atomic<size_t> ready_count_{0};
		uint64_t next_id_{1};
		std::mutex RequestMutex_;

		std::deque<Task> tasks_;
		int active_threads_{0};
		int idle_threads_{0};
		bool stopping_{false};
		std::mutex pool_mutex_;
		std::condition_variable wake_;
		std::condition_variable stopped_;
	};

	namespace
	{
		std::atomic<Requests*> requests_instance{nullptr};

		constexpr auto worker_idle_timeout = std::chrono::seconds(30);
		constexpr size_t max_worker_sessions = 8;

		bool ProcessShuttingDown()
		{
			using Fn = BOOLEAN(NTAPI*)();
			static const auto fn = reinterpret_cast<Fn>(
				GetProcAddress(GetModuleHandleW(L"ntdll.dll"), "RtlDllShutdownInProgress"));
			return fn != nullptr && fn() != 0;
		}

		std::string SessionKey(const Poco::URI& uri)
		{
			return uri.getScheme() + "://" + Poco::toLower(uri.getHost()) + ":" + std::to_string(uri.getPort());
		}

		// a reused connection the server already closed fails like this before any response byte arrives
		bool IsStaleConnection(const Poco::Exception& error)
		{
			const std::string_view name = error.className();
			return name == "class Poco::Net::NoMessageException"
				|| name == "class Poco::Net::ConnectionResetException"
				|| name == "class Poco::Net::ConnectionAbortedException"
				|| name == "class Poco::Net::SSLConnectionUnexpectedlyClosedException";
		}

		void LoadSystemRootCertificates(SSL_CTX* ssl_context)
		{
			X509_STORE* store = SSL_CTX_get_cert_store(ssl_context);
			HCERTSTORE system_store = CertOpenSystemStoreW(0, L"ROOT");
			if (store == nullptr || system_store == nullptr)
			{
				Log::GetLog()->error("Failed to open the system certificate store");
				return;
			}

			int count = 0;
			PCCERT_CONTEXT cert_context = nullptr;
			while ((cert_context = CertEnumCertificatesInStore(system_store, cert_context)) != nullptr)
			{
				const unsigned char* data = cert_context->pbCertEncoded;
				X509* certificate = d2i_X509(nullptr, &data, static_cast<long>(cert_context->cbCertEncoded));
				if (certificate != nullptr)
				{
					if (X509_STORE_add_cert(store, certificate) == 1)
					{
						++count;
					}

					X509_free(certificate);
				}
			}

			CertCloseStore(system_store, 0);

			Log::GetLog()->info("Loaded {} root certificates for HTTPS verification", count);
		}

		bool IsHexDigit(char c)
		{
			return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F');
		}

		// already form encoded
		bool IsFormEncoded(const std::string& value)
		{
			constexpr std::string_view needs_encoding = "\"#<>\\^`{|}";

			bool encoded = false;
			for (size_t i = 0; i < value.size(); ++i)
			{
				const char c = value[i];
				if (c == '%')
				{
					if (i + 2 >= value.size() || !IsHexDigit(value[i + 1]) || !IsHexDigit(value[i + 2]))
					{
						return false;
					}

					encoded = true;
					i += 2;
				}
				else if (c == '+')
				{
					encoded = true;
				}
				else if (static_cast<unsigned char>(c) <= 0x20 || static_cast<unsigned char>(c) >= 0x7F
					|| needs_encoding.find(c) != std::string_view::npos)
				{
					return false;
				}
			}

			return encoded;
		}

		void AppendFormValue(const std::string& value, std::string& body)
		{
			// values may already be encoded
			if (IsFormEncoded(value))
			{
				body += value;
			}
			else
			{
				Poco::URI::encode(value, "!#$&'()*+,/:;=?@[]", body);
			}
		}
	}

	Requests::Requests()
		: pimpl{ std::make_unique<impl>() }
	{
		const auto settings = ReadSettings();
		const bool verify_certificates = GetSettingBool(settings, "VerifyHttpsCertificates", false);
		pimpl->max_threads_ = GetSettingInt(settings, "MaxRequestThreads", 0);
		pimpl->legacy_status_result_ = GetSettingBool(settings, "LegacyHttpStatusResult", true);
		pimpl->keep_alive_ = GetSettingBool(settings, "HttpKeepAlive", false);

		Poco::Net::initializeSSL();
		Poco::SharedPtr<Poco::Net::InvalidCertificateHandler> ptrCert = new Poco::Net::RejectCertificateHandler(false);
		Poco::Net::Context::Ptr ptrContext = new Poco::Net::Context(Poco::Net::Context::TLS_CLIENT_USE, "", "", "",
			verify_certificates ? Poco::Net::Context::VERIFY_RELAXED : Poco::Net::Context::VERIFY_NONE, 9, false,
			"ALL:!ADH:!LOW:!EXP:!MD5:@STRENGTH");

		if (verify_certificates)
		{
			LoadSystemRootCertificates(ptrContext->sslContext());
			ptrContext->enableExtendedCertificateVerification(true);
		}

		Poco::Net::SSLManager::instance().initializeClient(0, ptrCert, ptrContext);

		game_api->GetCommands()->AddOnTickCallback("RequestsUpdate", std::bind(&impl::Update, this->pimpl.get()));

		requests_instance = this;
	}

	Requests::~Requests()
	{
		requests_instance = nullptr;

		pimpl->Shutdown();

		Poco::Net::uninitializeSSL();
		game_api->GetCommands()->RemoveOnTickCallback("RequestsUpdate");
	}

	Requests& Requests::Get()
	{
		static Requests instance;
		return instance;
	}

	uint64_t Requests::impl::Register(const std::function<void(bool, std::string)>& callback, void* return_address)
	{
		const HMODULE owner = GetModuleFromAddress(return_address);

		std::lock_guard<std::mutex> Guard(RequestMutex_);
		const uint64_t id = next_id_++;
		pending_.emplace(id, PendingRequest{callback, owner});

		return id;
	}

	void Requests::impl::Forget(uint64_t id)
	{
		std::function<void(bool, std::string)> callback;

		std::lock_guard<std::mutex> Guard(RequestMutex_);
		const auto iter = pending_.find(id);
		if (iter != pending_.end())
		{
			callback = std::move(iter->second.callback);
			pending_.erase(iter);
		}
	}

	void Requests::impl::WriteRequest(uint64_t id, bool success, std::string result)
	{
		std::lock_guard<std::mutex> Guard(RequestMutex_);
		if (pending_.find(id) == pending_.end())
		{
			return;
		}

		RequestsVec_.push_back({ id, success, std::move(result) });
		ready_count_ = RequestsVec_.size();
	}

	int Requests::impl::Cancel(HMODULE owner)
	{
		std::vector<std::function<void(bool, std::string)>> callbacks;

		{
			std::lock_guard<std::mutex> Guard(RequestMutex_);

			for (auto iter = pending_.begin(); iter != pending_.end();)
			{
				if (iter->second.owner == owner)
				{
					callbacks.push_back(std::move(iter->second.callback));
					iter = pending_.erase(iter);
				}
				else
				{
					++iter;
				}
			}
		}

		return static_cast<int>(callbacks.size());
	}

	bool Requests::impl::Submit(Task task)
	{
		std::unique_lock<std::mutex> lock(pool_mutex_);

		if (stopping_)
			return false;

		// idle workers take queued tasks first, a new worker is started only when all are busy
		if (static_cast<int>(tasks_.size()) < idle_threads_ || (max_threads_ > 0 && active_threads_ >= max_threads_))
		{
			tasks_.push_back(std::move(task));
			wake_.notify_one();
			return true;
		}

		++active_threads_;
		lock.unlock();

		try
		{
			std::thread(&impl::Worker, this, task).detach();
			return true;
		}
		catch (const std::exception& error)
		{
			lock.lock();
			--active_threads_;

			if (active_threads_ > 0)
			{
				tasks_.push_back(std::move(task));
				wake_.notify_one();
				return true;
			}

			Log::GetLog()->error("Failed to start request thread - {}", error.what());
			return false;
		}
	}

	void Requests::impl::Worker(Task task)
	{
		Sessions sessions;

		for (;;)
		{
			task(sessions);
			task = nullptr;

			std::unique_lock<std::mutex> lock(pool_mutex_);

			++idle_threads_;
			const bool has_task = wake_.wait_for(lock, worker_idle_timeout,
			                                     [this] { return stopping_ || !tasks_.empty(); }) && !stopping_;
			--idle_threads_;

			if (!has_task)
				break;

			task = std::move(tasks_.front());
			tasks_.pop_front();
		}

		sessions.clear();

		std::lock_guard<std::mutex> lock(pool_mutex_);
		if (--active_threads_ == 0)
			stopped_.notify_all();
	}

	void Requests::impl::Shutdown()
	{
		std::unique_lock<std::mutex> lock(pool_mutex_);

		stopping_ = true;
		tasks_.clear();
		wake_.notify_all();

		// at process exit the workers are already gone
		if (!ProcessShuttingDown())
			stopped_.wait(lock, [this] { return active_threads_ == 0; });
	}

	std::unique_ptr<Poco::Net::HTTPClientSession> Requests::impl::CreateSession(const Poco::URI& uri) const
	{
		std::unique_ptr<Poco::Net::HTTPClientSession> session;

		if (uri.getScheme() == "https")
			session = std::make_unique<Poco::Net::HTTPSClientSession>(uri.getHost(), uri.getPort());
		else
			session = std::make_unique<Poco::Net::HTTPClientSession>(uri.getHost(), uri.getPort());

		if (keep_alive_)
			session->setKeepAlive(true);

		return session;
	}

	Poco::Net::HTTPRequest Requests::impl::ConstructRequest(const Poco::URI& uri,
		const std::vector<std::string>& headers, const std::string& request_type)
	{
		const std::string& path(uri.getPathAndQuery());

		Poco::Net::HTTPRequest request(request_type, path, Poco::Net::HTTPMessage::HTTP_1_1);

		for (const auto& header : headers)
		{
			const auto separator = header.find(':');
			if (separator == std::string::npos || header.find_first_of("\r\n") != std::string::npos)
			{
				Log::GetLog()->warn("Skipping invalid request header {}", header);
				continue;
			}

			std::string key = header.substr(0, separator);
			std::string data = header.substr(separator + 1);

			Poco::trimInPlace(key);
			Poco::trimInPlace(data);

			if (key.empty())
			{
				Log::GetLog()->warn("Skipping invalid request header {}", header);
				continue;
			}

			request.add(key, data);
		}

		return request;
	}

	std::string Requests::impl::GetResponse(Poco::Net::HTTPClientSession* session,
		Poco::Net::HTTPResponse& response, bool* received) const
	{
		std::string result = "";

		std::istream& rs = session->receiveResponse(response);
		*received = true;

		// legacy: only 200 passes the body, any other status gives "<code> <reason>"
		const int status = static_cast<int>(response.getStatus());
		if (status == 200 || (!legacy_status_result_ && status >= 200 && status < 300))
		{
			std::ostringstream oss;
			Poco::StreamCopier::copyStream(rs, oss);
			result = oss.str();
		}
		else
		{
			Poco::NullOutputStream null;
			Poco::StreamCopier::copyStream(rs, null);
			result = std::to_string(response.getStatus()) + " " + response.getReason();
		}

		return result;
	}

	void Requests::impl::Execute(uint64_t id, const std::string& url, const std::vector<std::string>& headers,
		const std::string& request_type, const std::string* content_type, const std::string* body,
		Sessions& sessions)
	{
		std::string Result = "";
		Poco::Net::HTTPResponse response(Poco::Net::HTTPResponse::HTTP_BAD_REQUEST);
		std::unique_ptr<Poco::Net::HTTPClientSession> session;
		std::string session_key;
		bool completed = false;

		// a reused keep-alive session that fails before the response is retried once on a new one
		for (bool first_attempt = true;; first_attempt = false)
		{
			bool reused = false;
			bool received = false;

			try
			{
				const Poco::URI uri(url);

				Poco::Net::HTTPRequest request = ConstructRequest(uri, headers, request_type);

				if (keep_alive_ && first_attempt)
				{
					session_key = SessionKey(uri);

					const auto iter = std::find_if(sessions.begin(), sessions.end(),
					                               [&session_key](const auto& entry) { return entry.first == session_key; });
					if (iter != sessions.end())
					{
						session = std::move(iter->second);
						sessions.erase(iter);
						reused = true;
					}
				}

				if (session == nullptr)
					session = CreateSession(uri);

				if (body != nullptr)
				{
					request.setContentType(*content_type);
					request.setContentLength(static_cast<std::streamsize>(body->length()));

					std::ostream& OutputStream = session->sendRequest(request);
					OutputStream << *body;
				}
				else
				{
					session->sendRequest(request);
				}

				Result = GetResponse(session.get(), response, &received);
				completed = true;
			}
			catch (const Poco::Exception& exc)
			{
				if (reused && !received && IsStaleConnection(exc))
				{
					session.reset();
					response.setStatus(Poco::Net::HTTPResponse::HTTP_BAD_REQUEST);
					continue;
				}

				Log::GetLog()->error(exc.displayText());
			}
			catch (const std::exception& exc)
			{
				Log::GetLog()->error("Request to {} failed - {}", url, exc.what());
				response.setStatus(Poco::Net::HTTPResponse::HTTP_BAD_REQUEST);
			}

			break;
		}

		const bool success = (int)response.getStatus() >= 200
			&& (int)response.getStatus() < 300;

		if (keep_alive_ && completed && session != nullptr)
		{
			sessions.emplace_back(std::move(session_key), std::move(session));
			if (sessions.size() > max_worker_sessions)
				sessions.erase(sessions.begin());
		}

		session.reset();

		WriteRequest(id, success, std::move(Result));
	}

	__declspec(noinline) bool Requests::CreateGetRequest(const std::string& url,
		const std::function<void(bool, std::string)>& callback, std::vector<std::string> headers)
	{
		const uint64_t id = pimpl->Register(callback, _ReturnAddress());

		if (!pimpl->Submit([this, id, url, headers](impl::Sessions& sessions)
			{
				pimpl->Execute(id, url, headers, Poco::Net::HTTPRequest::HTTP_GET, nullptr, nullptr, sessions);
			}))
		{
			pimpl->Forget(id);
			return false;
		}

		return true;
	}

	__declspec(noinline) bool Requests::CreatePostRequest(const std::string& url,
		const std::function<void(bool, std::string)>& callback,
		const std::string& post_data, std::vector<std::string> headers)
	{
		const uint64_t id = pimpl->Register(callback, _ReturnAddress());

		if (!pimpl->Submit([this, id, url, post_data, headers](impl::Sessions& sessions)
			{
				const std::string content_type = "application/x-www-form-urlencoded";
				pimpl->Execute(id, url, headers, Poco::Net::HTTPRequest::HTTP_POST, &content_type, &post_data, sessions);
			}))
		{
			pimpl->Forget(id);
			return false;
		}

		return true;
	}

	__declspec(noinline) bool Requests::CreatePostRequest(const std::string& url,
		const std::function<void(bool, std::string)>& callback,
		const std::string& post_data, const std::string& content_type, std::vector<std::string> headers)
	{
		const uint64_t id = pimpl->Register(callback, _ReturnAddress());

		if (!pimpl->Submit([this, id, url, post_data, content_type, headers](impl::Sessions& sessions)
			{
				pimpl->Execute(id, url, headers, Poco::Net::HTTPRequest::HTTP_POST, &content_type, &post_data, sessions);
			}))
		{
			pimpl->Forget(id);
			return false;
		}

		return true;
	}

	__declspec(noinline) bool Requests::CreatePostRequest(const std::string& url,
		const std::function<void(bool, std::string)>& callback,
		const std::vector<std::string>& post_ids,
		const std::vector<std::string>& post_data, std::vector<std::string> headers)
	{
		if (post_ids.size() != post_data.size())
			return false;

		std::string body;

		for (size_t i = 0; i < post_ids.size(); ++i)
		{
			if (!body.empty())
			{
				body += '&';
			}

			AppendFormValue(post_ids[i], body);
			body += '=';
			AppendFormValue(post_data[i], body);
		}

		const uint64_t id = pimpl->Register(callback, _ReturnAddress());

		if (!pimpl->Submit([this, id, url, body, headers](impl::Sessions& sessions)
			{
				const std::string content_type = "application/x-www-form-urlencoded";
				pimpl->Execute(id, url, headers, Poco::Net::HTTPRequest::HTTP_POST, &content_type, &body, sessions);
			}))
		{
			pimpl->Forget(id);
			return false;
		}

		return true;
	}

	__declspec(noinline) bool Requests::CreateDeleteRequest(const std::string& url,
		const std::function<void(bool, std::string)>& callback, std::vector<std::string> headers)
	{
		const uint64_t id = pimpl->Register(callback, _ReturnAddress());

		if (!pimpl->Submit([this, id, url, headers](impl::Sessions& sessions)
			{
				pimpl->Execute(id, url, headers, Poco::Net::HTTPRequest::HTTP_DELETE, nullptr, nullptr, sessions);
			}))
		{
			pimpl->Forget(id);
			return false;
		}

		return true;
	}

	__declspec(noinline) int Requests::CancelPendingRequests()
	{
		return pimpl->Cancel(GetModuleFromAddress(_ReturnAddress()));
	}

	void CancelModuleRequests(HMODULE module)
	{
		Requests* instance = requests_instance;
		if (instance == nullptr || module == nullptr)
		{
			return;
		}

		const int cancelled = instance->pimpl->Cancel(module);
		if (cancelled > 0)
		{
			Log::GetLog()->warn("Plugin {} had {} request(s) in flight, their callbacks are dropped",
			                    GetModuleName(module), cancelled);
		}
	}

	void Requests::impl::Update()
	{
		if (ready_count_ == 0)
			return;

		std::vector<RequestData> requests_temp;

		{
			std::lock_guard<std::mutex> Guard(RequestMutex_);
			requests_temp.swap(RequestsVec_);
			ready_count_ = 0;
		}

		for (auto& request : requests_temp)
		{
			// taken one at a time, an earlier callback may cancel the later ones
			PendingRequest pending;
			{
				std::lock_guard<std::mutex> Guard(RequestMutex_);
				const auto iter = pending_.find(request.id);
				if (iter == pending_.end())
				{
					continue;
				}

				pending = std::move(iter->second);
				pending_.erase(iter);
			}

			try
			{
				pending.callback(request.success, std::move(request.result));
			}
			catch (const std::exception& error)
			{
				Log::GetLog()->error("Plugin {} threw in request callback: {}", GetModuleName(pending.owner),
				                     error.what());
			}
			catch (...)
			{
				Log::GetLog()->error("Plugin {} threw in request callback", GetModuleName(pending.owner));
			}
		}
	}
} // namespace API