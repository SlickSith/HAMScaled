chadra_fan_assassin = Creature:new {
	objectName = "@mob/creature_names:chadra_fan_assassin",
	socialGroup = "chadra_fan",
	pvpFaction = "",
	faction = "",
	level = 20,
	chanceHit = 0.33,
	damageMin = 240,
	damageMax = 250,
	baseXp = 1609,
	baseHAM = 3500,
	baseHAMmax = 4300,
	armor = 0,
	resists = {0,0,0,0,0,0,0,0,-1},
	meatType = "",
	meatAmount = 0,
	hideType = "",
	hideAmount = 0,
	boneType = "",
	boneAmount = 0,
	milk = 0,
	tamingChance = 0,
	ferocity = 0,
	pvpBitmask = ATTACKABLE,
	creatureBitmask = KILLER + STALKER,
	optionsBitmask = 128,
	diet = HERBIVORE,

	aiTemplate = "default",

	templates = {
		"object/mobile/chadra_fan_female.iff",
		"object/mobile/dressed_chadra_fan_f_01.iff",
		"object/mobile/dressed_chadra_fan_f_02.iff",
		"object/mobile/dressed_chadra_fan_f_03.iff",
		"object/mobile/chadra_fan_male.iff",
		"object/mobile/dressed_chadra_fan_m_01.iff",
		"object/mobile/dressed_chadra_fan_m_02.iff",
		"object/mobile/dressed_chadra_fan_m_03.iff"},
	lootGroups = {},
	weapons = {"pirate_weapons_heavy"},
	conversationTemplate = "",
	attacks = {
	}
}

CreatureTemplates:addCreatureTemplate(chadra_fan_assassin, "chadra_fan_assassin")