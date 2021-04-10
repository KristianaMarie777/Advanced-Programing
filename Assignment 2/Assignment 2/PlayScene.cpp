#include "PlayScene.h"
#include <iostream>
#include "Game.h"
#include <Windows.h>

#define NUMLONGSEC 500

using namespace std;
//"Living Room" (0), "Kitchen" (1), "First Floor Washroom" (2), "Work Room" (3), "Hallway" (4), "Bedroom" (5), "Storage Room" (6), "Basement" (7), "Second Floor Washroom" (8)
string nameshere[] = { "Living Room" , "Kitchen", "First Floor Washroom", "Work Room", "Hallway", "Bedroom", "Storage Room", "Basement", "Second Floor Washroom"};

PlayScene::PlayScene(bool newGame)
{
	directionName[0] = "N";
	directionName[1] = "E";
	directionName[2] = "S";
	directionName[3] = "W";
	if (!newGame)
	{
		roomName = nameshere[0];
		//items.push_back();

		ifstream openFile("gameText.txt");
		string getItems;

		while (getItems != roomName) { getline(openFile, getItems); }
		while (getItems != "ITEMS") { getline(openFile, getItems); }
		
		while (getItems != "END")
		{
			getline(openFile, getItems);
			if (getItems != "END")
			{
				interactableItems.push_back(getItems);
			}
			cout << getItems << "    ";
		}
		openFile.close();

		direction = 0;//Game::Instance()->getPlayer()->getDirection();
	}
}

