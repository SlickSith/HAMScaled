rorgungan_warrior = Creature:new {
	objectName = "@mob/creature_names:rorgungan_warrior",
	socialGroup = "rorgungan",
	pvpFaction = "rorgungan",
	faction = "rorgungan",
	level = 17,
	chanceHit = 0.310000,
	damageMin = 170,
	damageMax = 180,
	baseXp = 1102,
	baseHAM = 2900,
	baseHAMmax = 3500,
	armor = 0,
	resists = {15,15,0,-1,30,0,0,-1,-1},
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
	creatureBitmask = PACK + HERD,
	diet = HERBIVORE,

	aiTemplate = "default",

	templates = {"object/mobile/gungan_male.iff"},
	lootGroups = {
	    {
			groups = {
				{group = "junk", chance = 3000000},
				{group = "tailor_components", chance = 500000},
				{group = "loot_kit_parts", chance = 1500000},
				{group = "color_crystals", chance = 200000},
				{group = "crystals_poor", chance = 200000}
			},
			lootChance = 3200000
		}					
	},
	weapons = {"rebel_weapons_heavy"},
	attacks = merge(brawlernovice,marksmannovice)
}

CreatureTemplates:addCreatureTemplate(rorgungan_warrior, "rorgungan_warrior")