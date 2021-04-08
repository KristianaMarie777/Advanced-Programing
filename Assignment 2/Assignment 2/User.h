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

	string getName() const { return name; }
	void setName(const string name) { this->name = name; }
private:
	fstream outfile;
	string name;
};

#endif // !_USER_H_


