#include "Hooks.h"

#include <intrin.h>
#include <string>

#include <Logger/Logger.h>

#include "Offsets.h"
#include "IBaseApi.h"
#include "Helpers.h"
#include <detours.h>

namespace API
{
	Hooks::Hooks()
	{
		//No Longer Required.
	}

	bool Hooks::IsMissingSymbol(LPVOID address)
	{
		if (address == nullptr || Offsets::Get().IsMissingFunctionStub(address))
		{
			return true;
		}

		// unknown names resolve to the start of the code section
		const auto* image = reinterpret_cast<const BYTE*>(GetModuleHandleW(nullptr));
		const auto* dos_header = reinterpret_cast<const IMAGE_DOS_HEADER*>(image);
		const auto* nt_headers = reinterpret_cast<const IMAGE_NT_HEADERS*>(image + dos_header->e_lfanew);

		return address == image + nt_headers->OptionalHeader.BaseOfCode;
	}

	Hooks::Thunk* Hooks::AllocateThunk(LPVOID destination)
	{
		constexpr size_t page_size = 4096;

		if (thunk_page_ == nullptr || thunk_page_used_ + sizeof(Thunk) > page_size)
		{
			thunk_page_ = static_cast<BYTE*>(VirtualAlloc(nullptr, page_size, MEM_COMMIT | MEM_RESERVE,
			                                              PAGE_EXECUTE_READWRITE));
			thunk_page_used_ = 0;

			if (thunk_page_ == nullptr)
			{
				return nullptr;
			}
		}

		auto* thunk = reinterpret_cast<Thunk*>(thunk_page_ + thunk_page_used_);
		thunk_page_used_ += sizeof(Thunk);

		constexpr BYTE code[8] = {0xFF, 0x25, 0x02, 0x00, 0x00, 0x00, 0xCC, 0xCC};
		memcpy(thunk->code, code, sizeof(code));
		thunk->destination = destination;

		FlushInstructionCache(GetCurrentProcess(), thunk, sizeof(Thunk));

		return thunk;
	}

	void Hooks::SetThunkDestination(Thunk* thunk, LPVOID destination)
	{
		InterlockedExchangePointer(&thunk->destination, destination);
	}

	void Hooks::Relink(Target& target)
	{
		LPVOID next = target.trampoline;
		for (const auto& hook : target.hooks)
		{
			SetThunkDestination(hook->thunk, next);
			next = hook->detour;
		}

		SetThunkDestination(target.entry, next);
	}

	bool Hooks::AttachTarget(Target& target, const std::shared_ptr<Hook>& hook)
	{
		target.entry = AllocateThunk(hook->detour);
		if (target.entry == nullptr)
		{
			Log::GetLog()->error("Failed to allocate hook memory for {}", hook->name);
			return false;
		}

		LPVOID pointer = target.address;
		PDETOUR_TRAMPOLINE trampoline = nullptr;

		LONG error = DetourTransactionBegin();
		if (error != NO_ERROR)
		{
			Log::GetLog()->error("Failed to create Detour Transaction for {} ({})", hook->name, error);
			return false;
		}

		error = DetourUpdateThread(GetCurrentThread());
		if (error != NO_ERROR)
		{
			Log::GetLog()->error("Failed to update thread for {} ({})", hook->name, error);
			DetourTransactionAbort();
			return false;
		}

		error = DetourAttachEx(&pointer, target.entry, &trampoline, nullptr, nullptr);
		if (error != NO_ERROR || trampoline == nullptr)
		{
			Log::GetLog()->error("Failed to attach hook for {} ({})", hook->name, error);
			DetourTransactionAbort();
			return false;
		}

		// the trampoline code is at the start of the detours trampoline and is ready before commit
		target.trampoline = trampoline;
		SetThunkDestination(hook->thunk, target.trampoline);

		LPVOID const previous_original = *hook->original;
		*hook->original = hook->thunk;

		error = DetourTransactionCommit();
		if (error != NO_ERROR)
		{
			Log::GetLog()->error("Failed to commit Detour Transaction for {} ({})", hook->name, error);
			*hook->original = previous_original;
			target.trampoline = nullptr;
			return false;
		}

		return true;
	}