void PlayScene::output()
{
	gameText.open("gameText.txt");

	string getText;

	if (roomName == nameshere[7])
	{
		//while (getText != roomName) { getline(gameText, getText); }
		
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

	}
	else
	{
		if(follow.empty()){ cout << "\n" << roomName << endl << endl; }
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
	if (endingStart && finalGame != "ENDING") { finalGame = "ENDING"; }
	if (roomName == "Basement" && action == "STAIRS") { action = "LIVINGROOM"; }
	if (action == "STAIRS") { action = "HALLWAY"; }
	if(action == "SECOND_FLOOR_WASHROOM") {action = "SECOND_FLOOR_BATHROOM"; }

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
		else
		{
			Game::Instance()->changeSceneState(DEATH_SCENE_VER2);
		}
	}
	else
	{
		if (type == "TURN")
		{
			//cout << "int";
			gameText.open("gameText.txt");

			string getText;
			while (getText != finalGame) { getline(gameText, getText); }
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
				if (roomName == "Living Room" || roomName == "Kitchen" || roomName == "First Floor Washroom" || roomName == "Second Floor Washroom")
				{
					if (roomName == "Living Room")
					{
						if (action == "KEY_ON_BASEMENT")
						{
							while (getText != action) { getline(gameText, getText); }
							while (getText != to_string(gotKey + outOfBasement + lockedagain)) { getline(gameText, getText); }
							if (gotKey) { doorIsOpen = true; }
							if (outOfBasement && !lockedagain)
							{
								lockedagain = true;
								queue<string> getItemsthere;
								while (!follow.empty())
								{
									getItemsthere.push(follow.front());
									follow.pop();
								}
								for (int i = 0; i < 4; i++)
								{
									follow.push(nameshere[7]);
								}
								while (!follow.empty())
								{
									follow.push(getItemsthere.front());
									getItemsthere.pop();
								}
							}
						}
						else if (action == "BROKEN_TV_ON_BASEMENT")
						{
							if (outOfBasement)
							{
								Game::Instance()->changeSceneState(ESCAPE_SCENE);
							}
						}

					}
					else if (roomName == "Kitchen")
					{
						if (action == "CHAIR_ON_WINDOW")
						{
							if (outOfBasement)
							{
								Game::Instance()->changeSceneState(ESCAPE_SCENE);
							}
						}
					}
					else if (roomName == "First Floor Washroom")
					{
						if (action == "CRANK_ON_WINDOW")
						{
							Game::Instance()->changeSceneState(ESCAPE_SCENE);

						}
					}
					else if (roomName == "Second Floor Washroom")
					{
						if (action == "CRANK_ON_WINDOW") { Game::Instance()->changeSceneState(DEATH_SCENE_VER1); }
					}
				}
				else
				{

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
					if (roomName == "Bedroom")
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

					if (roomName == "Storage Room")
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
			if (follow.size() > 1)
				follow.pop();
			gameText.open("gameText.txt");
			cout << "walk";
			string getText;
			bool passIf = false;

			while (getText != type) { getline(gameText, getText); }

			if (interactableItems.searchItem(action))
			{

				if (action == "LIVINGROOM" || action == "KITCHEN" || action == "FIRST_FLOOR_BATHROOM" || action == "WORKROOM" || action == "HALLWAY" || action == "BEDROOM" || action == "STORAGEROOM"
					|| action == "BASEMENT" || action == "SECOND_FLOOR_BATHROOM")
				{
					cout << "\n\n";
					if (action == "LIVINGROOM")
					{
						if (roomName == nameshere[3] || roomName == nameshere[7]) { direction = 3; }
						else { direction = 2; }
						roomName = "Living Room";
					}
					else if (action == "KITCHEN")
					{
						if (roomName == "Living Room") { direction = 0; }
						else { direction = 3; }
						roomName = "Kitchen";
					}
					else if (action == "FIRST_FLOOR_BATHROOM")
					{
						if (roomName == "Living Room") { direction = 0; }
						else if (roomName == "Kitchen") { direction = 1; }
						else { direction = 3; }
						roomName = "First Floor Washroom";
					}
					else if (action == "WORKROOM")
					{
						roomName = "Work Room";
						direction = 1;
					}
					else if (action == "HALLWAY")
					{
						if (roomName == "Bedroom") { direction = 1; }
						else if (roomName == "Second Floor Washroom") { direction = 2; }
						else { direction = 0; }
						roomName = "Hallway";
					}
					else if (action == "BEDROOM")
					{
						roomName = "Bedroom";
						direction = 3;
					}
					else if (action == "STORAGEROOM")
					{
						roomName = "Storage Room";
						direction = 2;
					}
					else if (action == "BASEMENT")
					{
						if (doorIsOpen)
						{
							if (!endingStart)
							{
								roomName = "Basement";
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

						}
					}
					else if (action == "SECOND_FLOOR_BATHROOM")
					{
						roomName = "Second Floor Washroom";
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
				if (roomName == "Bedroom")
				{
					while (getText != "OPEN") { getline(gameText, getText); }
					if (action == "RED" || action == "BLACK" || action == "YELLOW" || action == "WHITE" || action == "PURPLE" || action == "GREEN")
						while (getText != "2") { getline(gameText, getText); }

					if (action == "RED")
					{
						red = true;
					}
					else if (action == "BLACK")
					{
						black = true;
					}
					else if (action == "YELLOW")
					{
						yellow = true;
					}
					else if (action == "WHITE")
					{
						white = true;
					}
					else if (action == "PURPLE")
					{
						purple = true;
					}
					else if (action == "GREEN")
					{
						green = true;
					}
					else if (action == "BLUE" || action == "ORANGE" || action == "INDIGO")
					{
						while (getText != "0") { getline(gameText, getText); }
						red = yellow = purple = black = white = green = false;
					}

					bool check = false;
					for (list<string>::iterator i = items.begin(); i != items.end(); i++)
					{
						if (*i == "Find SAFE code.") { check = true; }

					}
					if (!check)
						items.push_back("Find SAFE code.");

					if (red && yellow && purple && black && white && green)
					{
						while (getText != "1") { getline(gameText, getText); }


						gotCode = true;
						bool check1 = false, check2 = false, check3 = false, check4 = false, check5 = false;



						for (list<string>::iterator i = items.begin(); i != items.end(); i++)
						{
							if (*i == "Find the password for the computer.") { check1 = true; }
							if (*i == "Use type CATTHEYISHERE into the computer") { check2 = true; }
							if (*i == "Find where this password has to go.") { check3 = true; }
							if (*i == "Look around the house for cups. The colour of the cups are the code for the safe in the bedroom up stairs.") { check4 = true; }

						}
						if (check1) { items.remove("Find the password for the computer."); }
						if (check2) { items.remove("Use type CATTHEYISHERE into the computer"); }
						if (check3) { items.remove("Find where this password has to go."); }
						if (check4) { items.remove("Look around the house for cups. The colour of the cups are the code for the safe in the bedroom up stairs."); }
						if (check5) { items.remove("Find SAFE code."); }
						items.push_back("Get the Key.");
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


						if (!gotCode)
							items.push_back("Look around the house for cups. The colour of the cups are the code for the safe in the bedroom up stairs.");
						gotCode = true;
						bool check1 = false, check2 = false, check3 = false;



						for (list<string>::iterator i = items.begin(); i != items.end(); i++)
						{
							if (*i == "Find the password for the computer.") { check1 = true; }
							if (*i == "Use type CATTHEYISHERE into the computer") { check2 = true; }
							if (*i == "Find where this password has to go.") { check3 = true; }

						}
						if (check1) { items.remove("Find the password for the computer."); }
						if (check2) { items.remove("Use type CATTHEYISHERE into the computer"); }
						if (check3) { items.remove("Find where this password has to go."); }
					}
					else
					{
						bool ifFound = false;

						for (list<string>::iterator i = items.begin(); i != items.end(); i++)
						{
							if (*i == "Find the password for the computer.") { ifFound = true; }
						}

						if (!ifFound) { items.push_back("Find the password for the computer."); }

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

						if (((seenPassword * seenComputer) + gotCode + seenPassword) == 0)
						{
							items.push_back("Find the password for the computer.");
						}
						else if (((seenPassword * seenComputer) + gotCode + seenPassword) == 1)
						{
							bool ifFound = false;
							for (list<string>::iterator i = items.begin(); i != items.end(); i++)
							{
								if (*i == "Find the password for the computer.") { ifFound = true; }
							}
							items.push_back("Use type CATTHEYISHERE into the computer");
						}

						seenComputer = true;


					}
					else if (action == "PHOTO")
					{
						while (getText != to_string(seenComputer + gotCode + (seenPassword * seenComputer))) { getline(gameText, getText); }

						if ((seenComputer + gotCode + (seenPassword * seenComputer)) == 0)
						{
							items.push_back("Find where this password has to go.");
						}
						else if ((seenComputer + gotCode + (seenPassword * seenComputer)) == 1)
						{
							bool ifFound = false;
							for (list<string>::iterator i = items.begin(); i != items.end(); i++)
							{
								if (*i == "Find the password for the computer.") { ifFound = true; }
							}
							if (ifFound) { items.remove("Find the password for the computer."); }
							items.push_back("Use type CATTHEYISHERE into the computer");

						}
						seenPassword = true;

					}
					else if (action == "WINDOW")
					{
						if (roomName == "Second Floor Washroom")
						{
							if (!secondwindow)
								items.push_back("Look for missing SECOND_FLOOR_BATHROOM item.");

							secondwindow = true;
						}
						if (roomName == "First Floor Washroom")
						{
							if (!firstwindow)
								items.push_back("Look for missing FIRST_FLOOR_BATHROOM item.");

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
								if (*i == "Find SAFE code.") { check1 = true; }

							}
							if (!check1)
								items.push_back("Find SAFE code.");
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
				cout << word;
				Sleep(15);
			}
			cout << endl << endl;
			system("pause");
		}
	}
		
	if (endingStart && roomName != nameshere[7]) { follow.push(roomName); }
	
	if (outOfBasement)
	{
		string movement;
		bossRoom = follow.front();
		follow.pop();
	}

	if (outOfBasement && bossRoom == roomName) { Game::Instance()->changeSceneState(DEATH_SCENE_VER3); }
	if (enemy.empty() && roomName == "Basement") { Game::Instance()->changeSceneState(DEATH_SCENE_VER3); }
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
