#pragma once
#ifndef _PLATFORM_H_
#define _PLATFORM_H_

#include <iostream>
#include <string>

using namespace std;

class Achievement
{
private:
	string achievementTitle, achievementDescription;
	int scoreValue, achievementNum;

public:
	void AddAchievementinfo(string a, int n)
	{
		string numChoice;
		int num = 0;
		achievementNum = n;

		cout << a;

		cout << "\n\nWhat is the name of Achievement " << n << "?: ";
		cin >> ws;
		getline(cin, achievementTitle);

		cout << "\nWhat is it's description?: ";
		getline(cin, achievementDescription);

		do
		{
			cout << "\nHow much XP are you going to get?: ";
			getline(cin, numChoice);

			for (int i = 0; i < numChoice.size(); i++)
			{
				num = i;
				if (isalpha(numChoice[i]))
				{

					system("CLS");

					cout << a;

					cout << "\n\nWhat is the name of Achievement " << n << "?: " << achievementTitle;

					cout << "\n\nWhat is it's description?: " << achievementDescription;

					cout << "\n\nThere are letters in your answer. Type again.";
					break;
				}
			}

		} while (isalpha(numChoice[num]));

		scoreValue = stoi(numChoice);

	}

	string GetAchievementDescription()
	{
		string list = "Achievement " + to_string(achievementNum) + ": " + achievementTitle;

		list += "\n" + achievementDescription;
		list += "\nGet " + to_string(scoreValue) + "XP";


		return list;
	}

};

class Game
{
private:
	string gameName, publisherName, developerName;
	int numOfAchievement, gameNum;
	Achievement* achievement;

public:
	void AddGameInfo(string a, int n)
	{
		string numChoice;
		int num = 0;
		gameNum = n;


		cout << a;

		cout << "\n\nWhat is the name of Game " << n << "?: ";
		cin >> ws;
		getline(cin, gameName);

		cout << "\nWhat is the name of it's Publisher?: ";
		getline(cin, publisherName);

		cout << "\nWhat is the name of it's Developer?: ";
		getline(cin, developerName);

		do
		{
			cout << "\nHow Many Achievements are in " << gameName << "?: ";
			getline(cin, numChoice);

			for (int i = 0; i < numChoice.size(); i++)
			{
				num = i;
				if (isalpha(numChoice[i]))
				{

					system("CLS");

					cout << a;

					cout << "\n\nWhat is the name of Game " << n << "?: " << gameName;

					cout << "\n\nWhat is the name of it's Publisher?: " << publisherName;

					cout << "\n\nWhat is the name of it's Developer?: " << developerName;

					cout << "\n\nThere are letters in your answer. type again.";
					break;
				}
			}

		} while (isalpha(numChoice[num]));

		numOfAchievement = stoi(numChoice);

		achievement = new Achievement[stoi(numChoice)];

		for (int i = 0;i < stoi(numChoice);i++)
		{
			system("CLS");
			achievement[i].AddAchievementinfo(MenuText(a), i + 1);
		}
	}

	string GetGameDescription()
	{
		string text = "Game " + to_string(gameNum) + ": " + gameName;
		text += "\nPublisher: " + publisherName;
		text += "\nDeveloper: " + developerName;
		for (int i = 0; i < numOfAchievement; i++)
		{
			text += "\n" + GetAchievementInfo(i);
		}
		return  text;
	}

	string GetAchievementInfo(int i)
	{
		return achievement[i].GetAchievementDescription();
	}

	string MenuText(string a)
	{
		string text = a;

		text += "\n\n";

		text += "What is the name of Game " + to_string(gameNum) + "?: " + gameName;

		text += "\n\nWhat is the name of it's Publisher?: " + publisherName;

		text += "\n\nWhat is the name of it's Developer?: " + developerName;
		text += "\n\nHow Many Achievements are in " + gameName + "?: " + to_string(numOfAchievement);

		return text;
	}
};

class Platform
{
private:
	string platformName, manufacturerName;
	int numofGames, platformNum;
	Game* games;
public:
	void AddPlatformInfo(int n);
	string MenuText(string a);
	string GetPlatformDescription();
	string GetGameInfo(int n);

};



#endif // !1

