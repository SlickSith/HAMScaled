/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#ifndef SABER1HHIT3COMMAND_H_
#define SABER1HHIT3COMMAND_H_

#include "JediCombatQueueCommand.h"

class Saber1hHit3Command : public JediCombatQueueCommand {
public:

	Saber1hHit3Command(const String& name, ZoneProcessServer* server)
		: JediCombatQueueCommand(name, server) {

	}

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {

		if (!checkStateMask(creature))
			return INVALIDSTATE;

		if (!checkInvalidLocomotions(creature))
			return INVALIDLOCOMOTION;

		if (isWearingArmor(creature)) {
			//return NOJEDIARMOR;
		}
		return doCombatAction(creature, target);
	}

};

#endif //SABER1HHIT3COMMAND_H_
