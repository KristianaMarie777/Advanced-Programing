#include "Platform.h"
#include <cctype>

Platform::Platform()
{
	cout << "\n_____________________________________________________________\n";
	cout << "\n\nWhat do you want to name the new Platform?\n\n";

	cin >> ws;
	getline(cin, platformName);


	cout << "\nWhat is the name of the Manufacturer?\n\n";

	getline(cin, manufacturerName);


	MainMenu();
}


void Platform::CreateGame()
{
	games.push_back(new Game());
}

string Platform::PlatformList()
{
	string itemsInPlatform = "\n" + platformName;

	if (games.empty())
		itemsInPlatform += "\n\nThere are no games currently\n\n";
	else
	{
		itemsInPlatform += "\n\nThere are " + to_string(games.size());
		itemsInPlatform += " games currently\n\n";
	}
	return itemsInPlatform;
}

void Platform::RetypePlatform()
{
	string choice, nameChange;


	do
	{
		cout << "\n_____________________________________________________________\n";

		cout << "What do you want to retype?\n\nA.Platform's Name\nB.Manufactuer's Name\nC.None of the above. Please go back.\n\n";

		cin >> choice;

		if (choice.size() > 1)
			cout << "\n\nToo many characters. Taking first letter\n";

		switch (toupper(choice[0]))
		{
		case 'A':

			do
			{
				cout << "\n_____________________________________________________________\n";

				choice[0] = '\n';

				cout << "\n\nPlatform's current name is: " << platformName << endl << endl;
				cout << "Changing name to ";

				cin >> ws;
				getline(cin, nameChange);

				while (toupper(choice[0]) != 'A' && toupper(choice[0]) != 'B' && toupper(choice[0]) != 'C')
				{
					cout << "\n_____________________________________________________________\n";

					cout << "\nAre you sure you want to change Platform name from " << platformName << " to " << nameChange << "?";
					cout << "\n\nA.Yes, change it\nB.No, I'd like to rewrite it\nC.I would like to leave it as " << platformName << endl << endl;

					cin >> choice;

					if (choice.size() > 1)
						cout << "\n\nToo many characters. Taking first letter\n";

					if (toupper(choice[0]) == 'A')
					{
						platformName = nameChange;

						cout << "\n\nPlatform's name has been changed to " << platformName << endl << endl;
					}
					else if (toupper(choice[0]) == 'B')
					{
						cout << "\n\nPlatform's name has will stay as " << platformName << endl << endl;
					}
					else if (toupper(choice[0]) != 'C')
					{
						cout << "\n\nChoice does not exist. Try again\n";
					}
				}

			} while (toupper(choice[0]) != 'C' && toupper(choice[0]) != 'A');


			break;
		case 'B':

			do
			{
				cout << "\n_____________________________________________________________\n";

				choice[0] = '\n';

				cout << "\n\nManufacturer's current name is: " << manufacturerName << endl << endl;
				cout << "Changing name to ";

				cin >> ws;
				getline(cin, nameChange);

				while (toupper(choice[0]) != 'A' && toupper(choice[0]) != 'B' && toupper(choice[0]) != 'C')
				{
					cout << "\n_____________________________________________________________\n";

					cout << "\nAre you sure you want to change Manufacturer name from " << manufacturerName << " to " << nameChange << "?";
					cout << "\n\nA.Yes, change it\nB.No, I'd like to rewrite it\nC.I would like to leave it as " << manufacturerName << endl << endl;

					cin >> choice;

					if (choice.size() > 1)
						cout << "\n\nToo many characters. Taking first letter\n";

					if (toupper(choice[0]) == 'A')
					{
						manufacturerName = nameChange;

						cout << "\n\nManufactuer's name has been changed to " << manufacturerName << endl << endl;
					}
					else if (toupper(choice[0]) != 'C' && toupper(choice[0]) == 'B')
					{
						cout << "\n\nChoice does not exist. Try again\n";
					}
				}

			} while (toupper(choice[0]) != 'C' && toupper(choice[0]) != 'A');
			break;


		case 'C':
			// making sure Default doesn't activate when C in entered
			break;
		default:

			cout << "\nThat is not one of the choices.\n";
			break;
		}

	} while (toupper(choice[0]) != 'C');
}

void Platform::MainMenu()
{
	string choice;
	int numChoice;

	do
	{
		cout << "\n_____________________________________________________________\n";
		cout << "\n\nWelcome to " << platformName;
		cout << "\n\nMade by " << manufacturerName << endl << endl;

		if (games.empty())
			cout << "It seems that you currently have no games. ";
		else
		{
			cout << "Games that currently exists in " << platformName << endl;
			for (int i = 0; i <= games.size() - 1;i++)
			{
				cout << games[i]->GameList();
			}
		}

		cout << "Type:\n\nA.To create a Game\nB.To Exit Platform\nC.Change Platform or Manufacturer's name";

		if (!games.empty())
			cout << "\nD. Enter The Game";

		cout << "\n\nEnter choice here: ";
		cin >> choice;

		if (toupper(choice[0]) == 'A')
		{
			CreateGame();
		}
		else if (toupper(choice[0]) == 'C')
		{
			RetypePlatform();
		}
		else if (toupper(choice[0]) == 'D')
		{
			if (!games.empty())
			{
				cout << "\n_____________________________________________________________\n";
				cout << "\n\nSorry. This option is not available at the moment.\nEnter A and Create a new game to activate choice later.";
			}
			else
			{
				cout << "\n_____________________________________________________________\n";
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
						cout << "\n\nThat is not one of the choices.Please try again.\n";

				} while (numChoice == games.size());
			}
		}
		else if (toupper(choice[0]) != 'B')
		{
			cout << "\nThat is not one of the following choices. Please try again.";
		}

	} while (toupper(choice[0]) != 'B');
}

string Platform::GetPlatformName()
{
	return platformName;
}

