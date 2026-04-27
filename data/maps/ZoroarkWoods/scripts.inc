.set LOCALID_CELEBI_ILLUSION, 1
.set LOCALID_ZOROARK, 2

ZoroarkWoods_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ZoroarkWoods_OnTransition
	.byte 0

ZoroarkWoods_OnTransition:
	compare VAR_ZOROARK_STORY_STATE, 2
	goto_if_ge ZoroarkWoods_EventScript_HideZoroark
	end

ZoroarkWoods_EventScript_HideZoroark::
	setflag FLAG_HIDE_ZOROARK_ILLUSION
	end

ZoroarkWoods_EventScript_ZoroarkTrigger::
	lock
	msgbox ZoroarkWoods_Text_WhatIsThat, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	release
	end

ZoroarkWoods_EventScript_ZoroarkBattle::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	msgbox ZoroarkWoods_Text_WoundedPokemon, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	setflag FLAG_HIDE_ZOROARK_ILLUSION
	removeobject LOCALID_CELEBI_ILLUSION
	fadedefaultbgm
	playmoncry SPECIES_ZOROARK, CRY_MODE_ENCOUNTER
	waitmoncry
	msgbox ZoroarkWoods_Text_ZoroarkRevealed, MSGBOX_DEFAULT
	closemessage
	setvar 0x4040, 0
	setflag 0x495
	setwildbattle SPECIES_ZOROARK, 20, ITEM_NONE
	dowildbattle
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq ZoroarkWoods_EventScript_DefeatZoroark
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq ZoroarkWoods_EventScript_CaughtZoroark
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq ZoroarkWoods_EventScript_RanFromZoroark
	releaseall
	end

ZoroarkWoods_EventScript_DefeatZoroark::
	msgbox ZoroarkWoods_Text_ZoroarkDefeated, MSGBOX_DEFAULT
	closemessage
	additem ITEM_CRYSTAL_ILLUSION, 1
	setvar VAR_ZOROARK_STORY_STATE, 2
	setflag FLAG_HIDE_ZOROARK_ILLUSION
	releaseall
	end

ZoroarkWoods_EventScript_CaughtZoroark::
	msgbox ZoroarkWoods_Text_ZoroarkCaught, MSGBOX_DEFAULT
	closemessage
	additem ITEM_CRYSTAL_ILLUSION, 1
	setvar VAR_ZOROARK_STORY_STATE, 2
	setflag FLAG_HIDE_ZOROARK_ILLUSION
	releaseall
	end

ZoroarkWoods_EventScript_RanFromZoroark::
	msgbox ZoroarkWoods_Text_ZoroarkLaughs, MSGBOX_DEFAULT
	closemessage
	warp MAP_ZOROARK_SHRINE, 8, 10
	releaseall
	end

ZoroarkWoods_EventScript_ForestFlute::
	additem ITEM_FLUTE, 1
	end

ZoroarkWoods_Text_WhatIsThat:
	.string "Something is lying in the clearing...$"

ZoroarkWoods_Text_WoundedPokemon:
	.string "A wounded Celebi lies on the ground,\n"
	.string "glowing faintly.\p"
	.string "As you approach, the air shimmers...$"

ZoroarkWoods_Text_ZoroarkRevealed:
	.string "ZOROARK: GWOOOOR!\p"
	.string "The illusion breaks! It was a ZOROARK\n"
	.string "using its powers to trick you!\p"
	.string "Zoroark attacks!$"

ZoroarkWoods_Text_ZoroarkDefeated:
	.string "Zoroark falls back, grinning.\p"
	.string "It drops a shimmering crystal and\n"
	.string "vanishes into the fog...$"

ZoroarkWoods_Text_ZoroarkCaught:
	.string "Zoroark was caught!\p"
	.string "But it seems unfazed. It grins and\n"
	.string "drops a crystal before teleporting away.$"

ZoroarkWoods_Text_ZoroarkLaughs:
	.string "Zoroark: Grahahaha!\p"
	.string "You flee, and darkness consumes you...\p"
	.string "You wake up back at the shrine.$"
