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
	bool getSeenCom() const { return seenComputer; }

	void setSeenPassword(bool seenPassword) { this->seenPassword = seenPassword; }
	bool getSeenPassword() const { return seenPassword; }

	void setgotCode(bool gotCode) { this->gotCode = gotCode; }
	bool getgotCode() const { return gotCode; }

	void setGotCrank(bool gotCrank) { this->gotCrank = gotCrank; }
	bool getGotCrank() const { return gotCrank; }

	void setSecondWindow(bool secondwindow) { this->secondwindow = secondwindow; }
	bool getSecondWindow() const { return secondwindow; }

	void setFirstWindow(bool firstwindow) { this->firstwindow = firstwindow; }
	bool getFirstWindow() const { return firstwindow; }

	void setTextOnce(bool firstwindow) { this->textOnce = textOnce; }
	bool getTextOnce() const { return textOnce; }
	
	void setOpenSafe(bool opensafe) { this->opensafe = opensafe; }
	bool getOpenSafe() const { return opensafe; }

	void setGotKey(bool gotKey) { this->gotKey = gotKey; }
	bool getGotKey() const { return gotKey; }

	void setDoorIsOpen(bool doorIsOpen) { this->doorIsOpen = doorIsOpen; }
	bool getDoorIsOpen() const { return doorIsOpen; }

	void setEndingStart(bool endingStart) { this->endingStart = endingStart; }
	bool getEndingStart() const { return endingStart; }

	void setLockedAgain(bool lockedagain) { this->lockedagain = lockedagain; }
	bool getLockedAgain() const { return lockedagain; }

	void setOutOfBasement(bool outOfBasement) { this->outOfBasement = outOfBasement; }
	bool getOutOfBasement() const { return outOfBasement; }

	void setRoomName(string roomName) { this->roomName = roomName; }
	string getRoomName() const { return roomName; }

	void setBossRoom(string bossRoom) { this->bossRoom = bossRoom; }
	string getBossRoom() const { return bossRoom; }

	void setEnemy(stack<string> enemy) { this->enemy = enemy; }
	stack<string> getEnemy() const { return enemy; }

	void setFollow(queue<string> follow) { this->follow = follow; }
	queue<string> getFollow() const { return follow; }

	void setItems(list<string> items) { this->items = items; }
	list<string> getItems() const { return items; }

private:
	fstream outfile;
	string name, roomName, bossRoom = "H";
	int loadSave = 0, direction;
	bool newUser = false;
	bool seenComputer = false, seenPassword = false, gotCode = false, gotCrank = false, secondwindow = false, firstwindow = false,
		opensafe = false, gotKey = true, doorIsOpen = false, endingStart = false, outOfBasement = false, lockedagain = false, textOnce = false;
	stack<string> enemy;
	queue<string> follow;
	list<string> items;
};

#endif // !_USER_H_


