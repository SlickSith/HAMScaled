sleemo_vandal = Creature:new {
	objectName = "",
	customName = "Sleemo Vandal",
	socialGroup = "Sleemo Gang",
	pvpFaction = "",
	faction = "",
	level = 9,
	chanceHit = 0.27,
	damageMin = 80,
	damageMax = 90,
	baseXp = 292,
	baseHAM = 675,
	baseHAMmax = 825,
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
	pvpBitmask = ATTACKABLE,
	creatureBitmask = PACK + HERD,
	optionsBitmask = 128,
	diet = HERBIVORE,

	aiTemplate = "default",

	templates = {},
	lootGroups = {},
	weapons = {"pirate_weapons_medium"},
	conversationTemplate = "",
	attacks = merge(brawlermaster,marksmanmaster)
}

CreatureTemplates:addCreatureTemplate(sleemo_vandal, "sleemo_vandal")