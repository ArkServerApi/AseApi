#include "Hooks.h"

#include <string>

#include <Logger/Logger.h>

#include "Offsets.h"
#include "IBaseApi.h"
#include <detours.h>

namespace API
{
	Hooks::Hooks()
	{
		//No Longer Required.
	}

	bool Hooks::SetHookInternal(const std::string& func_name, LPVOID detour, LPVOID* original)
	{
		LPVOID target = Offsets::Get().GetAddress(func_name);
		if (target == nullptr)
		{
			Log::GetLog()->error("{} does not exist", func_name);
			return false;
		}

		auto& hook_vector = all_hooks_[func_name];

		// Detour-chain semantics:
		//   - For the 1st hook on this function we attach `detour` on top of `target`
		//     (the real function). The trampoline returned in `new_target` will jump
		//     to the real function and is exposed to the plugin as `*original`.
		//   - For subsequent hooks we stack on top of the previous detour, so the
		//     new trampoline jumps to the previous detour, not directly to the real
		//     function. This preserves a deterministic invocation order:
		//       last-attached detour -> ... -> first detour -> real function
		//   - Detours does NOT rewrite trampolines created by earlier `DetourAttach`
		//     calls, so `*original` pointers handed to previously loaded plugins
		//     remain valid. They become invalid only on `DetourDetach`, which is
		//     why `DisableHook` rebuilds the entire chain inside one transaction
		//     and republishes new trampoline addresses to all remaining plugins.
		LPVOID new_target = hook_vector.empty()
			                    ? target
			                    : hook_vector.back()->detour;


		if (DetourTransactionBegin())
		{
			Log::GetLog()->error("Failed to create Detour Transaction for {}", func_name);
			DetourTransactionAbort();
			return false;
		}
		if (DetourUpdateThread(GetCurrentThread()))
		{
			Log::GetLog()->error("Failed to update thread for {}", func_name);
			DetourTransactionAbort();
			return false;
		}
		if (DetourAttach(&new_target, detour))
		{
			Log::GetLog()->error("Failed to attach hook for {}", func_name);
			DetourTransactionAbort();
			return false;
		}

		if (DetourTransactionCommit())
		{
			Log::GetLog()->error("Failed to commit Detour Transaction for {}", func_name);
			DetourTransactionAbort();
			return false;
		}
		*original = new_target; //same as ppOriginal in MH_CreateHook

		hook_vector.push_back(std::make_shared<Hook>(new_target, detour, original));

		return true;
	}

	bool Hooks::DisableHook(const std::string& func_name, LPVOID detour)
	{
		const LPVOID target = Offsets::Get().GetAddress(func_name);
		if (target == nullptr)
		{
			Log::GetLog()->error("{} does not exist", func_name);
			return false;
		}

		auto& hook_vector = all_hooks_[func_name];

		const auto iter = std::find_if(hook_vector.begin(), hook_vector.end(),
		                               [detour](const std::shared_ptr<Hook>& hook) -> bool
		                               {
			                               return hook->detour == detour;
		                               });

		if (iter == hook_vector.end())
		{
			Log::GetLog()->warn("Failed to find hook ({})", func_name);
			return false;
		}

		// Build the list of hooks that must remain after removal, preserving original order.
		std::vector<std::shared_ptr<Hook>> remaining;
		remaining.reserve(hook_vector.size() - 1);
		for (const auto& h : hook_vector)
		{
			if (h->detour != detour)
				remaining.push_back(h);
		}

		if (DetourTransactionBegin())
		{
			Log::GetLog()->error("Failed to create Detour Transaction for {}", func_name);
			DetourTransactionAbort();
			return false;
		}
		if (DetourUpdateThread(GetCurrentThread()))
		{
			Log::GetLog()->error("Failed to update thread for {}", func_name);
			DetourTransactionAbort();
			return false;
		}

		// Detach all hooks placed on this function. We keep track of how many were
		// successfully detached so we can roll back on failure.
		size_t detached_count = 0;
		for (const auto& hook : hook_vector)
		{
			if (DetourDetach(&hook->target, hook->detour))
			{
				Log::GetLog()->error("Failed to detach hook for {} (rolling back)", func_name);
				DetourTransactionAbort();
				return false;
			}
			++detached_count;
		}
		(void)detached_count;

		// Re-attach the remaining hooks inside the SAME transaction, rebuilding the
		// detour chain from scratch and updating each plugin's `original` trampoline
		// pointer atomically. This guarantees that on commit either the full chain
		// (minus the removed hook) is live, or nothing changes (on abort).
		LPVOID prev_target = target;
		std::vector<LPVOID> new_targets;
		new_targets.reserve(remaining.size());
		for (auto& hook : remaining)
		{
			LPVOID new_target = prev_target;
			if (DetourAttach(&new_target, hook->detour))
			{
				Log::GetLog()->error("Failed to re-attach hook for {} (rolling back)", func_name);
				DetourTransactionAbort();
				return false;
			}
			new_targets.push_back(new_target);
			prev_target = hook->detour;
		}

		if (DetourTransactionCommit())
		{
			Log::GetLog()->error("Failed to commit Detour Transaction for {}", func_name);
			DetourTransactionAbort();
			return false;
		}

		// Transaction committed successfully: publish the new chain state.
		// At this point the trampoline addresses returned by Detours are valid and
		// the plugin-visible `original` pointers can safely be updated.
		for (size_t i = 0; i < remaining.size(); ++i)
		{
			remaining[i]->target = new_targets[i];
			if (remaining[i]->original != nullptr)
				*remaining[i]->original = new_targets[i];
		}

		hook_vector = std::move(remaining);

		return true;
	}
} // namespace API

// Free function
ArkApi::IHooks& ArkApi::GetHooks()
{
	return reinterpret_cast<IHooks&>(*API::game_api->GetHooks());
}
