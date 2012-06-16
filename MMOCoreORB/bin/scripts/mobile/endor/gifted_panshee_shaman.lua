gifted_panshee_shaman = Creature:new {
	objectName = "@mob/creature_names:gifted_panshee_shaman",
	socialGroup = "panshee_tribe",
	pvpFaction = "panshee_tribe",
	faction = "panshee_tribe",
	level = 38,
	chanceHit = 0.42,
	damageMin = 330,
	damageMax = 370,
	baseXp = 3733,
	baseHAM = 9200,
	baseHAMmax = 11200,
	armor = 0,
	resists = {25,25,25,25,25,25,25,25,-1},
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
	creatureBitmask = PACK + HEALER,
	optionsBitmask = 128,
	diet = HERBIVORE,

	aiTemplate = "default",

	templates = {
		"object/mobile/dressed_ewok_m_07.iff",
		"object/mobile/dressed_ewok_m_11.iff"},
	lootGroups = {},
	weapons = {"ewok_weapons"},
	conversationTemplate = "",
	attacks = merge(riflemanmaster)
}

CreatureTemplates:addCreatureTemplate(gifted_panshee_shaman, "gifted_panshee_shaman")