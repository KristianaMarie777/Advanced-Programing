#include "User.h"
#include <fstream>
#include <string>
#include <direct.h>
#include <iostream>
#include <vector>
#include "DynTempQueue.h"

User::User(string player)
{
	//creating all variables

	string names, numChoice;
	string cat;
	int nameList = 0, numchoice;

	bool itemsExist = false, notANum = false;
	DynTempStack<string> users;

	outfile.open("User.txt", ios::in);

	while (getline(outfile, names))
	{
		nameList++;
		users.push(names);
		if (!itemsExist)
		{
			itemsExist = true;
		}
	}

	outfile.close();

	//output menu
	do
	{
		users.displayList_Num();

		nameList = users.size();

		cout << nameList++ << ". New User\n" << nameList << ". Quit\n\n\nEnter choice here: ";

		getline(cin, numChoice);


		for (numchoice = 0; numchoice < numChoice.size(); numchoice++)
		{

			if (!isdigit(numChoice[numchoice]) && numChoice[numchoice] != ' ')
			{
				notANum = true;
				break;
			}
		}

		if (!notANum)
		{
			if (stoi(numChoice) > nameList && stoi(numChoice) < 0)
			{

			}
			else
			{
				if (stoi(numChoice) == nameList - 1)
				{
					string newName;

					system("CLS");

					cout << "Enter new user name here: ";
					getline(cin, newName);

					users.push(newName);

					const char* nameChar = &newName[0];
					_mkdir(nameChar);

					setName(nameChar);

					NewGame();

					setNewUser(true);
					//fstream saveFile(name + "\\getNumSaves.txt", ios::in);


				}
				else if (stoi(numChoice) == nameList)
				{
					setName(player);
				}
				else
				{
					string name;
					users.find(stoi(numChoice), name);
					cout << name << endl << endl;
					users.push(name);
					setName(name);
				}
			}
		}
	} while (notANum);

	DynTempStack<string> switchuser;

	while (!users.isEmpty())
	{
		string namehere;

		users.pop(namehere);
		switchuser.push(namehere);

	}

	outfile.open("User.txt", ios::out);


	while (!switchuser.isEmpty())
	{
		string namehere;

		switchuser.pop(namehere);
		outfile << namehere << endl;
	}

	outfile.close();
}

void User::Loadsave()
{
	fstream saveFile(name + "\\" + name + to_string(loadSave), ios::in);
	string startName;

	saveFile >> startName;
	saveFile >> passStoryScene;
	
	saveFile.close();

}

void User::NewGame()
{

	passStoryScene = false;
	direction = 0;

	fstream saveFile(name + "\\" + name + to_string(loadSave), ios::out);

	saveFile << "passStoryScene " << 0 << endl;

	saveFile.close();
}
