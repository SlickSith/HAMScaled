settler = Creature:new {
	objectName = "@mob/creature_names:settler",
	socialGroup = "thug",
	pvpFaction = "thug",
	faction = "thug",
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
	creatureBitmask = NONE,
	diet = HERBIVORE,

	aiTemplate = "default",

	templates = {"object/mobile/dressed_tatooine_settler.iff"},
	lootGroups = {},
	weapons = {"rebel_weapons_light"},
	attacks = merge(marksmannovice,brawlernovice)
}

CreatureTemplates:addCreatureTemplate(settler, "settler")
