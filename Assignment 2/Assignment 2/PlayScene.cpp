#include "PlayScene.h"
#include <iostream>
#include "Game.h"
#include <Windows.h>

#define NUMLONGSEC 500

using namespace std;

//Names of the rooms
//0. Living Room
//1. Kitchen
//2. First Floor Washroom
//3. Work Room
//4. Hallway
//5. Bedroom
//6. Storage Room
//7. Basement
//8. Second Floor Washroom
string nameshere[] = { "Living Room" , "Kitchen", "First Floor Washroom", "Work Room", "Hallway", "Bedroom", "Storage Room", "Basement", "Second Floor Washroom"};

//Objectives in game
//0. Get the Key.
//1. Find SAFE code.
//2. Find where this password has to go.
//3. Use type CATTHEYISHERE into the computer
//4. Look around the house for cups. The colour of the cups are the code for the safe in the bedroom up stairs.
//5. Find the password for the computer.
//6. Look for missing SECOND_FLOOR_BATHROOM item.
//7. Look for missing FIRST_FLOOR_BATHROOM item.
//8. Use KEY on the BASEMENT
//
string objectives[] = { "Get the Key.", "Find SAFE code.", "Find where this password has to go.", "Use type CATTHEYISHERE into the computer",
		"Look around the house for cups. The colour of the cups are the code for the safe in the bedroom up stairs.",
		"Find the password for the computer.","Look for missing SECOND_FLOOR_BATHROOM item.", "Look for missing FIRST_FLOOR_BATHROOM item.",
		"Use KEY on the BASEMENT"};

string directionName[] = { "N","E" ,"S","W" };

PlayScene::PlayScene(bool newGame)
{
	//taking all user data from past save inputing it onto items
	roomName = Game::Instance()->getPlayer()->getRoomName();

	ifstream openFile("gameText.txt");
	string getItems;

	while (getItems != roomName) { getline(openFile, getItems); }
	while (getItems != "ITEMS") { getline(openFile, getItems); }
		
	while (getItems != "END")
	{
		getline(openFile, getItems);
		if (getItems != "END") { interactableItems.push_back(getItems); }
	}
	openFile.close();

	direction =  Game::Instance()->getPlayer()->getDirection();

	seenComputer = Game::Instance()->getPlayer()->getSeenCom();
	seenPassword = Game::Instance()->getPlayer()->getSeenPassword();
	gotCode = Game::Instance()->getPlayer()->getgotCode();
	gotCrank = Game::Instance()->getPlayer()->getGotCrank(); 
	secondwindow = Game::Instance()->getPlayer()->getSecondWindow(); 
	firstwindow = Game::Instance()->getPlayer()->getFirstWindow();
	opensafe = Game::Instance()->getPlayer()->getOpenSafe(); 
	gotKey = Game::Instance()->getPlayer()->getGotKey();
	doorIsOpen = Game::Instance()->getPlayer()->getDoorIsOpen();  
	endingStart = Game::Instance()->getPlayer()->getEndingStart();  
	outOfBasement = Game::Instance()->getPlayer()->getOutOfBasement();  
	lockedagain = Game::Instance()->getPlayer()->getLockedAgain();
	bossRoom = Game::Instance()->getPlayer()->getBossRoom();

	enemy = Game::Instance()->getPlayer()->getEnemy();
	follow = Game::Instance()->getPlayer()->getFollow();
	items = Game::Instance()->getPlayer()->getItems();
	if (gotKey)
		red = yellow = purple = black = white = green = true;
}

