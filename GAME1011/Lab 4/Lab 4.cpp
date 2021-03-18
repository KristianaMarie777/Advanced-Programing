// Lab 4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

bool palindrome(string word, int currentletter, bool includeSpaces = false,int lettercheck = 0)
{

    if (currentletter < 0 && lettercheck > word.size() - 1)
    {
        return true;
    }

    if (word[currentletter] != word[lettercheck])
    {
        return false;
    }
    else if (word[currentletter] == word[lettercheck])
    {
        return palindrome(word, currentletter - 1, includeSpaces,lettercheck + 1);
    }
}


void sort(int* numArray, int start, int end)
{
    int mid = end;

    cout << "start value is " << start << " end value is " << end << endl;

    for (int i = 0; i < 20; i++)
    {
        cout << numArray[i] << " ";
    }
    
    cout << endl<< endl;
    
    if (start < end)
    {
        for(int begin = start + 1; begin <= mid;)
        {
            if (numArray[mid] < numArray[begin])
            {
                int beginChange = numArray[begin], midChange = numArray[mid];
                numArray[begin] = midChange;
                numArray[mid] = beginChange;

            }

            if (numArray[begin] > numArray[start])
            {
                mid -= 1;
            }
            else
            {
                begin += 1;
            }

        }

        if (numArray[mid] < numArray[start])
        {
            int startChange = numArray[start], midChange = numArray[mid];
            numArray[start] = midChange;
            numArray[mid] = startChange;

        }

        cout << "\n\nsort(numArray, start = " << start << ", mid - 1 = " << mid - 1 << " );\n\n";
        sort(numArray, start, mid - 1);
        cout << "\n\nsort(numArray, mid + 1 = " << mid + 1 << ", end = " << end << ");\n\n";
        sort(numArray, mid + 1, end);
        
    }
}


void reverseWord(string word, int currentLetter)
{

    cout << word[currentLetter];

    if (currentLetter != 0)
    {
        reverseWord(word, currentLetter - 1);
    }

}

string reverseWordS(string word, int currentLetter)
{
    string wordR = "";
    if (currentLetter >= 0)
    {
        wordR = word[currentLetter] + reverseWordS(word, currentLetter - 1);
    }

    return wordR;

}

int main()
{
    
    srand(time(NULL));

    int numArray[20];
    string choice, word, insideChoice;
    bool reset = false;
    do
    {
        cout << "Which function do you want to try out?\n\n\nA. Palindrome\nB. QuickSort\nC. Reverse\nD. None, Exist game\n\nEnter choice here: ";

        getline(cin, choice);
        
        system("CLS");
        if (isalpha(choice[0]))
        {
            switch (toupper(choice[0]))
            {
            case 'A':
                cout << "Enter word here: ";
                //cin >> word;
                getline(cin,word);
                
                do
                {
                    if (reset)
                    {
                        cout << "Enter word here: " << word;
                        cout << "\n\nNot one of the choices. Try again.\n";
                    
                    }

                    cout << "\n\nInclude spaces?\nA. Yes\nB. No\n\nEnter choice here: ";
                    getline(cin, insideChoice);

                    if (!isalpha(insideChoice[0]))
                    {
                        reset = true;
                        system("CLS");
                    
                    }

                } while (toupper(insideChoice[0]) != 'A' || toupper(insideChoice[0]) != 'B' );

                if (reset)
                {
                    reset = false;
                }
                
                cout << "\n\nThe Word \"" << word << "\" is ";
                if (!(palindrome(word, word.size() - 1)))
                {
                    cout << "not ";
                }

                cout << "a palindrome word.\n\n";

                system("pause");

                system("CLS");

                break;
            case 'B':
                for (int i = 0; i < 20; i++)
                {
                    numArray[i] = rand() % 30;
                }

                cout << "Numbers in array are :\n";
                for (int i = 0; i < 20; i++)
                {
                    cout << numArray[i] << " ";
                }
                
                cout << endl << endl;

                system("pause");

                sort(numArray, 0, 19);

                cout << "sorted Nums is:\n";

                for (int i = 0; i < 20; i++)
                {
                    cout << numArray[i] << " ";
                }

                cout << endl << endl;
                system("pause");

                system("CLS");

                break;
            case 'C':
                cout << "Enter word here: ";
                getline(cin, word);
                
                cout << endl << endl << reverseWordS(word,word.size()-1) << endl << endl;

                system("pause");

                system("CLS");

            case 'D':
                cout << "Goodbye.\n\n";
                break;
            default:
                cout << "That was not one of the choices. Try again.\n\n";
                break;
            }
        }
        else
        {
            cout << "That is not a letter. Try again.\n\n";
        }
    } while (toupper(choice[0]) != 'D');

    return 0;
}
