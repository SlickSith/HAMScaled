/*
Copyright (C) 2007 <SWGEmu>

This File is part of Core3.

This program is free software; you can redistribute
it and/or modify it under the terms of the GNU Lesser
General Public License as published by the Free Software
Foundation; either version 2 of the License,
or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
See the GNU Lesser General Public License for
more details.

You should have received a copy of the GNU Lesser General
Public License along with this program; if not, write to
the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA

Linking Engine3 statically or dynamically with other modules
is making a combined work based on Engine3.
Thus, the terms and conditions of the GNU Lesser General Public License
cover the whole combination.

In addition, as a special exception, the copyright holders of Engine3
give you permission to combine Engine3 program with free software
programs or libraries that are released under the GNU LGPL and with
code included in the standard release of Core3 under the GNU LGPL
license (or modified versions of such code, with unchanged license).
You may copy and distribute such a system following the terms of the
GNU LGPL for Engine3 and the licenses of the other code concerned,
provided that you include the source code of that other code when
and as the GNU LGPL requires distribution of source code.

Note that people who make modified versions of Engine3 are not obligated
to grant this special exception for their modified versions;
it is their choice whether to do so. The GNU Lesser General Public License
gives permission to release a modified version without this exception;
this exception also makes it possible to release a modified version
which carries forward this exception.
*/

/*
 *	server/zone/managers/creature/CreatureManager.cpp generated by Engine3 IDL compiler 0.51
 */

#include "../../Zone.h"

#include "../../objects/creature/Creature.h"

#include "../../objects/creature/CreatureObject.h"

#include "../../objects/creature/CreatureGroup.h"

#include "../../objects/creature/trainer/TrainerCreature.h"

#include "../../objects/creature/recruiter/RecruiterCreature.h"

#include "../../objects/creature/shuttle/ShuttleCreature.h"

#include "CreatureManager.h"

#include "CreatureManagerImplementation.h"

/*
 *	CreatureManagerStub
 */

CreatureManager::CreatureManager() : ORBObjectStub(NULL) {
}

CreatureManager::CreatureManager(ORBObjectServant* obj) : ORBObjectStub(obj) {
}

CreatureManager::CreatureManager(CreatureManager& ref) : ORBObjectStub(ref) {
}

CreatureManager::~CreatureManager() {
}

CreatureManager* CreatureManager::clone() {
	return new CreatureManager(*this);
}


void CreatureManager::init() {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 6);

		invocation.executeWithVoidReturn();
	} else
		((CreatureManagerImplementation*) _impl)->init();
}

void CreatureManager::start() {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 7);

		invocation.executeWithVoidReturn();
	} else
		((CreatureManagerImplementation*) _impl)->start();
}

void CreatureManager::stop() {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 8);

		invocation.executeWithVoidReturn();
	} else
		((CreatureManagerImplementation*) _impl)->stop();
}

void CreatureManager::loadTrainers() {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 9);

		invocation.executeWithVoidReturn();
	} else
		((CreatureManagerImplementation*) _impl)->loadTrainers();
}

void CreatureManager::loadRecruiters() {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 10);

		invocation.executeWithVoidReturn();
	} else
		((CreatureManagerImplementation*) _impl)->loadRecruiters();
}

void CreatureManager::unloadCreature(Creature* creature) {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 11);
		invocation.addObjectParameter(creature);

		invocation.executeWithVoidReturn();
	} else
		((CreatureManagerImplementation*) _impl)->unloadCreature(creature);
}

Creature* CreatureManager::spawnCreature(const string& stfname, const string& name, int objCrc, float x, float y, int bitmask, bool doLock) {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 12);
		invocation.addAsciiParameter(stfname);
		invocation.addAsciiParameter(name);
		invocation.addSignedIntParameter(objCrc);
		invocation.addFloatParameter(x);
		invocation.addFloatParameter(y);
		invocation.addSignedIntParameter(bitmask);
		invocation.addBooleanParameter(doLock);

		return (Creature*) invocation.executeWithObjectReturn();
	} else
		return ((CreatureManagerImplementation*) _impl)->spawnCreature(stfname, name, objCrc, x, y, bitmask, doLock);
}

TrainerCreature* CreatureManager::spawnTrainer(const string& profession, const string& stfname, const string& name, int objCrc, float x, float y, bool doLock) {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 13);
		invocation.addAsciiParameter(profession);
		invocation.addAsciiParameter(stfname);
		invocation.addAsciiParameter(name);
		invocation.addSignedIntParameter(objCrc);
		invocation.addFloatParameter(x);
		invocation.addFloatParameter(y);
		invocation.addBooleanParameter(doLock);

		return (TrainerCreature*) invocation.executeWithObjectReturn();
	} else
		return ((CreatureManagerImplementation*) _impl)->spawnTrainer(profession, stfname, name, objCrc, x, y, doLock);
}

