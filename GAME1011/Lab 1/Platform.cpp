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

string Platform::PlatformList()
{
	return string();
}

void Platform::RetypePlatform()
{
	char choice;
	
	do
	{


		cout << "What do you want to retype?\n\nA.Platform's Name\nB.Manufactuer's Name\nC.None of the above. Please go back.\n\n";

		cin >> choice;

		switch (choice)
		{
		case 'A':
			break;
		case 'B':
			break;
		case 'C':
			cout << "hi";
			break;
		default:
			break;
		}

	}while (choice != 'C' && choice != 'c');
}
