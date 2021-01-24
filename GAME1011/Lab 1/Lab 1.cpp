// Lab 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//this is a check

#include <iostream>
#include "Platform.h"
#include <cctype>

int main()
{
<<<<<<< HEAD
<<<<<<< Updated upstream
    vector<Platform*> platforms;

    platforms.push_back(new Platform());

    return 0;
=======
    string names, numChoice;
    int num, value;
    Platform* platforms;
    cout << "Hello user\n\n";

    do
    {

        cout << "How Many Platforms do you want to create?: ";
        cin >> numChoice;

        system("CLS");

        for (size_t i = 0; i < numChoice.size(); i++)
=======
    string names, numChoice;
    int num, value;
    
    cout << "Hello user\n\n";

    do
    {

        cout << "How Many Platforms do you want to create?: ";
        cin >> numChoice;

        system("CLS");

        for (int i = 0; i < numChoice.size(); i++)
>>>>>>> start
        {
            value = i;
            if (isalpha(numChoice[i]))
            {
                cout << "That is not a number. Please type again.\n\n";
<<<<<<< HEAD
            }
        }


    } while (isalpha(numChoice[value]));

    num = stoi(numChoice);

    platforms = new Platform [num];
    
    for (int i = 0; i < num; i++)
    {
        cout << platforms[i].GetPlatformName();

    }



>>>>>>> Stashed changes
=======
                break;
            }
        }


    } while (isalpha(numChoice[value]));

    num = stoi(numChoice);

    Platform* platforms = new Platform[num];

    for (int i = 0; i < num; i++)
    {
        system("CLS");
        platforms[i].AddPlatformInfo(i+1);
    }

    
    system("CLS");
    for (int i = 0; i < num;i++)
    {
        cout << (platforms+i)->GetPlatformDescription() << "\n\n\n";
    }

>>>>>>> start
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
