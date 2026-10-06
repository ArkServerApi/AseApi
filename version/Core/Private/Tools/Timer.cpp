#include <Timer.h>

#include <atomic>
#include <condition_variable>
#include <intrin.h>
#include <thread>

#include <Logger/Logger.h>

#include "../IBaseApi.h"
#include "../Helpers.h"

namespace API
{
	struct Timer::AsyncTimer
	{
		std::mutex mutex;
		std::condition_variable condition;
		bool stop{false};
		std::atomic<bool> done{false};
		std::function<void()> callback;
		uint64_t id;
		HMODULE owner;
		std::string owner_name;
	};

	Timer::Timer()
	{
		game_api->GetCommands()->AddOnTimerCallback("TimerUpdate", std::bind(&Timer::Update, this));
	}

	Timer::~Timer()
	{
		game_api->GetCommands()->RemoveOnTimerCallback("TimerUpdate");
	}

	Timer& Timer::Get()
	{
		static Timer instance;
		return instance;
	}

	__declspec(noinline) void Timer::DelayExecuteInternal(const std::function<void()>& callback, int delay_seconds)
	{
		AddTimer(callback, delay_seconds, 0, 1, true, false, _ReturnAddress());
	}

	__declspec(noinline) void Timer::RecurringExecuteInternal(const std::function<void()>& callback,
	                                                          int execution_interval,
	                                                          int execution_counter, bool async)
	{
		AddTimer(callback, 0, execution_interval, execution_counter, false, async, _ReturnAddress());
	}

	__declspec(noinline) uint64_t Timer::DelayExecuteWithIdInternal(const std::function<void()>& callback,
	                                                                 int delay_seconds)
	{
		return AddTimer(callback, delay_seconds, 0, 1, true, false, _ReturnAddress());
	}

	__declspec(noinline) uint64_t Timer::RecurringExecuteWithIdInternal(const std::function<void()>& callback,
	                                                                    int execution_interval,
	                                                                    int execution_counter, bool async)
	{
		return AddTimer(callback, 0, execution_interval, execution_counter, false, async, _ReturnAddress());
	}

	uint64_t Timer::AddTimer(const std::function<void()>& callback, int delay_seconds, int execution_interval,
	                         int execution_counter, bool exec_once, bool async, void* return_address)
	{
		const HMODULE owner = GetModuleFromAddress(return_address);

		uint64_t id;
		{
			std::lock_guard<std::mutex> lock(mutex_);
			id = next_id_++;
		}

		if (!async)
		{
			const auto exec_time = std::chrono::steady_clock::now() + std::chrono::seconds(delay_seconds);

			auto timer = std::make_unique<TimerFunc>(exec_time, callback, exec_once, execution_counter,
			                                         execution_interval, id, owner);

			// Update merges these, so a callback may add timers while the list is being walked
			std::lock_guard<std::mutex> lock(mutex_);
			pending_timer_funcs_.push_back(std::move(timer));

			return id;
		}

		auto state = std::make_shared<AsyncTimer>();
		state->callback = callback;
		state->id = id;
		state->owner = owner;
		state->owner_name = GetModuleName(owner);

		{
			std::lock_guard<std::mutex> lock(mutex_);
			std::erase_if(async_timers_, [](const std::shared_ptr<AsyncTimer>& timer) { return timer->done.load(); });
			async_timers_.push_back(state);
		}

		try
		{
			std::thread([state, execution_interval, execution_counter]()
			{
				for (int i = 0; execution_counter == -1 || i < execution_counter; ++i)
				{
					try
					{
						state->callback();
					}
					catch (const std::exception& error)
					{
						Log::GetLog()->error("Plugin {} threw in async timer: {}", state->owner_name, error.what());
					}
					catch (...)
					{
						Log::GetLog()->error("Plugin {} threw in async timer", state->owner_name);
					}

					std::unique_lock<std::mutex> lock(state->mutex);
					if (state->condition.wait_for(lock, std::chrono::seconds(execution_interval),
					                              [&state] { return state->stop; }))
					{
						break;
					}
				}

				state->callback = nullptr;
				state->done = true;
			}).detach();
		}
		catch (const std::exception& error)
		{
			Log::GetLog()->error("Failed to start async timer - {}", error.what());

			state->callback = nullptr;
			state->done = true;
			return 0;
		}

		return id;
	}

