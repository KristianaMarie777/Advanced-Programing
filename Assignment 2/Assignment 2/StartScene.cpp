#include "StartScene.h"
#include <fstream>
#include <string>

using namespace std;

StartScene::StartScene()
{
	user();


}

StartScene::~StartScene()
{
}

void StartScene::output()
{
}

void StartScene::update()
{
}

void StartScene::input()
{
}

void StartScene::save()
{
}

void StartScene::user()
{
	std::ofstream outfile("User.txt");
	string names, numChoice;

	int nameList = 0, numchoice;

	cout << nameList << ". New User\n";


	while (outfile << names)
	{
		cout << ++nameList << names << endl;
		userNames.add(names);
	}

	cout << ++nameList << ". Quit\n\n\nEnter choice here: ";
	cin >> numChoice;

	for (numchoice = 0; numchoice < numChoice.size(); numchoice++)
	{
		if (!isdigit(numChoice[numchoice]) && numChoice[numchoice] != ' ')
		{
			break;
		}
	}

	if (isdigit(numChoice[numchoice]) || numChoice[numchoice] != ' ')
	{
		if (stoi(numChoice) > nameList && stoi(numChoice) < 0)
		{

		}
		else
		{
			if (stoi(numChoice) == 0)
			{
				string newName;
				userNames.add(newName);


			}
			else if (stoi(numChoice) == nameList)
			{

			}
			else
			{

			}
		}
	}

	outfile.close();
}
