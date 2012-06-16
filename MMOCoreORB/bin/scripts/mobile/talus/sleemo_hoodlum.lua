sleemo_hoodlum = Creature:new {
	objectName = "@mob/creature_names:sleemo_hoodlum",
	socialGroup = "Sleemo Gang",
	pvpFaction = "",
	faction = "",
	level = 6,
	chanceHit = 0.250000,
	damageMin = 50,
	damageMax = 55,
	baseXp = 113,
	baseHAM = 180,
	baseHAMmax = 220,
	armor = 0,
	resists = {0,0,0,0,0,0,0,-1,-1},
	meatType = "",
	meatAmount = 0,
	hideType = "",
	hideAmount = 0,
	boneType = "",
	boneAmount = 0,
	milk = 0,
	tamingChance = 0.000000,
	ferocity = 0,
	pvpBitmask = ATTACKABLE,
	creatureBitmask = HERD,
	diet = HERBIVORE,

	aiTemplate = "default",

	templates = {"object/mobile/dressed_criminal_thug_human_male_02.iff",
				"object/mobile/dressed_crook_zabrak_male_01.iff",
				"object/mobile/dressed_criminal_thug_zabrak_male_01.iff",
				"object/mobile/dressed_desperado_bith_female_01.iff"},
	lootGroups = {},
	weapons = {"pirate_weapons_light"},
	attacks = merge(brawlermaster,marksmanmaster)
}

CreatureTemplates:addCreatureTemplate(sleemo_hoodlum, "sleemo_hoodlum")