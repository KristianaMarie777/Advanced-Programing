#include "PlayScene.h"
#include <iostream>
#include "Game.h"
#include <Windows.h>

#define NUMLONGSEC 500

using namespace std;

string nameshere[] = { "Living Room" , "Kitchen", "First Floor Washroom", "Work Room", "hallway", "Bedroom", "Storage Room", "Basement", "Second Floor Washroom"};

PlayScene::PlayScene()
{
	directionName[0] = "N";
	directionName[1] = "E";
	directionName[2] = "S";
	directionName[3] = "W";
	roomName = nameshere[3];
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
	txtOutput();
	
	gameText.close();
}

void PlayScene::update()
{

	if (type == "TURN")
	{
		gameText.open("gameText.txt");

		string getText;

		while (getText != type)
		{
			getline(gameText, getText);
		}

		if (action == "RIGHT")
		{
			direction = ++direction % 4;
		}
		else if (action == "LEFT")
		{

			direction = (((direction - 1) % 4) < 0) ? 3 : ((--direction) % 4);

		}
		else
		{
			txtOutput();
		}
		gameText.close();
		cout << endl << endl;
		system("pause");
	}
	else if (type == "LOCK")
	{
		gameText.open("gameText.txt");

		string getText;

		while (getText != type)
		{
			getline(gameText, getText);
		}

		if (interactableItems.searchItem(action))
		{
			if (roomName == "First Floor Washroom")
			{



				if (action == "KITCHEN")
				{

				}
				else if (action == "FIRST_FLOOR_BATHROOM")
				{

				}
				else if (action == "WORKROOM")
				{

				}
				else if (action == "LIVINGROOM")
				{

				}
				else
				{

				}
			}
			else if (roomName == "Second Floor Washroom")
			{

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
	else if (type == "USE")
	{
		gameText.open("gameText.txt");

		string getText;

		while (getText != type)
		{
			getline(gameText, getText);
		}

		if (interactableItems.searchItem(action))
		{
			if (roomName == "Living Room" || roomName == "Kitchen" || roomName == "First Floor Washroom" || roomName == "Second Floor Washroom")
			{
				if (roomName == "Living Room")
				{
					if (action == "KEY_ON_BASEMENT")
					{

					}
					else if (action == "BROKEN_TV_ON_BASEMENT")
					{

					}
					else
					{

					}

				}
				else if (roomName == "Kitchen")
				{
					if (action == "CHAIR_ON_WINDOW")
					{

					}
					else
					{

					}
				}
				else if (roomName == "First Floor Washroom")
				{
					if (action == "CRANK_ON_WINDOW")
					{

					}
					else
					{

					}
				}
				else if (roomName == "Second Floor Washroom")
				{
					if (action == "CRANK_ON_WINDOW")
					{

					}
					else
					{

					}
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
	else if (type == "GET")
	{
		gameText.open("gameText.txt");

		string getText;

		while (getText != type)
		{
			getline(gameText, getText);
		}

		if (interactableItems.searchItem(action))
		{
			if (action == "KEY")
			{
				if (roomName == "Bedroom")
				{

				}
				else
				{

				}

			}
			else if (action == "CRANK")
			{
				if (roomName == "Storage Room")
				{

				}
				else
				{

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
	else if (type == "WALKTO" || type == "WALK_TO")
	{
		gameText.open("gameText.txt");

		string getText;
		bool passIf = false;

		while (getText != type)
		{
			getline(gameText, getText);
		}

		if (action == "STAIRS")
		{
			action = "HALLWAY";
		}
		if (interactableItems.searchItem(action))
		{
			
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

				while (getText != roomName)
				{
					getline(gameText, getText);
				}
				//cout << "here";
				while (getText != "ITEMS")
				{
					getline(gameText, getText);
				}
				//cout << "here";
				while (getText != "END")
				{
					getline(gameText, getText);
					if (getText != "END")
					{
						interactableItems.push_back(getText);
					}
					//cout << getItems << "    ";
				}
			}
			else
			{
				passIf = true;
				while (getText != to_string(passIf))
				{
					getline(gameText, getText);
				}
			}


			
		}
		else
		{
			while (getText != to_string(passIf))
			{
				getline(gameText, getText);
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

		while (getText != type)
		{
			getline(gameText, getText);
		}

		if (roomName == nameshere[3])
		{
			if(!seenComputer)
				seenComputer = true;
			

			while (getText != roomName)
			{
				getline(gameText, getText);
			}

			while (getText != type)
			{
				getline(gameText, getText);
			}


			if (action == "CATTHEYISHERE")
			{
				while (getText != action)
				{
					getline(gameText, getText);
				}

				while (getText != to_string(gotCode))
				{
					getline(gameText, getText);
				}

				gotCode = true;
			}
			else
			{
				while (getText != "ELSE")
				{
					getline(gameText, getText);
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

		while (getText != type)
		{
			getline(gameText, getText);
		}

		if (interactableItems.searchItem(action))
		{

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
				while (getText != to_string((seenPassword * seenComputer) + gotCode + seenPassword))
				{
					getline(gameText, getText);
				}
				seenComputer = true;


			}
			else if (action == "PHOTO")
			{
				while (getText != to_string(seenComputer + gotCode + (seenPassword * seenComputer)))
				{
					getline(gameText, getText);
				}
				seenPassword = true;

			}
			

		}
		txtOutput();
		gameText.close();
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
