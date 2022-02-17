#include <timeMult.h>
#include <GameAPI.h>
#include <GameData.h>
#include <settings.h>
#include <ranges>

extern DataHandler* g_dataHandler;

namespace TimeMult
{
	void FillMaps()
	{
		std::vector<Script*> vec;
		const auto command = GetByOpcode(0x1186);
		for (auto iter = g_dataHandler->scriptList.Begin(); !iter.End(); ++iter) vec.push_back(iter.Get());
		for (const auto& iter : std::ranges::reverse_view(vec))
		{
			if (g_specialMods.contains(iter->modIndex)) continue;
			if (HasScriptCommand(iter, command, nullptr))
			{
				g_specialMods.emplace(iter->modIndex);
				Log(FormatString("Found SGTM use in mod: %02X (%50s), form: %08X (%50s)", iter->modIndex, GetModName(
					iter), iter->refID, iter->GetName()));
			}
		}
		vec.clear();
	}

	void Set(TimeGlobal* timeGlobal, char isImmediateChange)
	{
		timeGlobal->Set(g_timeMult, isImmediateChange);
	}

	void ModifyMap(const Float64 timeMult, const UInt16 mod)
	{
		g_localMults.erase(mod);
		if (timeMult != 1) g_localMults.emplace(mod, timeMult);
		if (timeMult == 0) g_localMults.clear();

		g_timeMult = 1;

		if (g_yTM_MinMax == 0)
			for (const auto val : g_localMults | std::views::values) g_timeMult *= val;
		else if (g_yTM_MinMax == 1) {
			Float64 min = 1.0, max = 1.0;
			for (const auto val : g_localMults | std::views::values) {
				if (val < min) min = val;
				if (val > max) max = val;
			}
			g_timeMult = min * max;
		}
	}
}