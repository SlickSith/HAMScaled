pirate_leader = Creature:new {
	objectName = "@mob/creature_names:pirate_leader",
	socialGroup = "pirate",
	pvpFaction = "pirate",
	faction = "pirate",
	level = 43,
	chanceHit = 0.46,
	damageMin = 365,
	damageMax = 440,
	baseXp = 4279,
	baseHAM = 8600,
	baseHAMmax = 11800,
	armor = 0,
	resists = {10,15,30,40,-1,40,30,-1,-1},
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

	templates = {},
	lootGroups = {},
	weapons = {"pirate_weapons_heavy"},
	conversationTemplate = "",
	attacks = merge(brawlermaster,marksmanmaster)
}

CreatureTemplates:addCreatureTemplate(pirate_leader, "pirate_leader")