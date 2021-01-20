#include "Platform.h"
#include <cctype>

Platform::Platform()
{
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

void Platform::CreateGame()
{
	games.push_back(new Game());
}

string Platform::PlatformList()
{
	string itemsInPlatform;
	return itemsInPlatform;
}

void Platform::RetypePlatform()
{
	char choice;
	string nameChange;


	do
	{
		cout << "What do you want to retype?\n\nA.Platform's Name\nB.Manufactuer's Name\nC.None of the above. Please go back.\n\n";

		cin >> choice;

		switch (toupper(choice))
		{
		case 'A':

			do
			{
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


		case 'C':
			// making sure Default doesn't activate when C in entered
			break;
		default:

			cout << "\nThat is not one of the choices.\n";
			break;
		}

	}while (toupper(choice) != 'C');
}

void Platform::MainMenu()
{
	char choice;
	int numChoice;

	do
	{
		cout << "\n\n\nWelcome to " << platformName;
		cout << "\n\nMade by " << manufactuerName << endl << endl;

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
		else if (toupper(choice) == 'C')
		{
			RetypePlatform();
		}
		else if (toupper(choice) == 'D')
		{
			if (!games.empty())
			{
				cout << "\n\nSorry. This option is not available at the moment.\nEnter A and Create a new game to activate choice later.";
			}
			else
			{
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
}
