explorer = Creature:new {
	objectName = "@mob/creature_names:explorer",
	socialGroup = "Mercenary",
	pvpFaction = "",
	faction = "townsperson",
	level = 7,
	chanceHit = 0.26,
	damageMin = 55,
	damageMax = 65,
	baseXp = 147,
	baseHAM = 270,
	baseHAMmax = 330,
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
	creatureBitmask = NONE,
	optionsBitmask = 128,
	diet = HERBIVORE,

	aiTemplate = "default",

	templates = {	"object/mobile/dressed_commoner_fat_zabrak_male_01.iff",
					"object/mobile/dressed_commoner_naboo_human_female_07.iff",
					"object/mobile/dressed_commoner_naboo_human_male_08.iff",
					"object/mobile/dressed_commoner_tatooine_aqualish_female_03.iff",
					"object/mobile/dressed_commoner_naboo_moncal_female_01.iff",
					"object/mobile/dressed_commoner_tatooine_aqualish_male_05.iff",
					"object/mobile/dressed_commoner_naboo_bothan_male_01.iff",
					"object/mobile/dressed_commoner_tatooine_aqualish_female_04.iff",
					"object/mobile/dressed_commoner_naboo_moncal_male_02.iff"
					},
	lootGroups = {},
	weapons = {},
	conversationTemplate = "",
	attacks = {
	}
}

CreatureTemplates:addCreatureTemplate(explorer, "explorer")