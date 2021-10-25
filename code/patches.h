#pragma once
#include "main.h"

void patchRemoveTagsAddIcons()
{
	WriteRelJump(0x71A3D5, UInt32(Tile__SetStringValueInjectIconHook));
	WriteRelJump(0x782516, UInt32(InventoryMenuSortingHook));
	WriteRelJump(0x72F0ED, UInt32(BarterContainerMenuSortingHook));
	WriteRelJump(0x75D138, UInt32(BarterContainerMenuSortingHook));

	WriteRelJump(0x70189E, UInt32(Tile__SetStringValueHotkeyHook));
	WriteRelJump(0x7814FA, UInt32(Tile__SetStringValueHotkeyHook2));

}

/*void patchRemoveTagsHotkey()
{
	WriteRelCall(0x77DD63, UInt32(Tile__SetStringValueRemoveTag)); // HUDMainMenu Hotkey
	WriteRelCall(0x77E06C, UInt32(Tile__SetStringValueRemoveTag));

	WriteRelCall(0x70191F, UInt32(Tile__SetStringValueRemoveTag)); // PipBoy Hotkey
	WriteRelCall(0x70195B, UInt32(Tile__SetStringValueRemoveTag));
}

void patchRemoveTagsHUDMain()
{
	// not unsafe but I dislike it
	WriteRelCall(0x777231, UInt32(Tile__SetStringValueRemoveTag)); // Pick Up Prompt
	WriteRelCall(0x776F76, UInt32(strcpy_s_Alt));
}*/

//	00769802

	//	WriteRelCall(0x71A3D5, UInt32(Tile__SetStringValueInjectTile)); // Tile Creation
	//	WriteRelCall(0x75D21E, UInt32(Tile__SetStringValueRemoveTag)); // Container
	//	WriteRelJump(0x72F37F, UInt32(PostJazzHookBarter)); // Barter
	//	WriteRelJump(0x7828F8, UInt32(PostJazzHookInventory)); // Inventory
	//	WriteRelCall(0x72A9B5, UInt32(Tile__SetStringValueRemoveTag)); // Recipes

void patch1080pUI()
{

	//	WriteRelCall(0x70B9CE, UInt32(Tile_SetStringValueCursor));
//	WriteRelCall(0x70B320, UInt32(Tile_SetStringValueCursor));
//	WriteRelCall(0x70CC1F, UInt32(Tile_SetStringValueCursor));

	WriteRelJump(0x715D54, UInt32(UIWidth));
	WriteRelCall(0x715DA6, 0x4DC200);
	WriteRelJump(0x715DB4, UInt32(UIHeight));

//	SafeWriteBuf(0x106EC38, "\x00\x00\xF0\x44", 4); //1280
//	SafeWriteBuf(0x106F2DC, "\x00\x00\x87\x44", 4); //960
//	SafeWriteBuf(0x106E960, "\x00\x00\x00\x00\x00\x00\x9E\x40", 8); //1280
//	SafeWriteBuf(0x106E7F8, "\x00\x00\x00\x00\x00\xe0\x90\x40", 8); //960
//	SafeWriteBuf(0x1021790, "\x1D\xC7\x71\x1C\xC7\x71\xFC\x3F", 8); //1.3333
	SafeWriteBuf(0x1078128, "\x1D\xC7\x71\x1C\xC7\x71\xFC\x3F", 8); //1.3333
//	SafeWriteBuf(0x713040, "\xDD\x05\xF8\xE7\x06\x01", 6);

	WriteRelJump(0x713037, UInt32(UIWidth2));
	WriteRelJump(0x713040, UInt32(UIHeight2));
	WriteRelJump(0x7FBBDC, UInt32(UIWidth3));
	WriteRelJump(0x7FBBE5, UInt32(UIHeight3));
//	`DC 0D 60 E9 06 01`
//	`D9 05 DC F2 06 01`
//	SafeWriteBuf(0x11A0190, "\x60\x05\x00\x00", 4); //960


//	SafeWriteBuf(0x106F070, "\x00\x00\x00\x00\x00\x60\x78\x40", 8);
	//	SafeWriteBuf(0x1021790, "\x00\x00\x00\x00\x00\x00\xF8\x3F", 8);

	//01189488 0118948C 01189490 01189494 01189498

//	SafeWriteBuf(0x71302B, "\x66\x0F\x1F\x44\x00\x00", 6);
//	SafeWriteBuf(0x713031, "\x66\x0F\x1F\x44\x00\x00", 6);
//	SafeWriteBuf(0x713037, "\xD9\x05\x38\xEC\x06\x01", 6);
	// sub_E68A80 Tile_A04640
}

void patchAddyCMToSettingsMenu()
{
	
	WriteRelCall(0x7CC9D4, UInt32(AddyCMToSettingsMenu));
	WriteRelJump(0x7CCA43, 0x7CCAAD);

//	SafeWriteBuf(0x7CBF77

//	SafeWriteBuf(0x7CBF8C, "\x66\x0F\x1F\x44\x00\x00", 6);//
//	SafeWriteBuf(0x7CB674, "\x0F\x1F\x44\x00\x00", 5);
//	SafeWriteBuf(0x7CB686, "\x0F\x1F\x44\x00\x00", 5);
//	SafeWriteBuf(0x7CB698, "\x0F\x1F\x44\x00\x00", 5);
//	SafeWriteBuf(0x7CB6AA, "\x0F\x1F\x44\x00\x00", 5);
//	SafeWriteBuf(0x7CB6BC, "\x0F\x1F\x44\x00\x00", 5);
//	SafeWriteBuf(0x7CB6CE, "\x0F\x1F\x44\x00\x00", 5);
//	SafeWriteBuf(0x7CB6E0, "\x0F\x1F\x44\x00\x00", 5);
//	SafeWriteBuf(0x7CBE50, "\x81\x7A\x08\x50\x05\x7D\x00", 7);
	
/*	SafeWriteBuf(0x7CC044, "\x0F\x1F\x44\x00\x00", 5);
	SafeWriteBuf(0x7CC392, "\x0F\x1F\x44\x00\x00", 5);
	SafeWriteBuf(0x7CC23E, "\x0F\x1F\x44\x00\x00", 5);
	SafeWriteBuf(0x7CC0C3, "\x0F\x1F\x44\x00\x00", 5);
	SafeWriteBuf(0x7CC044, "\x0F\x1F\x44\x00\x00", 5);
	SafeWriteBuf(0x7CC416, "\x0F\x1F\x44\x00\x00", 5);
	SafeWriteBuf(0x7CC582, "\x0F\x1F\x44\x00\x00", 5);*/
//	SafeWriteBuf(0x7CBF59, "\x0F\x1F\x44\x00\x00", 5);
//	SafeWriteBuf(0x7CC01F, "\x0F\x1F\x44\x00\x00", 5);
	
}