void PlayScene::output()
{

	gameText.open("gameText.txt");

	string getText;

	if (roomName == nameshere[7])
	{
		//checks if responce was outputed
		if (!textOnce)
		{
			while (getText != roomName) { getline(gameText, getText); }
			txtOutput();
			textOnce = true;
		}
		else
		{
			if (enemy.top() != "Boss Fell down") { enemy.pop(); }
		}

		//outputs enemy's attack
		for (int i = 0; i < enemy.top().size(); i++)
		{
			cout << enemy.top()[i];
			Sleep(15);
		}
		
		//checks if the boss fell down and outputs a response
		if (enemy.top() != "Boss Fell down") { enemy.pop(); }
		else
		{
			enemy.pop();
			cout << endl << endl;
			string getOut = "Quickly. Run up stairs. NOW!\n It'll get up as soon as you make one mistake right now.\n Use the WALKTO LIVINGROOM.";
			for (int i = 0; i < getOut.size(); i++)
			{
				cout << getOut[i];
				Sleep(15);
			}
		}
		cout << endl << endl;

	}
	else
	{
		//if the player is being followed then appropriate output would come out
		if(follow.empty()) { cout << "\n" << roomName << endl << endl; }
		else { cout << "\n" << roomName << "					You can make: " <<  follow.size() << "    The boss is in room: " <<bossRoom<< endl << endl; }

		//shoews compass at the side
		cout << "       " << directionName[direction] << "\n       T\n       |\n";
		cout << directionName[(((direction - 1) % 4) < 0) ? 3 : ((direction - 1) % 4)] << " <----+----> " << directionName[(1 + direction) % 4] << "\n       |\n       v\n";
		cout << "       " << directionName[(2 + direction) % 4] << endl;

		//finds room name in text
		while (getText != roomName) { getline(gameText, getText); }

		//finds direction player is facing in text
		while (getText != directionName[direction]) { getline(gameText, getText); }

		//out puts response
		txtOutput();
	}
	
	gameText.close();

}

