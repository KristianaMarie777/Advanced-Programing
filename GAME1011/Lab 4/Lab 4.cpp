// Lab 4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

bool palindrome(string word, int currentletter, int lettercheck)
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
        return palindrome(word, currentletter - 1, lettercheck + 1);
    }
}


void sort(int* numArray, int start, int end, int first ,int total)
{
    
    cout << " start is " << start << " and end is " << end << endl;
    
    for (int i = 0; i < 20; i++)
    {
        cout << numArray[i] << " ";
    }

    
    cout << endl << endl;
    
    
    if (start != total-1)
    {
        //cout << "change";
        if (end == 0)
        {
            sort(numArray, start, total - 1, start,total);
        }

        if (start > end)
        {
            if (numArray[end] < numArray[first])
            {

                int startChange = numArray[first], endChange = numArray[end];

                numArray[first] = endChange;
                numArray[end] = startChange;

                sort(numArray, start, end, first,total);
            }

            sort(numArray, 0, end, 0,total);
        }

        
        if (numArray[end] < numArray[first] && numArray[end] < numArray[start])
        {
            
            int startChange = numArray[start], endChange = numArray[end];

            numArray[start] = endChange;
            numArray[end] = startChange;
            sort(numArray, start + 1, end, first, total);
        }

        if (numArray[start] > numArray[first])
        {
            sort(numArray, start, end - 1, first,total);
        }
        else
        {
            sort(numArray, start + 1, end, first,total);
        }
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

    for (int i = 0; i < 20; i++)
    {
        numArray[i] = rand() % 30 + 5;
    }

    cout << "Numbers in array are :\n";
    for (int i = 0; i < 20; i++)
    {
        cout << numArray[i] <<" ";
    }
    
    cout << endl << endl << endl;

    sort(numArray,0,19,0,20);

    cout << "sorted Nums is:\n";

    for (int i = 0; i < 20; i++)
    {
        cout << numArray[i] << " ";
    }
    

    return 0;
}
