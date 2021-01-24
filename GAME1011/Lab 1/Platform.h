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
	void AddAchievementinfo(string a,int n)
	{
<<<<<<< HEAD
<<<<<<< Updated upstream
		cout << "\n\nWhat do you like to name this Achievement\n\n";
		cin >> achievementTitle;

		cout << "\n\nWhat is this Achievement's Description?\n\n";
		cin >> achievementDescription;

		cout << "\n\nHow many points does this Achievement gives the player?\n\n";
		cin >> scoreValue;

		MainMenu();
=======

>>>>>>> Stashed changes
	}

	string GetTitle()
	{
		return achievementTitle;
	}

	string AchievementFullDescription()
	{
		string list;

		return list;
	}

<<<<<<< Updated upstream
	void RetypeAchievement()
	{
=======
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

					cout << "\n\nWhat is it's description?: " <<  achievementDescription;

					cout << "\n\nThere are letters in your answer. Type again.";
					break;
				}
			}

		} while (isalpha(numChoice[num]));

		scoreValue = stoi(numChoice);
>>>>>>> start

	}

	string GetAchievementDescription()
	{
<<<<<<< HEAD
		char choice;
		AchievementFullDescription();
=======
	void MainMenu()
	{

	}
	string Achievementlist()
	{
		string list = "\n" + achievementTitle;
>>>>>>> Stashed changes
=======
		string list = "Achievement "+to_string(achievementNum)+": "+ achievementTitle;

		list += "\n" + achievementDescription;
		list += "\nGet " + to_string(scoreValue) +"XP";
>>>>>>> start


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
<<<<<<< HEAD
<<<<<<< Updated upstream
		cout << "\nWhat Title do you want to give this Game?\n\n";

		cin >> gameName;

		cout << "\n\nWhat is the Publisher's Name?\n\n";

		cin >> publisherName;

		cout << "\n\nWhat is the Developer's Name?\n\n";

		cin >> developerName;

		MainMenu();
=======

>>>>>>> Stashed changes

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
		string list;

		return list;
	}

<<<<<<< Updated upstream
	void RetypeGame()
	{
		char choice;
		string nameChange;


		do
		{
			cout << "What do you want to retype?\n\nA.Game's Name\nB.Publisher's Name\nC.Publisher's Name\nD.None of the above. Please go back.\n\n";

			cin >> choice;

			switch (toupper(choice))
			{
			case 'A':

				do
				{
					choice = '\n';

					cout << "\n\nGame's current name is: " << gameName << endl << endl;
					cout << "Changing name to ";

					cin >> nameChange;

					while (toupper(choice) != 'A' && toupper(choice) != 'B' && toupper(choice) != 'C')
					{
						cout << "\nAre you sure you want to change Game name from " << gameName << " to " << nameChange << "?";
						cout << "\n\nA.Yes, change it\nB.No, I'd like to rewrite it\nC.I would like to leave it as " << gameName << endl << endl;

						cin >> choice;

						if (toupper(choice) == 'A')
						{
							gameName = nameChange;

							cout << "\n\nGame's name has been changed to " << gameName << endl << endl;
						}
						else if (toupper(choice) != 'C' && toupper(choice) == 'B')
						{
							cout << "\n\nChoice does not exist. Try again\n";
						}
					}

				} while (toupper(choice) != 'C' && toupper(choice) != 'A');


				break;
			case 'B':

				do
				{
					choice = '\n';

					cout << "\n\nPublisher's current name is: " << publisherName << endl << endl;
					cout << "Changing name to ";

					cin >> nameChange;

					while (toupper(choice) != 'A' && toupper(choice) != 'B' && toupper(choice) != 'C')
					{
						cout << "\nAre you sure you want to change Publisher name from " << publisherName << " to " << nameChange << "?";
						cout << "\n\nA.Yes, change it\nB.No, I'd like to rewrite it\nC.I would like to leave it as " << publisherName << endl << endl;

						cin >> choice;

						if (toupper(choice) == 'A')
						{
							publisherName = nameChange;

							cout << "\n\nPublisher's name has been changed to " << publisherName << endl << endl;
						}
						else if (toupper(choice) != 'C' && toupper(choice) != 'B')
						{
							cout << "\n\nChoice does not exist. Try again\n";
						}
					}

				} while (toupper(choice) != 'C' && toupper(choice) != 'A');
				break;

			case 'C':

				do
				{
					choice = '\n';

					cout << "\n\nDeveloper's current name is: " << developerName << endl << endl;
					cout << "Changing name to ";

					cin >> nameChange;

					while (toupper(choice) != 'A' && toupper(choice) != 'B' && toupper(choice) != 'C')
					{
						cout << "\nAre you sure you want to change Developer's name from " << developerName << " to " << nameChange << "?";
						cout << "\n\nA.Yes, change it\nB.No, I'd like to rewrite it\nC.I would like to leave it as " << developerName << endl << endl;

						cin >> choice;

						if (toupper(choice) == 'A')
						{
							developerName = nameChange;

							cout << "\n\nDeveloper's name has been changed to " << developerName << endl << endl;
						}
						else if (toupper(choice) != 'C' && toupper(choice) != 'B')
						{
							cout << "\n\nChoice does not exist. Try again\n";
						}
					}

				} while (toupper(choice) != 'C' && toupper(choice) != 'A');


				break;
			case 'D':
				// making sure Default doesn't activate when D in entered
				break;
			default:

				cout << "\nThat is not one of the choices.\n";
				break;
			}

		} while (toupper(choice) != 'C');
	}
	void MainMenu()
	{
		char choice;
		int numChoice;

		do
		{
			cout << "\n\n\nWelcome to " << gameName;
			cout << "\n\npublished by " << publisherName << endl;
			cout << "Developed by "<< developerName << endl;

			if (achievement.empty())
				cout << "It seems that you currently have no achievements. ";
			else
			{
				cout << "In-Game Achievements";
			}

			cout << "Type:\n\nA.To create a Achievement\nB.To Exit Game\nC.Change Game, Publisher's name, and Developer's name";

			if (!achievement.empty())
				cout << "\nD. Look at Achievement's infomation/Edit Achievements\n\n";
=======
		string numChoice;
		int num = 0;
		gameNum = n;


		cout << a;

		cout << "\n\nWhat is the name of Game " << n <<"?: ";
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
>>>>>>> start

		numOfAchievement = stoi(numChoice);

<<<<<<< HEAD
			if (toupper(choice) == 'A')
			{
				CreateAchievement();
			}
			else if (toupper(choice) == 'C')
			{
				RetypeGame();
			}
			else if (toupper(choice) == 'D')
			{
				if (!achievement.empty())
				{
					cout << "\n\nSorry. This option is not available at the moment.\nEnter A and Create a new Achievement to activate choice later.";
				}
				else
				{
					do
					{

						cout << "\nWhich Achievement do you want to know more about?\n\n";
=======
		achievement = new Achievement[stoi(numChoice)];

		for (int i = 0;i < stoi(numChoice);i++)
		{
			system("CLS");
			achievement[i].AddAchievementinfo(MenuText(a), i + 1);
		}
	}
>>>>>>> start

	string GetGameDescription()
	{
		string text = "Game " + to_string(gameNum) +": "+ gameName;
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

<<<<<<< HEAD
						else if (numChoice != achievement.size())
							cout << "\n\nThat is not on of the choices. Please try again.\n";

					} while (numChoice == achievement.size());
				}
			}
			else if (toupper(choice) != 'B')
			{
				cout << "\nThat is not one if the following choices. Please try again.";
			}

		} while (toupper(choice) != 'B');
=======
	void MainMenu()
	{

>>>>>>> Stashed changes
=======
		text += "\n\nWhat is the name of it's Publisher?: " + publisherName;

		text += "\n\nWhat is the name of it's Developer?: " + developerName;
		text += "\n\nHow Many Achievements are in " + gameName + "?: " + to_string(numOfAchievement);

		return text;
>>>>>>> start
	}
};

class Platform
{
private:
<<<<<<< HEAD
	string platformName, manufactuerName;
	vector<Game*> games;
public:
	Platform();
	void SetPlatformName();
	void SetManufactuer();
	void CreateGame();
	string PlatformList();
	void MainMenu();
<<<<<<< Updated upstream
=======
	string GetPlatformName();
	void SetNames();
>>>>>>> Stashed changes
=======
	string platformName, manufacturerName;
	int numofGames, platformNum;
	Game* games;
public:
	void AddPlatformInfo(int n);
	void SetPlatNum(int i);
	string MenuText(string a);
	string GetPlatformDescription();
	string GetGameInfo(int n);
>>>>>>> start

};

#endif // !1

