// Lab 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//this is a check

#include <iostream>
#include "Platform.h"
#include <cctype>

int main()
{
    string names, numChoice;
    int num, value;

    cout << "Hello user\n\n";

    do
    {

        cout << "How Many Platforms do you want to create?: ";
        cin >> numChoice;

        system("CLS");

        for (int i = 0; i < numChoice.size(); i++)
        {
            value = i;
            if (isalpha(numChoice[i]))
            {
                cout << "That is not a number. Please type again.\n\n";
                break;
            }
        }


    } while (isalpha(numChoice[value]));

    num = stoi(numChoice);

    Platform* platforms = new Platform[num];

    for (int i = 0; i < num; i++)
    {
        system("CLS");
        platforms[i].AddPlatformInfo(i + 1);
    }


    system("CLS");
    for (int i = 0; i < num;i++)
    {
        cout << (platforms + i)->GetPlatformDescription() << "\n\n\n";
    }

}

