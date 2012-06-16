sludge_panther = Creature:new {
	objectName = "@mob/creature_names:sludge_panther",
	socialGroup = "panther",
	pvpFaction = "",
	faction = "",
	level = 16,
	chanceHit = 0.31,
	damageMin = 170,
	damageMax = 180,
	baseXp = 1102,
	baseHAM = 2900,
	baseHAMmax = 3500,
	armor = 0,
	resists = {15,5,5,-1,-1,-1,-1,-1,-1},
	meatType = "meat_carnivore",
	meatAmount = 24,
	hideType = "hide_leathery",
	hideAmount = 30,
	boneType = "bone_mammal",
	boneAmount = 31,
	milk = 0,
	tamingChance = 0.25,
	ferocity = 6,
	pvpBitmask = AGGRESSIVE + ATTACKABLE,
	creatureBitmask = PACK + KILLER + STALKER,
	optionsBitmask = 128,
	diet = CARNIVORE,

	aiTemplate = "default",

	templates = {"object/mobile/minor_sludge_panther.iff"},
	lootGroups = {},
	weapons = {},
	conversationTemplate = "",
	attacks = {
		{"stunattack","stunChance=50"}
	}
}

CreatureTemplates:addCreatureTemplate(sludge_panther, "sludge_panther")