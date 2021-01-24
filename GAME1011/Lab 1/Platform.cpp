#include "Platform.h"
#include <cctype>
//this
void Platform::AddPlatformInfo(int n)
{
<<<<<<< HEAD
<<<<<<< Updated upstream
	cout << "\n\nWhat do you want to name the new Platform?\n\n";
	SetPlatformName();

	cout << "\nWhat is the name of the Manufactuer?\n\n";
	SetManufactuer();

	MainMenu();
}

void Platform::SetPlatformName()
{
	cin >> platformName; 
}

void Platform::SetManufactuer()
{
	cin >> manufactuerName;
}

=======
	cout << "What is the name of this Platform?: ";
	cin >> ws;
	getline(cin, platformName);

	cout << "\n\nWhat is the name the this Platform?: ";
	getline(cin, platformName);

}

>>>>>>> Stashed changes
void Platform::CreateGame()
{
	games.push_back(new Game());
}

string Platform::PlatformList()
{
<<<<<<< Updated upstream
	string itemsInPlatform;
	return itemsInPlatform;
}
//chchchchchecking
void Platform::RetypePlatform()
{
	char choice;
	string nameChange;


	do
	{
		cout << "What do you want to retype?\n\nA.Platform's Name\nB.Manufactuer's Name\nC.None of the above. Please go back.\n\n";

		cin >> choice;

		switch (toupper(choice))
=======
	string numChoice;
	int num = 0;
	platformNum = n;

	cout << "What is the name of Platform " << n << "?: ";
	cin >> ws;
	getline(cin, platformName);

	cout << "\nWhat is the name of it's Manufacturer?: ";
	getline(cin, manufacturerName);
	do
	{
		cout << "\nHow Many Games are in " << platformName << "?: ";
		getline(cin, numChoice);

		for (int i = 0; i < numChoice.size(); i++)
>>>>>>> start
		{
			num = i;
			if (isalpha(numChoice[i]))
			{
<<<<<<< HEAD
				choice = '\n';

				cout << "\n\nPlatform's current name is: " << platformName << endl << endl;
				cout << "Changing name to ";

				cin >> nameChange;

				while (toupper(choice) != 'A' && toupper(choice) != 'B' && toupper(choice) != 'C')
				{
					cout << "\nAre you sure you want to change Platform name from " << platformName << " to " << nameChange << "?";
					cout << "\n\nA.Yes, change it\nB.No, I'd like to rewrite it\nC.I would like to leave it as " << platformName << endl << endl;

					cin >> choice;

					if (toupper(choice) == 'A')
					{
						platformName = nameChange;

						cout << "\n\nPlatform's name has been changed to " << platformName << endl << endl;
					}
					else if (toupper(choice) == 'B')
					{
						cout << "\n\nPlatform's name has lefted as " << platformName << endl << endl;
					}
					else if (toupper(choice) != 'C')
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

				cout << "\n\nManufactuer's current name is: " << manufactuerName << endl << endl;
				cout << "Changing name to ";

				cin >> nameChange;

				while (toupper(choice) != 'A' && toupper(choice) != 'B' && toupper(choice) != 'C')
				{
					cout << "\nAre you sure you want to change Manufactuer name from " << manufactuerName << " to " << nameChange << "?";
					cout << "\n\nA.Yes, change it\nB.No, I'd like to rewrite it\nC.I would like to leave it as " << manufactuerName << endl << endl;

					cin >> choice;

					if (toupper(choice) == 'A')
					{
						manufactuerName = nameChange;

						cout << "\n\nManufactuer's name has been changed to " << manufactuerName << endl << endl;
					}
					else if (toupper(choice) != 'C' && toupper(choice) == 'B')
					{
						cout << "\n\nChoice does not exist. Try again\n";
					}
				}

			} while (toupper(choice) != 'C' && toupper(choice) != 'A');
			break;
=======
				system("CLS");
				cout << "What is the name of Platform " << platformNum << "?: " << platformName;
				cout << "\n\nWhat is the name of it's Manufacturer?: " << manufacturerName;
				cout << "\n\nThere are letters in your answer. type again.";
				break;
			}
		}
>>>>>>> start

	} while (isalpha(numChoice[num]));
	
	numofGames = stoi(numChoice);
	
	games = new Game[stoi(numChoice)];

	for (int i = 0;i < stoi(numChoice);i++)
	{
		system("CLS");
		games[i].AddGameInfo(MenuText(numChoice),i+1);
	}

}

<<<<<<< HEAD
	}while (toupper(choice) != 'C');
