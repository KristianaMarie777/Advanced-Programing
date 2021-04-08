#include "PlayScene.h"
#include <iostream>
#include "Game.h"

using namespace std;



PlayScene::PlayScene()
{
	directionName[0] = "N";
	directionName[1] = "E";
	directionName[2] = "S";
	directionName[3] = "W";
	direction = 0;//Game::Instance()->getPlayer()->getDirection();
}

void PlayScene::output()
{

	cout << "       " << directionName[direction] << "\n       T\n       |\n";
	cout << directionName[(((direction - 1) % 4) < 0) ? 3 : ((direction-1) % 4)] << " <----+----> " << directionName[(1 + direction) % 4] << "\n       |\n       v\n";
	cout << "       " << directionName[(2 + direction) % 4] <<endl;
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
			if (washRommTop) { washRommTop = false; }
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
			if (washRommTop) { washRommTop = false; }
			if (storageRoom) { storageRoom = false; }
			if (basement) { basement = false; }

		}
		else if (action == "WASHROOM_MID_FLOOR" || action == "BATHROOM_MID_FLOOR")
		{
			if (!kitchen) { kitchen = true; }

			if (livingRoom) { livingRoom = false; }
			if (washRoomMid) { washRoomMid = false; }
			if (workRoom) { workRoom = false; }
			if (hallWay) { hallWay = false; }
			if (bedRoom) { bedRoom = false; }
			if (washRommTop) { washRommTop = false; }
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
			if (washRommTop) { washRommTop = false; }
			if (storageRoom) { storageRoom = false; }
			if (basement) { basement = false; }

		}
		else if (action == "HALLWAY")
		{

			if (!hallWay)
			{
				hallWay = true;
				if (washRommTop) { direction = 2; }
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
			if (washRommTop) { washRommTop = false; }
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
			if (washRommTop) { washRommTop = false; }
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
			if (washRommTop) { washRommTop = false; }
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
			if (washRommTop) { washRommTop = false; }
			if (storageRoom) { storageRoom = false; }
			if (workRoom) { workRoom = false; }

		}
		else if (action == "WASHROOM_TOP_FLOOR" || action == "BATHROOM_TOP_FLOOR")
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
			if (washRommTop) { washRommTop = false; }
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
