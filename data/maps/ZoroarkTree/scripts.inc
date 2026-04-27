.set LOCALID_CELEBI, 0

ZoroarkTree_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ZoroarkTree_OnTransition
	.byte 0

ZoroarkTree_OnTransition:
	compare VAR_ZOROARK_STORY_STATE, 4
	goto_if_ge ZoroarkTree_EventScript_HideCelebi
	end

ZoroarkTree_EventScript_HideCelebi::
	setflag FLAG_HIDE_CELEBI
	end

ZoroarkTree_EventScript_Celebi::
	lock
	faceplayer
	msgbox ZoroarkTree_Text_CelebiBlocks, MSGBOX_DEFAULT
	closemessage
	setvar 0x4040, 0
	setwildbattle SPECIES_CELEBI, 25, ITEM_NONE
	dowildbattle
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq ZoroarkTree_EventScript_CelebiDefeatedPuzzle
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq ZoroarkTree_EventScript_CelebiCaughtPuzzle
	msgbox ZoroarkTree_Text_CelebiWaits, MSGBOX_DEFAULT
	closemessage
	release
	end

ZoroarkTree_EventScript_CelebiDefeatedPuzzle::
ZoroarkTree_EventScript_CelebiCaughtPuzzle::
	msgbox ZoroarkTree_Text_CelebiRevealsCrystal, MSGBOX_DEFAULT
	closemessage
	additem ITEM_CRYSTAL_ANCIENT, 1
	setvar VAR_ZOROARK_STORY_STATE, 3
	msgbox ZoroarkTree_Text_PlaceCrystals, MSGBOX_DEFAULT
	closemessage
	release
	end

ZoroarkTree_EventScript_Altar::
	lock
	compare VAR_ZOROARK_STORY_STATE, 3
	goto_if_eq ZoroarkTree_EventScript_CheckCrystals
	compare VAR_ZOROARK_STORY_STATE, 4
	goto_if_ge ZoroarkTree_EventScript_PortalActive
	msgbox ZoroarkTree_Text_EmptyAltar, MSGBOX_SIGN
	end

ZoroarkTree_EventScript_CheckCrystals::
	checkitem ITEM_CRYSTAL_ILLUSION
	compare VAR_RESULT, FALSE
	goto_if_eq ZoroarkTree_EventScript_MissingCrystal
	checkitem ITEM_CRYSTAL_ANCIENT
	compare VAR_RESULT, FALSE
	goto_if_eq ZoroarkTree_EventScript_MissingCrystal
	msgbox ZoroarkTree_Text_PlaceCrystalsYesNo, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq ZoroarkTree_EventScript_DontPlace
	removeitem ITEM_CRYSTAL_ILLUSION, 1
	removeitem ITEM_CRYSTAL_ANCIENT, 1
	msgbox ZoroarkTree_Text_CrystalsPlaced, MSGBOX_DEFAULT
	closemessage
	fadeoutbgm 1
	setvar VAR_ZOROARK_STORY_STATE, 4
	setflag FLAG_HIDE_CELEBI
	removeobject LOCALID_CELEBI
	fadescreen FADE_TO_BLACK
	playse SE_M_DETECT
	waitse
	fadescreen FADE_FROM_BLACK
	msgbox ZoroarkTree_Text_PortalOpens, MSGBOX_DEFAULT
	closemessage
	release
	end

ZoroarkTree_EventScript_DontPlace::
	msgbox ZoroarkTree_Text_DontPlace, MSGBOX_DEFAULT
	closemessage
	release
	end

ZoroarkTree_EventScript_MissingCrystal::
	msgbox ZoroarkTree_Text_MissingCrystal, MSGBOX_DEFAULT
	closemessage
	release
	end

ZoroarkTree_EventScript_PortalActive::
	msgbox ZoroarkTree_Text_EnterPortal, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq ZoroarkTree_EventScript_DontEnter
	fadeoutbgm 1
	fadescreen FADE_TO_BLACK
	setvar VAR_ZOROARK_STORY_STATE, 5
	goto ZoroarkTree_EventScript_EndingSequence
	release
	end

ZoroarkTree_EventScript_DontEnter::
	msgbox ZoroarkTree_Text_DontEnter, MSGBOX_DEFAULT
	closemessage
	release
	end

