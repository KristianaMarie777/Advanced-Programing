#pragma once
#ifndef _PLATFORM_H_
#define _PLATFORM_H_

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Achievement
{
private:
	string achievementTitle, achievementDescription;
	int scoreValue;

public:

};

class Game
{
private:
	string gameName, publisherName, developerName;
	vector<Achievement*> achievement;

public:

};

class Platform
{
private:
	string platformName, manufactuerName;
	vector<Game*> games;
public:
	Platform();
	void SetPlatformName();
	void SetManufactuer();
	void CreateGame();
	string PlatformList();
	void RetypePlatform();

};

#endif // !1

