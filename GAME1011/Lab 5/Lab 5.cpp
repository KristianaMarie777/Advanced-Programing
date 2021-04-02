#include <iostream>
#include "Character.h"
#include "DynTempQueue.h"
#include "DynTempStack.h"
#include <string>

using namespace std;

int main()
{
    string choice1, choice2, characterName, weaponListName[10], weaponListDes[9], abilityList[10];
    DynTempQueue<char> qChar;
    DynTempQueue<Character*> qCharacters;
    DynTempStack<char> sChar;
    DynTempStack<Character*> sCharacters;
    bool reset = false, primitive;
    char charItems;
    Human cat;
    int numOfWeapon, weaponDamage[10], numAbilities;
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
            do
            {

                switch (toupper(choice2[0]))
                {
                case 'A':


                    if (primitive)
                    {
                        qChar.enqueue(charItems);
                    }
                    else
                    {

                        Character *cat = new Human(characterName, numOfWeapon, weaponListName, weaponListDes, weaponDamage, numAbilities, abilityList);
                        qCharacters.enqueue(cat);

                        while (true)
                        {

                        }
                    
                    }
                    break;
                case 'B':


                    if (primitive)
                    {

                    }
                    else
                    {

                    }
                    break;
                case 'C':

                    break;
                default:
                    break;
                }

            } while (toupper(choice2[0]) != 'D');

        }
        else if (toupper(choice1[0]) == 'C' || toupper(choice1[0]) == 'D')
        {
            
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