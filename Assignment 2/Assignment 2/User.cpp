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

	bool itemsExist = false, notANum = false, notinrange = false;
	DynTempStack<string> users;

	outfile.open("User.txt", ios::in);
	// gest users
	while (getline(outfile, names))
	{
		nameList++;
		users.push(names);
		if (!itemsExist) { itemsExist = true; }
	}

	outfile.close();

	//output menu
	//loops if not one of the options
	do
	{
		//clears screen
		system("CLS");

		//outputs list
		users.displayList_Num();
		nameList = users.size();
		cout << nameList++ << ". New User\n" << nameList << ". Quit";

		//if any bool returns true the folloring will be outputed
		if (notinrange) { cout << "\n\nNot in range"; }
		if (notANum) { cout << "\n\nNot a number"; }

		cout << "\n\n\nEnter choice here: ";

		getline(cin, numChoice);

		//checks if it is a number
		for (numchoice = 0; numchoice < numChoice.size(); numchoice++)
		{

			if (!isdigit(numChoice[numchoice]) && numChoice[numchoice] != ' ')
			{
				notANum = true;
				break;
			}
		}

		//if it is a number the the following will be outputed
		if (!notANum)
		{
			//if the number in the range
			if (stoi(numChoice) > nameList && stoi(numChoice) < 0)
			{
				notANum = false;
				notinrange = true;
			}
			else
			{
				//checks which answer it was and outputs responce
				if (stoi(numChoice) == nameList - 1)
				{
					string newName;

					system("CLS");

					cout << "Enter new user name here: ";
					getline(cin, newName);

					//adds new player to end
					users.push(newName);

					//creates a folder for player
					const char* nameChar = &newName[0];
					_mkdir(nameChar);

					//sets player name
					setName(nameChar);

					//creates a new game
					NewGame();


				}
				else if (stoi(numChoice) == nameList)
				{
					//exit game
					exit(1);
				}
				else
				{
					//finds name in stack, takes it out and puts it at the top. also sets the name
					string name;

					users.find(stoi(numChoice), name);
					//cout << name << endl << endl;
					users.push(name);
					setName(name);
				}
			}
		}
	} while (notANum);

	DynTempStack<string> switchuser;

	//flips names in stack by order
	while (!users.isEmpty())
	{
		string namehere;

		users.pop(namehere);
		switchuser.push(namehere);

	}

	outfile.open("User.txt", ios::out);

	//inputs fliped items into text file for later use
	while (!switchuser.isEmpty())
	{
		string namehere;

		switchuser.pop(namehere);
		outfile << namehere << endl;
	}

	outfile.close();

	//loads save
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
	getline(saveFile,roomName);
	//Seen_Computer: 
	saveFile >> startName >> seenComputer;
	//Seen_Password:
	saveFile >> startName >> seenPassword;
	//Got_Code:
	saveFile >> startName >> gotCode;
	//Got_Key: 
	saveFile >> startName >> gotKey;
	//Got_Crank: 
	saveFile >> startName >> gotCrank;
	//Open_Safe: 
	saveFile >> startName >> opensafe;
	//Seen_Second_Floor_Bathroom_Window: 
	saveFile >> startName >> secondwindow;
	//Seen_First_Floor_Bathroom_Window: 
	saveFile >> startName >> firstwindow;
	//Door_Is_Open: 
	saveFile >> startName >> doorIsOpen;
	//Ending_Start : 
	saveFile >> startName >> endingStart;
	//Out_Of_Basement: 
	saveFile >> startName >> outOfBasement;
	//Locked_Again: 
	saveFile >> startName >> lockedagain; 
	//Text_Once:
	saveFile >> startName >> textOnce;
	//Pass_First_Scene:
	saveFile >> startName >> passfirstscene;
	//Boss_Room: 

	if (passfirstscene)
	{
		cout << passfirstscene;
	}
	else
	{
		cout << "hee";
	}
	getline(saveFile, bossRoom);
	getline(saveFile, bossRoom);
	cout << bossRoom;
	//OBJECTIVE
	while (startName != "END")
	{
		cout << startName;
		getline(saveFile,startName);
		if (startName != "END" && startName != "OBJECTIVE" && startName != "") { items.push_back(startName); }
		
	}
	//ENEMY
	saveFile >> startName;
	cout << startName << endl;
	while (startName != "END")
	{
		getline(saveFile, startName);
		if (startName != "END" && startName != "ENEMY" && startName != "") { enemy.push(startName); }
	}
	//FOLLOW
	saveFile >> startName;
	cout << startName << endl;
	while (startName != "END")
	{
		getline(saveFile, startName);
		if (startName != "END" && startName != "FOLLOW" && startName != "") { follow.push(startName); }
	}
	
	saveFile.close();
}

void User::NewGame()
{

	fstream saveFile(name + "\\" + name + ".txt", ios::out);

	saveFile << "Living Room" << endl;
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
	saveFile << "Text_Once: " << 0 << endl;
	saveFile << "Pass_First_Scene: " << 0 << endl;
	saveFile << "H" << endl;
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

	saveFile << roomName << endl;
	saveFile << "Seen_Computer: " << seenComputer << endl;
	saveFile << "Seen_Password: " << seenPassword << endl;
	saveFile << "Got_Code: " << gotCode << endl;
	saveFile << "Got_Key: " << gotKey << endl;
	saveFile << "Got_Crank: " << gotCrank << endl;
	saveFile << "Open_Safe: " << opensafe << endl;
	saveFile << "Seen_Second_Floor_Bathroom_Window: " << secondwindow << endl;
	saveFile << "Seen_First_Floor_Bathroom_Window: " << firstwindow << endl;
	saveFile << "Door_Is_Open: " << doorIsOpen << endl;
	saveFile << "Ending_Start: " << endingStart << endl;
	saveFile << "Out_Of_Basement: " << outOfBasement << endl;
	saveFile << "Locked_Again: " << lockedagain << endl;
	saveFile << "Text_Once: " << textOnce << endl;
	saveFile << "Pass_First_Scene: " << passfirstscene << endl;
	if (bossRoom == "H") { saveFile << "H" << endl; }
	else { saveFile << bossRoom << endl; }


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
