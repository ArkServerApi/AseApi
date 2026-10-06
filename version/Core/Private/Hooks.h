#pragma once

#include <IHooks.h>

#include <memory>
#include <mutex>
#include <unordered_map>
#include <vector>

namespace API
{
	class Hooks : public ArkApi::IHooks
	{
	public:
		Hooks();

		Hooks(const Hooks&) = delete;
		Hooks(Hooks&&) = delete;
		Hooks& operator=(const Hooks&) = delete;
		Hooks& operator=(Hooks&&) = delete;

		~Hooks() override = default;

		bool SetHookInternal(const std::string& func_name, LPVOID detour, LPVOID* original) override;

		bool DisableHook(const std::string& func_name, LPVOID detour) override;

		/**
		 * \brief Removes every hook whose detour lives in the given module
		 */
		void RemoveModuleHooks(HMODULE module);

	private:
		// jmp qword ptr [rip+2]; int3; int3; dq destination
		struct Thunk
		{
			BYTE code[8];
			LPVOID destination;
		};

		struct Hook
		{
			std::string name;
			LPVOID detour;
			LPVOID* original;
			HMODULE owner;
			Thunk* thunk;
		};

		// hooks run from back to front, the front one calls the engine trampoline
		struct Target
		{
			LPVOID address{nullptr};
			LPVOID trampoline{nullptr};
			Thunk* entry{nullptr};
			std::vector<std::shared_ptr<Hook>> hooks;
		};

		Thunk* AllocateThunk(LPVOID destination);
		static void SetThunkDestination(Thunk* thunk, LPVOID destination);
		static void Relink(Target& target);
		bool AttachTarget(Target& target, const std::shared_ptr<Hook>& hook);
		static bool IsMissingSymbol(LPVOID address);

		std::unordered_map<LPVOID, Target> targets_;

		BYTE* thunk_page_{nullptr};
		size_t thunk_page_used_{0};

		std::mutex mutex_;
	};
} // namespace API