=======
void Platform::SetPlatNum(int i)
{
	platformNum = i;
>>>>>>> start
}
=======
	string itemsInPlatform = "\n" ;

	for (int i = 0; i < 10; i++)
	{

	}

	if (games.empty())
		itemsInPlatform += "\n\nThere are no games currently\n\n";
	else
	{
		itemsInPlatform += "\n\nThere are " + to_string(games.size());
		itemsInPlatform += " games currently\n\n";
	}
	return itemsInPlatform;
}
>>>>>>> Stashed changes

string Platform::MenuText(string a)
{
<<<<<<< HEAD
	char choice;
	int numChoice;
=======
	string text = "What is the name of Platform " + to_string(platformNum);
	text += "?: " + platformName;
	text += "\n\nWhat is the name of it's Manufacturer?: " + manufacturerName;
	text += "\n\nHow Many Games are in " + platformName + "?: " + a;
	return text;
}
>>>>>>> start

string Platform::GetPlatformDescription()
{
	string text= "Platform #" + to_string(platformNum)+": " + platformName;
	text += "\nManufacturer: " + manufacturerName;
	for (size_t i = 0; i < numofGames; i++)
	{
<<<<<<< HEAD
<<<<<<< Updated upstream
		cout << "\n\n\nWelcome to " << platformName;
		cout << "\n\nMade by " << manufactuerName << endl << endl;
=======
		cout << "\n________________________________________________________________________________________________________________________\n";
		cout << "\n\nWelcome to " << platformName;
		cout << "\n\nMade by " << manufacturerName << endl << endl;
>>>>>>> Stashed changes

		if (games.empty())
			cout << "It seems that you currently have no games. ";
		else
		{
			cout << "Games";
		}

		cout << "Type:\n\nA.To create a Game\nB.To Exit Platform\nC.Change Platform or Manufactur's name";

		if (!games.empty())
			cout << "\nD. Enter The Game\n\n";

		cout << "\nEnter choice here: ";
		cin >> choice;

		if (toupper(choice) == 'A')
		{
			CreateGame();
		}
<<<<<<< Updated upstream
		else if (toupper(choice) == 'C')
		{
			RetypePlatform();
		}
		else if (toupper(choice) == 'D')
		{
			if (!games.empty())
			{
=======
		else if (toupper(choice[0]) == 'D')
		{
			if (!games.empty())
			{
				cout << "\n________________________________________________________________________________________________________________________\n";
>>>>>>> Stashed changes
				cout << "\n\nSorry. This option is not available at the moment.\nEnter A and Create a new game to activate choice later.";
			}
			else
			{
<<<<<<< Updated upstream
=======
				cout << "\n________________________________________________________________________________________________________________________\n";
>>>>>>> Stashed changes
				do
				{

					cout << "\nWhich game do you want to Enter?\n\n";

					for (int i = 0; i == games.size() - 1; i++)
					{
						cout << i << ". " << games[i]->GetGameName() << endl;
					}
					cout << games.size() << ". Go Back to Platform's Main Menu\n\n\nEnter choice here: ";

					cin >> numChoice;

					if (numChoice >= 0 && numChoice < games.size())
						games[numChoice]->MainMenu();

					else if (numChoice != games.size())
						cout << "\n\nThat is not on of the choices.Please try again.\n";

				} while (numChoice == games.size());
			}
		}
		else if (toupper(choice) != 'B')
		{
			cout << "\nThat is not one if the following choices. Please try again.";
		}

	} while (toupper(choice)!='B');
=======
		text += "\n" + GetGameInfo(i);
	}
	return text;
>>>>>>> start
}
<<<<<<< Updated upstream
=======

<<<<<<< HEAD
void Platform::SetNames()
{

=======
string Platform::GetGameInfo(int n)
{
	return games[n].GetGameDescription();
>>>>>>> start
}

>>>>>>> Stashed changes
