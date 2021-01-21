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
	Achievement()
	{

	}

	string GetTitle()
	{
		return achievementTitle;
	}

	string AchievementFullDescription()
	{
		string list = achievementTitle + "\n\n\n";

		list += achievementDescription[40];
		list += "\n" + achievementDescription;
		list += "\n\n" + scoreValue;


		return list;
	}

	void MainMenu()
	{

	}
	string Achievementlist()
	{
		string list = "\n" + achievementTitle;

		list += "\n\nEarn " + to_string(scoreValue);
		list += "xp";

		return list;
	}
};

class Game
{
private:
	string gameName, publisherName, developerName;
	vector<Achievement*> achievement;

public:
	Game()
	{


	}

	void CreateAchievement()
	{
		achievement.push_back(new Achievement());
	}

	string GetGameName()
	{
		return  gameName;
	}

	string GameList()
	{
		string list = "\n" + gameName;

		if (achievement.empty())
			list += "\n\nThere are no achievements currently\n\n";
		else
		{
			list += "\n\nThere are " + to_string(achievement.size());
			list += " games currently\n\n";
		}

		return list;
	}

	void MainMenu()
	{

	}
};

class Platform
{
private:
	string platformName, manufacturerName;
	vector<Game*> games;
public:
	Platform();
	void CreateGame();
	string PlatformList();
	void MainMenu();
	string GetPlatformName();
	void SetNames();

};



#endif // !1

