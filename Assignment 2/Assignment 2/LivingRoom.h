#pragma once
#ifndef _LIVING_ROOM_H_
#define _LIVING_ROOM_H_

#include "Room.h"
#include <fstream>
#include <Windows.h>

class LivingRoom : public Room
{
public:
	LivingRoom()
	{
		setName("Living Room");

		ifstream openFile("gameText.txt");
		string getItems;

		while (getItems != getName())
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
				seInteractableItems(getItems);
			}
			cout << getItems << "    ";
		}
		openFile.close();

	}
	virtual ~LivingRoom() = default;

private:

};

#endif // !_LIVING_ROOM_H_



