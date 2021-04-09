#pragma once
#ifndef _ROOM_H_
#define _ROOM_H_

#include <string>
#include "SearchNext.h"

using namespace std;

class Room
{
protected:

	void setName(string name) { roomName = name; }
	void seInteractableItems(string name) { interactableItems.push_back(name); }

public:
	Room() = default;
	virtual ~Room() = default;

	
	string getName() const { return roomName; }
	SearchAbleVector<string> getInteractableItems() { return interactableItems; }
private:
	string roomName;
	SearchAbleVector<string> interactableItems;
};

#endif // !_ROOM_H_
