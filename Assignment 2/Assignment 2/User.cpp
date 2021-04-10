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
	Loadsave();
}

User::~User()
{
	save();
}

void User::Loadsave()
{
	ifstream saveFile(name + "\\" + name + ".txt");
	string startName;

	//Room_name: 
	saveFile >> startName;
	getline(saveFile,roomName);
	cout << startName << "  " << roomName << endl;
	//Seen_Computer: 
	saveFile >> startName >> seenComputer;
	cout << startName << "  " << seenComputer << endl;
	//Seen_Password:
	saveFile >> startName >> seenPassword;
	cout << startName << "  " << seenPassword << endl;
	//Got_Code:
	saveFile >> startName >> gotCode;
	cout << startName << "  " << gotCode << endl;
	//Got_Key: 
	saveFile >> startName >> gotKey;
	cout << startName << "  " << gotKey << endl;
	//Got_Crank: 
	saveFile >> startName >> gotCrank;
	cout << startName << "  " << gotCrank << endl;
	//Open_Safe: 
	saveFile >> startName >> opensafe;
	cout << startName << "  " << opensafe << endl;
	//Seen_Second_Floor_Bathroom_Window: 
	saveFile >> startName >> secondwindow;
	cout << startName << "  " << secondwindow << endl;
	//Seen_First_Floor_Bathroom_Window: 
	saveFile >> startName >> firstwindow;
	cout << startName << "  " << firstwindow << endl;
	//Door_Is_Open: 
	saveFile >> startName >> doorIsOpen;
	cout << startName << "  " << doorIsOpen << endl;
	//Ending_Start : 
	saveFile >> startName >> endingStart;
	cout << startName << "  " << endingStart << endl;
	//Out_Of_Basement: 
	saveFile >> startName >> outOfBasement;
	cout << startName << "  " << outOfBasement << endl;
	//Locked_Again: 
	saveFile >> startName >> lockedagain;
	cout << startName << "  " << lockedagain << endl;
	//Boss_Room: 
	saveFile >> startName;
	getline(saveFile, bossRoom);
	cout << startName << "  " << bossRoom << endl;
	//OBJECTIVE
	while (startName != "END")
	{
		getline(saveFile,startName);
		if (startName != "END" && startName != "OBJECTIVE") { items.push_back(startName); }
		cout << startName << endl;
	}
	//ENEMY
	saveFile >> startName;
	cout << startName << endl;
	while (startName != "END")
	{
		getline(saveFile, startName);
		if (startName != "END" && startName != "ENEMY") { enemy.push(startName); }
		cout << startName << endl;
	}
	//FOLLOW
	saveFile >> startName;
	cout << startName << endl;
	while (startName != "END")
	{
		getline(saveFile, startName);
		if (startName != "END" && startName != "FOLLOW") { follow.push(startName); }
		cout << startName << endl;
	}
	
	saveFile.close();
}

void User::NewGame()
{

	fstream saveFile(name + "\\" + name + ".txt", ios::out);

	saveFile << "Room_name: Living Room" << endl;
	saveFile << "Seen_Computer: "<< 0 << endl;
	saveFile << "Seen_Password: " << 0 << endl;
	saveFile << "Got_Code: " << 0 << endl;
	saveFile << "Got_Key: " << 0 << endl;
	saveFile << "Got_Crank: " << 0 << endl;
	saveFile << "Open_Safe: " << 0 << endl;
	saveFile << "Seen_Second_Floor_Bathroom_Window: " << 0 << endl;
	saveFile << "Seen_First_Floor_Bathroom_Window: " << 0 << endl;
	saveFile << "Door_Is_Open: " << 0 << endl;
	saveFile << "Ending_Start: " << 0 << endl;
	saveFile << "Out_Of_Basement: " << 0 << endl;
	saveFile << "Locked_Again: " << 0 << endl;
	saveFile << "Boss_Room: H" << endl;
	saveFile << "OBJECTIVE" << endl;
	saveFile << "Escape the house" << endl;
	saveFile << "END" << endl;
	saveFile << "ENEMY" << endl;
	saveFile << "END" << endl;
	saveFile << "FOLLOW" << endl;
	saveFile << "END" << endl;

	saveFile.close();
}

void User::save()
{
	ofstream saveFile(name + "\\" + name + ".txt");

	saveFile << "Room_name: " << roomName << endl;
	saveFile << "Seen_Computer: " << seenComputer << endl;
	saveFile << "Seen_Password: " << seenPassword << endl;
	saveFile << "Got_Code: " << gotCode << endl;
	saveFile << "Got_Key: " << gotKey << endl;
	saveFile << "Got_Crank: " << gotCrank << endl;
	saveFile << "Open_Safe: " << opensafe << endl;
	saveFile << "Seen_Second_Floor_Bathroom_Window: " << secondwindow << endl;
	saveFile << "Seen_First_Floor_Bathroom_Window: " << firstwindow << endl;
	saveFile << "Door_Is_Open: " << doorIsOpen << endl;
	saveFile << "Ending_Start : " << endingStart << endl;
	saveFile << "Out_Of_Basement: " << outOfBasement << endl;
	saveFile << "Locked_Again: " << lockedagain << endl;
	if (bossRoom == "H") { saveFile << "Boss_Room: H" << endl; }
	else { saveFile << "Boss_Room: " << bossRoom << endl; }
	saveFile << "OBJECTIVE" << endl;
	while (!items.empty())
	{
		saveFile << items.front() << endl;
		items.pop_front();
	}
	saveFile << "END" << endl;
	saveFile << "ENEMY" << endl;
	if (!enemy.empty())
	{
		stack<string> value = enemy;
		stack<string> swaping;
		while (!value.empty())
		{
			swaping.push(value.top());
			value.pop();
		}
		while (!swaping.empty())
		{
			saveFile << swaping.top() << endl;
			swaping.pop();
		}
	}
	saveFile << "END" << endl;
	saveFile << "FOLLOW" << endl;
	if (!follow.empty())
	{
		queue<string> value = follow;
		while (!value.empty())
		{
			saveFile << value.front() << endl;
			value.pop();
		}
	}
	saveFile << "END" << endl;

	saveFile.close();
}