ShuttleCreature* CreatureManager::spawnShuttle(const string& Planet, const string& City, Coordinate* playerSpawnPoint, float x, float y, float z, bool doLock) {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 14);
		invocation.addAsciiParameter(Planet);
		invocation.addAsciiParameter(City);
		invocation.addObjectParameter(playerSpawnPoint);
		invocation.addFloatParameter(x);
		invocation.addFloatParameter(y);
		invocation.addFloatParameter(z);
		invocation.addBooleanParameter(doLock);

		return (ShuttleCreature*) invocation.executeWithObjectReturn();
	} else
		return ((CreatureManagerImplementation*) _impl)->spawnShuttle(Planet, City, playerSpawnPoint, x, y, z, doLock);
}

RecruiterCreature* CreatureManager::spawnRecruiter(const string& stfname, const string& name, int objCrc, float x, float y, bool doLock) {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 15);
		invocation.addAsciiParameter(stfname);
		invocation.addAsciiParameter(name);
		invocation.addSignedIntParameter(objCrc);
		invocation.addFloatParameter(x);
		invocation.addFloatParameter(y);
		invocation.addBooleanParameter(doLock);

		return (RecruiterCreature*) invocation.executeWithObjectReturn();
	} else
		return ((CreatureManagerImplementation*) _impl)->spawnRecruiter(stfname, name, objCrc, x, y, doLock);
}

CreatureGroup* CreatureManager::spawnCreatureGroup(int count, const string& stfname, const string& name, int objCrc, float x, float y, int bitmask, int layout) {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 16);
		invocation.addSignedIntParameter(count);
		invocation.addAsciiParameter(stfname);
		invocation.addAsciiParameter(name);
		invocation.addSignedIntParameter(objCrc);
		invocation.addFloatParameter(x);
		invocation.addFloatParameter(y);
		invocation.addSignedIntParameter(bitmask);
		invocation.addSignedIntParameter(layout);

		return (CreatureGroup*) invocation.executeWithObjectReturn();
	} else
		return ((CreatureManagerImplementation*) _impl)->spawnCreatureGroup(count, stfname, name, objCrc, x, y, bitmask, layout);
}

void CreatureManager::registerFunctions() {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 17);

		invocation.executeWithVoidReturn();
	} else
		((CreatureManagerImplementation*) _impl)->registerFunctions();
}

void CreatureManager::registerGlobals() {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 18);

		invocation.executeWithVoidReturn();
	} else
		((CreatureManagerImplementation*) _impl)->registerGlobals();
}

void CreatureManager::loadCreatureFile() {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 19);

		invocation.executeWithVoidReturn();
	} else
		((CreatureManagerImplementation*) _impl)->loadCreatureFile();
}

Creature* CreatureManager::getCreature(unsigned long long oid) {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 20);
		invocation.addUnsignedLongParameter(oid);

		return (Creature*) invocation.executeWithObjectReturn();
	} else
		return ((CreatureManagerImplementation*) _impl)->getCreature(oid);
}

/*
 *	CreatureManagerAdapter
 */

CreatureManagerAdapter::CreatureManagerAdapter(CreatureManagerImplementation* obj) : ORBObjectAdapter((ORBObjectServant*) obj) {
}

Packet* CreatureManagerAdapter::invokeMethod(uint32 methid, ORBMethodInvocation* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		init();
		break;
	case 7:
		start();
		break;
	case 8:
		stop();
		break;
	case 9:
		loadTrainers();
		break;
	case 10:
		loadRecruiters();
		break;
	case 11:
		unloadCreature((Creature*) inv->getObjectParameter());
		break;
	case 12:
		resp->insertLong(spawnCreature(inv->getAsciiParameter(_param0_spawnCreature__string_string_int_float_float_int_bool_), inv->getAsciiParameter(_param1_spawnCreature__string_string_int_float_float_int_bool_), inv->getSignedIntParameter(), inv->getFloatParameter(), inv->getFloatParameter(), inv->getSignedIntParameter(), inv->getBooleanParameter())->_getORBObjectID());
		break;
	case 13:
		resp->insertLong(spawnTrainer(inv->getAsciiParameter(_param0_spawnTrainer__string_string_string_int_float_float_bool_), inv->getAsciiParameter(_param1_spawnTrainer__string_string_string_int_float_float_bool_), inv->getAsciiParameter(_param2_spawnTrainer__string_string_string_int_float_float_bool_), inv->getSignedIntParameter(), inv->getFloatParameter(), inv->getFloatParameter(), inv->getBooleanParameter())->_getORBObjectID());
		break;
	case 14:
		resp->insertLong(spawnShuttle(inv->getAsciiParameter(_param0_spawnShuttle__string_string_Coordinate_float_float_float_bool_), inv->getAsciiParameter(_param1_spawnShuttle__string_string_Coordinate_float_float_float_bool_), (Coordinate*) inv->getObjectParameter(), inv->getFloatParameter(), inv->getFloatParameter(), inv->getFloatParameter(), inv->getBooleanParameter())->_getORBObjectID());
		break;
	case 15:
		resp->insertLong(spawnRecruiter(inv->getAsciiParameter(_param0_spawnRecruiter__string_string_int_float_float_bool_), inv->getAsciiParameter(_param1_spawnRecruiter__string_string_int_float_float_bool_), inv->getSignedIntParameter(), inv->getFloatParameter(), inv->getFloatParameter(), inv->getBooleanParameter())->_getORBObjectID());
		break;
	case 16:
		resp->insertLong(spawnCreatureGroup(inv->getSignedIntParameter(), inv->getAsciiParameter(_param1_spawnCreatureGroup__int_string_string_int_float_float_int_int_), inv->getAsciiParameter(_param2_spawnCreatureGroup__int_string_string_int_float_float_int_int_), inv->getSignedIntParameter(), inv->getFloatParameter(), inv->getFloatParameter(), inv->getSignedIntParameter(), inv->getSignedIntParameter())->_getORBObjectID());
		break;
	case 17:
		registerFunctions();
		break;
	case 18:
		registerGlobals();
		break;
	case 19:
		loadCreatureFile();
		break;
	case 20:
		resp->insertLong(getCreature(inv->getUnsignedLongParameter())->_getORBObjectID());
		break;
	default:
		return NULL;
	}

	return resp;
}

