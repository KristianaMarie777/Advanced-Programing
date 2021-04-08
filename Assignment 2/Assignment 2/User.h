#pragma once
#ifndef _USER_H_
#define _USER_H_

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class User
{
public:
	User(string player = "");
	~User() = default;
	//void update();

	void Loadsave();

	void setLoadSave(int num) { loadSave = num; }

	string getName() const { return name; }
	void setName(const string name) { this->name = name; }

	bool getNewUser() const { return newUser; }
	void setNewUser(const bool newUser) { this->newUser = newUser; }

	int getDirection() const { return direction; }
	void setDirection(const int direction) { this->direction = direction; }

	void NewGame();
private:
	fstream outfile;
	string name;
	int loadSave = 0, direction;
	bool newUser = false;
	bool passStoryScene;
};

#endif // !_USER_H_


