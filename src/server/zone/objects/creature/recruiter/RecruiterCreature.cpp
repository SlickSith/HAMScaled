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
 *	server/zone/objects/creature/recruiter/RecruiterCreature.cpp generated by Engine3 IDL compiler 0.51
 */

#include "../Creature.h"

#include "../../scene/SceneObject.h"

#include "../../player/Player.h"

#include "RecruiterCreature.h"

#include "RecruiterCreatureImplementation.h"

/*
 *	RecruiterCreatureStub
 */

RecruiterCreature::RecruiterCreature() : Creature(NULL) {
}

RecruiterCreature::RecruiterCreature(ORBObjectServant* obj) : Creature(obj) {
}

RecruiterCreature::RecruiterCreature(RecruiterCreature& ref) : Creature(ref) {
}

RecruiterCreature::~RecruiterCreature() {
}

RecruiterCreature* RecruiterCreature::clone() {
	return new RecruiterCreature(*this);
}


void RecruiterCreature::sendConversationStartTo(SceneObject* obj) {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 6);
		invocation.addObjectParameter(obj);

		invocation.executeWithVoidReturn();
	} else
		((RecruiterCreatureImplementation*) _impl)->sendConversationStartTo(obj);
}

void RecruiterCreature::sendFactions(Player* player) {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 7);
		invocation.addObjectParameter(player);

		invocation.executeWithVoidReturn();
	} else
		((RecruiterCreatureImplementation*) _impl)->sendFactions(player);
}

void RecruiterCreature::selectConversationOption(int option, SceneObject* obj) {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 8);
		invocation.addSignedIntParameter(option);
		invocation.addObjectParameter(obj);

		invocation.executeWithVoidReturn();
	} else
		((RecruiterCreatureImplementation*) _impl)->selectConversationOption(option, obj);
}

/*
 *	RecruiterCreatureAdapter
 */

RecruiterCreatureAdapter::RecruiterCreatureAdapter(RecruiterCreatureImplementation* obj) : CreatureAdapter(obj) {
}

Packet* RecruiterCreatureAdapter::invokeMethod(uint32 methid, ORBMethodInvocation* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		sendConversationStartTo((SceneObject*) inv->getObjectParameter());
		break;
	case 7:
		sendFactions((Player*) inv->getObjectParameter());
		break;
	case 8:
		selectConversationOption(inv->getSignedIntParameter(), (SceneObject*) inv->getObjectParameter());
		break;
	default:
		return NULL;
	}

	return resp;
}

void RecruiterCreatureAdapter::sendConversationStartTo(SceneObject* obj) {
	return ((RecruiterCreatureImplementation*) impl)->sendConversationStartTo(obj);
}

void RecruiterCreatureAdapter::sendFactions(Player* player) {
	return ((RecruiterCreatureImplementation*) impl)->sendFactions(player);
}

void RecruiterCreatureAdapter::selectConversationOption(int option, SceneObject* obj) {
	return ((RecruiterCreatureImplementation*) impl)->selectConversationOption(option, obj);
}

/*
 *	RecruiterCreatureHelper
 */

RecruiterCreatureHelper RecruiterCreatureHelper::instance;

RecruiterCreatureHelper::RecruiterCreatureHelper() {
	className = "RecruiterCreature";

	ObjectRequestBroker::instance()->registerClass(className, this);
}

ORBClassHelper* RecruiterCreatureHelper::getInstance() {
		return &instance;
}

ORBObject* RecruiterCreatureHelper::instantiateObject() {
	return new RecruiterCreature();
}

ORBObjectAdapter* RecruiterCreatureHelper::createAdapter(ORBObjectServant* obj) {
	ORBObjectAdapter* adapter = new RecruiterCreatureAdapter((RecruiterCreatureImplementation*)obj);

	ORBObjectStub* stub = new RecruiterCreature(obj);
	stub->_setORBClassName(className);
	stub->_setClassHelper(this);

	adapter->setStub(stub);

	obj->_setStub(stub);

	return adapter;
}

/*
 *	RecruiterCreatureServant
 */

RecruiterCreatureServant::RecruiterCreatureServant(unsigned long long oid) : CreatureImplementation(oid) {
	_classHelper = RecruiterCreatureHelper::getInstance();
}

RecruiterCreatureServant::~RecruiterCreatureServant() {
}

void RecruiterCreatureServant::_setStub(ORBObjectStub* stub) {
	_this = (RecruiterCreature*) stub;
	CreatureServant::_setStub(stub);
}

ORBObjectStub* RecruiterCreatureServant::_getStub() {
	return _this;
}

