#pragma once

#include <functional>
#include <chrono>
#include <cstdint>
#include <memory>
#include <mutex>
#include <vector>

#include "API/Base.h"

namespace API
{
	class Timer
	{
	public:
		ARK_API static Timer& Get();

		Timer(const Timer&) = delete;
		Timer(Timer&&) = delete;
		Timer& operator=(const Timer&) = delete;
		Timer& operator=(Timer&&) = delete;

		/**
		 * \brief Executes function after X seconds
		 * \tparam Func Callback function type
		 * \tparam Args Callback arguments types
		 * \param callback Callback function
		 * \param delay Delay in seconds
		 * \param args Callback arguments
		 */
		template <typename Func, typename... Args>
		void DelayExecute(const Func& callback, int delay, Args&&... args)
		{
			DelayExecuteInternal(std::bind(callback, std::forward<Args>(args)...), delay);
		}

		/**
		 * \brief Executes function every X seconds
		 * \tparam Func Callback function type
		 * \tparam Args Callback arguments types
		 * \param callback Callback function
		 * \param execution_interval Delay between executions in seconds
		 * \param execution_counter Amount of times to execute function, -1 for unlimited
		 * \param async If true, function will be executed in the new thread. No game functions may be called there.
		 * \param args Callback arguments
		 */
		template <typename Func, typename... Args>
		void RecurringExecute(const Func& callback, int execution_interval,
		                      int execution_counter, bool async, Args&&... args)
		{
			RecurringExecuteInternal(std::bind(callback, std::forward<Args>(args)...), execution_interval,
			                         execution_counter, async);
		}

		/**
		 * \brief Same as DelayExecute, returns an id that can be passed to CancelTimer
		 */
		template <typename Func, typename... Args>
		uint64_t DelayExecuteWithId(const Func& callback, int delay, Args&&... args)
		{
			return DelayExecuteWithIdInternal(std::bind(callback, std::forward<Args>(args)...), delay);
		}

		/**
		 * \brief Same as RecurringExecute, returns an id that can be passed to CancelTimer
		 */
		template <typename Func, typename... Args>
		uint64_t RecurringExecuteWithId(const Func& callback, int execution_interval,
		                                int execution_counter, bool async, Args&&... args)
		{
			return RecurringExecuteWithIdInternal(std::bind(callback, std::forward<Args>(args)...),
			                                      execution_interval, execution_counter, async);
		}

		/**
		 * \brief Stops a timer. An async timer finishes the execution that is already running.
		 * \param id Id returned by DelayExecuteWithId or RecurringExecuteWithId
		 * \return true if the timer was found
		 */
		ARK_API bool CancelTimer(uint64_t id);

	private:
		friend void CancelModuleTimers(HMODULE module);
		friend bool HasModuleTimerThreads(HMODULE module);

		struct TimerFunc
		{
			TimerFunc(const std::chrono::time_point<std::chrono::steady_clock>& next_time,
			          std::function<void()> callback,
			          bool exec_once, int execution_counter, int execution_interval, uint64_t id, HMODULE owner)
				: next_time(next_time),
				  callback(move(callback)),
				  exec_once(exec_once),
				  execution_counter(execution_counter),
				  execution_interval(execution_interval),
				  id(id),
				  owner(owner)
			{
			}

			std::chrono::time_point<std::chrono::steady_clock> next_time;
			std::function<void()> callback;
			bool exec_once;
			int execution_counter;
			int execution_interval;
			uint64_t id;
			HMODULE owner;
			bool cancelled{false};
			bool running{false};
		};

		struct AsyncTimer;

		Timer();
		~Timer();

		ARK_API void DelayExecuteInternal(const std::function<void()>& callback, int delay_seconds);
		ARK_API void RecurringExecuteInternal(const std::function<void()>& callback, int execution_interval,
		                                      int execution_counter, bool async);

		ARK_API uint64_t DelayExecuteWithIdInternal(const std::function<void()>& callback, int delay_seconds);
		ARK_API uint64_t RecurringExecuteWithIdInternal(const std::function<void()>& callback, int execution_interval,
		                                                int execution_counter, bool async);

		uint64_t AddTimer(const std::function<void()>& callback, int delay_seconds, int execution_interval,
		                  int execution_counter, bool exec_once, bool async, void* return_address);

		void Update();

		std::vector<std::unique_ptr<TimerFunc>> timer_funcs_;
		std::vector<std::unique_ptr<TimerFunc>> pending_timer_funcs_;
		std::vector<std::shared_ptr<AsyncTimer>> async_timers_;
		uint64_t next_id_{1};
		std::mutex mutex_;
	};
} // namespace API
