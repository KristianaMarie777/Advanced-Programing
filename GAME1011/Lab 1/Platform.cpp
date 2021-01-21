#include "Platform.h"
#include <cctype>

Platform::Platform()
{
	cout << "What is the name of this Platform?: ";
	cin >> ws;
	getline(cin, platformName);

	cout << "\n\nWhat is the name the this Platform?: ";
	getline(cin, platformName);

}

void Platform::CreateGame()
{
	games.push_back(new Game());
}

string Platform::PlatformList()
{
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

void Platform::MainMenu()
{
	string choice;
	int numChoice;

	do
	{
		cout << "\n________________________________________________________________________________________________________________________\n";
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
		else if (toupper(choice[0]) == 'D')
		{
			if (!games.empty())
			{
				cout << "\n________________________________________________________________________________________________________________________\n";
				cout << "\n\nSorry. This option is not available at the moment.\nEnter A and Create a new game to activate choice later.";
			}
			else
			{
				cout << "\n________________________________________________________________________________________________________________________\n";
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

void Platform::SetNames()
{

}

