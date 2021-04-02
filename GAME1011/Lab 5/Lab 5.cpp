#include <iostream>
#include "Character.h"
#include "DynTempQueue.h"
#include "DynTempStack.h"
#include <string>
#include <Windows.h>

using namespace std;

int main()
{
    string numChoice, choice1, choice2;
    DynTempQueue<char> qChar;
    DynTempQueue<Character*> qCharacters;
    DynTempStack<char> sChar;
    DynTempStack<Character*> sCharacters;
    bool reset = false, primitive, pass;
    int numcheck;
    do
    {
        cout << "Chooses one of the following 4 options:\n\nA. Use DynTempQueue<char>\nB. Use DynTempQueue<Character*>\nC. Use DynTempStack<char>\nD. Use DynTempStack<Character*>\nE. Exit\n\nEnter choice here: ";

        getline(cin, choice1);

        if (toupper(choice1[0]) == 'A' || toupper(choice1[0]) == 'C')
        {
            primitive = true;
        }
        else
        {
            primitive = false;
        }

        if (toupper(choice1[0]) == 'A' || toupper(choice1[0]) == 'B')
        {
            system("CLS");

            do
            {

                do
                {
                    reset = false;
                    cout << "How many iteams do you want to create? (the max is 10): ";

                    getline(cin, numChoice);

                    for (numcheck = 0; numcheck < numChoice.size(); numcheck++)
                    {
                        if (!isdigit(numChoice[numcheck]) && numChoice[numcheck] != ' ')
                        {
                            system("CLS");
                            reset = true;
                            cout << "Has letters in it. Try again.\n";

                            break;
                        }
                    }

                } while (reset);
                
                if (!(stoi(numChoice) <= 10))
                {
                    system("CLS");
                    reset = true;
                
                    cout << "The number is too high. Try again.\n";
                }

            } while (reset);
            cout << "\n\nUsing enqueue";

            for (int i = 0; i < 3; i++)
            {

                Sleep(500);
                cout << ".";
            }

            for (int i = 0; i < stoi(numChoice); i++)
            {
                system("CLS");
                if (primitive)
                {
                    char charItems;

                    cout << "Enter char here: ";

                    cin >> charItems;

                    qChar.enqueue(charItems);
                }
                else
                {


                    string characterName, health;
                    
                    do
                    {
                        cout << "Choose what type of character.\n\nA. Human\nB. Undaed\nC. Ghost\n\nEnter choice here: ";

                        getline(cin, choice2);

                        if (choice2.size() > 1)
                        {
                            cout << "Too many char. Taking first letter.\n\n";
                        }

                        if (toupper(choice2[0]) == 'A' || toupper(choice2[0]) == 'B' || toupper(choice2[0]) == 'C')
                        {
                            cout << "\n\nType in a name for this character: ";

                            getline(cin, characterName);
                            if (toupper(choice2[0]) == 'C')
                                do
                                {
                                    reset = false;
                                    cout << "\n\nEnter amount of Health: ";

                                    getline(cin, health);

                                    for (numcheck = 0; numcheck < health.size(); numcheck++)
                                    {
                                        if (!isdigit(health[numcheck]) && health[numcheck] != ' ')
                                        {
                                            cout << "Not a number. Try again.\n";
                                            reset = true;
                                            break;
                                        }
                                    }

                                } while (reset);
                        }

                        if (toupper(choice2[0]) == 'A')
                        {
                            qCharacters.enqueue(new Human(characterName));
                        }
                        else if (toupper(choice2[0]) == 'B')
                        {
                            qCharacters.enqueue(new Undead(characterName));
                        }
                        else if (toupper(choice2[0]) == 'C')
                        {
                            qCharacters.enqueue(new Ghost(characterName, stoi(health)));
                        }
                        else
                        {
                            cout << "Not any of the choices. Try agian. \n\n";
                        }

                    } while (toupper(choice2[0]) != 'B' && toupper(choice2[0]) != 'A' && toupper(choice2[0]) != 'C');


                }

            }
            system("CLS");
            cout << "Using dequeue";
            for (int i = 0; i < 3; i++)
            {

                Sleep(500);
                cout << ".";
            }

            cout << endl << endl;

            if (primitive)
            {
                while (!qChar.isEmpty())
                {
                    char value;
                    qChar.dequeue(value);
                    cout << value << " ";
                }
            }
            else
            {
                while (!qCharacters.isEmpty())
                {
                    Character* character;
                    qCharacters.dequeue(character);
                    character->DisplayInfo();
                    cout << endl << endl;
                }
            }
            cout << endl << endl;
            reset = false;
            system("pause");
            system("CLS");
        }
        else if (toupper(choice1[0]) == 'C' || toupper(choice1[0]) == 'D')
        {
            system("CLS");

            do
            {

                do
                {
                    reset = false;
                    cout << "How many iteams do you want to create? (the max is 10): ";

                    getline(cin, numChoice);

                    for (numcheck = 0; numcheck < numChoice.size(); numcheck++)
                    {
                        if (!isdigit(numChoice[numcheck]) && numChoice[numcheck] != ' ')
                        {
                            system("CLS");
                            reset = true;
                            cout << "Has letters in it. Try again.\n";

                            break;
                        }

                    }

                } while (reset);

                if (!(stoi(numChoice) <= 10))
                {
                    system("CLS");
                    reset = true;

                    cout << "The number is too high. Try again.\n";
                }

            } while (reset);
            cout << "\n\nUsing enqueue";

            for (int i = 0; i < 3; i++)
            {

                Sleep(500);
                cout << ".";
            }

            for (int i = 0; i < stoi(numChoice); i++)
            {
                system("CLS");
                if (primitive)
                {
                    char charItems;

                    cout << "Enter char here: ";

                    cin >> charItems;

                    sChar.push(charItems);
                }
                else
                {


                    string characterName, health;

                    do
                    {
                        cout << "Choose what type of character.\n\nA. Human\nB. Undaed\nC. Ghost\n\nEnter choice here: ";

                        getline(cin, choice2);

                        if (choice2.size() > 1)
                        {
                            cout << "Too many char. Taking first letter.\n\n";
                        }

                        if (toupper(choice2[0]) == 'A' || toupper(choice2[0]) == 'B' || toupper(choice2[0]) == 'C')
                        {
                            cout << "\n\nType in a name for this character: ";

                            getline(cin, characterName);
                            if (toupper(choice2[0]) == 'C')
                                do
                                {
                                    reset = false;
                                    cout << "\n\nEnter amount of Health: ";

                                    getline(cin, health);

                                    for (numcheck = 0; numcheck < health.size(); numcheck++)
                                    {
                                        if (!isdigit(health[numcheck]) && health[numcheck] != ' ')
                                        {
                                            cout << "Not a number. Try again.\n";
                                            reset = true;
                                            break;
                                        }
                                    }

                                } while (reset);
                        }

                        if (toupper(choice2[0]) == 'A')
                        {
                            sCharacters.push(new Human(characterName));
                        }
                        else if (toupper(choice2[0]) == 'B')
                        {
                            sCharacters.push(new Undead(characterName));
                        }
                        else if (toupper(choice2[0]) == 'C')
                        {
                            sCharacters.push(new Ghost(characterName, stoi(health)));
                        }
                        else
                        {
                            cout << "Not any of the choices. Try agian. \n\n";
                        }

                    } while (toupper(choice2[0]) != 'B' && toupper(choice2[0]) != 'A' && toupper(choice2[0]) != 'C');


                }

            }
            system("CLS");
            cout << "Using dequeue";
            for (int i = 0; i < 3; i++)
            {

                Sleep(500);
                cout << ".";
            }

            cout << endl << endl;

            if (primitive)
            {
                while (!sChar.isEmpty())
                {
                    char value;
                    sChar.pop(value);
                    cout << value << " ";
                }
            }
            else
            {
                while (!sCharacters.isEmpty())
                {
                    Character* character;
                    sCharacters.pop(character);
                    character->DisplayInfo();
                    cout << endl << endl;
                }
            }
            cout << endl << endl;
            reset = false;
            system("pause");
            system("CLS");
        }
        else if (toupper(choice1[0]) == 'E')
        {
            
        }
        else
        {
            system("CLS");
            cout << "Not one of the choices. Try again. \n\n";
        }
    } while (toupper(choice1[0]) != 'E');


    return 0;
}