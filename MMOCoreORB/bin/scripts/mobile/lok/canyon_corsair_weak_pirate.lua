canyon_corsair_weak_pirate = Creature:new {
	objectName = "@mob/creature_names:canyon_corsair_pirate_weak",
	socialGroup = "canyon_corsair",
	pvpFaction = "canyon_corsair",
	faction = "canyon_corsair",
	level = 29,
	chanceHit = 0.39,
	damageMin = 290,
	damageMax = 300,
	baseXp = 3005,
	baseHAM = 8400,
	baseHAMmax = 10200,
	armor = 0,
	resists = {25,20,20,20,20,-1,-1,-1,-1},
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
		"object/mobile/dressed_corsair_pirate_weak_hum_f.iff",
		"object/mobile/dressed_corsair_pirate_weak_hum_m.iff",
		"object/mobile/dressed_corsair_pirate_weak_rod_m.iff"},
	lootGroups = {},
	weapons = {"pirate_weapons_heavy"},
	conversationTemplate = "",
	attacks = {
	}
}

CreatureTemplates:addCreatureTemplate(canyon_corsair_weak_pirate, "canyon_corsair_weak_pirate")