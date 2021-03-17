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

int sort(int* numArray, int currectSpace, int total, bool reset)
{

    if (currectSpace + 2 == total && !reset)
    {
        return 1;
    }

    if (numArray[currectSpace % (total - 1)] > numArray[currectSpace % total])
    {
        int currentNum = numArray[currectSpace % (total - 1)], nextNum = numArray[currectSpace % total];

        numArray[currectSpace % (total - 1)] = nextNum;
        numArray[currectSpace % total] = currentNum;
        if (currectSpace + 2 == total)
        {
            return sort(numArray, currectSpace + 1, total, false);
        }
        else
        {
            return sort(numArray, currectSpace + 1, total, true);
        }
    }
    else
    {
        return sort(numArray, currectSpace + 1, total, reset);
    }



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

    sort( numArray, 0, 20, false);


}
