//#include "IntStack.h"
#include <iostream>
//#include "DynIntStack.h"
//#include "IntQueue.h"
#include "DynTempQueue.h"

using namespace std;

int main()
{

    DynTempQueue<int> iQueue;

    cout << "Enqueue 5 items...\n";

    for (int i = 1; i <= 5; i++)
    {
        iQueue.enqueue(i * i);

    }

    cout << "The values in the queue were: \n";

    while (!iQueue.isEmpty())
    {
        int value;
        iQueue.dequeue(value);
        cout << value << " ";
    }

    return 0;
}