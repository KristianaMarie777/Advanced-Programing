#include <iostream>
#include "Character.h"
#include <vector>
#include <windows.h>

using namespace std;

int main()
{
	string choice, menuReload, characterName, numChoice, weaponName, weaponDescription, abilityName;
	int characterNum = 0, numOfWeapon, numcheck, numAbilities;
	float healthBar;
	Character* characters[12];
	int num;

	

	do
	{
		num = 0;
		cout << "Welcome to Character Customization\n\n\n";

		cout << "This program will allow you to create 12 characters\n";

		cout << "Do you want to:\n\n";
		cout << "A. Create a new character\n";
		if (characterNum != 0)
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
			if (!(characterNum >= 12))
			{
				string* weaponListName, * weaponListDes, * abilityList;
				int* weaponDamage;


				abilityList = new string{ "No-Special-Abilities" };
				weaponListName = new string{ "No-Name" };
				weaponListDes = new string{ "No-Description" };
				weaponDamage = new int{ 0 };


				menuReload = "What type of Character do you want to create?: \n\nA. Human\nB. Undead\nC. Ghost";
				cout << menuReload;
				cout << endl << endl;
				do
				{
					cout << "Enter choice here: ";
					cin >> ws;
					getline(cin, choice);


					if (choice[1] != NULL)
					{
						cout << "\nToo many Characters Taking first character...\n\n";
					}

					if (toupper(choice[0]) != 'A' && toupper(choice[0]) != 'B' && toupper(choice[0]) != 'C')
					{
						system("CLS");
						cout << menuReload;
						cout << "\nThat is not one of the choices. Please try again\n\n";
					}

				} while (toupper(choice[0]) != 'A' && toupper(choice[0]) != 'B' && toupper(choice[0]) != 'C');

				system("CLS");

				choice[0] = toupper(choice[0]);

				menuReload += "\n\nEnter choice here: " + choice + "\n\nWhat is the name of this character: ";
				cout << menuReload;

				cin >> ws;
				getline(cin, characterName);

				menuReload += characterName;
				system("CLS");

				//Allows only Ghost to have modified health.
				if (choice[0] == 'C')
				{
					cout << menuReload;
					do
					{
						cout << "\nHow much health will the character have: ";

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
								cout << "\n\nThis answer has characters other than numbers. Try again.";
								break;
							}
						}
					} while (!isdigit(numChoice[numcheck]));
					healthBar = stoi(numChoice);
					menuReload += "\nHow much health will the character have: " + numChoice;
					system("CLS");
				}

				cout << menuReload << endl;

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
							system("CLS");
							cout << menuReload;
							cout << "\n\nThis answer has characters other than numbers. Try again.\n";
							break;
						}

					}
					if (isdigit(numChoice[numcheck]))
					{
						if (stoi(numChoice) > 1 && choice[0] == 'C')
						{
							system("CLS");
							cout << menuReload;
							cout << "\n\nGhost cannot have more than 1 weapons. Try again.\n";
						}
						else if (stoi(numChoice) > 2 && choice[0] == 'B')
						{
							system("CLS");
							cout << menuReload;
							cout << "\n\nUndead cannot have more than 2 weapons. Try again.\n";
						}
					}

				} while (!isdigit(numChoice[numcheck]) || ((stoi(numChoice) > 2 && choice[0] == 'B') || (stoi(numChoice) > 1 && choice[0] == 'C')));

				system("CLS");

				menuReload += "\nHow many Weapons can the character have (Can use ";
				if (choice[0] == 'A')
					menuReload += "an unlimited amount of weapons): ";
				else if (choice[0] == 'B')
					menuReload += "up to 2 weapons): ";
				else if (choice[0] == 'C')
					menuReload += "up to 1 weapon): ";

				menuReload += numChoice;
				numOfWeapon = stoi(numChoice);
				if (!(choice[0] == 'A'))
				{
					cout << menuReload;
					do
					{

						cout << "\nHow many special abilities each weapon have (Can have ";
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
								system("CLS");
								cout << menuReload;
								cout << "\n\nThis answer has characters other than numbers. Try again.";
								break;
							}
						}

						if (stoi(numChoice) > 4 && choice[0] == 'B')
						{
							system("CLS");
							cout << menuReload;
							cout << "\n\nUndead cannot have more than 4 abilities per weapon. Try Again";
						}
					} while (!isdigit(numChoice[numcheck]) || (stoi(numChoice) > 4 && choice[0] == 'B'));

					system("CLS");

					menuReload += "\nHow many special abilities each weapon have (Can have ";
					if (choice[0] == 'A')
						menuReload += "no abilities): ";
					else if (choice[0] == 'B')
						menuReload += "up to 4 abilities): ";
					else if (choice[0] == 'C')
						menuReload += "an unlimited amount of abilities): ";
					menuReload += numChoice;
					numAbilities = stoi(numChoice);
				}
				else
				{
					numAbilities = 0;
				}

				abilityList = new string[numOfWeapon * numAbilities];
				weaponListName = new string[numOfWeapon];
				weaponListDes = new string[numOfWeapon];
				weaponDamage = new int[numOfWeapon];


				for (int i = 0; i < numOfWeapon;i++)
				{
					menuReload += "\nWhat is the name of this weapon: ";

					cout << menuReload;
					cin >> ws;
					getline(cin, weaponName);

					menuReload += weaponName;

					weaponListName[i] = weaponName;


					cout << "What the weapon's description: ";
					cin >> ws;
					getline(cin, weaponDescription);

					weaponListDes[i] = weaponDescription;

					menuReload += "\nWhat the weapon's description: " + weaponDescription;

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
								system("CLS");
								cout << menuReload;
								cout << "\n\nThis answer has characters other than numbers. Try again.\n";
								break;
							}

						}

					} while (!isdigit(numChoice[numcheck]));

					system("CLS");
					menuReload += "\nHow much Damage does it inflict on enemies : ";
					weaponDamage[i] = stoi(numChoice);
					menuReload += numChoice;
					cout << menuReload << endl;

					//Keeps Humans from having abilities

					for (int a = 0; a < numAbilities; a++)
					{

						cout << "What is the name of ability #" << a + 1 << ": ";
						cin >> abilityName;
						abilityList[(i * numAbilities) + a] = abilityName;
						menuReload += "\nWhat is the name of ability #" + to_string(a + 1);
						menuReload += ": " + abilityName;
					}

					system("CLS");
				}
				cout << menuReload << endl << endl;
				//abilityList = new string( "none");

				if (choice[0] == 'A')
				{
					cout << "Creating Human Character ";
					for (int i = 0; i < 3; i++)
					{
						Sleep(500);
						cout << ".";
					}

					characters[characterNum] = new Human(characterName, numOfWeapon, weaponListName, weaponListDes, weaponDamage, numAbilities, abilityList);
				}
				else if (choice[0] == 'B')
				{
					cout << "Creating Undead Character ";
					for (int i = 0; i < 3; i++)
					{
						Sleep(500);
						cout << ".";
					}
					characters[characterNum] = new Undead(characterName, numOfWeapon, weaponListName, weaponListDes, weaponDamage, numAbilities, abilityList);
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
					characters[characterNum] = new Ghost(characterName, healthBar, numOfWeapon, weaponListName, weaponListDes, weaponDamage, numAbilities, abilityList);
				}

				system("CLS");

				characterNum += 1;
			}
			else
			{
				cout << "There are Too many characters. Delete one to create a new character ";
				for (int i = 0; i < 3; i++)
				{
					Sleep(500);
					cout << ".";
				}
			}
			break;

		case 'B':

			if (characterNum !=0)
			{

				for (int i = 0; i < characterNum; i++)
				{
					cout << i << ".";
					characters[i]->DisplayInfo();
					cout << endl << endl;
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
			if (characterNum != 0)
			{
				menuReload = "";
				for (int i = 0; i < characterNum; i++)
				{
					menuReload += to_string(i) + "." + characters[i]->getCharacterName() + "\n";

				}
				cout << menuReload;
				cout << "A.To Exit\n\n";
				do
				{
					
					
					cout << "\n\nEnter one of the following numbers or leave: \n";
					cin >> numChoice;

					for (int i = 0; i < numChoice.size(); i++)
					{
						numcheck = i;

						if (!isdigit(numChoice[i]) && !(numChoice[i]=='A'))
						{
							break;
						}
					}
					if (toupper(numChoice[0]) == 'A')
						break;
					else
					{
						if ((isdigit(numChoice[numcheck])) || !(stoi(numChoice) < 0 && stoi(numChoice) > 11))
						{
							system("CLS");
							cout << menuReload;
							cout << "A.To Exit\n\n";
							cout << "\n\nCannot read answer. Try again.\n";
						}
					}
					
	

				} while ((!(stoi(numChoice) >= 0 && stoi(numChoice) <= 11) || (!isdigit(numChoice[numcheck]))));

				if (!(isdigit(numChoice[numcheck])) || !(stoi(numChoice) < 0 && stoi(numChoice) > 11))
				{
					for (int i = stoi(numChoice); i < characterNum; i++)
					{
						if((i+1) == characterNum)
							characters[i] = new Undead;
						else
							characters[i] = characters[i + 1];

					}
					characterNum -= 1;

					cout << "Deleting";
					for (int i = 0; i < 3; i++)
					{
						Sleep(500);
						cout << ".";
					}
				}

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
		case 'D':
			cout << "GoodBye";
			for (int i = 0; i < 3; i++)
			{
				Sleep(500);
				cout << ".";
			}
			break;
		default:
			cout << "That is not any of the choices. Try again";
			for (int i = 0; i < 3; i++)
			{
				Sleep(1000);
				cout << ".";
			}
			system("CLS");
			break;
		}
	} while (toupper(choice[0]) != 'D' );

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
