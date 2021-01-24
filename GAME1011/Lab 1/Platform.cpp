#include "Platform.h"
#include <cctype>

void Platform::AddPlatformInfo(int n)
{
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
		{
			num = i;
			if (isalpha(numChoice[i]))
			{
				system("CLS");
				cout << "What is the name of Platform " << platformNum << "?: " << platformName;
				cout << "\n\nWhat is the name of it's Manufacturer?: " << manufacturerName;
				cout << "\n\nThere are letters in your answer. type again.";
				break;
			}
		}

	} while (isalpha(numChoice[num]));

	numofGames = stoi(numChoice);

	games = new Game[stoi(numChoice)];

	for (int i = 0;i < stoi(numChoice);i++)
	{
		system("CLS");
		games[i].AddGameInfo(MenuText(numChoice), i + 1);
	}

}

void Platform::SetPlatNum(int i)
{
	platformNum = i;
}

string Platform::MenuText(string a)
{
	string text = "What is the name of Platform " + to_string(platformNum);
	text += "?: " + platformName;
	text += "\n\nWhat is the name of it's Manufacturer?: " + manufacturerName;
	text += "\n\nHow Many Games are in " + platformName + "?: " + a;
	return text;
}

string Platform::GetPlatformDescription()
{
	string text = "Platform #" + to_string(platformNum) + ": " + platformName;
	text += "\nManufacturer: " + manufacturerName;
	for (size_t i = 0; i < numofGames; i++)
	{
		text += "\n" + GetGameInfo(i);
	}
	return text;
}

string Platform::GetGameInfo(int n)
{
	return games[n].GetGameDescription();
}

