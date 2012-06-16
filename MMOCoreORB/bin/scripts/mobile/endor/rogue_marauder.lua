rogue_marauder = Creature:new {
	objectName = "",
	customName = "a Rogue Marauder",
	socialGroup = "self",
	pvpFaction = "endor_marauder",
	faction = "endor_marauder",
	level = 44,
	chanceHit = 0.47,
	damageMin = 345,
	damageMax = 400,
	baseXp = 4370,
	baseHAM = 12000,
	baseHAMmax = 12000,
	armor = 0,
	resists = {0,0,0,-1,0,0,-1,0,-1},
	meatType = "",
	meatAmount = 0,
	hideType = "",
	hideAmount = 0,
	boneType = "",
	boneAmount = 0,
	milk = 0,
	tamingChance = 0,
	ferocity = 0,
	pvpBitmask = AGGRESSIVE + ATTACKABLE,
	creatureBitmask = PACK + KILLER,
	optionsBitmask = 128,
	diet = HERBIVORE,

	aiTemplate = "default",

	templates = {
			"object/mobile/dressed_marauder.iff",
			"object/mobile/dressed_marauder_male.iff",
			"object/mobile/dressed_marauder_male_02.iff",
			"object/mobile/dressed_marauder_male_03.iff",
			"object/mobile/dressed_marauder_female.iff"},
	lootGroups = {},
	weapons = {"pirate_weapons_heavy"},
	conversationTemplate = "",
	attacks = merge(riflemanmaster,pistoleermaster,carbineermaster,brawlermaster)
}

CreatureTemplates:addCreatureTemplate(rogue_marauder, "rogue_marauder")