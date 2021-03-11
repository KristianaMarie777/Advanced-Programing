#include <iostream>
#include "SortVector.h"
#include "SearchNext.h"
#include <cstdlib>
#include <ctime>
#include <Windows.h>

using namespace std;

template <class T>
void OptionA(SimpleVector<T>* Item, bool isInt = true, bool hasLetters = false)
{
	system("CLS");
	string optionA, menuA;
	bool redooptionA = false;
	do
	{
		menuA = Item->sprint(hasLetters);
		Item->print();

		menuA += "\nA.push_back & increase array size\nB.last_element & increase array size\nC.push_back & keep same array size\nD.last_element & keep same array size\nE.pop_back\nF.Change one of elements\nG.leave optionA\n\nEnter choice here: ";
		
		if (redooptionA)
		{
			cout << "\n\nThose aren't any of the choices. Try again.\n\n";
		}

		cout << "\nA.push_back & increase array size\nB.last_element & increase array size\nC.push_back & keep same array size\nD.last_element & keep same array size\nE.pop_back\nF.leave optionA\n\nEnter choice here: ";
		cin >> optionA;
		menuA += optionA;

		if (optionA.size() > 1)
		{
			cout << "Too many characters. Taking first character";
		}

		
		string addElements;
		bool reset = false;
		if (toupper(optionA[0]) == 'A' || toupper(optionA[0]) == 'B' || toupper(optionA[0]) == 'C' || toupper(optionA[0]) == 'D')
		{
			do
			{
				cout << "What type of value do you want to add?: ";
				cin >> addElements;

				for (int i = 0; i < addElements.size(); i++)
				{
					if (hasLetters)
					{
						if (!isalpha(addElements[i]))
						{
							reset = true;
							break;
						}
					}
					else
					{
						if (!isdigit(addElements[i]))
						{
							reset = true;
							break;
						}
					}
				}
				reset = false;

			}while (reset);

		}
		
		for (int i = 0; i < 3; i++)
		{
			Sleep(500);
			cout << ".";
			menuA += ".";

		}

		
		string whichElement;
		int value = 0;
		bool resetagain = false;
		switch (toupper(optionA[0]))
		{
		case 'A':

			if (hasLetters)
			{
				Item->push_back(addElements[0]);
			}
			else
			{
				if (isInt)
				{
					Item->push_back(stoi(addElements));
				}
				else
				{
					Item->push_back(stod(addElements));

				}
			}
			if (redooptionA)
				redooptionA = false;
			break;
		case 'B':
			if (hasLetters)
			{
				Item->last_element(addElements[0]);
			}
			else
			{
				if (isInt)
				{
					Item->last_element(stoi(addElements));
				}
				else
				{
					Item->last_element(stod(addElements));

				}
			}
			if (redooptionA)
				redooptionA = false;
			break;
		case 'C':

			if (hasLetters)
			{
				Item->push_back(addElements[0], false);
			}
			else
			{
				if (isInt)
				{
					Item->push_back(stoi(addElements), false);
				}
				else
				{
					Item->push_back(stod(addElements), false);

				}
			}
			if (redooptionA)
				redooptionA = false;
			break;
		case 'D':

			if (hasLetters)
			{
				Item->last_element(addElements[0],false);
			}
			else
			{
				if (isInt)
				{
					Item->last_element(stoi(addElements), false);
				}
				else
				{
					Item->last_element(stod(addElements), false);

				}
			}
			if (redooptionA)
				redooptionA = false;
			break;
		case 'E':
			
			Item->pop_back();

			if (redooptionA)
				redooptionA = false;
			break;
		case 'F':
			
			break;
		default:
			redooptionA = true;
			break;
		}

		system("CLS");

	} while (toupper(optionA[0]) != 'F');

}

void optionB(SearchAbleVector<int> intItem, SearchAbleVector<double> doubleItem, SearchAbleVector<char> charItem)
{

	string optionB, menu, getout;
	bool redooptionB = false, redoDeppOptionB = false, activateB = true;

	do
	{
		menu = "Values in intTable:\n" + intItem.sprint() + "Values in doubleTable:\n" + doubleItem.sprint() + "Values in charTable:\n" + charItem.sprint(true);
		cout << menu;
		if (redooptionB)
		{
			cout << "\n\nThat was not one of the choices. Try again.";
		}

		menu += "\n\nA.Search in intTable\nB.Search in doubleTable\nC.Search in charTable\nD.Exit Option B\n\n\nEnter choice here: ";
		cout << "\n\nA.Search in intTable\nB.Search in doubleTable\nC.Search in charTable\nD.Exit Option B\n\n\nEnter choice here: ";
		cin >> optionB;

		menu += optionB + "\n";

		if (optionB.size() > 1)
		{
			menu += "Too many characters. Taking first character";
			cout << "Too many characters. Taking first character";
		}

		for (int i = 0; i < 3; i++)
		{
			Sleep(500);
			cout << ".";
			menu += ".";

		}

		int result;
		string search;
		int i;

		switch (toupper(optionB[0]))
		{
		case 'A':
			
			do
			{
				if (redoDeppOptionB)
				{
					cout << menu;
					cout << "\n\nnot a int. Try again\n\n";
				}
				cout << "\n\nWhat int do you want to find: ";
				cin >> search;

				for (i = 0; i < search.size(); i++)
				{
					if (!isdigit(search[i]))
					{
						
						redoDeppOptionB == true;
						system("CLS");
						break;
					}
				}

			} while (isdigit(search[i]));

			result = intItem.findItem(stoi(search));
			if (!activateB)
				activateB = true;

			if (redooptionB)
				redooptionB = false;
			break;
		case 'B':

			do
			{
				if (redoDeppOptionB)
				{
					cout << menu;
					cout << "\n\nnot a double. Try again\n\n";
				}
				cout << "\n\nWhat double do you want to find: ";
				cin >> search;

				for (i = 0; i < search.size(); i++)
				{
					if (!isdigit(search[i]) && search[i] != '.')
					{
						redoDeppOptionB = true;
						break;
					}
				}

			} while (isdigit(search[i]) || search[i] == '.');

			result = doubleItem.findItem(stod(search));

			if (!activateB)
				activateB = true;

			if (redooptionB)
				redooptionB = false;
			break;
		case 'C':

			
			do
			{
				if (redoDeppOptionB)
				{
					cout << menu;
					cout << "\n\nnot a char. Try again\n\n";
				}
				cout << "\n\nWhat char do you want to find: ";
				cin >> search;

				for (i = 0; i < search.size(); i++)
				{
					if (!isalpha(search[i]))
					{
						redoDeppOptionB = true;
						break;
					}
				}

			} while (isalpha(search[i]));

			if (search.size() > 1)
			{
				cout << "\nToo many characters. Taking first character";
			}

			result = charItem.findItem(search[0]);

			if (!activateB)
				activateB = true;

			if (redooptionB)
				redooptionB = false;
			break;
		case 'D':
			if (redooptionB)
				redooptionB = false;
			system("CLS");
			if(activateB)
				activateB = false;
			break;
		default:
			redooptionB = true;
			system("CLS");
			if(activateB)
				activateB = false;
			break;
		}

		if (activateB)
		{
			if (result == -1)
			{
				cout << search << " was not found" << endl;
			}
			else
			{
				cout << search << " was found at subscript number " << result << endl;
			}

			cout << "enter any value to Exit: ";
			cin >> getout;
			system("CLS");
		}
		redoDeppOptionB = false;

	} while (toupper(optionB[0]) != 'D');
}