	__declspec(noinline) bool Hooks::SetHookInternal(const std::string& func_name, LPVOID detour, LPVOID* original)
	{
		const LPVOID address = Offsets::Get().GetAddress(std::string_view(func_name), _ReturnAddress());
		if (IsMissingSymbol(address))
		{
			ReportDeprecatedUse(func_name, GetModuleFromAddress(_ReturnAddress()));
			Log::GetLog()->error("{} does not exist, the hook was not installed", func_name);
			return false;
		}

		if (detour == nullptr || original == nullptr)
		{
			Log::GetLog()->error("Invalid detour for {}", func_name);
			return false;
		}

		std::lock_guard<std::mutex> lock(mutex_);

		auto hook = std::make_shared<Hook>(Hook{func_name, detour, original, GetModuleFromAddress(detour), nullptr});

		auto& target = targets_[address];

		for (const auto& existing : target.hooks)
		{
			if (existing->name != func_name)
			{
				Log::GetLog()->warn("{} has the same address as {}, the hooks share one chain", func_name,
				                    existing->name);
				break;
			}
		}

		hook->thunk = AllocateThunk(target.hooks.empty() ? target.trampoline : target.hooks.back()->detour);
		if (hook->thunk == nullptr)
		{
			Log::GetLog()->error("Failed to allocate hook memory for {}", func_name);
			return false;
		}

		if (target.trampoline == nullptr)
		{
			target.address = address;
			if (!AttachTarget(target, hook))
			{
				targets_.erase(address);
				return false;
			}

			target.hooks.push_back(hook);
			return true;
		}

		// the new hook runs first; publish it only once its original is set
		*original = hook->thunk;
		target.hooks.push_back(hook);
		SetThunkDestination(target.entry, detour);

		return true;
	}

	__declspec(noinline) bool Hooks::DisableHook(const std::string& func_name, LPVOID detour)
	{
		std::lock_guard<std::mutex> lock(mutex_);

		const LPVOID address = Offsets::Get().GetAddress(std::string_view(func_name), _ReturnAddress());

		Target* target = nullptr;
		std::vector<std::shared_ptr<Hook>>::iterator iter;

		const auto find_in = [&](Target& candidate, bool match_name)
		{
			iter = std::find_if(candidate.hooks.begin(), candidate.hooks.end(),
			                    [&](const std::shared_ptr<Hook>& hook)
			                    {
				                    return hook->detour == detour && (!match_name || hook->name == func_name);
			                    });

			if (iter != candidate.hooks.end())
			{
				target = &candidate;
			}
		};

		if (!IsMissingSymbol(address))
		{
			const auto target_iter = targets_.find(address);
			if (target_iter != targets_.end())
			{
				find_in(target_iter->second, false);
			}
		}

		if (target == nullptr)
		{
			for (auto& [key, candidate] : targets_)
			{
				find_in(candidate, true);
				if (target != nullptr)
				{
					break;
				}
			}
		}

		if (target == nullptr)
		{
			Log::GetLog()->warn("Failed to find hook ({})", func_name);
			return false;
		}

		// nothing is detached, so no trampoline that a running call may still use is freed
		target->hooks.erase(iter);
		Relink(*target);

		return true;
	}

	void Hooks::RemoveModuleHooks(HMODULE module)
	{
		if (module == nullptr)
		{
			return;
		}

		std::lock_guard<std::mutex> lock(mutex_);

		for (auto& [key, target] : targets_)
		{
			bool changed = false;

			for (auto iter = target.hooks.begin(); iter != target.hooks.end();)
			{
				if ((*iter)->owner == module)
				{
					Log::GetLog()->warn("Plugin {} did not remove its hook on {}, removing it", GetModuleName(module),
					                    (*iter)->name);

					iter = target.hooks.erase(iter);
					changed = true;
				}
				else
				{
					++iter;
				}
			}

			if (changed)
			{
				Relink(target);
			}
		}
	}
} // namespace API

// Free function
ArkApi::IHooks& ArkApi::GetHooks()
{
	return reinterpret_cast<IHooks&>(*API::game_api->GetHooks());
}
