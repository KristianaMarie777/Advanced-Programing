#include <iostream>
#include "Character.h"
#include "DynTempQueue.h"
#include "DynTempStack.h"
#include <string>
#include <Windows.h>

using namespace std;

int main()
{
    //creating all variables
    string numChoice, choice1, choice2;

    //qChar stands for Queue char
    DynTempQueue<char> qChar;
    
    //qCharacters stands for Queue Character
    DynTempQueue<Character*> qCharacters;
    
    //sChar stands for Stack char
    DynTempStack<char> sChar;
    
    //sCharacters stands for Stack Character
    DynTempStack<Character*> sCharacters;

    //created the bool variables reset, and primitive
    bool reset = false, primitive;
    
    //for for loops related to the string numChoice
    int numcheck;


    do
    {
        cout << "Chooses one of the following 4 options:\n\nA. Use DynTempQueue<char>\nB. Use DynTempQueue<Character*>\nC. Use DynTempStack<char>\nD. Use DynTempStack<Character*>\nE. Exit\n\nEnter choice here: ";

        getline(cin, choice1);

        //to change primitive to true or false. primitive will be used to make sure to use either primitive or non-primitive choice 
        if (toupper(choice1[0]) == 'A' || toupper(choice1[0]) == 'C')
        {
            primitive = true;
        }
        else
        {
            primitive = false;
        }

        if (toupper(choice1[0]) == 'A' || toupper(choice1[0]) == 'B')
        {//if either A or B were chosen
            //removes main menu choices
            system("CLS");

            //do statment that will loop if numChoice has letters in it or is not a number between 0 and 10

            do
            {
                //to reset "reset" to false
                reset = false;

                //get number of items to push into the objects
                cout << "How many iteams do you want to create? (1 - 10): ";

                getline(cin, numChoice);

                //for loop to check if any on the characters in numChoice are not numbers
                for (numcheck = 0; numcheck < numChoice.size(); numcheck++)
                {

                    //if the char in the string is not a space or letter then the do loop will loop
                    if (!isdigit(numChoice[numcheck]) && numChoice[numcheck] != ' ')
                    {
                        //clear screen
                        system("CLS");
                        //set reset to true
                        reset = true;
                        cout << "Has letters in it. Try again.\n";

                        break;
                    }
                }

                //if all chars in numChoice are numbers then if statment will activate
                if (!reset)
                {
                    //if statment is true then do loop will loop
                    if (!(stoi(numChoice) <= 10 && stoi(numChoice) > 0))
                    {
                        system("CLS");
                        reset = true;

                        cout << "The number is not within range. Try again.\n";
                    }
                }

            } while (reset);

            //To tell the player what to do next before output is clear
            cout << "\n\nUsing enqueue";

            for (int i = 0; i < 3; i++)
            {

                Sleep(500);
                cout << ".";
            }

            //for loop to add all iteams
            //uses stoi to change the numbers in the string numChoice into a int
            for (int i = 0; i < stoi(numChoice); i++)
            {
                system("CLS");
                
                if (primitive)
                {//for primitive list

                    char charItems;

                    //Enter choice
                    cout << "Enter char here: ";

                    cin >> charItems;

                    //inputting choice into qChar
                    qChar.enqueue(charItems);
                }
                else
                {//for non-primitive list

                    //for the character's name and health
                    string characterName, health;
                    
                    //do loop to loop if one of the coices aren't choose.
                    do
                    {
                        //enter choice
                        cout << "Choose what type of character.\n\nA. Human\nB. Undaed\nC. Ghost\n\nEnter choice here: ";

                        getline(cin, choice2);

                        //if there are too many letter it would tell the user that it would take the first letter only
                        if (choice2.size() > 1)
                        {
                            cout << "Too many char. Taking first letter.\n\n";
                        }


                        //will go in if one of the choices were true
                        if (toupper(choice2[0]) == 'A' || toupper(choice2[0]) == 'B' || toupper(choice2[0]) == 'C')
                        {
                            //get character name
                            cout << "\n\nType in a name for this character: ";

                            getline(cin, characterName);

                            //if Ghost was chosen then if statment will activate 
                            if (toupper(choice2[0]) == 'C')
                            {
                                //do loop to loop if there are any letters in health
                                do
                                {
                                    reset = false;
                                    cout << "\n\nEnter amount of Health: ";

                                    getline(cin, health);

                                    //for loop to check if one of the characters within health had a letter
                                    for (numcheck = 0; numcheck < health.size(); numcheck++)
                                    {
                                        //if true then do loop will reset it self
                                        if (!isdigit(health[numcheck]) && health[numcheck] != ' ')
                                        {
                                            cout << "Not a number. Try again.\n";
                                            reset = true;
                                            break;
                                        }
                                    }

                                } while (reset);
                            }
                        }

                        //inputing data into qCharacters
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
                        {//if the right answer wasn't chosen
                            cout << "Not any of the choices. Try agian. \n\n";
                        }

                    } while (toupper(choice2[0]) != 'B' && toupper(choice2[0]) != 'A' && toupper(choice2[0]) != 'C');


                }

            }
            system("CLS");
            //to tell player that it would be using dequeue
            cout << "Using dequeue";
            for (int i = 0; i < 3; i++)
            {

                Sleep(500);
                cout << ".";
            }

            cout << endl << endl;

            //to output the items inside of the queue using dequeue
            if (primitive)
            {
                //if the user choice a primitive queue the following will be outputted
                while (!qChar.isEmpty())
                {
                    char value;
                    qChar.dequeue(value);
                    cout << value << " ";
                }
            }
            else
            {
                //if the user choice a non-primitive queue the following will be outputted
                while (!qCharacters.isEmpty())
                {
                    Character* character;
                    qCharacters.dequeue(character);
                    character->DisplayInfo();
                    cout << endl << endl;
                }
            }
            cout << endl << endl;
            //variable "reset" will will be now false 
            reset = false;
            //allow the user the read the output for however long they need before leaving
            system("pause");
            //clears screen when the user goes bace to the main menu
            system("CLS");
        }
        else if (toupper(choice1[0]) == 'C' || toupper(choice1[0]) == 'D')
        {//if either C or D were chosen

             //removes main menu choices
             system("CLS");

             //do statment that will loop if numChoice has letters in it or is not a number between 0 and 10

             do
             {
                 //to reset "reset" to false
                 reset = false;

                 //get number of items to push into the objects
                 cout << "How many iteams do you want to create? (1 - 10): ";

                 getline(cin, numChoice);

                 //for loop to check if any on the characters in numChoice are not numbers
                 for (numcheck = 0; numcheck < numChoice.size(); numcheck++)
                 {

                     //if the char in the string is not a space or letter then the do loop will loop
                     if (!isdigit(numChoice[numcheck]) && numChoice[numcheck] != ' ')
                     {
                         //clear screen
                         system("CLS");
                         //set reset to true
                         reset = true;
                         cout << "Has letters in it. Try again.\n";

                         break;
                     }
                 }

                 //if all chars in numChoice are numbers then if statment will activate
                 if (!reset)
                 {
                     //if statment is true then do loop will loop
                     if (!(stoi(numChoice) <= 10 && stoi(numChoice) > 0))
                     {
                         system("CLS");
                         reset = true;

                         cout << "The number is not within range. Try again.\n";
                     }
                 }

             } while (reset);

             //To tell the player what to do next before output is clear
             cout << "\n\nUsing push";

             for (int i = 0; i < 3; i++)
             {

                 Sleep(500);
                 cout << ".";
             }

             //for loop to add all iteams
             //uses stoi to change the numbers in the string numChoice into a int
             for (int i = 0; i < stoi(numChoice); i++)
             {
                 system("CLS");

                 if (primitive)
                 {//for primitive list

                     char charItems;

                     //Enter choice
                     cout << "Enter char here: ";

                     cin >> charItems;

                     //inputting choice into qChar
                     sChar.push(charItems);
                 }
                 else
                 {//for non-primitive list

                     //for the character's name and health
                     string characterName, health;

                     //do loop to loop if one of the choices aren't choose.
                     do
                     {
                         //enter choice
                         cout << "Choose what type of character.\n\nA. Human\nB. Undaed\nC. Ghost\n\nEnter choice here: ";

                         getline(cin, choice2);

                         //if there are too many letter it would tell the user that it would take the first letter only
                         if (choice2.size() > 1)
                         {
                             cout << "Too many char. Taking first letter.\n\n";
                         }


                         //will go in if one of the coices were true
                         if (toupper(choice2[0]) == 'A' || toupper(choice2[0]) == 'B' || toupper(choice2[0]) == 'C')
                         {
                             //get character name
                             cout << "\n\nType in a name for this character: ";

                             getline(cin, characterName);

                             //if Ghost was chosen then if statment will activate 
                             if (toupper(choice2[0]) == 'C')
                             {
                                 //do loop to loop if there are any letters in health
                                 do
                                 {
                                     reset = false;
                                     cout << "\n\nEnter amount of Health: ";

                                     getline(cin, health);

                                     //for loop to check if one of the characters within health had a letter
                                     for (numcheck = 0; numcheck < health.size(); numcheck++)
                                     {
                                         //if true then do loop will reset it self
                                         if (!isdigit(health[numcheck]) && health[numcheck] != ' ')
                                         {
                                             cout << "Not a number. Try again.\n";
                                             reset = true;
                                             break;
                                         }
                                     }

                                 } while (reset);
                             }
                         }

                         //inputing data into sCharacters
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
                         {//if the right answer wasn't chosen
                             cout << "Not any of the choices. Try agian. \n\n";
                         }

                     } while (toupper(choice2[0]) != 'B' && toupper(choice2[0]) != 'A' && toupper(choice2[0]) != 'C');


                 }

             }
             system("CLS");
             //to tell player that it would be using pop
             cout << "Using pop";
             for (int i = 0; i < 3; i++)
             {

                 Sleep(500);
                 cout << ".";
             }

             cout << endl << endl;

             //to output the items inside of the stack using pop
             if (primitive)
             {
                 //if the user choice a primitive stack the following will be outputted
                 while (!sChar.isEmpty())
                 {
                     char value;
                     sChar.pop(value);
                     cout << value << " ";
                 }
             }
             else
             {
                 //if the user choice a non-primitive stack the following will be outputted
                 while (!sCharacters.isEmpty())
                 {
                     Character* character;
                     sCharacters.pop(character);
                     character->DisplayInfo();
                     cout << endl << endl;
                 }
             }
             cout << endl << endl;
             //variable "reset" will will be now false 
             reset = false;
             //allow the user the read the output for however long they need before leaving
             system("pause");
             //clears screen when the user goes bace to the main menu
             system("CLS");
        }
        else if (toupper(choice1[0]) == 'E')
        {
            //if E was chosen. Nothing will be outputted and user will leave game
        }
        else
        {
            //if none of the other option were activated it will clear the screen and add a message that they did not choose any of the following option
            system("CLS");
            cout << "Not one of the choices. Try again. \n\n";
        }


    } while (toupper(choice1[0]) != 'E');


    return 0;
}