int main()
{
	srand(time(NULL));
	const int SIZE = rand()% 30+5;
	char option[] = "aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ";
	string choice;
	bool redochoice = false;
	SimpleVector<int> intTable(SIZE);
	SimpleVector<double> doubleTable(SIZE);
	SimpleVector<char> charTable(SIZE);

	for (int i = 0; i < SIZE; i++)
	{

		int intrand = rand() % 100 + 1, doublerand = rand() % 200 + 1, charrand = rand() % 52,
			intempty = rand() % 10 + 1, doubleempty = rand() % 10 + 1, charempty = rand() % 10 + 1;
		if (intempty != 1)
			intTable[i] = (i * intrand);
		if (doubleempty != 1)
			doubleTable[i] = (i * 0.14 * doublerand);

		if (charempty != 1)
			charTable[i] = option[charrand];
	}

	do
	{
		cout << "The max size is " << SIZE << endl << endl;
			
		SortVector<int> sortIntTable(intTable);
		SortVector<double> sortDoubleTable(doubleTable);
		SortVector<char> sortCharTable(charTable);

		sortIntTable.Sort();
		sortDoubleTable.Sort();
		sortCharTable.Sort();

		cout << "Values in intTable:\n";
		intTable.print();

		cout << "Values in doubleTable:\n";
		doubleTable.print();

		cout << "Values in charTable:\n";
		charTable.print();

		if (redochoice)
		{
			cout << "That was not one of the choices. Try again.\n\n";
		}

		cout << "\n\nA.add element to the end\nB.Search for item\nC.Exit \n\n\nEnter choice here: ";
		cin >> choice;

		if (choice.size() > 1)
		{
			cout << "Too many characters. Taking first character";
		}

		for (int i = 0; i < 3; i++)
		{
			Sleep(500);
			cout << ".";
			
		}

		string choice2;
		bool wrong = false;
		switch (toupper(choice[0]))
		{
		case 'A':
			system("CLS");
			
			do
			{
				if (wrong)
				{
					cout << "wrong choice. Try again\n\n";
				}

				cout << "\nWhich Table do you want to modify?\nA.intTable\nB.doubleTable\nC.charTable\nD.leave\n\nEnter choice here: ";
				
				cin >> choice2;

				if (choice.size() > 1)
				{
					cout << "Too many characters. Taking first character";
				}

				for (int i = 0; i < 3; i++)
				{
					Sleep(500);
					cout << ".";

				}

				if (isalpha(choice2[0]))
				{
					if (toupper(choice2[0]) == 'A')
					{
						OptionA(&intTable);
						choice2[0] = 'D';
					}
					else if (toupper(choice2[0]) == 'B')
					{
						OptionA(&doubleTable, false);
						choice2[0] = 'D';
					}
					else if (toupper(choice2[0]) == 'C')
					{
						OptionA(&charTable,false, true);
						choice2[0] = 'D';
					}
					else if (toupper(choice2[0]) == 'D')
					{

					}
					else
					{
						system("CLS");
						wrong = true;
					}
				}
				else
				{
					system("CLS");
					wrong = true;
				}
				
			} while (toupper(choice2[0]) != 'D');

			system("CLS");


			if (redochoice)
				redochoice = false;
			break;
		case 'B':

			system("CLS");
			cout << "To search for a item, The items will be sorted in accending order.";
			for (int i = 0; i < 5; i++)
			{
				Sleep(500);
				cout << ".";

			}
			system("CLS");

			optionB(sortIntTable, sortDoubleTable, sortCharTable);

			if (redochoice)
				redochoice = false;
			break;
		case 'C':
			if(redochoice)
				redochoice = false;
			break;
		default:
			redochoice = true;
			break;
		}

	} while (toupper(choice[0]) != 'C');

	return 0;

}