void PlayScene::update()
{
	if (outOfBasement)
	{
		//saves the room the boss is currently in.
		bossRoom = follow.front();
		//removes the front of the queue for the next update
		follow.pop();
	}

	//incases where there are two meanings to code such as useing GOTO for WALKTO. GOTO will be changed to WALKTO 
	if (endingStart && finalGame != "FIGHT") { finalGame = "FIGHT"; }
	if (roomName == nameshere[7] && action == "STAIRS") { action = "LIVINGROOM"; }
	if (action == "STAIRS") { action = "HALLWAY"; }
	if (action == "SECOND_FLOOR_WASHROOM") { action = "SECOND_FLOOR_BATHROOM"; }
	if (action == "FIRST_FLOOR_WASHROOM") { action = "FIRST_FLOOR_WASHROOM"; }
	if (type == "GOTO") { type = "WALKTO"; }

	if (!enemy.empty())
	{
		//For the boss fight. the User would be able to the DODGE command to DODGE attacks. Use wrong input then you die.
		if (type == "DODGE")
		{
			if (enemy.top() == "RIGHT")
			{
				if (action != "LEFT") { Game::Instance()->changeSceneState(DEATH_SCENE_VER2); }
			}
			else if (enemy.top() == "LEFT")
			{
				if (action != "RIGHT") { Game::Instance()->changeSceneState(DEATH_SCENE_VER2); }
			}
			else if (enemy.top() == "UP")
			{
				if (action != "DOWN") { Game::Instance()->changeSceneState(DEATH_SCENE_VER2); }
			}
			else if (enemy.top() == "DOWN")
			{
				if (action != "UP") { Game::Instance()->changeSceneState(DEATH_SCENE_VER2); }
			}
		}
		else { Game::Instance()->changeSceneState(DEATH_SCENE_VER2); }
		
	}
	else
	{
		//if you are not in the boss fight you can use the following actions.
		if (type == "TURN")
		{
			//turns the player right or left
			gameText.open("gameText.txt");

			string getText;
			while (getText != type) { getline(gameText, getText); }

			if (action == "RIGHT") { direction = ++direction % 4; }
			else if (action == "LEFT") { direction = (((direction - 1) % 4) < 0) ? 3 : ((--direction) % 4); }
			else
			{
				//outputs code if it didn't know what the player was doing
				txtOutput();
				cout << endl << endl;
				system("pause");
			}
			gameText.close();

		}
		else if (type == "USE")
		{
			//allows the player to use Items together
			gameText.open("gameText.txt");

			string getText;
			//finds type in text
			while (getText != type) { getline(gameText, getText); }

			//checks if item is interactable
			if (interactableItems.searchItem(action))
			{
				//checks if player is in right room
				if (roomName == nameshere[0] || roomName == nameshere[1] || roomName == nameshere[2] || roomName == nameshere[8])
				{
					//finds which room the player is in
					if (roomName == nameshere[0])
					{
						//outputs code depening on action
						if (action == "KEY_ON_BASEMENT")
						{
							//finds action in text
							while (getText != action) { getline(gameText, getText); }
							//finds version in text
							while (getText != to_string(gotKey + outOfBasement + lockedagain)) { getline(gameText, getText); }

							//checks if player has the key
							if (gotKey) 
							{ 
								//checks if objective exists and removes it
								doorIsOpen = true;
								bool check = false;
								for (list<string>::iterator i = items.begin(); i != items.end(); i++)
								{
									if (*i == objectives[8]) { check = true; }
								}
								if (check) { items.remove(objectives[8]); }
							}

							//checks if player is running away from the boss and is trying to lock the basement door
							if (outOfBasement && !lockedagain && bossRoom == nameshere[7])
							{
								lockedagain = true;
								
								//add 4 more items to the follow list
								queue<string> getItemsthere;
								follow.swap(getItemsthere);
								for (int i = 0; i < 4; i++) { follow.push(nameshere[7]); }
								while (!getItemsthere.empty())
								{
									follow.push(getItemsthere.front());
									getItemsthere.pop();
								}
							}

						}
						else if (action == "BROKEN_TV_ON_WINDOW") 
						{ 
							if (outOfBasement)
							{
								while (getText != "RUNAWAY") { getline(gameText, getText); }
							}
							while (getText != action) { getline(gameText, getText); }
							if (outOfBasement) { Game::Instance()->changeSceneState(ESCAPE_SCENE_VER1); } 
						}
						
					}
					else if (roomName == nameshere[1])
					{
						//outputs code depening on action
						if (action == "CHAIR_ON_WINDOW")
						{
							if (outOfBasement)
							{
								while (getText != "RUNAWAY") { getline(gameText, getText); }
							}
							while (getText != action) { getline(gameText, getText); }
							if (outOfBasement) { Game::Instance()->changeSceneState(ESCAPE_SCENE_VER1); }
						}
					}
					else if (roomName == nameshere[2])
					{
						//outputs code depening on action
						if (action == "CRANK_ON_WINDOW") 
						{
							if (outOfBasement) { Game::Instance()->changeSceneState(ESCAPE_SCENE_VER2); }
							else 
							{ 
								while (getText != "0") { getline(gameText, getText); }
								Game::Instance()->changeSceneState(ESCAPE_SCENE_VER3); 
							}
						}
					}
					else if (roomName == nameshere[8])
					{
						//outputs code depening on action
						if (action == "CRANK_ON_WINDOW") 
						{
							while (getText != "0") { getline(gameText, getText); }
							Game::Instance()->changeSceneState(DEATH_SCENE_VER1); 
						}
					}
				}
			}

			//for output
			txtOutput();
			gameText.close();
			cout << endl << endl;
			system("pause");
		}
		else if (type == "SEE")
		{
			//checks which type of action and outputs a responce or no responce
			if (action == "TODO")
			{
				cout << endl << endl;

				for (list<string>::iterator i = items.begin(); i != items.end(); i++) { cout << *i << endl; }
			}
			else if (action == "SAVE") 
			{ 
				cout << "\nSaved";
				Game::Instance()->getPlayer()->save();
			}
			
			cout << endl << endl;
			system("pause");
		}
		else if (type == "GET")
		{
			cout << endl << endl;

			//checks if item exists
			if (interactableItems.searchItem(action))
			{
				//checks which item it is
				if (action == "KEY")
				{
					//checks which room player is in and output a response
					if (roomName == nameshere[5])
					{
						//checks if player has got the code and output a response
						if (gotCode)
						{
							//checks if player has opened the safe and output a response
							if (opensafe)
							{
								//checks if player has the key and output a response
								if (gotKey)
								{
									string word = "You already have the KEY.";

									for (int i = 0; i < word.size(); i++)
									{
										cout << word[i];
										Sleep(15);
									}
								}
								else
								{
									gotKey = true;

									string word = "KEY aquired.";

									bool ifFound = false;
									for (list<string>::iterator i = items.begin(); i != items.end(); i++)
									{
										if (*i == objectives[0]) { ifFound = true; }
									}
									if (ifFound) { items.remove(objectives[0]); }
									items.push_back(objectives[8]);
									for (int i = 0; i < word.size(); i++)
									{
									//	cout << word[i];
										Sleep(15);
									}
								}
							}
							else
							{
								string word = "The SAFE is still closed.";
								bool check = false;

								for (list<string>::iterator i = items.begin(); i != items.end(); i++) 
								{
									if (*i == objectives[1]) { check = true; }
								}
								if (!check){ items.push_back(objectives[1]); }
								
								for (int i = 0; i < word.size(); i++)
								{
									cout << word[i];
									Sleep(15);
								}

							}
						}
						else
						{
							string word = "What Key?";

							for (int i = 0; i < word.size(); i++)
							{
								cout << word[i];
								Sleep(15);
							}
						}
					}

				}
				else if (action == "CRANK")
				{
					//checks witch room player is in
					if (roomName == nameshere[6])
					{
						//checks if player has crank and output a response
						if (gotCrank)
						{
							
							string word = "We already have the CRANK.";
							for (int i = 0; i < word.size(); i++)
							{
								cout << word[i];
								Sleep(15);
							}
						}
						else
						{
							
							string word = "Got CRANK.";
							for (int i = 0; i < word.size(); i++)
							{
								cout << word[i];
								Sleep(15);
							}
							gotCrank = true;
						}
					}
				}
				else
				{
					//outputs 
					string word = "Not a gettable item.";

					for (int i = 0; i < word.size(); i++)
					{
						cout << word[i];
						Sleep(15);
					}

				}
			}
			else
			{
				//outputs 
				string word = "That is not here";

				for (int i = 0; i < word.size(); i++)
				{
					cout << word[i];
					Sleep(15);
				}

			}
			cout << endl << endl;
			system("pause");

		}
		else if (type == "WALKTO" || type == "WALK_TO")
		{
			
			gameText.open("gameText.txt");
			string getText;
			bool passIf = false;

			//finds type in text
			while (getText != type) { getline(gameText, getText); }

			//checks if the action exists
			if (interactableItems.searchItem(action))
			{
				//checks if it is a room
				if (action == "LIVINGROOM" || action == "KITCHEN" || action == "FIRST_FLOOR_BATHROOM" || action == "WORKROOM" || action == "HALLWAY" || action == "BEDROOM" || action == "STORAGEROOM" || action == "BASEMENT" || action == "SECOND_FLOOR_BATHROOM")
				{
					cout << "\n\n";
					//finds which room player is going to and sets the room and direction player is facing depending on which room they were in
					if (action == "LIVINGROOM")
					{
						if (roomName == nameshere[7]) { outOfBasement = true; }
						
						if (roomName == nameshere[3] || roomName == nameshere[7]) { direction = 3; }
						else { direction = 2; }
						roomName = nameshere[0];

					}
					else if (action == "KITCHEN")
					{
						if (roomName == nameshere[0]) { direction = 0; }
						else { direction = 3; }
						roomName = nameshere[1];
					}
					else if (action == "FIRST_FLOOR_BATHROOM")
					{
						if (roomName == nameshere[0]) { direction = 0; }
						else if (roomName == nameshere[1]) { direction = 1; }
						else { direction = 3; }
						roomName = nameshere[2];
					}
					else if (action == "WORKROOM")
					{
						roomName = nameshere[3];
						direction = 1;
					}
					else if (action == "HALLWAY")
					{
						if (roomName == nameshere[5]) { direction = 1; }
						else if (roomName == nameshere[8]) { direction = 2; }
						else { direction = 0; }
						roomName = nameshere[4];
					}
					else if (action == "BEDROOM")
					{
						roomName = nameshere[5];
						direction = 3;
					}
					else if (action == "STORAGEROOM")
					{
						roomName = nameshere[6];
						direction = 2;
					}
					else if (action == "BASEMENT")
					{
						if (doorIsOpen)
						{
							if (!endingStart)
							{
								roomName = nameshere[7];
								direction = 2;
								endingStart = true;
								bossFight();
							}
							else
							{
								string word = "What are you doing?\n Don't go back down there.";

								for (int i = 0; i < word.size(); i++)
								{
									cout << word[i];
									Sleep(15);
								}
							}
						}
						else
						{
							string word = "The door is locked.";

							for (int i = 0; i < word.size(); i++)
							{
								cout << word[i];
								Sleep(15);
							}
							cout << endl << endl;
							system("pause");
						}
					}
					else if (action == "SECOND_FLOOR_BATHROOM")
					{
						roomName = nameshere[8];
						direction = 0;
					}

					//clears vector
					interactableItems.clear();

					//finds room in text
					while (getText != roomName) { getline(gameText, getText); }
					//finds ITEMS in text
					while (getText != "ITEMS") { getline(gameText, getText); }

					//adds items to the interactable items list until text reads END
					while (getText != "END")
					{
						getline(gameText, getText);
						if (getText != "END") { interactableItems.push_back(getText); }
					}


				}
				else
				{
					passIf = true;

					//find version
					while (getText != to_string(passIf)) { getline(gameText, getText); }
					
					//outputs text
					txtOutput();
					system("pause");
				}

			}
			else
			{
				//find version
				while (getText != to_string(passIf)) { getline(gameText, getText); }

				//outputs text
				txtOutput();
				system("pause");
			}

			//checks if player is out of the basement and running away from boss
			if (outOfBasement) 
			{ 
				//adds current location of player to boss
				follow.push(roomName); 
				//if true then monster would become quicker
				if(counter++ > 3)
				{
					if (follow.size() > 1) { follow.pop(); }
				}
			}
			gameText.close();
			cout << endl << endl;

		}
		else if (type == "PRESS")
		{

			gameText.open("gameText.txt");

			string getText;

			//moves file depening of if they are running away from a boss
			while (getText != finalGame) { getline(gameText, getText); }

			//code will activate if player is running away from boss
			if (!endingStart)
			{

				//check if player is in right room
				if (roomName == nameshere[5])
				{
					//finds OPEN in text files
					while (getText != "OPEN") { getline(gameText, getText); }

					//finds text if certain buttons were pressed
					if (action == "RED" || action == "BLACK" || action == "YELLOW" || action == "WHITE" || action == "PURPLE" || action == "GREEN")
						while (getText != "2") { getline(gameText, getText); }
					
					//checks witch buttons were pressed
					if (action == "RED") { red = true; }
					else if (action == "BLACK") { black = true; }
					else if (action == "YELLOW") { yellow = true; }
					else if (action == "WHITE") { white = true; }
					else if (action == "PURPLE") { purple = true; }
					else if (action == "GREEN") { green = true; }
					else if (action == "BLUE" || action == "ORANGE" || action == "INDIGO")
					{
						while (getText != "0") { getline(gameText, getText); }
						red = yellow = purple = black = white = green = false;
					}

					bool check = false;
					//checks if objectives exist and added them if it doesn't
					for (list<string>::iterator i = items.begin(); i != items.end(); i++) 
					{ 
						if (*i == objectives[1]) { check = true; }
					}
					if (!check) { items.push_back(objectives[1]); }
					
					//if following buttons were pressed then code would activate
					if (red && yellow && purple && black && white && green)
					{
						//finds version of text
						while (getText != "1") { getline(gameText, getText); }

						gotCode = true;
						bool check1 = false, check2 = false, check3 = false, check4 = false, check5 = false;

						//checks if certain objectives exist and removes them
						for (list<string>::iterator i = items.begin(); i != items.end(); i++)
						{
							if (*i == objectives[5]) { check1 = true; }
							if (*i == objectives[3]) { check2 = true; }
							if (*i == objectives[2]) { check3 = true; }
							if (*i == objectives[4]) { check4 = true; }
							if (*i == objectives[1]) { check5 = true; }

						}
						if (check1) { items.remove(objectives[5]); }
						if (check2) { items.remove(objectives[3]); }
						if (check3) { items.remove(objectives[2]); }
						if (check4) { items.remove(objectives[4]); }
						if (check5) { items.remove(objectives[1]); }
						items.push_back(objectives[0]);
						opensafe = true;
					}

				}
			}

			//outputs text
			txtOutput();
			gameText.close();
			cout << endl << endl;
			system("pause");
		}
		else if (type == "TYPE")
		{

			gameText.open("gameText.txt");

			string getText;

			//if player is in the final part of the game it would move text file output to either end of the file or stays at the top
			while (getText != finalGame) { getline(gameText, getText); }

			//will move text file output to where the first command is call. In this case it would look for TYPE in the file
			while (getText != type) { getline(gameText, getText); }

			//Code will not activate if the player is running away from the boss
			if (!endingStart)
			{
				//checks if you you are in work room
				if (roomName == nameshere[3])
				{

					if (!seenComputer) { seenComputer = true; }

					//finds room name in text
					while (getText != roomName) { getline(gameText, getText); }
					//finds type in text
					while (getText != type) { getline(gameText, getText); }

					//checks if it is the password
					if (action == "CATTHEYISHERE")
					{
						//finds action in text
						while (getText != action) { getline(gameText, getText); }
						//finds witch version in text
						while (getText != to_string(gotCode)) { getline(gameText, getText); }

						//adds objective to list
						if (!gotCode) { items.push_back("Look around the house for cups. The colour of the cups are the code for the safe in the bedroom up stairs."); }
						
						gotCode = true;
						bool check1 = false, check2 = false, check3 = false;

						//checks if certain objective exists and removes them.
						for (list<string>::iterator i = items.begin(); i != items.end(); i++)
						{
							if (*i == objectives[5]) { check1 = true; }
							if (*i == objectives[3]) { check2 = true; }
							if (*i == objectives[2]) { check3 = true; }
						}
						if (check1) { items.remove(objectives[5]); }
						if (check2) { items.remove(objectives[3]); }
						if (check3) { items.remove(objectives[2]); }
					}
					else
					{
						bool ifFound = false;

						//checks if certain objective exists and doesn't add it.
						for (list<string>::iterator i = items.begin(); i != items.end(); i++)
						{
							if (*i == objectives[5]) { ifFound = true; }
						}

						if (!ifFound) { items.push_back(objectives[5]); }
						//finds else in text
						while (getText != "ELSE") { getline(gameText, getText); }

					}

				}
			}

			//outputs text
			txtOutput();
			gameText.close();
			cout << endl << endl;
			system("pause");
		}
		else if (type == "LOOK_AT" || type == "LOOKAT")
		{
			//opening game text
			gameText.open("gameText.txt");

			string getText;

			//if player is in the final part of the game it would move text file output to either end of the file or stays at the top
			while (getText != finalGame) { getline(gameText, getText); }

			//will move text file output to where the first command is call. In this case it would look for LOOKAT in the file
			while (getText != type) { getline(gameText, getText); }

			//Code will not activate if the player is running away from the boss
			if (!endingStart)
			{

				//checks if you can interact with the items or action.
				if (interactableItems.searchItem(action))
				{
					//finds room name in text
					while (getText != roomName) { getline(gameText, getText); }
					//finds type in text
					while (getText != type) { getline(gameText, getText); }
					//finds action in text
					while (getText != action) { getline(gameText, getText); }

					//if some actions have more then 1 text
					if (action == "COMPUTER")
					{
						//finds the text using numbers
						while (getText != to_string((seenPassword * seenComputer) + gotCode + seenPassword)) { getline(gameText, getText); }
						
						//adds new objectives to list
						if (((seenPassword * seenComputer) + gotCode + seenPassword) == 0) { items.push_back(objectives[5]); }
						else if (((seenPassword * seenComputer) + gotCode + seenPassword) == 1)
						{
							bool ifFound = false;
							for (list<string>::iterator i = items.begin(); i != items.end(); i++)
							{
								if (*i == objectives[5]) { ifFound = true; }
							}
							items.push_back(objectives[3]);
						}
						
						seenComputer = true;
					}
					else if (action == "PHOTO")
					{
						//finds the text using numbers
						while (getText != to_string(seenComputer + gotCode + (seenPassword * seenComputer))) { getline(gameText, getText); }

						//adds new objectives to list
						if ((seenComputer + gotCode + (seenPassword * seenComputer)) == 0)
						{
							bool ifFound = false;
							for (list<string>::iterator i = items.begin(); i != items.end(); i++)
							{
								if (*i == objectives[2]) { ifFound = true; }
							}
							items.push_back(objectives[2]);
						}
						else if ((seenComputer + gotCode + (seenPassword * seenComputer)) == 1)
						{
							bool ifFound = false;
							for (list<string>::iterator i = items.begin(); i != items.end(); i++)
							{
								if (*i == objectives[5]) { ifFound = true; }
							}
							if (ifFound) { items.remove(objectives[5]); }
							items.push_back(objectives[3]);

						}
						seenPassword = true;

					}
					else if (action == "WINDOW")
					{
						//checks which room you are in
						if (roomName == nameshere[8])
						{
							//adds new objectives
							if (!secondwindow) { items.push_back(objectives[6]); }
							secondwindow = true;
						}
						if (roomName == nameshere[2])
						{
							if (!firstwindow) { items.push_back(objectives[7]); }
							firstwindow = true;
						}

					}
					else if (action == "SAFE")
					{
						//adds new objectives to list
						if ((gotCode + gotKey + opensafe) == 0)
						{
							bool check1 = false;
							for (list<string>::iterator i = items.begin(); i != items.end(); i++)
							{
								if (*i == objectives[1]) { check1 = true; }
							}
							if (!check1) { items.push_back(objectives[1]); }
						}

						//finds the text using numbers
						while (getText != to_string(gotCode + gotKey + opensafe)) { getline(gameText, getText); }

					}
					else if (action == "KEY")
					{
						//finds the text using numbers
						if (gotCode)
						{
							while (getText != to_string(gotKey + opensafe)) { getline(gameText, getText); }
						}
					}

				}
			}

			//for output
			txtOutput();
			gameText.close();
			cout << endl << endl;
			system("pause");
		}
		else
		{
			
			//outputs text if the command doesn't exists
			string word = "\"What was I supposed to do?\"";

			for (int i = 0; i < word.size(); i++)
			{
				cout << word[i];
				Sleep(15);
			}
			cout << endl << endl;
			system("pause");
		}
		//if boss is in the same room as player it will lead to an instance game over
		if (outOfBasement && bossRoom == roomName) { Game::Instance()->changeSceneState(DEATH_SCENE_VER3); }
	}
	//if the player is still in the basement when the game tells you to leave it will lead to an instance game over
	if (enemy.empty() && roomName == nameshere[7]) { Game::Instance()->changeSceneState(DEATH_SCENE_VER3); }
	autoSave();
}

