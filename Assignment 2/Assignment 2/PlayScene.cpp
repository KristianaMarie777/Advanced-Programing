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
	
	currentRoom = new LivingRoom();

	direction = 0;//Game::Instance()->getPlayer()->getDirection();
}

void PlayScene::output()
{
	cout << "       " << directionName[direction] << "\n       T\n       |\n";
	cout << directionName[(((direction - 1) % 4) < 0) ? 3 : ((direction - 1) % 4)] << " <----+----> " << directionName[(1 + direction) % 4] << "\n       |\n       v\n";
	cout << "       " << directionName[(2 + direction) % 4] << endl;

	gameText.open("gameText.txt");

	string getText;

	while (getText != currentRoom->getName())
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
	else if (type == "GO" || type == "GO_TO")
	{
		if (action == "LIVINGROOM" || action == "LIVING_ROOM")
		{
			if (!livingRoom) 
			{ 
				livingRoom = true; 

				if (workRoom) { direction = 3; }
				else { direction = 2; }
			}

			if (kitchen) { kitchen = false; }
			if (washRoomMid) { washRoomMid = false; }
			if (workRoom) { workRoom = false; }
			if (hallWay) { hallWay = false; }
			if (bedRoom) { bedRoom = false; }
			if (washRoomTop) { washRoomTop = false; }
			if (storageRoom) { storageRoom = false; }
			if (basement) { basement = false; }
		}
		else if (action == "KITCHEN")
		{
			if (!kitchen) 
			{ 
				kitchen = true; 

				if (livingRoom) { direction = 0; }
				else { direction = 3; }
			}

			if (livingRoom) { livingRoom = false; }
			if (washRoomMid) { washRoomMid = false; }
			if (workRoom) { workRoom = false; }
			if (hallWay) { hallWay = false; }
			if (bedRoom) { bedRoom = false; }
			if (washRoomTop) { washRoomTop = false; }
			if (storageRoom) { storageRoom = false; }
			if (basement) { basement = false; }

		}
		else if (action == "FIRST_FLOOR_WASHROOM" || action == "FIRST_FLOOR_BATHROOM")
		{

			if (!washRoomMid) { washRoomMid = true; }

			if (livingRoom) { livingRoom = false; }
			if (kitchen) { kitchen = false; }
			if (workRoom) { workRoom = false; }
			if (hallWay) { hallWay = false; }
			if (bedRoom) { bedRoom = false; }
			if (washRoomTop) { washRoomTop = false; }
			if (storageRoom) { storageRoom = false; }
			if (basement) { basement = false; }

		}
		else if (action == "WORKROOM" || action == "WORK_ROOM")
		{

			if (!workRoom)
			{
				workRoom = true;
				direction = 1;
			}

			if (livingRoom) { livingRoom = false; }
			if (washRoomMid) { washRoomMid = false; }
			if (kitchen) { kitchen = false; }
			if (hallWay) { hallWay = false; }
			if (bedRoom) { bedRoom = false; }
			if (washRoomTop) { washRoomTop = false; }
			if (storageRoom) { storageRoom = false; }
			if (basement) { basement = false; }

		}
		else if (action == "HALLWAY")
		{

			if (!hallWay)
			{
				hallWay = true;
				if (washRoomTop) { direction = 2; }
				else 
				{ 
					if (bedRoom) { direction = 1; }
					else { direction = 0; }
				}
			}

			if (livingRoom) { livingRoom = false; }
			if (washRoomMid) { washRoomMid = false; }
			if (kitchen) { kitchen = false; }
			if (workRoom) { workRoom = false; }
			if (bedRoom) { bedRoom = false; }
			if (washRoomTop) { washRoomTop = false; }
			if (storageRoom) { storageRoom = false; }
			if (basement) { basement = false; }

		}
		else if (action == "BEDROOM")
		{

			if (!bedRoom)
			{
				bedRoom = true;
				direction = 3;
			}

			if (livingRoom) { livingRoom = false; }
			if (washRoomMid) { washRoomMid = false; }
			if (kitchen) { kitchen = false; }
			if (hallWay) { hallWay = false; }
			if (workRoom) { workRoom = false; }
			if (washRoomTop) { washRoomTop = false; }
			if (storageRoom) { storageRoom = false; }
			if (basement) { basement = false; }

		}
		else if (action == "STORAGEROOM" || action == "STORAGE_ROOM")
		{

			if (!storageRoom)
			{
				storageRoom = true;
				direction = 2;
			}

			if (livingRoom) { livingRoom = false; }
			if (washRoomMid) { washRoomMid = false; }
			if (kitchen) { kitchen = false; }
			if (hallWay) { hallWay = false; }
			if (bedRoom) { bedRoom = false; }
			if (washRoomTop) { washRoomTop = false; }
			if (workRoom) { workRoom = false; }
			if (basement) { basement = false; }

		}
		else if (action == "BASEMENT")
		{

			if (!basement)
			{
				basement = true;
				direction = 2;
			}

			if (livingRoom) { livingRoom = false; }
			if (washRoomMid) { washRoomMid = false; }
			if (kitchen) { kitchen = false; }
			if (hallWay) { hallWay = false; }
			if (bedRoom) { bedRoom = false; }
			if (washRoomTop) { washRoomTop = false; }
			if (storageRoom) { storageRoom = false; }
			if (workRoom) { workRoom = false; }

		}
		else if (action == "WASHROOM_TOP_FLOOR" || action == "BATHROOM_TOP_FLOOR")
		{

			if (!washRoomTop)
			{
				washRoomTop = true;
				direction = 2;
			}

			if (livingRoom) { livingRoom = false; }
			if (washRoomMid) { washRoomMid = false; }
			if (kitchen) { kitchen = false; }
			if (hallWay) { hallWay = false; }
			if (bedRoom) { bedRoom = false; }
			if (basement) { basement = false; }
			if (storageRoom) { storageRoom = false; }
			if (workRoom) { workRoom = false; }

		}

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
	
		std::cout << action << "     ";


		if (currentRoom->getInteractableItems().findItem(action) < 0)
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

			while (getText != currentRoom->getName())
			{
				getline(gameText, getText);
			}

			while (getText != action)
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
