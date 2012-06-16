owaitacyg_amafie = Creature:new {
	objectName = "@npc_name:zabrak_base_male",
	customName = "Owaitacyg Amafie",
	socialGroup = "townsperson",
	pvpFaction = "townsperson",
	faction = "townsperson",
	level = 13,
	chanceHit = 0.29,
	damageMin = 150,
	damageMax = 160,
	baseXp = 609,
	baseHAM = 1500,
	baseHAMmax = 1900,
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
	ferocity = 3,
	pvpBitmask = NONE,
	creatureBitmask = NONE,
	optionsBitmask = 128,
	diet = CARNIVORE,

	aiTemplate = "default",

	templates = {"object/mobile/dressed_bestine_rumor02.iff"},
	lootGroups = {},
	weapons = {},
	conversationTemplate = "",
	attacks = {}
}

CreatureTemplates:addCreatureTemplate(owaitacyg_amafie, "owaitacyg_amafie")