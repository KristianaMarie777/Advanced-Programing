#pragma once
#ifndef _SEARCHNEXT_H_
#define _SEARCHNEXT_H_

#include "SimpleVector.h"
#include "SortVector.h"

template <class T>
class SearchAbleVector : public SimpleVector<T>
{
public:
	SearchAbleVector(int s) : SimpleVector<T>(s) {}
	SearchAbleVector(SearchAbleVector& obj) : SimpleVector<T>(obj) {};
	//SearchAbleVector(SortVector& obj) : SimpleVector<T>(obj) {};
	SearchAbleVector(SimpleVector<T>& obj) : SimpleVector<T>(obj){}
	int findItem(T);
private:
};

/*
template<class T>
SearchAbleVector<T>::SearchAbleVector(SearchAbleVector& obj) : SimpleVector<T>(obj) {}
*/

template<class T>
int SearchAbleVector<T>::findItem(T item)
{
	int num = ((this->size() - 1) / 2), num2 = ((this->size() - 1) / 2)/2, previousNum = 0;


	while (num != previousNum)
	{
		
		if (this->operator[](num) == item)
		{
			return num;
		}

		previousNum = num;

		if (this->operator[](num) < item)
		{
			num += num2;
			num2 /= 2;
		}
		else if (this->operator[](num) > item)
		{
			num -= num2;
			num2 /= 2;
		}
		
	}

	return -1;
}

#endif // !_SEARCHNEXT_H_


