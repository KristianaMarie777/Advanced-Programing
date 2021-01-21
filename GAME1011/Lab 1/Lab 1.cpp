// Lab 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Platform.h"
#include <vector>

int main()
{
    string choice;
    int numChoice;
    vector<Platform*> platforms;

    do
    {
        cout << "\n________________________________________________________________________________________________________________________\n";
        cout << "Hello user\n\n";

        if (platforms.empty())
        {
            cout << "It seems that you currently have no platforms. ";
        }
        else
        {
            cout << "Platforms that currently exist in program\n\n";
            for (int i = 0; i <= platforms.size() - 1;i++)
            {
                cout << platforms[i]->PlatformList();
            }
        }

        cout << "Do you want to:\n\nA. Create a new Platform\nB.Leave program";

        if (!platforms.empty())
            cout << "\nC.Enter Platform";

        cout << "\n\n";

        cin >> choice;

        if (choice.size() > 1)
            cout << "\n\nToo many characters. Taking first letter\n";

        if (toupper(choice[0]) == 'A')
        {
            platforms.push_back(new Platform());
        }
        else if (toupper(choice[0]) == 'C')
        {


            if (platforms.empty())
            {
                cout << "\n________________________________________________________________________________________________________________________\n";

                cout << "\n\nSorry. This option is not available at the moment.\nEnter A and Create a new game to activate choice later.";
            }
            else
            {
                do
                {
                    cout << "\n________________________________________________________________________________________________________________________\n";

                    cout << "\nWhich game do you want to Enter?\n\n";

                    for (int i = 0; i == platforms.size() - 1; i++)
                    {
                        cout << i << ". " << platforms[i]->GetPlatformName() << endl;
                    }
                    cout << platforms.size() << ". Go Back to Platform's Main Menu\n\n\nEnter choice here: ";

                    cin >> numChoice;

                    if (numChoice >= 0 && numChoice < platforms.size())
                        platforms[numChoice]->MainMenu();

                    else if (numChoice != platforms.size())
                        cout << "\n\nThat is not on of the choices.Please try again.\n";

                } while (numChoice != platforms.size());
            }
        }
        else if (toupper(choice[0]) != 'B')
        {
            cout << "\n\nNot one of the choices. Try again.";
        }

    } while(toupper(choice[0]) != 'B');
    return 0;
}

