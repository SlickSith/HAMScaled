rebel_commandant = Creature:new {
	objectName = "@mob/creature_names:corvette_rebel_commandant",
	socialGroup = "rebel",
	pvpFaction = "rebel",
	faction = "rebel",
	level = 151,
	chanceHit = 8.5,
	damageMin = 895,
	damageMax = 1500,
	baseXp = 14314,
	baseHAM = 81000,
	baseHAMmax = 99000,
	armor = 2,
	resists = {50,65,30,30,30,30,80,65,-1},
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

	templates = {"object/mobile/dressed_rebel_general_human_female_02.iff"},
	lootGroups = {
		{
			groups = {
				{group = "color_crystals", chance = 200000},
				{group = "junk", chance = 3600000},
				{group = "rifles", chance = 1000000},
				{group = "pistols", chance = 1000000},
				{group = "clothing_attachments", chance = 500000},
				{group = "armor_attachments", chance = 500000}
			},
			lootChance = 4000000
		}					
	},
	weapons = {"rebel_weapons_heavy"},
	conversationTemplate = "",
	attacks = merge(riflemanmaster,pistoleermaster,carbineermaster,brawlermaster)
}

CreatureTemplates:addCreatureTemplate(rebel_commandant, "rebel_commandant")