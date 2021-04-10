#pragma once
#ifndef _USER_H_
#define _USER_H_

#include <fstream>
#include <iostream>
#include <string>
#include <list>
#include <stack>
#include <queue>

using namespace std;

class User
{
public:
	User(string player = "");
	~User();
	//void update();

	void Loadsave();

	string getName() const { return name; }
	void setName(const string name) { this->name = name; }

	bool getNewUser() const { return newUser; }
	void setNewUser(const bool newUser) { this->newUser = newUser; }

	int getDirection() const { return direction; }
	void setDirection(const int direction) { this->direction = direction; }

	void NewGame();
	void save();
	void setSeenCom(bool seenComputer) { this->seenComputer = seenComputer; }
	void setSeenCom(bool seenComputer) { this->seenComputer = seenComputer; }

	void setSeenPassword(bool seenPassword) { this->seenPassword = seenPassword; }
	void setSeenPassword(bool seenPassword) { this->seenPassword = seenPassword; }

	void setgotCode(bool gotCode) { this->gotCode = gotCode; }
	void setgotCode(bool gotCode) { this->gotCode = gotCode; }

	void setGotCrank(bool gotCrank) { this->gotCrank = gotCrank; }

	void setSecondWindow(bool secondwindow) { this->secondwindow = secondwindow; }

	void setFirstWindow(bool firstwindow) { this->firstwindow = firstwindow; }

	void setOpenSafe(bool opensafe) { this->opensafe = opensafe; }

	void setGotKey(bool gotKey) { this->gotKey = gotKey; }

	void setDoorIsOpen(bool doorIsOpen) { this->doorIsOpen = doorIsOpen; }

	void setEndingStart(bool endingStart) { this->endingStart = endingStart; }

	void setLockedAgain(bool lockedagain) { this->lockedagain = lockedagain; }

	void setOutOfBasement(bool outOfBasement) { this->outOfBasement = outOfBasement; }

	void setRoomName(string roomName) { this->roomName = roomName; }

	void setBossRoom(string bossRoom) { this->bossRoom = bossRoom; }

	void setEnemy(stack<string> enemy) { this->enemy = enemy; }

	void setFollow(queue<string> follow) { this->follow = follow; }

	void setItems(list<string> items) { this->items = items; }

private:
	fstream outfile;
	string name, roomName, bossRoom = "H";
	int loadSave = 0, direction;
	bool newUser = false;
	bool seenComputer = false, seenPassword = false, gotCode = false, gotCrank = false, secondwindow = false, firstwindow = false,
		opensafe = false, gotKey = true, doorIsOpen = false, endingStart = false, outOfBasement = false, lockedagain = false;
	stack<string> enemy;
	queue<string> follow;
	list<string> items;
};

#endif // !_USER_H_


