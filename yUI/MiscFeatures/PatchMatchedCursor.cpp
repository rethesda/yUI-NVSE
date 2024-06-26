#include <main.h>
#include <Safewrite.hpp>

#include <SimpleINILibrary.h>


namespace Patch::MatchedCursor
{
	bool enable = false;

	void __fastcall CursorTileSetStringValue(Tile* tile, void* dummyEDX, Tile::EnumValue tilevalue, char* src, char propagate)
	{
		tile->Set(Tile::kValue_zoom, -1, propagate);
		tile->Set(Tile::kValue_systemcolor, 1, propagate);
	}

	void __fastcall CursorTileSetIntValue(Tile* tile, void* dummyEDX, Tile::EnumValue tilevalue, int value)
	{
		tile->Set(Tile::kValue_visible, value, true);
		ThisCall(0xA0B350, InterfaceManager::GetSingleton()->pkCursor, 1, 0);
	}

	void Patch(const bool enable)
	{
		if (enable)
		{
			WriteRelCall(0x70B33A, CursorTileSetStringValue);
			WriteRelCall(0x70C727, CursorTileSetIntValue);
		}
		else
		{
			UndoSafeWrite(0x70B33A);
			UndoSafeWrite(0x70C727);
		}
	}

	void HandleINIs()
	{
		const auto iniPath = GetCurPath() / yUI_INI;
		CSimpleIniA ini;
		ini.SetUnicode();


		if (ini.LoadFile(iniPath.c_str()) == SI_FILE) return;

		enable = ini.GetOrCreate("General", "bMatchingCursor", 0, "; match cursor color to HUD color");

		ini.SaveFile(iniPath.c_str(), false);
	}

	extern void Init()
	{
		if (g_nvseInterface->isEditor) return;
		HandleINIs();
		Patch(enable);
	}
}
