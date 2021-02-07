#include <iostream>
#include "Character.h"
#include <vector>
#include <windows.h>

using namespace std;

int main()
{
	
	//string choice, innerChoice, characterName, numChoice, menuReload, title, weaponName;
	//string* abilityList, *weaponList, * weaponSpecialAlist, *weaponDescription;
	//int health, numcheck,numAbillites, damageValue,weaponSpecialA, numWeapon,characterNum = 0;
	string choice, menuReload, characterName, numChoice, weaponName, weaponDescription;
	int characterNum = 0, numOfWeapon, numcheck, numAbilities;
	float healthBar;
	Character* characters  = new Undead;
	int num;
	bool characterExists = false;

	

	do
	{
		num = 0;
		cout << "Welcome to Character Customization\n\n\n";

		cout << "Do you want to:\n\n";
		cout << "A. Create a new character\n";
		if (characterExists)
		{
			cout << "B. Look at Your characters\n";
			cout << "C. Delete Character\n";
		}
		cout << "D. Exit Character Customization\n\n";
		cout << "Enter Choice here: ";
		cin >> ws;
		getline(cin, choice);

		system("CLS");
		
		switch (toupper(choice[0]))
		{
		case 'A':
			string * weaponListName, * weaponListDes, * abilityList;
			int* weaponDamage;


			abilityList = new string{ "No-Special-Abilities" };
			numAbilities = new int{ 0 };
			weaponListName = new string{"No-Name"};
			weaponListDes = new string{ "No-Description" };
			weaponDamage = new int{ 0 };
			

			menuReload = "What type of Character do you want to create?: \n\nA. Human\nB. Undead\nC. Ghost\n\nEnter choice here: ";
			cout << menuReload;

			do
			{

				cin >> ws;
				getline(cin, choice);


				if (choice[1] != NULL)
				{
					cout << "Too many Characters Taking first character...\n\n";
				}

				if (toupper(choice[0]) != 'A' && toupper(choice[0]) != 'B' && toupper(choice[0]) != 'C')
				{
					system("CLS");
					cout << menuReload;
					cout << "That is not one of the choices. Please try again\n\n";
				}
				
			} while (toupper(choice[0]) != 'A' && toupper(choice[0]) != 'B' && toupper(choice[0]) != 'C');

			choice[0] = toupper(choice[0]);

			menuReload += choice + "\nWhat is the name of this character: ";
			cout << "\nWhat is the name of this character: ";

			cin >> ws;
			getline(cin, characterName);
			
			menuReload += characterName;
			
			//Allows only Ghost to have modified health.
			if (choice[0] == 'C')
			{
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
				healthBar = stoi(numChoice);
			}

			do
			{
				cout << "How many Weapons can the character have (Can use ";
				if (choice[0] == 'A')
					cout << "an unlimited amount of weapons): ";
				else if (choice[0] == 'B')
					cout << "up to 2 weapons): ";
				else if (choice[0] == 'C')
					cout << "up to 1 weapon): ";

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

				if (stoi(numChoice) > 1 && choice[0] == 'C')
				{
					cout << "Ghost cannot have more than 1 weapons. Try again.\n\n";
				}
				else if (stoi(numChoice) > 2 && choice[0] == 'B')
				{
					cout << "Undead cannot have more than 2 weapons. Try again.\n\n";
				}

			} while (!isdigit(numChoice[numcheck]) || (stoi(numChoice) > 2 && choice[0] == 'B') ||(stoi(numChoice) > 1 && choice[0] == 'C'));

			numOfWeapon = stoi(numChoice);


			do
			{

				cout << "How many special abilities each weapon have (Can have ";
				if (choice[0] == 'A')
					cout << "no abilities): ";
				else if (choice[0] == 'B')
					cout << "up to 4 abilities): ";
				else if (choice[0] == 'C')
					cout << "an unlimited amount of abilities): ";

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

			numAbilities = stoi(numChoice);

			abilityList = new string[numOfWeapon*numAbilities];
			weaponListName = new string[numOfWeapon];
			weaponListDes = new string[numOfWeapon];
			weaponDamage = new int[numOfWeapon];

			for (int i = 0; i < numOfWeapon;i++)
			{
				cout << "What is the name of this weapon: ";
				cin >> ws;
				getline(cin, weaponName);

				weaponListName[i] = weaponName;

				cout << "What the weapon's description: ";
				cin >> ws;
				getline(cin, weaponDescription);

				weaponListDes[i] =weaponDescription;
				

				do
				{
					cout << "How much Damage does it inflict on enemies: ";
					cin >> ws;
					getline(cin, numChoice);

					for (int i = 0; i < numChoice.size(); i++)
					{

						numcheck = i;
						if (!isdigit(numChoice[numcheck]))
						{
							break;
						}

					}

				} while (!isdigit(numChoice[numcheck]));

				weaponDamage[i] =stoi(numChoice);

				//Keeps Humans from having abilities

				for (int a = 0; a < numAbilities[i]; a++)
				{
					cout << "What is the name of ability #" << a+1 << ": ";
					cin >> abilityName[a];
				}

			}
			//abilityList = new string( "none");
			cout << endl << sizeof(weaponListDes) << endl;
			if (choice[0] == 'A')
			{
				cout << "Creating Undead Character ";
				for (int i = 0; i < 3; i++)
				{
					Sleep(500);
					cout << ".";
				}

				characters = {new Human(characterName,numOfWeapon,weaponListName,weaponListDes,weaponDamage,numAbilities,abilityList) };
			}
			else if (choice[0] == 'B')
			{
				cout << "Creating Undead Character ";
				for (int i = 0; i < 3; i++)
				{
					Sleep(500);
					cout << ".";
				}
				characters = {new Undead(characterName,numOfWeapon,weaponListName,weaponListDes,weaponDamage,numAbilities,abilityList) };
				cout << "pass\n";
			}
			else if (choice[0] == 'C')
			{
				cout << "Creating Ghost Character ";
				for (int i = 0; i < 3; i++)
				{
					Sleep(500);
					cout << ".";
				}
				characters = new Ghost(characterName,healthBar,numOfWeapon,weaponListName,weaponListDes,weaponDamage,numAbilities,abilityList);
			}

			system("CLS");

			characterExists = true;

			characterNum += 1;

			break;

		case 'B':

			if (characterExists)
			{

				for (int i = 0; i < characterNum; i++)
				{
					characters[i].DisplayInfo();
				}
				cout << "\n\nPress enter to Exit\n";
				cin.ignore();
			}
			else
			{
				cout << "This choice is not available yet. Create a new character to activate it\n resetting choices ";
				for (int i = 0; i < 3; i++)
				{
					Sleep(500);
					cout << ".";
				}
			}

			system("CLS");
			break;
		case 'C':
			characterNum -= 1;
			break;
		case 'D':
			break;
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
