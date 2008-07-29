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

#ifndef IGNORELISTIMPLEMENTATION_H_
#define IGNORELISTIMPLEMENTATION_H_

#include "IgnoreList.h" 
#include "Player.h" 
#include "PlayerObject.h" 

#include "../../packets/player/AddIgnoreMessage.h"
#include "../../packets/player/IgnoreListMessage.h"
#include "../../packets/player/PlayerObjectDeltaMessage9.h"

#include "../../Zone.h"
#include "../../ZoneServer.h"

#include "../../objects/terrain/PlanetNames.h"

#include "../../managers/player/PlayerManager.h"

#include "../waypoint/WaypointObject.h"
#include "../../managers/object/ObjectManager.h"

class Player;
class PlayerObject;

class IgnoreListImplementation : public IgnoreListServant {
	Vector<string> ignoreName;
	Vector<string> ignoreServer;
	
	int ignoreMagicNumber;
	Player* player;
	
public:
	IgnoreListImplementation(Player* pl): IgnoreListServant(){		
		player = pl;		
		ignoreMagicNumber = 0;
	}
	~IgnoreListImplementation(){
	}
	
	inline void init(){
	}

	int getCount(){
			return ignoreName.size();
	}
	
	int getMagicNumber(){
		return ignoreMagicNumber;
	}

	string& getIgnoreName(const int i){
		return ignoreName.get(i);
	}
	
	string& getIgnoreServer(const int i){
		return ignoreServer.get(i);
	}
	
	void ignoreMagicNumberReset() {
		ignoreMagicNumber = 0;	
	}
	
	
	void addIgnore(string& name, string& server) {
		PlayerObject* playerObject = player->getPlayerObject();
		int magicnumber;
		String::toLower(name);
		
		for(int i = 0; i < ignoreName.size(); ++i){
			if(ignoreName.get(i) == name){
				stringstream ignoreString;
				ignoreString << "You are already ignoring " << name << ".";
				unicode message = unicode(ignoreString.str());
				player->sendSystemMessage(message);
				return;
			}
		}		
		
		try {
			stringstream query;
			query << "SELECT * from `characters` where lower(`firstname`) = '" << name << "';";
			ResultSet* ignore = ServerDatabase::instance()->executeQuery(query);
		
			if (!ignore->next()) {
				stringstream ignoreString;
				ignoreString << name << " is not a valid name.";
				unicode message = unicode(ignoreString.str());
				player->sendSystemMessage(message);
				
				delete ignore;
				return;
			}
			
		delete ignore;
		
		} catch (DatabaseException& e) {
			cout << "IgnorelistImplementation void addIgnore -> Select DB Query exception! \n";
			return;
		}

		magicnumber = ignoreMagicNumber;	
		
		ignoreName.add(name);
		ignoreServer.add(server);		
		
		ignoreMagicNumber = magicnumber + (ignoreName.size() +1);
		
		//toString();
		
		AddIgnoreMessage* add = new AddIgnoreMessage(player->getObjectID(),	name, server, true);
		player->sendMessage(add);
	    
		Player* playerToAdd = player->getZone()->getZoneServer()->getPlayerManager()->getPlayer(name);
			
		stringstream ignoreString;
		ignoreString << name << " is now ignored.";
		unicode message = unicode(ignoreString.str());
		player->sendSystemMessage(message);
		
		IgnoreListMessage* list = new IgnoreListMessage(player);
        player->sendMessage(list);
		
		PlayerObjectDeltaMessage9* dplay9 = new PlayerObjectDeltaMessage9(playerObject);
		dplay9->updateIgnoreList();
		dplay9->close();
		player->sendMessage(dplay9);
	}
	
	void removeIgnore(string& name) {	
		int i = 0;
		int magicnumber;
		String::toLower(name);	
		
		PlayerObject* playerObject = player->getPlayerObject();
		
		magicnumber = ignoreMagicNumber;
		
		for(int i = 0; i < ignoreName.size(); ++i){
			if(ignoreName.get(i) == name){
				string inServer = ignoreServer.get(i);
				
				ignoreName.remove(i);
				ignoreServer.remove(i);

				ignoreMagicNumber = magicnumber + (ignoreName.size() +1);
						
				//toString();
				
				AddIgnoreMessage* remove = new AddIgnoreMessage(player->getObjectID(),name, inServer, false);
				player->sendMessage(remove);
				
				stringstream ignoreString;
				ignoreString << name << " is no longer ignored.";
				unicode message = unicode(ignoreString.str());
				player->sendSystemMessage(message);
				
				IgnoreListMessage* list = new IgnoreListMessage(player);
				player->sendMessage(list);
				
				PlayerObjectDeltaMessage9* dplay9 = new PlayerObjectDeltaMessage9(playerObject);
				dplay9->updateIgnoreList();
				dplay9->close();
				player->sendMessage(dplay9);
				
				break;
			}
		}
	}	
	