	bool Timer::CancelTimer(uint64_t id)
	{
		if (id == 0)
		{
			return false;
		}

		bool found = false;
		std::function<void()> callback;

		{
			std::lock_guard<std::mutex> lock(mutex_);

			for (auto* list : {&timer_funcs_, &pending_timer_funcs_})
			{
				for (const auto& data : *list)
				{
					if (data->id == id && !data->cancelled)
					{
						data->cancelled = true;
						found = true;
					}
				}
			}

			for (const auto& timer : async_timers_)
			{
				if (timer->id == id)
				{
					{
						std::lock_guard<std::mutex> state_lock(timer->mutex);
						timer->stop = true;
					}

					timer->condition.notify_all();
					found = true;
				}
			}
		}

		return found;
	}

	void CancelModuleTimers(HMODULE module)
	{
		if (module == nullptr)
		{
			return;
		}

		auto& timer = Timer::Get();

		std::vector<std::unique_ptr<Timer::TimerFunc>> removed;

		{
			std::lock_guard<std::mutex> lock(timer.mutex_);

			for (auto& data : timer.timer_funcs_)
			{
				// a running callback is cleaned up by Update once it returns
				if (data->owner == module && !data->running)
				{
					data->cancelled = true;
					removed.push_back(std::move(data));
				}
				else if (data->owner == module)
				{
					data->cancelled = true;
				}
			}

			std::erase(timer.timer_funcs_, nullptr);

			for (auto& data : timer.pending_timer_funcs_)
			{
				if (data->owner == module)
				{
					removed.push_back(std::move(data));
				}
			}

			std::erase(timer.pending_timer_funcs_, nullptr);

			for (const auto& state : timer.async_timers_)
			{
				if (state->owner == module)
				{
					{
						std::lock_guard<std::mutex> state_lock(state->mutex);
						state->stop = true;
					}

					state->condition.notify_all();
				}
			}
		}

		if (!removed.empty())
		{
			Log::GetLog()->warn("Plugin {} left {} timer(s) running, removing them", GetModuleName(module),
			                    removed.size());
		}
	}

	bool HasModuleTimerThreads(HMODULE module)
	{
		auto& timer = Timer::Get();

		std::lock_guard<std::mutex> lock(timer.mutex_);

		return std::any_of(timer.async_timers_.begin(), timer.async_timers_.end(),
		                   [module](const std::shared_ptr<Timer::AsyncTimer>& state)
		                   {
			                   return state->owner == module && !state->done;
		                   });
	}

	void Timer::Update()
	{
		std::vector<TimerFunc*> due;

		{
			std::lock_guard<std::mutex> lock(mutex_);

			for (auto& data : pending_timer_funcs_)
			{
				timer_funcs_.push_back(std::move(data));
			}

			pending_timer_funcs_.clear();

			if (timer_funcs_.empty())
			{
				return;
			}

			const auto now = std::chrono::steady_clock::now();

			for (const auto& data : timer_funcs_)
			{
				if (data->cancelled || now < data->next_time)
				{
					continue;
				}

				if (data->exec_once)
				{
					data->cancelled = true;
				}
				else
				{
					if (data->execution_counter > 0)
					{
						--data->execution_counter;
					}
					else if (data->execution_counter != -1)
					{
						data->cancelled = true;
						continue;
					}

					data->next_time += std::chrono::seconds(data->execution_interval);
					if (data->next_time <= now)
					{
						data->next_time = now + std::chrono::seconds(data->execution_interval);
					}
				}

				data->running = true;
				due.push_back(data.get());
			}
		}

		for (TimerFunc* data : due)
		{
			try
			{
				data->callback();
			}
			catch (const std::exception& error)
			{
				Log::GetLog()->error("Plugin {} threw in timer: {}", GetModuleName(data->owner), error.what());
			}
			catch (...)
			{
				Log::GetLog()->error("Plugin {} threw in timer", GetModuleName(data->owner));
			}
		}

		std::vector<std::unique_ptr<TimerFunc>> removed;

		{
			std::lock_guard<std::mutex> lock(mutex_);

			for (TimerFunc* data : due)
			{
				data->running = false;
			}

			for (auto& data : timer_funcs_)
			{
				if (data->cancelled || (!data->exec_once && data->execution_counter == 0))
				{
					removed.push_back(std::move(data));
				}
			}

			std::erase(timer_funcs_, nullptr);
		}
	}
} // namespace API
