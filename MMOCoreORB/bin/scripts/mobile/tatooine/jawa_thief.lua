jawa_thief = Creature:new {
	objectName = "@mob/creature_names:jawa_thief",
	socialGroup = "jawa",
	pvpFaction = "jawa",
	faction = "jawa",
	level = 9,
	chanceHit = 0.27,
	damageMin = 80,
	damageMax = 90,
	baseXp = 235,
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
	creatureBitmask = HERD,
	optionsBitmask = 128,
	diet = HERBIVORE,

	aiTemplate = "default",

	templates = {"object/mobile/jawa_male.iff"},
	lootGroups = {
	    {
			groups = {
				{group = "junk", chance = 3000000},
				{group = "color_crystals", chance = 200000},
				{group = "pistols", chance = 500000},
				{group = "rifles", chance = 500000},
				{group = "carbines", chance = 500000}
			},
			lootChance = 3500000
		}					
	},
	weapons = {"novice_weapons"},
	conversationTemplate = "",
	attacks = merge(marksmannovice)
}

CreatureTemplates:addCreatureTemplate(jawa_thief, "jawa_thief")