void PlayScene::input()
{

	cin >> type >> action;

	//To capitalize all letters int type and action 
	for (int i = 0; i < type.size(); i++)
	{
		if (isalpha(type[i]))
		{
			type[i] = toupper(type[i]);

		}
	}
	for (int i = 0; i < action.size(); i++)
	{
		if (isalpha(action[i]))
		{
			action[i] = toupper(action[i]);

		}
	}
	
}


void PlayScene::txtOutput()
{
	string text;
	while (text != "END")
	{
		getline(gameText, text);
		if (text != "-")
		{
			if (text != "END")
			{
				for (int i = 0; i < text.size(); i++)
				{
					cout << text[i];
					Sleep(15);
				}
			}

		}
		else
		{
			Sleep(NUMLONGSEC);
		}
		cout << endl;
	}
}


void PlayScene::bossFight()
{

	enemy.push("Boss Fell down");
	enemy.push("LEFT");
	enemy.push("Boss's Claws are coming into the LEFT");
	enemy.push("LEFT");
	enemy.push("Boss's Claws are coming into the LEFT");
	enemy.push("RIGHT");
	enemy.push("Boss's Claws are coming into the RIGHT");
	enemy.push("UP");
	enemy.push("The boss is about to pounce");
	enemy.push("DOWN");
	enemy.push("The boss is going for your legs");
	enemy.push("UP");
	enemy.push("The boss is about to pounce");
	enemy.push("UP");
	enemy.push("The boss is about to pounce");
	enemy.push("RIGHT");
	enemy.push("Boss's Claws are coming into the RIGHT");
	enemy.push("LEFT");
	enemy.push("Boss's Claws are coming into the LEFT");
	enemy.push("RIGHT");
	enemy.push("Boss's Claws are coming into the RIGHT");
	enemy.push("RIGHT");
	enemy.push("Boss's Claws are coming into the RIGHT");
	enemy.push("DOWN");
	enemy.push("The boss is going for your legs");
	enemy.push("UP");
	enemy.push("The boss is about to pounce");
	
	follow.push(nameshere[7]);
	follow.push(nameshere[7]);
	follow.push(nameshere[7]);
	follow.push(nameshere[7]);
	follow.push(nameshere[7]);

}