void CreatureManagerAdapter::init() {
	return ((CreatureManagerImplementation*) impl)->init();
}

void CreatureManagerAdapter::start() {
	return ((CreatureManagerImplementation*) impl)->start();
}

void CreatureManagerAdapter::stop() {
	return ((CreatureManagerImplementation*) impl)->stop();
}

void CreatureManagerAdapter::loadTrainers() {
	return ((CreatureManagerImplementation*) impl)->loadTrainers();
}

void CreatureManagerAdapter::loadRecruiters() {
	return ((CreatureManagerImplementation*) impl)->loadRecruiters();
}

void CreatureManagerAdapter::unloadCreature(Creature* creature) {
	return ((CreatureManagerImplementation*) impl)->unloadCreature(creature);
}

Creature* CreatureManagerAdapter::spawnCreature(const string& stfname, const string& name, int objCrc, float x, float y, int bitmask, bool doLock) {
	return ((CreatureManagerImplementation*) impl)->spawnCreature(stfname, name, objCrc, x, y, bitmask, doLock);
}

TrainerCreature* CreatureManagerAdapter::spawnTrainer(const string& profession, const string& stfname, const string& name, int objCrc, float x, float y, bool doLock) {
	return ((CreatureManagerImplementation*) impl)->spawnTrainer(profession, stfname, name, objCrc, x, y, doLock);
}

ShuttleCreature* CreatureManagerAdapter::spawnShuttle(const string& Planet, const string& City, Coordinate* playerSpawnPoint, float x, float y, float z, bool doLock) {
	return ((CreatureManagerImplementation*) impl)->spawnShuttle(Planet, City, playerSpawnPoint, x, y, z, doLock);
}

RecruiterCreature* CreatureManagerAdapter::spawnRecruiter(const string& stfname, const string& name, int objCrc, float x, float y, bool doLock) {
	return ((CreatureManagerImplementation*) impl)->spawnRecruiter(stfname, name, objCrc, x, y, doLock);
}

CreatureGroup* CreatureManagerAdapter::spawnCreatureGroup(int count, const string& stfname, const string& name, int objCrc, float x, float y, int bitmask, int layout) {
	return ((CreatureManagerImplementation*) impl)->spawnCreatureGroup(count, stfname, name, objCrc, x, y, bitmask, layout);
}

void CreatureManagerAdapter::registerFunctions() {
	return ((CreatureManagerImplementation*) impl)->registerFunctions();
}

void CreatureManagerAdapter::registerGlobals() {
	return ((CreatureManagerImplementation*) impl)->registerGlobals();
}

void CreatureManagerAdapter::loadCreatureFile() {
	return ((CreatureManagerImplementation*) impl)->loadCreatureFile();
}

Creature* CreatureManagerAdapter::getCreature(unsigned long long oid) {
	return ((CreatureManagerImplementation*) impl)->getCreature(oid);
}

/*
 *	CreatureManagerHelper
 */

CreatureManagerHelper CreatureManagerHelper::instance;

CreatureManagerHelper::CreatureManagerHelper() {
	className = "CreatureManager";

	ObjectRequestBroker::instance()->registerClass(className, this);
}

ORBClassHelper* CreatureManagerHelper::getInstance() {
		return &instance;
}

ORBObject* CreatureManagerHelper::instantiateObject() {
	return new CreatureManager();
}

ORBObjectAdapter* CreatureManagerHelper::createAdapter(ORBObjectServant* obj) {
	ORBObjectAdapter* adapter = new CreatureManagerAdapter((CreatureManagerImplementation*)obj);

	ORBObjectStub* stub = new CreatureManager(obj);
	stub->_setORBClassName(className);
	stub->_setClassHelper(this);

	adapter->setStub(stub);

	obj->_setStub(stub);

	return adapter;
}

/*
 *	CreatureManagerServant
 */

CreatureManagerServant::CreatureManagerServant() {
	_classHelper = CreatureManagerHelper::getInstance();
}

CreatureManagerServant::~CreatureManagerServant() {
}

void CreatureManagerServant::_setStub(ORBObjectStub* stub) {
	_this = (CreatureManager*) stub;
}

ORBObjectStub* CreatureManagerServant::_getStub() {
	return _this;
}

