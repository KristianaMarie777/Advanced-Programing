#pragma once
#ifndef _SORTVECTOR_H_
#define _SORTVECTOR_H_

#include "SimpleVector.h"
#include "SearchNext.h"

template <class T>
class SortVector : public SimpleVector<T>
{
public:
	SortVector(int s) : SimpleVector<T>(s){}
	SortVector(SortVector& obj) : SimpleVector<T>(obj) {}
	//SortVector(SearchAbleVector& obj) : SimpleVector<T>(obj) {}
	SortVector(SimpleVector<T>& obj) : SimpleVector<T>(obj) {}
	void Sort();
private:
};

template<class T>
void SortVector<T>::Sort()
{

	bool* reset = new bool[this->size()];

	for (int i = 0; i < this->size(); i++)
	{
		reset[i] = this->isFilled(i);
	}

	for (int i = 0; i < this->size(); i++)
	{
		int switchArray = i;
		T elements = this->operator[](i);
		bool trueOrFalse = reset[i];

		if (reset[i])
		{
		
			for (int a = i + 1; a < this->size(); a++)
			{

				if (this->operator[](a) < elements || !reset[a])
				{
					switchArray = a;
					trueOrFalse = reset[a];
					elements = this->operator[](a);

					if (!reset[a])
					{
						break;
					}
					

				}

			}
		
		this->operator[](switchArray) = this->operator[](i);
		this->operator[](i) = elements;
		this->isFilled(switchArray) = reset[i];
		this->isFilled(i) = trueOrFalse;
		reset[switchArray] = reset[i];
		reset[i] = trueOrFalse;
		}

	}
}

#endif // !_SEARCHNEXT_H_

