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
		cout << "\n\nWhat do you like to name this Achievement\n\n";
		cin >> achievementTitle;

		cout << "\n\nWhat is this Achievement's Description?\n\n";
		cin >> achievementDescription;

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
		string list;

		return list;
	}

	void RetypeAchievement()
	{

	}

	void MainMenu()
	{
		char choice;
		AchievementFullDescription();


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
		cout << "\nWhat Title do you want to give this Game?\n\n";

		cin >> gameName;

		cout << "\n\nWhat is the Publisher's Name?\n\n";

		cin >> publisherName;

		cout << "\n\nWhat is the Developer's Name?\n\n";

		cin >> developerName;

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
		string list;

		return list;
	}

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

			cout << "\nEnter choice here: ";
			cin >> choice;

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

						for (int i = 0; i == achievement.size() - 1; i++)
						{
							cout << i << ". " << achievement[i]->GetTitle() << endl;
						}
						cout << achievement.size() << ". Go Back to Game's Main Menu\n\n\nEnter choice here: ";

						cin >> numChoice;

						if (numChoice >= 0 && numChoice < achievement.size())
							achievement[numChoice]->MainMenu();

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
	}
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
	void MainMenu();

};

#endif // !1

