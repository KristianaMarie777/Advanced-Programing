#pragma once
#ifndef _SEARCHNEXT_H_
#define _SEARCHNEXT_H_

#include "SimpleVector.h"
#include "SortVector.h"
#include <string>

template <class T>
class SearchAbleVector : public SimpleVector<T>
{
public:
	SearchAbleVector(int s = 0) : SimpleVector<T>(s) {}
	SearchAbleVector(SearchAbleVector& obj) : SimpleVector<T>(obj) {};
	//SearchAbleVector(SortVector& obj) : SimpleVector<T>(obj) {};
	SearchAbleVector(SimpleVector<T>& obj) : SimpleVector<T>(obj){}
	int findItem(T);
	bool searchItem(T);
private:
	void SearchingItem(bool& check,T item,int start,int end);
};

/*
template<class T>
SearchAbleVector<T>::SearchAbleVector(SearchAbleVector& obj) : SimpleVector<T>(obj) {}
*/

template<class T>
int SearchAbleVector<T>::findItem(T item)
{
	int numOfEmpty = 0;

	for (int i = 0; i < this->size(); i++)
	{
		if (!this->isFilled(i))
		{
			//cout << "true";
			numOfEmpty += 1;
		}
	}

	int num = ((this->size()-numOfEmpty)/2) + numOfEmpty, check = this->size() - numOfEmpty, wait = 0, numTimes;

	int check2 = this->size(), check3 = this->size();
	for (numTimes = 0; check3 > 0; numTimes++)
	{
		check2 /= 2;
		if (check2 == 0)
			check2 = 1;
		//cout << check3 << " " << check2 << " | ";
		check3 -= check2;
	}

	for (int i = 0; i < numTimes + 1; i++)
	{

		check /= 2;
		if (i != 0)
		{
			if (check == 0)
			{
				check = 1;
			}

			if (this->operator[](num) < item)
			{
				num += check;
				
			}
			else if (this->operator[](num) > item)
			{
				num -= check;
			}
		}

		
		//cout << this->operator[](num) <<" == " << item << " ";
		if (this->operator[](num) == item)
		{
			return num;
		}
		
	}

	return -1;
}

template<class T>
bool SearchAbleVector<T>::searchItem(T item)
{
	bool itemcheck = false;

	SearchingItem(itemcheck, item, 0, this->size() - 1);

	return itemcheck;
}

template<class T>
void SearchAbleVector<T>::SearchingItem(bool& check,T item, int start, int end)
{
	int mid = (end - start)/2 + start;
	
	//cout << this->operator[](mid) << "\n";
	
	if (this->operator[](mid) == item)
	{
		check = true;
	}

	if (start < end)
	{

		if (!check)
		{
			SearchingItem(check,item, start, mid-1);
			SearchingItem(check,item, mid+1, end);
		}
	}
}

#endif // !_SEARCHNEXT_H_


