#include "PlayScene.h"
#include <iostream>
#include "Game.h"
#include <Windows.h>

using namespace std;

PlayScene::PlayScene()
{
	directionName[0] = "N";
	directionName[1] = "E";
	directionName[2] = "S";
	directionName[3] = "W";
	roomName = "Living Room";
	ifstream openFile("gameText.txt");
	string getItems;

	while (getItems != roomName)
	{
		getline(openFile, getItems);
	}

	while (getItems != "ITEMS")
	{
		getline(openFile, getItems);
	}

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

void PlayScene::output()
{
	cout << "       " << directionName[direction] << "\n       T\n       |\n";
	cout << directionName[(((direction - 1) % 4) < 0) ? 3 : ((direction - 1) % 4)] << " <----+----> " << directionName[(1 + direction) % 4] << "\n       |\n       v\n";
	cout << "       " << directionName[(2 + direction) % 4] << endl;

	gameText.open("gameText.txt");

	string getText;

	while (getText != roomName)
	{
		getline(gameText, getText);
	}

	while (getText != directionName[direction])
	{
		getline(gameText, getText);
	}

	while (getText != "END")
	{
		getline(gameText, getText);
		if (getText != "END")
		{
			for (int i = 0; i < getText.size(); i++)
			{
				cout << getText[i];
				Sleep(15);
			}
			Sleep(150);
		}
		cout << endl;
	}
	gameText.close();
}

void PlayScene::update()
{
	//system("pause");

	if (type == "TURN")
	{
		if (action == "RIGHT")
		{
			direction = ++direction % 4;
		}
		else if (action == "LEFT")
		{

			direction = (((direction - 1) % 4) < 0) ? 3 : ((--direction) % 4);

		}
	}
	else if (type == "WALKTO" || type == "WALK_TO")
	{

		if (interactableItems.searchItem(action))
		{
			//cout << "here";
			if (action == "LIVINGROOM" || action == "KITCHEN" || action == "FIRST_FLOOR_BATHROOM" || action == "WORKROOM" || action == "HALLWAY" || action == "BEDROOM" || action == "STORAGEROOM" 
				|| action == "BASEMENT" ||  action == "SECOND_FLOOR_BATHROOM")
			{
				cout << "\n\n";
				if (action == "LIVINGROOM") 
				{ 
					if (roomName == "Work Room") { direction = 3; }
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
					if (roomName == "BEDROOM") { direction = 1; }
					else { direction = 0; }
					roomName = "hallway"; 
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
					roomName = "Basement"; 
					direction = 2;
				}
				else if (action == "SECOND_FLOOR_BATHROOM") 
				{ 
					roomName = "Second Floor Washroom"; 
					direction = 2;
				}


				interactableItems.clear();
				ifstream openFile("gameText.txt");
				string getItems;

				while (getItems != roomName)
				{
					getline(openFile, getItems);
				}
				//cout << "here";
				while (getItems != "ITEMS")
				{
					getline(openFile, getItems);
				}
				//cout << "here";
				while (getItems != "END")
				{
					getline(openFile, getItems);
					if (getItems != "END")
					{
						interactableItems.push_back(getItems);
					}
					//cout << getItems << "    ";
				}
				openFile.close();
			}
			else
			{
				string word = "That isn't even a room!\n\n";
				for (int i = 0; i < word.size(); i++)
				{
					cout << word[i];
					Sleep(15);
				}
			}
		}
		else
		{
			string word = "You can't walk there.\n\n";
			for (int i = 0; i < word.size(); i++)
			{
				cout << word[i];
				Sleep(15);
			}
		}

		system("pause");
	
	}
	else if (type == "GET")
	{
		if (action == "RIGHT")
		{
			direction = ++direction % 4;
		}
		else if (action == "LEFT")
		{

			direction = (((direction - 1) % 4) < 0) ? 3 : ((--direction) % 4);

		}
	}
	else if (type == "LOOK_AT" || type == "LOOKAT")
	{
		type = "LOOKAT";


		if (!interactableItems.searchItem(action))
		{
			string word = "There is not a item like in here.\n\n";
			for (int i = 0; i < word.size(); i++)
			{
				cout << word[i];
				Sleep(15);
			}
		}
		else
		{
			gameText.open("gameText.txt");

			string getText;

			while (getText != roomName)
			{
				getline(gameText, getText);
			}

			while (getText != type)
			{
				getline(gameText, getText);
			}

			while (getText != action)
			{
				getline(gameText, getText);
			}

			if (action == "COMPUTER")
			{
				if (!seenComputer)
				{
					if (seenPassword)
					{
						getline(gameText, getText);
						while (getText != "END")
						{
							getline(gameText, getText);
							if (getText != "END")
							{
								for (int i = 0; i < getText.size(); i++)
								{
									cout << getText[i];
									Sleep(15);
								}
								Sleep(150);
							}
							cout << endl;
						}
					}
					else
					{
						while (getText != "2")
						{
							getline(gameText, getText);
						}

						while (getText != "END")
						{
							getline(gameText, getText);
							if (getText != "END")
							{
								for (int i = 0; i < getText.size(); i++)
								{
									cout << getText[i];
									Sleep(15);
								}
								Sleep(150);
							}
							cout << endl;
						}
					}
					
					
				}
				else
				{
					if (seenPassword)
					{
						while (getText != "3")
						{
							getline(gameText, getText);
						}
					}
					else
					{
						while (getText != "1")
						{
							getline(gameText, getText);
						}
					}

					while (getText != "END")
					{
						getline(gameText, getText);
						if (getText != "END")
						{
							for (int i = 0; i < getText.size(); i++)
							{
								cout << getText[i];
								Sleep(15);
							}
							Sleep(150);
						}
						cout << endl;
					}
				}



			}
			else
			{
				while (getText != "END")
				{
					getline(gameText, getText);
					if (getText != "END")
					{
						for (int i = 0; i < getText.size(); i++)
						{
							cout << getText[i];
							Sleep(15);
						}
						Sleep(150);
					}
					cout << endl;
				}
			}
			gameText.close(); 

		}


		cout << endl << endl;
		system("pause");
	}
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
