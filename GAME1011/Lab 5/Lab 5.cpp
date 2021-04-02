#include <iostream>
#include "Character.h"
#include "DynTempQueue.h"
#include "DynTempStack.h"
#include <string>

using namespace std;

int main()
{
    string numChoice, choice1, choice2;
    DynTempQueue<char> qChar;
    DynTempQueue<Character*> qCharacters;
    DynTempStack<char> sChar;
    DynTempStack<Character*> sCharacters;
    bool reset = false, primitive;
    do
    {


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

            for (int i = 0; i < stoi(numChoice); i++)
            {
                if (primitive)
                {
                    char charItems;
                    qChar.enqueue(charItems);
                }
                else
                {
                    string characterName;
                    int health;
                    Character* character;

                    do
                    {
                        if (toupper(choice2[0]) == 'A')
                        {
                            character = new Human(characterName);
                        }
                        else if (toupper(choice2[0]) == 'B')
                        {
                            character = new Undead(characterName);
                        }
                        else if (toupper(choice2[0]) == 'C')
                        {
                            character = new Ghost(characterName, health);
                        }
                        else
                        {

                        }

                    } while (toupper(choice2[0]) == 'B' || toupper(choice2[0]) == 'A' || toupper(choice2[0]) == 'C');

                    qCharacters.enqueue(character);

                }
            }

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
                    cout << character << " ";
                }
            }
            
        }
        else if (toupper(choice1[0]) == 'C' || toupper(choice1[0]) == 'D')
        {

            for (int i = 0; i < stoi(numChoice); i++)
            {
                if (primitive)
                {
                    char charItems;
                    sChar.push(charItems);
                }
                else
                {
                    string characterName;
                    int health;
                    Character* character;

                    do
                    {
                        if (toupper(choice2[0]) == 'A')
                        {
                            character = new Human(characterName);
                        }
                        else if (toupper(choice2[0]) == 'B')
                        {
                            character = new Undead(characterName);
                        }
                        else if (toupper(choice2[0]) == 'C')
                        {
                            character = new Ghost(characterName, health);
                        }
                        else
                        {

                        }

                    } while (toupper(choice2[0]) == 'B' || toupper(choice2[0]) == 'A' || toupper(choice2[0]) == 'C');

                    sCharacters.push(character);

                }
            }

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
                    cout << character << " ";
                }
            }

        }
        else if (toupper(choice1[0]) == 'E')
        {

        }
        else
        {

        }



    } while (toupper(choice1[0]) != 'E');


    return 0;
}