void PlayScene::autoSave()
{
	
	Game::Instance()->getPlayer()->setDirection(direction);
	Game::Instance()->getPlayer()->setBossRoom(bossRoom);
	Game::Instance()->getPlayer()->setDoorIsOpen(doorIsOpen);
	Game::Instance()->getPlayer()->setEndingStart(endingStart);
	Game::Instance()->getPlayer()->setEnemy(enemy);
	Game::Instance()->getPlayer()->setFirstWindow(firstwindow);
	Game::Instance()->getPlayer()->setFollow(follow);
	Game::Instance()->getPlayer()->setgotCode(gotCode);
	Game::Instance()->getPlayer()->setGotCrank(gotCrank);
	Game::Instance()->getPlayer()->setGotKey(gotKey);
	Game::Instance()->getPlayer()->setItems(items);
	Game::Instance()->getPlayer()->setLockedAgain(lockedagain);
	Game::Instance()->getPlayer()->setOpenSafe(opensafe);
	Game::Instance()->getPlayer()->setOutOfBasement(outOfBasement);
	Game::Instance()->getPlayer()->setRoomName(roomName);
	Game::Instance()->getPlayer()->setSecondWindow(secondwindow);
	Game::Instance()->getPlayer()->setSeenCom(seenComputer);
	Game::Instance()->getPlayer()->setSeenPassword(seenPassword);
	Game::Instance()->getPlayer()->setTextOnce(textOnce);
}
