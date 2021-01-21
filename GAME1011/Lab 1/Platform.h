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
		cout << "\n________________________________________________________________________________________________________________________\n";
		cout << "\n\nWhat do you like to name this Achievement\n\n";
		cin >> ws;
		getline(cin, achievementTitle);

		cout << "\n\nWhat is this Achievement's Description?\n\n";

		getline(cin, achievementDescription);

		cout << "\n\nHow many points does this Achievement gives the player?\n\n";
		cin >> scoreValue;

		MainMenu();
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

	void RetypeAchievement()
	{
		string choice, nameChange;
		int newvalue;

		do
		{
			cout << "\n________________________________________________________________________________________________________________________\n";
			cout << "What do you want to retype?\n\nA.Achievement's Name\nB.Description's Name\nC.Score Value\nD.None of the above. Please go back.\n\n";

			cin >> choice;

			if (choice.size() > 1)
				cout << "\n\nToo many characters. Taking first letter\n";

			switch (toupper(choice[0]))
			{
			case 'A':

				do
				{
					cout << "\n________________________________________________________________________________________________________________________\n";
					choice = '\n';

					cout << "\n\nAchievement's current name is: " << achievementTitle << endl << endl;
					cout << "Changing name to ";

					cin >> ws;
					getline(cin, nameChange);

					while (toupper(choice[0]) != 'A' && toupper(choice[0]) != 'B' && toupper(choice[0]) != 'C')
					{
						cout << "\nAre you sure you want to change Achievement name from " << achievementTitle << " to " << nameChange << "?";
						cout << "\n\nA.Yes, change it\nB.No, I'd like to rewrite it\nC.I would like to leave it as " << achievementTitle << endl << endl;

						cin >> choice;

						if (choice.size() > 1)
							cout << "\n\nToo many characters. Taking first letter\n";

						if (toupper(choice[0]) == 'A')
						{
							achievementTitle = nameChange;

							cout << "\n\nGame's name has been changed to " << achievementTitle << endl << endl;
						}
						else if (toupper(choice[0]) != 'C' && toupper(choice[0]) == 'B')
						{
							cout << "\n\nChoice does not exist. Try again\n";
						}
					}

				} while (toupper(choice[0]) != 'C' && toupper(choice[0]) != 'A');


				break;
			case 'B':

				do
				{
					cout << "\n________________________________________________________________________________________________________________________\n";
					choice = '\n';

					cout << "\n\nPlease type in new description here\n\n";

					cin >> ws;
					getline(cin, nameChange);

					while (toupper(choice[0]) != 'A' && toupper(choice[0]) != 'B' && toupper(choice[0]) != 'C')
					{
						cout << "\nAre you sure you want to change the description?";
						cout << "\n\nA.Yes, change it\nB.No, I'd like to rewrite it\nC.I would like to leave it as currently is.";

						cin >> choice;

						if (choice.size() > 1)
							cout << "\n\nToo many characters. Taking first letter\n";

						if (toupper(choice[0]) == 'A')
						{
							achievementDescription = nameChange;

							cout << "\n\nDescription has been changed.\n\n";
						}
						else if (toupper(choice[0]) != 'C' && toupper(choice[0]) != 'B')
						{
							cout << "\n\nChoice does not exist. Try again\n";
						}
					}

				} while (toupper(choice[0]) != 'C' && toupper(choice[0]) != 'A');
				break;

			case 'C':

				do
				{
					cout << "\n________________________________________________________________________________________________________________________\n";
					choice = '\n';

					cout << "\n\nThe Score Value is currently: " << scoreValue << endl << endl;
					cout << "Changing it to ";

					cin >> newvalue;

					while (toupper(choice[0]) != 'A' && toupper(choice[0]) != 'B' && toupper(choice[0]) != 'C')
					{
						cout << "\nAre you sure you want to change score value from " << scoreValue << " to " << newvalue << "?";
						cout << "\n\nA.Yes, change it\nB.No, I'd like to rewrite it\nC.I would like to leave it as " << scoreValue << endl << endl;

						cin >> choice;

						if (choice.size() > 1)
							cout << "\n\nToo many characters. Taking first letter\n";

						if (toupper(choice[0]) == 'A')
						{
							scoreValue = newvalue;

							cout << "\n\nDeveloper's name has been changed to " << scoreValue << endl << endl;
						}
						else if (toupper(choice[0]) != 'C' && toupper(choice[0]) != 'B')
						{
							cout << "\n\nChoice does not exist. Try again\n";
						}
					}

				} while (toupper(choice[0]) != 'C' && toupper(choice[0]) != 'A');


				break;
			case 'D':
				// making sure Default doesn't activate when D in entered
				break;
			default:

				cout << "\nThat is not one of the choices.\n";
				break;
			}

		} while (toupper(choice[0]) != 'C');

	}

	void MainMenu()
	{
		string choice;

		do
		{
			cout << "\n________________________________________________________________________________________________________________________\n";
			AchievementFullDescription();

			cout << "Type:\n\nA. To Exit Achievement\nB. Edit Achievement\n\nEnter choice here: ";

			cin >> choice;

			if (choice.size() > 1)
				cout << "\n\nToo many characters. Taking first letter\n";

			if (toupper(choice[0]) == 'B')
			{
				RetypeAchievement();
			}
			else if (toupper(choice[0]) != 'A')
			{
				cout << "\nThat is not one of the following choices. Please try again.";
			}

		} while (toupper(choice[0]) != 'A');
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
		cout << "\n________________________________________________________________________________________________________________________\n";
		cout << "\nWhat Title do you want to give this Game?\n\n";

		cin >> ws;
		getline(cin, gameName);

		cout << "\n\nWhat is the Publisher's Name?\n\n";

		getline(cin, publisherName);

		cout << "\n\nWhat is the Developer's Name?\n\n";

		getline(cin, developerName);

		MainMenu();

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

	void RetypeGame()
	{
		string choice, nameChange;


		do
		{
			cout << "\n________________________________________________________________________________________________________________________\n";
			cout << "What do you want to retype?\n\nA.Game's Name\nB.Publisher's Name\nC.Publisher's Name\nD.None of the above. Please go back.\n\n";

			cin >> choice;

			if (choice.size() > 1)
				cout << "\n\nToo many characters. Taking first letter\n";

			switch (toupper(choice[0]))
			{
			case 'A':

				do
				{
					cout << "\n________________________________________________________________________________________________________________________\n";
					choice = '\n';

					cout << "\n\nGame's current name is: " << gameName << endl << endl;
					cout << "Changing name to ";

					cin >> ws;
					getline(cin, nameChange);

					while (toupper(choice[0]) != 'A' && toupper(choice[0]) != 'B' && toupper(choice[0]) != 'C')
					{
						cout << "\n________________________________________________________________________________________________________________________\n";
						cout << "\nAre you sure you want to change Game name from " << gameName << " to " << nameChange << "?";
						cout << "\n\nA.Yes, change it\nB.No, I'd like to rewrite it\nC.I would like to leave it as " << gameName << endl << endl;

						cin >> choice;

						if (choice.size() > 1)
							cout << "\n\nToo many characters. Taking first letter\n";

						if (toupper(choice[0]) == 'A')
						{
							gameName = nameChange;

							cout << "\n\nGame's name has been changed to " << gameName << endl << endl;
						}
						else if (toupper(choice[0]) != 'C' && toupper(choice[0]) == 'B')
						{
							cout << "\n\nChoice does not exist. Try again\n";
						}
					}

				} while (toupper(choice[0]) != 'C' && toupper(choice[0]) != 'A');


				break;
			case 'B':

				do
				{
					cout << "\n________________________________________________________________________________________________________________________\n";
					choice = '\n';

					cout << "\n\nPublisher's current name is: " << publisherName << endl << endl;
					cout << "Changing name to ";

					cin >> ws;
					getline(cin, nameChange);

					while (toupper(choice[0]) != 'A' && toupper(choice[0]) != 'B' && toupper(choice[0]) != 'C')
					{
						cout << "\n________________________________________________________________________________________________________________________\n";
						cout << "\nAre you sure you want to change Publisher name from " << publisherName << " to " << nameChange << "?";
						cout << "\n\nA.Yes, change it\nB.No, I'd like to rewrite it\nC.I would like to leave it as " << publisherName << endl << endl;

						cin >> choice;

						if (choice.size() > 1)
							cout << "\n\nToo many characters. Taking first letter\n";

						if (toupper(choice[0]) == 'A')
						{
							publisherName = nameChange;

							cout << "\n\nPublisher's name has been changed to " << publisherName << endl << endl;
						}
						else if (toupper(choice[0]) != 'C' && toupper(choice[0]) != 'B')
						{
							cout << "\n\nChoice does not exist. Try again\n";
						}
					}

				} while (toupper(choice[0]) != 'C' && toupper(choice[0]) != 'A');
				break;

			case 'C':

				do
				{
					cout << "\n________________________________________________________________________________________________________________________\n";
					choice = '\n';

					cout << "\n\nDeveloper's current name is: " << developerName << endl << endl;
					cout << "Changing name to ";

					cin >> ws;
					getline(cin, nameChange);

					while (toupper(choice[0]) != 'A' && toupper(choice[0]) != 'B' && toupper(choice[0]) != 'C')
					{
						cout << "\n________________________________________________________________________________________________________________________\n";
						cout << "\nAre you sure you want to change Developer's name from " << developerName << " to " << nameChange << "?";
						cout << "\n\nA.Yes, change it\nB.No, I'd like to rewrite it\nC.I would like to leave it as " << developerName << endl << endl;

						cin >> choice;

						if (choice.size() > 1)
							cout << "\n\nToo many characters. Taking first letter\n";

						if (toupper(choice[0]) == 'A')
						{
							developerName = nameChange;

							cout << "\n\nDeveloper's name has been changed to " << developerName << endl << endl;
						}
						else if (toupper(choice[0]) != 'C' && toupper(choice[0]) != 'B')
						{
							cout << "\n\nChoice does not exist. Try again\n";
						}
					}

				} while (toupper(choice[0]) != 'C' && toupper(choice[0]) != 'A');


				break;
			case 'D':
				// making sure Default doesn't activate when D in entered
				break;
			default:

				cout << "\nThat is not one of the choices.\n";
				break;
			}

		} while (toupper(choice[0]) != 'C');
	}
	void MainMenu()
	{
		string choice;
		int numChoice;

		do
		{
			cout << "\n________________________________________________________________________________________________________________________\n";
			cout << "\n\n\nWelcome to " << gameName;
			cout << "\n\npublished by " << publisherName << endl;
			cout << "Developed by " << developerName << endl;

			if (achievement.empty())
				cout << "It seems that you currently have no achievements. ";
			else
			{
				cout << "In-Game Achievements";
				for (int i = 0; i <= achievement.size() - 1;i++)
				{
					cout << achievement[i]->Achievementlist();
				}
			}

			cout << "Type:\n\nA.To create a Achievement\nB.To Exit Game\nC.Change Game, Publisher's name, and Developer's name";

			if (!achievement.empty())
				cout << "\nD. Look at the Achievement’s information/Edit Achievements\n\n";

			cout << "\nEnter choice here: ";
			cin >> choice;

			if (choice.size() > 1)
				cout << "\n\nToo many characters. Taking first letter\n";

			if (toupper(choice[0]) == 'A')
			{
				CreateAchievement();
			}
			else if (toupper(choice[0]) == 'C')
			{
				RetypeGame();
			}
			else if (toupper(choice[0]) == 'D')
			{
				if (achievement.empty())
				{
					cout << "\n\nSorry. This option is not available at the moment.\nEnter A and Create a new Achievement to activate choice later.";
				}
				else
				{
					do
					{
						cout << "\n________________________________________________________________________________________________________________________\n";
						cout << "\nWhich Achievement do you want to know more about?\n\n";

						for (int i = 0; i == achievement.size() - 1; i++)
						{
							cout << i << ". " << achievement[i]->GetTitle() << endl;
						}
						cout << achievement.size() << ". Go Back to Game's Main Menu\n\n\nEnter choice here: ";

						cin >> numChoice;

						if (numChoice >= 0 && numChoice < achievement.size())
							achievement[numChoice]->MainMenu();

						else if (numChoice != achievement.size())
							cout << "\n\nThat is not one of the choices. Please try again.\n";

					} while (numChoice == achievement.size());
				}
			}
			else if (toupper(choice[0]) != 'B')
			{
				cout << "\nThat is not one of the following choices. Please try again.";
			}

		} while (toupper(choice[0]) != 'B');
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
	void RetypePlatform();
	void MainMenu();
	string GetPlatformName();

};



#endif // !1

