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

	direction = Game::Instance()->getPlayer()->getDirection();

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

		for (int i = 0; i < enemy.top().size(); i++)
		{
			cout << enemy.top()[i];
			Sleep(15);
		}
		
		if (enemy.top() != "Boss Fell down") { enemy.pop(); }
		else
		{
			enemy.pop();
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
		if(follow.empty()) { cout << "\n" << roomName << endl << endl; }
		else { cout << "\n" << roomName << "					" <<  follow.size() << endl << endl; }

		cout << "       " << directionName[direction] << "\n       T\n       |\n";
		cout << directionName[(((direction - 1) % 4) < 0) ? 3 : ((direction - 1) % 4)] << " <----+----> " << directionName[(1 + direction) % 4] << "\n       |\n       v\n";
		cout << "       " << directionName[(2 + direction) % 4] << endl;

		while (getText != roomName) { getline(gameText, getText); }
		while (getText != directionName[direction]) { getline(gameText, getText); }
		txtOutput();
	}
	
	gameText.close();

}

void PlayScene::update()
{
	if (outOfBasement)
	{
		bossRoom = follow.front();
		follow.pop();
	}
	//if (roomName != nameshere[7] && follow.size() > 1) { follow.pop(); }
	if (endingStart && finalGame != "FIGHT") { finalGame = "FIGHT"; }
	if (roomName == nameshere[7] && action == "STAIRS") { action = "LIVINGROOM"; }
	if (action == "STAIRS") { action = "HALLWAY"; }
	if (action == "SECOND_FLOOR_WASHROOM") { action = "SECOND_FLOOR_BATHROOM"; }
	if (type == "GOTO") { type = "WALKTO"; }

	if (!enemy.empty())
	{
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
		if (type == "TURN")
		{
			//cout << "int";
			gameText.open("gameText.txt");

			string getText;
			while (getText != type) { getline(gameText, getText); }
			//cout << "int";

			if (action == "RIGHT") { direction = ++direction % 4; }
			else if (action == "LEFT") { direction = (((direction - 1) % 4) < 0) ? 3 : ((--direction) % 4); }
			else
			{
				txtOutput();
				cout << endl << endl;
				system("pause");
			}
			gameText.close();
		}
		else if (type == "USE")
		{
			gameText.open("gameText.txt");

			string getText;

			while (getText != type) { getline(gameText, getText); }

			if (interactableItems.searchItem(action))
			{
				if (roomName == nameshere[0] || roomName == nameshere[1] || roomName == nameshere[2] || roomName == nameshere[8])
				{
					if (roomName == nameshere[0])
					{
						if (action == "KEY_ON_BASEMENT")
						{
							while (getText != action) { getline(gameText, getText); }
							while (getText != to_string(gotKey + outOfBasement + lockedagain)) { getline(gameText, getText); }
							if (gotKey) 
							{ 
								doorIsOpen = true;
								bool check = false;

								for (list<string>::iterator i = items.begin(); i != items.end(); i++)
								{
									if (*i == objectives[8]) { check = true; }
								}
								if (check) { items.remove(objectives[8]); }
							}
							if (outOfBasement && !lockedagain && bossRoom == nameshere[7])
							{
								lockedagain = true;
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
						if (action == "CRANK_ON_WINDOW") 
						{
							if (outOfBasement) { Game::Instance()->changeSceneState(ESCAPE_SCENE_VER2); }
							else { Game::Instance()->changeSceneState(ESCAPE_SCENE_VER3); }
						}
					}
					else if (roomName == nameshere[8])
					{
						if (action == "CRANK_ON_WINDOW") { Game::Instance()->changeSceneState(DEATH_SCENE_VER1); }
					}
				}
			}

			txtOutput();
			gameText.close();
			cout << endl << endl;
			system("pause");
		}
		else if (type == "SEE")
		{
			if (action == "TODO")
			{
				cout << endl << endl;

				for (list<string>::iterator i = items.begin(); i != items.end(); i++) { cout << *i << endl; }
			}
			else if (action == "SAVE") { Game::Instance()->getPlayer()->save(); }
			
			cout << endl << endl;
			system("pause");
		}
		else if (type == "GET")
		{
			cout << endl << endl;
			if (interactableItems.searchItem(action))
			{
				if (action == "KEY")
				{
					if (roomName == nameshere[5])
					{
						if (gotCode)
						{
							if (opensafe)
							{
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
										cout << word[i];
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

					if (roomName == nameshere[6])
					{
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

			while (getText != type) { getline(gameText, getText); }

			if (interactableItems.searchItem(action))
			{
				if (action == "LIVINGROOM" || action == "KITCHEN" || action == "FIRST_FLOOR_BATHROOM" || action == "WORKROOM" || action == "HALLWAY" || action == "BEDROOM" || action == "STORAGEROOM" || action == "BASEMENT" || action == "SECOND_FLOOR_BATHROOM")
				{
					cout << "\n\n";
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

					interactableItems.clear();

					while (getText != roomName) { getline(gameText, getText); }
					//cout << "here";
					while (getText != "ITEMS") { getline(gameText, getText); }
					//cout << "here";
					while (getText != "END")
					{
						getline(gameText, getText);
						if (getText != "END") { interactableItems.push_back(getText); }
						cout << getText << "    ";
					}


				}
				else
				{
					passIf = true;
					while (getText != to_string(passIf)) { getline(gameText, getText); }

					txtOutput();
					system("pause");
				}

			}
			else
			{
				while (getText != to_string(passIf)) { getline(gameText, getText); }
				txtOutput();
				system("pause");
			}
			if (outOfBasement) { follow.push(roomName); }
			gameText.close();
			cout << endl << endl;

		}
		else if (type == "PRESS")
		{

			gameText.open("gameText.txt");

			string getText;
			while (getText != finalGame) { getline(gameText, getText); }
			if (!endingStart)
			{
				if (roomName == nameshere[5])
				{
					while (getText != "OPEN") { getline(gameText, getText); }
					if (action == "RED" || action == "BLACK" || action == "YELLOW" || action == "WHITE" || action == "PURPLE" || action == "GREEN")
						while (getText != "2") { getline(gameText, getText); }

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
					for (list<string>::iterator i = items.begin(); i != items.end(); i++) 
					{ 
						if (*i == objectives[1]) { check = true; }
					}

					if (!check) { items.push_back(objectives[1]); }
					
					if (red && yellow && purple && black && white && green)
					{
						while (getText != "1") { getline(gameText, getText); }

						gotCode = true;
						bool check1 = false, check2 = false, check3 = false, check4 = false, check5 = false;

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
			txtOutput();
			gameText.close();
			cout << endl << endl;
			system("pause");
		}
		else if (type == "TYPE")
		{

			gameText.open("gameText.txt");

			string getText;
			while (getText != finalGame) { getline(gameText, getText); }
			while (getText != type) { getline(gameText, getText); }
			if (!endingStart)
			{
				if (roomName == nameshere[3])
				{

					if (!seenComputer) { seenComputer = true; }

					while (getText != roomName) { getline(gameText, getText); }
					while (getText != type) { getline(gameText, getText); }

					if (action == "CATTHEYISHERE")
					{
						while (getText != action) { getline(gameText, getText); }
						while (getText != to_string(gotCode)) { getline(gameText, getText); }


						if (!gotCode) { items.push_back("Look around the house for cups. The colour of the cups are the code for the safe in the bedroom up stairs."); }
						
						gotCode = true;
						bool check1 = false, check2 = false, check3 = false;

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

						for (list<string>::iterator i = items.begin(); i != items.end(); i++)
						{
							if (*i == objectives[5]) { ifFound = true; }
						}

						if (!ifFound) { items.push_back(objectives[5]); }

						while (getText != "ELSE") { getline(gameText, getText); }

					}

				}
			}
			txtOutput();
			gameText.close();
			cout << endl << endl;
			system("pause");
		}
		else if (type == "LOOK_AT" || type == "LOOKAT")
		{
			gameText.open("gameText.txt");

			string getText;
			while (getText != finalGame) { getline(gameText, getText); }
			while (getText != type) { getline(gameText, getText); }

			if (!endingStart)
			{
				if (interactableItems.searchItem(action))
				{

					while (getText != roomName) { getline(gameText, getText); }
					while (getText != type) { getline(gameText, getText); }
					while (getText != action) { getline(gameText, getText); }

					if (action == "COMPUTER")
					{
						while (getText != to_string((seenPassword * seenComputer) + gotCode + seenPassword)) { getline(gameText, getText); }

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
						while (getText != to_string(seenComputer + gotCode + (seenPassword * seenComputer))) { getline(gameText, getText); }

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
						if (roomName == nameshere[8])
						{
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

						if ((gotCode + gotKey + opensafe) == 0)
						{
							bool check1 = false;
							for (list<string>::iterator i = items.begin(); i != items.end(); i++)
							{
								if (*i == objectives[1]) { check1 = true; }
							}
							if (!check1) { items.push_back(objectives[1]); }
						}
						while (getText != to_string(gotCode + gotKey + opensafe)) { getline(gameText, getText); }

					}
					else if (action == "KEY")
					{
						if (gotCode)
						{
							while (getText != to_string(gotKey + opensafe)) { getline(gameText, getText); }
						}
					}

				}
			}
			txtOutput();
			gameText.close();
			cout << endl << endl;
			system("pause");
		}
		else
		{

			string word = "\"What was I supposed to do?\"";

			for (int i = 0; i < word.size(); i++)
			{
				cout << word[i];
				Sleep(15);
			}
			cout << endl << endl;
			system("pause");
		}
		if (outOfBasement && bossRoom == roomName) { Game::Instance()->changeSceneState(DEATH_SCENE_VER3); }
	}

	if (enemy.empty() && roomName == nameshere[7]) { Game::Instance()->changeSceneState(DEATH_SCENE_VER3); }
	autoSave();
}

void PlayScene::input()
{

	cin >> type >> action;

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

void PlayScene::save()
{
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
