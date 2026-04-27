.set LOCALID_HINT_SPIRIT, 1

ZoroarkShrine_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ZoroarkShrine_OnTransition
	.byte 0

ZoroarkShrine_OnTransition:
	end

ZoroarkShrine_EventScript_Intro::
	end

ZoroarkShrine_EventScript_HintSpirit::
	lock
	faceplayer
	msgbox ZoroarkShrine_Text_SpiritSpeaks, MSGBOX_DEFAULT
	closemessage
	release
	end

ZoroarkShrine_EventScript_Item::
	lock
	faceplayer
	msgbox ZoroarkShrine_Text_Item, MSGBOX_DEFAULT
	closemessage
	additem ITEM_SUPER_POTION, 3
	setflag FLAG_ITEM_ZOROARK_SHRINE_TM_FIRE
	release
	end

ZoroarkShrine_EventScript_PillarSign::
	msgbox ZoroarkShrine_Text_PillarSign, MSGBOX_SIGN
	end

ZoroarkShrine_Text_SpiritSpeaks:
	.string "Spirit: Find the 2 crystals to escape.\p"
	.string "ZOROARK is in the WOODS to the SOUTH.\n"
	.string "CELEBI is at the Ancient TREE.\p"
	.string "WALK SOUTH to the map edge to exit.$"

ZoroarkShrine_Text_PillarSign:
	.string "Exit: SOUTH to WOODS$"

ZoroarkShrine_Text_Item:
	.string "Found 3 Super Potions!$"
