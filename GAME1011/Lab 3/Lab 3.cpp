#include <iostream>
#include "SortVector.h"
#include "SearchNext.h"
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	srand(time(NULL));
	const int SIZE = rand()% 30+5;

	cout << "The max size is " << SIZE << endl << endl;
	//SimpleVector<int> intTable(SIZE);
	//SimpleVector<double> doubleTable(SIZE);
	//SearchAbleVector<int> intTable(SIZE);
	//SearchAbleVector<double> doubleTable(SIZE);
	SortVector<int> intTable(SIZE);
	SortVector<double> doubleTable(SIZE);

	for (int i = 0; i < SIZE; i++)
	{

		int intrand = rand()%10 + 1, doublerand = rand() % 20 + 1, intempty = rand() % 10 + 1, doubleempty = rand() % 10 + 1;
		if (intempty != 1)
			intTable[i] = (i * intrand);
		if (doubleempty != 1)
			doubleTable[i] = (i * 0.14 * doublerand);
	}

	//SimpleVector<int> iTable2(intTable);
	SortVector<int> iTable2(intTable);



	cout << "Values in intTable:\n";
	intTable.print();

	cout << "Values in doubleTable:\n";
	doubleTable.print();
	
	cout << "Values in iTable2:\n";
	iTable2.print();

	//iTable2[10] = 20;

	//int iresult;

	cout << "Searching for number 6 in intTable.\n";
	//iresult = intTable.findItem(6);
	//if (iresult == -1)
	//{
	//	cout << "6 was not found" << endl;
	//}
	//else
	//{
	//	cout << "6 was found at subscript number " << iresult << endl;
	//}
	cout << "Sorting values\n";
	intTable.Sort();
	doubleTable.Sort();
	iTable2.Sort();

	cout << "Values in intTable:\n";
	intTable.print();

	cout << "Values in doubleTable:\n";
	doubleTable.print();

	cout << "Values in iTable2:\n";
	iTable2.print();

	SearchAbleVector<int> findi(intTable);
	SearchAbleVector<double> findd(doubleTable);
	cout << "finding 4 in intTable...";
	int iresult = findi.findItem(4);
	if (iresult == -1)
	{
		cout << "4 was not found" << endl;
	}
	else
	{
		cout << "4 was found at subscript number " << iresult << endl;
	}

	cout << "finding 2.14 in doubleTable...";
	int dresult = findd.findItem(2.14);
	
	if (dresult == -1)
	{
		cout << "2.14 was not found" << endl;
	}
	else
	{
		cout << "2.14 was found at subscript number " << dresult << endl;
	}
	return 0;

}
