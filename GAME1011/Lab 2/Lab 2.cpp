// Lab 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Character.h"
#include <vector>

using namespace std;

int main()
{
	string choice, innerChoice, characterName, numChoice, menuReload;
	float health;
	int numcheck,numAbillites;
	Character* characters;
	
	do
	{
		cout << "Welcome to Character Customization\n\n\n";

		cout << "Do you want to:\n\n";
		cout << "A. Create a new character\n";
		if (characters != NULL)
		{
			cout << "B. Look at Your characters\n";
			cout << "C. Delete Character\n";
		}
		cout << "D. Exit Character Customization\n\n";
		cout << "Enter Choice here: ";
		cin >> ws;
		getline(cin, choice);

		system("CLS");
		
		switch (choice[0])
		{
		case 'A':
			do
			{
				menuReload = "What type of Character do you want to create?: \n\nA. Human\nB. Undead\nC. Ghost\n\nEnter choice here: ";
				cout << menuReload;
				cin >> ws;
				getline(cin, choice);
				
				
				if (choice[1] != NULL)
				{
					cout << "Too many Characters Taking first character...\n\n";
				}
				if (choice[0] != 'A' && choice[0] != 'B' && choice[0] != 'C')
				{
					system("CLS");
					cout << "That is not one of the choices. Please try again\n\n";
				}
				
			} while (choice[0] != 'A' && choice[0] != 'B' && choice[0] != 'C');

			menuReload += choice + "\nWhat is the name of this character: ";
			cout << "\nWhat is the name of this character: ";

			cin >> ws;
			getline(cin, choice);
			
			menuReload += choice;
			
			
			do
			{
				cout << "How much health will the character have: ";

				//getting character's max health
				
				
				cin >> ws;
				getline(cin, numChoice);
				
				
				for (int i = 0; i < numChoice.size();i++)
				{
					numcheck = i;
					if (!isdigit(numChoice[i]))
					{
						system("CLS");
						cout << menuReload;
						
						cout << "This answer has characters other than numbers. Try again.\n\n";
						break;
					}
				}
			} while (!isdigit(numChoice[numcheck]));

			health = stoi(numChoice);

			do
			{

				cout << "How many special abilites will the character have: ";

				cin >> ws;
				getline(cin, numChoice);

				
				for (int i = 0; i < numChoice.size();i++)
				{
					numcheck = i;
					if (!isdigit(numChoice[i]))
					{
						cout << "This answer has characters other than numbers. Try again.\n\n";
						break;
					}
				}
			} while (!isdigit(numChoice[numcheck]));

			numAbillites = stoi(numChoice);

			if (choice[0] == 'A')
			{
				characters = new Undead(characterName);
			}
			else if (choice[0] == 'A')
			{

			}
			else if (choice[0] == 'A')
			{

			}
			break;

		case 'B':
		case 'C':
		case 'D':
		default:
			break;
		}
	} while (true);

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
