stormtrooper_captain = Creature:new {
	objectName = "@mob/creature_names:stormtrooper_captain",
	socialGroup = "imperial",
	pvpFaction = "imperial",
	faction = "imperial",
	level = 29,
	chanceHit = 3.08,
	damageMin = 280,
	damageMax = 290,
	baseXp = 3005,
	baseHAM = 8300,
	baseHAMmax = 10100,
	armor = 0,
	resists = {20,20,20,-1,30,-1,30,-1,-1},
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
	creatureBitmask = PACK + KILLER,
	optionsBitmask = 128,
	diet = HERBIVORE,

	aiTemplate = "default",

	templates = {"object/mobile/dressed_stormtrooper_captain_black_black.iff"},
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
	weapons = {"stormtrooper_weapons"},
	conversationTemplate = "",
	attacks = merge(riflemanmaster,carbineermaster)
}

CreatureTemplates:addCreatureTemplate(stormtrooper_captain, "stormtrooper_captain")