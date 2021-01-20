#include "Platform.h"

Platform::Platform()
{
	RetypePlatform();
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
}

string Platform::PlatformList()
{
	return string();
}

void Platform::RetypePlatform()
{
	char choice;
	string nameChange;

	do
	{


		cout << "What do you want to retype?\n\nA.Platform's Name\nB.Manufactuer's Name\nC.None of the above. Please go back.\n\n";

		cin >> choice;

		switch (choice)
		{
		case 'A':

			do
			{
				choice = '\n';

				cout << "\n\nPlatform's current name is: " << platformName << endl << endl;
				cout << "Changing name to ";

				cin >> nameChange;

				while (choice != '1' && choice != '2' && choice != '3')
				{
					cout << "Are you sure you want to change Platform name from " << platformName << " to " << nameChange << "?";
					cout << "\n\n1.Yes, change it\n2.No, I'd like to rewrite it\n3.I would like to leave it as " << platformName << endl << endl;

					cin >> choice;

					if (choice == '1')
					{
						platformName = nameChange;

						cout << "\n\nPlatform's name has been changed to " << platformName << endl << endl;
					}
					else if (choice == '3')
					{
						cout << "\n\nPlatform's name has lefted as " << platformName << endl << endl;
					}
					else if (choice != '2')
					{
						cout << "\n\nChoice does not exist. Try again\n";
					}
				}

			} while (choice != '3' && choice != '1');


			break;
		case 'B':
			break;
		case ('C' && 'c'):
			break;
		default:
			cout << "That is not one of the choices.\n";
			break;
		}

	}while (choice != 'C' && choice != 'c');
}
