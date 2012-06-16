criminal = Creature:new {
	objectName = "@mob/creature_names:criminal",
	socialGroup = "thug",
	pvpFaction = "thug",
	faction = "thug",
	level = 7,
	chanceHit = 0.26,
	damageMin = 55,
	damageMax = 65,
	baseXp = 187,
	baseHAM = 270,
	baseHAMmax = 330,
	armor = 0,
	resists = {0,0,0,0,0,0,0,-1,-1},
	meatType = "",
	meatAmount = 0,
	hideType = "",
	hideAmount = 0,
	boneType = "",
	boneAmount = 0,
	milk = 0,
	tamingChance = 0,
	ferocity = 0,
	pvpBitmask = NONE,
	creatureBitmask = PACK + STALKER,
	optionsBitmask = 128,
	diet = HERBIVORE,

	aiTemplate = "default",

	templates = {"object/mobile/dressed_criminal_thug_human_male_01.iff",
					"object/mobile/dressed_criminal_thug_bothan_female_01.iff",
					"object/mobile/dressed_goon_twk_male_01.iff",
					"object/mobile/dressed_robber_twk_female_01.iff",
					"object/mobile/dressed_goon_twk_female_01.iff",
					"object/mobile/dressed_robber_human_female_01.iff",
					"object/mobile/dressed_villain_trandoshan_male_01.iff",
					"object/mobile/dressed_criminal_thug_bothan_male_01.iff",
					"object/mobile/dressed_villain_trandoshan_female_01.iff"
					},
	lootGroups = {},
	weapons = {"pirate_weapons_light"},
	conversationTemplate = "",
	attacks = merge(riflemanmaster,pistoleermaster,carbineermaster,brawlermaster)
}

CreatureTemplates:addCreatureTemplate(criminal, "criminal")