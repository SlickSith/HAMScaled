/*
 *	server/zone/objects/player/IgnoreList.h generated by engine3 IDL compiler 0.55
 */

#ifndef IGNORELIST_H_
#define IGNORELIST_H_

#include "engine/orb/DistributedObjectBroker.h"

class Player;

class PlayerManager;

class PlayerObject;

class IgnoreList : public DistributedObjectStub {
public:
	IgnoreList(Player* player);

	int getCount();

	int getMagicNumber();

	string& getIgnoreName(const int i);

	string& getIgnoreServer(const int i);

	void addIgnore(string& name, string& inServer);

	void ignoreMagicNumberReset();

	void removeIgnore(string& name);

	void saveIgnore();

	void loadIgnore();

	void toString();

protected:
	IgnoreList(DummyConstructorParameter* param);

	virtual ~IgnoreList();

	string _return_getIgnoreName;
	string _return_getIgnoreServer;

	friend class IgnoreListHelper;
};

class IgnoreListImplementation;

class IgnoreListAdapter : public DistributedObjectAdapter {
public:
	IgnoreListAdapter(IgnoreListImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	int getCount();

	int getMagicNumber();

	string& getIgnoreName(const int i);

	string& getIgnoreServer(const int i);

	void addIgnore(string& name, string& inServer);

	void ignoreMagicNumberReset();

	void removeIgnore(string& name);

	void saveIgnore();

	void loadIgnore();

	void toString();

protected:
	string _param0_addIgnore__string_string_;
	string _param1_addIgnore__string_string_;
	string _param0_removeIgnore__string_;
};

class IgnoreListHelper : public DistributedObjectClassHelper, public Singleton<IgnoreListHelper> {
	static IgnoreListHelper* staticInitializer;

public:
	IgnoreListHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class SingletonWrapper<IgnoreListHelper>;
};

class IgnoreListServant : public DistributedObjectServant {
public:
	IgnoreList* _this;

public:
	IgnoreListServant();
	virtual ~IgnoreListServant();

	void _setStub(DistributedObjectStub* stub);
	DistributedObjectStub* _getStub();

};

#endif /*IGNORELIST_H_*/