	void toString() {		
		cout << "Ignore List for " << player->getFirstName() << endl;
		cout << "Number of Ignores = " << ignoreName.size() << endl;
		
		for(int i = 0; i < ignoreName.size(); ++i){			
			cout << ignoreName.get(i) << " on " << ignoreServer.get(i) << ". Current magicnumber is " << ignoreMagicNumber << endl;			
		}
	}
	
	void loadIgnore() {
		int magicnumber;		
		
		//Clean before loading! Some server functions (eg. reInserting a player) are using cached objects.
		// We dont want the ignorelist entries get doubled !
		ignoreMagicNumber = 0;
		ignoreName.removeAll();
		ignoreServer.removeAll();		
		
		try {
			stringstream loadQuery;
			
			loadQuery.str("");
			loadQuery << "SELECT * from `ignorelist` where `character_id` = '" << player->getCharacterID() << "';";
			ResultSet* ignore = ServerDatabase::instance()->executeQuery(loadQuery);
			
			while (ignore->next()) {
				magicnumber = ignoreMagicNumber;
				
				string server = ignore->getString(6);
				string name = ignore->getString(4);
				String::toLower(name);
				
				ignoreName.add(name);
				ignoreServer.add(server);

				int newMagicNumber = magicnumber + (ignoreName.size() +1);
				ignoreMagicNumber = newMagicNumber;
		
				//toString();
				
				AddIgnoreMessage* add = new AddIgnoreMessage(player->getObjectID(),	name, server, true);
				player->sendMessage(add);
				
				Player* playerToAdd = player->getZone()->getZoneServer()->getPlayerManager()->getPlayer(name);
				
				IgnoreListMessage* list = new IgnoreListMessage(player);
				player->sendMessage(list);
			
				PlayerObject* playerObject = player->getPlayerObject();		
				PlayerObjectDeltaMessage9* dplay9 = new PlayerObjectDeltaMessage9(playerObject);
				dplay9->updateIgnoreList();
				dplay9->close();
				player->sendMessage(dplay9);
			}
		} catch (DatabaseException& e) {
			cout << "IgnorelistImplementation void loadIgnore -> Select DB Query exception! \n";
		}
	}


	void saveIgnore() {
		int i = 0 ;
		string lcaseName;
		stringstream deleteQuery;
		
		try {		
			deleteQuery.str("");
			deleteQuery << "DELETE FROM ignorelist WHERE character_id = " << player->getCharacterID();
			ServerDatabase::instance()->executeStatement(deleteQuery);			
		} catch (...) {
			cout << "IgnorelistImplementation void saveIgnore -> Delete from Ignorelist Query exception! \n";
		}
		
		
		for(int i = 0; i < ignoreName.size(); ++i){
			try {
				stringstream query;
				string lcaseName = ignoreName.get(i);
				String::toLower(lcaseName);
				
				query.str("");
				query << "SELECT * FROM characters WHERE lower(firstname) = \"" + lcaseName + "\""; 
				ResultSet* ignore = ServerDatabase::instance()->executeQuery(query);
			
				if (ignore->next()) {
					string lcaseIgnore = ignore->getString(3);
					String::toLower(lcaseIgnore);
					
					stringstream saveQuery;
					saveQuery.str("");
					saveQuery << "INSERT INTO `ignorelist` "
					<< "(`character_id`,`firstname`,`surname`,`ignore_id`,`ignore_firstname`,`ignore_surname`,`ignore_galaxy`)"
					<< " VALUES ('"
					<< player->getCharacterID() << "','" << player->getFirstName() << "','"
					<< player->getLastName() << "','" <<  ignore->getUnsignedInt(0) << "','" 
					<< lcaseIgnore << "','" << ignore->getString(4) << "','" 
					<< ignore->getUnsignedInt(2) << "');";

					ServerDatabase::instance()->executeStatement(saveQuery);						
				}			
			} catch (...) {
					cout << "IgnorelistImplementation void saveIgnores -> Insert DB Query exception! \n";
			}
		}
	}

};
#endif /*IGNORELISTIMPLEMENTATION_H_*/
