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
 *	server/zone/objects/player/sui/messagebox/SuiMessageBox.cpp generated by Engine3 IDL compiler 0.51
 */

#include "../SuiBox.h"

#include "../../Player.h"

#include "SuiMessageBox.h"

#include "SuiMessageBoxImplementation.h"

/*
 *	SuiMessageBoxStub
 */

SuiMessageBox::SuiMessageBox() : SuiBox(NULL) {
}

SuiMessageBox::SuiMessageBox(ORBObjectServant* obj) : SuiBox(obj) {
}

SuiMessageBox::SuiMessageBox(SuiMessageBox& ref) : SuiBox(ref) {
}

SuiMessageBox::~SuiMessageBox() {
}

SuiMessageBox* SuiMessageBox::clone() {
	return new SuiMessageBox(*this);
}


BaseMessage* SuiMessageBox::generateMessage() {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 6);

		return (BaseMessage*) invocation.executeWithObjectReturn();
	} else
		return ((SuiMessageBoxImplementation*) _impl)->generateMessage();
}

/*
 *	SuiMessageBoxAdapter
 */

SuiMessageBoxAdapter::SuiMessageBoxAdapter(SuiMessageBoxImplementation* obj) : SuiBoxAdapter(obj) {
}

Packet* SuiMessageBoxAdapter::invokeMethod(uint32 methid, ORBMethodInvocation* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		resp->insertLong(generateMessage()->_getORBObjectID());
		break;
	default:
		return NULL;
	}

	return resp;
}

BaseMessage* SuiMessageBoxAdapter::generateMessage() {
	return ((SuiMessageBoxImplementation*) impl)->generateMessage();
}

/*
 *	SuiMessageBoxHelper
 */

SuiMessageBoxHelper SuiMessageBoxHelper::instance;

SuiMessageBoxHelper::SuiMessageBoxHelper() {
	className = "SuiMessageBox";

	ObjectRequestBroker::instance()->registerClass(className, this);
}

ORBClassHelper* SuiMessageBoxHelper::getInstance() {
		return &instance;
}

ORBObject* SuiMessageBoxHelper::instantiateObject() {
	return new SuiMessageBox();
}

ORBObjectAdapter* SuiMessageBoxHelper::createAdapter(ORBObjectServant* obj) {
	ORBObjectAdapter* adapter = new SuiMessageBoxAdapter((SuiMessageBoxImplementation*)obj);

	ORBObjectStub* stub = new SuiMessageBox(obj);
	stub->_setORBClassName(className);
	stub->_setClassHelper(this);

	adapter->setStub(stub);

	obj->_setStub(stub);

	return adapter;
}

/*
 *	SuiMessageBoxServant
 */

SuiMessageBoxServant::SuiMessageBoxServant(Player* play, unsigned int typeID, unsigned int boxtype) : SuiBoxImplementation(play, typeID, boxtype) {
	_classHelper = SuiMessageBoxHelper::getInstance();
}

SuiMessageBoxServant::~SuiMessageBoxServant() {
}

void SuiMessageBoxServant::_setStub(ORBObjectStub* stub) {
	_this = (SuiMessageBox*) stub;
	SuiBoxServant::_setStub(stub);
}

ORBObjectStub* SuiMessageBoxServant::_getStub() {
	return _this;
}