ZoroarkTree_EventScript_EndingSequence::
	msgbox ZoroarkTree_Text_PortalTravel, MSGBOX_DEFAULT
	closemessage
	playse SE_M_TELEPORT
	waitse
	msgbox ZoroarkTree_Text_NotHome, MSGBOX_DEFAULT
	closemessage
	delay 60
	msgbox ZoroarkTree_Text_LabReveal, MSGBOX_DEFAULT
	closemessage
	delay 60
	msgbox ZoroarkTree_Text_ProjectInfo, MSGBOX_DEFAULT
	closemessage
	delay 60
	msgbox ZoroarkTree_Text_VoiceOver, MSGBOX_DEFAULT
	closemessage
	delay 60
	msgbox ZoroarkTree_Text_ZoroarkCameo, MSGBOX_DEFAULT
	closemessage
	playmoncry SPECIES_ZOROARK, CRY_MODE_NORMAL
	waitmoncry
	fadeoutbgm 1
	delay 120
	msgbox ZoroarkTree_Text_ToBeContinued, MSGBOX_DEFAULT
	closemessage
	warp MAP_LITTLEROOT_TOWN, 6, 8
	end

ZoroarkTree_Text_CelebiBlocks:
	.string "Celebi: Ti-ti-ti!\p"
	.string "The guardian of the forest blocks\n"
	.string "your path. It seems to be testing\l"
	.string "you...$"

ZoroarkTree_Text_CelebiWaits:
	.string "Celebi waits patiently, its eyes\n"
	.string "filled with ancient wisdom...$"

ZoroarkTree_Text_CelebiRevealsCrystal:
	.string "Celebi smiles and reveals the\n"
	.string "ANCIENT CRYSTAL!$"

ZoroarkTree_Text_PlaceCrystals:
	.string "Celebi: Ti-ti!\p"
	.string "Place the crystals on the altar\n"
	.string "to open the portal home.$"

ZoroarkTree_Text_EmptyAltar:
	.string "An ancient stone altar. There are\n"
	.string "indentations for two crystals...$"

ZoroarkTree_Text_MissingCrystal:
	.string "You don't have all the crystals\n"
	.string "yet. Find the Illusion Crystal\l"
	.string "and the Ancient Crystal.$"

ZoroarkTree_Text_PlaceCrystalsYesNo:
	.string "Place the Illusion Crystal and\n"
	.string "Ancient Crystal on the altar?$"

ZoroarkTree_Text_DontPlace:
	.string "You decide to wait...$"

ZoroarkTree_Text_CrystalsPlaced:
	.string "The crystals begin to glow!$"

ZoroarkTree_Text_PortalOpens:
	.string "A portal of light opens before you!\p"
	.string "The way home is open!$"

ZoroarkTree_Text_EnterPortal:
	.string "Enter the portal?$"

ZoroarkTree_Text_DontEnter:
	.string "You hesitate at the threshold...$"

ZoroarkTree_Text_PortalTravel:
	.string "You step into the portal...\p"
	.string "Light surrounds you as you're\n"
	.string "pulled through space and time...$"

ZoroarkTree_Text_NotHome:
	.string "... ... ... ...\p"
	.string "Wait.\p"
	.string "This isn't your world.$"

ZoroarkTree_Text_LabReveal:
	.string "You're standing in a high-tech\n"
	.string "laboratory surrounded by scientists\l"
	.string "in white coats.$"

ZoroarkTree_Text_ProjectInfo:
	.string "A monitor displays:\p"
	.string "PROJECT: MYSTICAL_FOREST\n"
	.string "SIMULATION: COMPLETE\p"
	.string "Test Subject No.001\n"
	.string "Memory Integration: FAILED\p"
	.string "Next Test: COASTAL_RUINS\n"
	.string "Initializing...$"

ZoroarkTree_Text_VoiceOver:
	.string "Voice: Subject shows resistance\n"
	.string "to memory wipe.\p"
	.string "Prepare containment. And someone\n"
	.string "get me that ZOROARK specimen.\l"
	.string "It's been loose in the simulation\l"
	.string "again...$"

ZoroarkTree_Text_ZoroarkCameo:
	.string "From the shadows, ZOROARK appears!\p"
	.string "It smirks at you and vanishes\n"
	.string "through the wall...$"

ZoroarkTree_Text_ToBeContinued:
	.string "To be continued in...\p"
	.string "POKÉMON ESCAPE ROOM:\n"
	.string "COASTAL RUINS$"
