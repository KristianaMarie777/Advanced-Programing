#pragma once
#ifndef _SIMPLEVECTOR_H_
#define _SIMPLEVECTOR_H_

#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

template <class T>
class SimpleVector
{
private:
	T* aptr;
	int arraySize;
	bool* filledElement;
	void subError() const;
	
public:
	SimpleVector(int);
	SimpleVector(const SimpleVector&);
	~SimpleVector();
	int size()
	{
		return arraySize;
	}
	T& operator[](int);
	void print() const;
	string sprint(bool chars = false)const;
	void push_back(T, bool increaseSize = true);
	void last_element(T, bool increaseSize = true);
	void pop_back();
	bool& isFilled(const int a) const { return filledElement[a]; }
};

template<class T>
SimpleVector<T>::SimpleVector(int s)
{
	arraySize = s;
	aptr = new T[s];
	filledElement = new bool[s];
	for (int i = 0; i < arraySize; i++)
	{
		aptr[i] = T();
		filledElement[i] = false;
	}
}

template<class T>
SimpleVector<T>::SimpleVector(const SimpleVector& obj)
{
	arraySize = obj.arraySize;
	aptr = new T[arraySize];
	filledElement = new bool[arraySize];

	for (int i = 0; i < arraySize; i++)
	{
		aptr[i] = obj.aptr[i];
		filledElement[i] = obj.isFilled(i);
	}
}

template<class T>
SimpleVector<T>::~SimpleVector()
{
	if (arraySize > 0)
	{
		delete[] aptr;
		delete[] filledElement;
	}
}

template<class T>
void SimpleVector<T>::subError() const
{
	cout << "ERROR: Subscript out of range.\n";
	exit(0);
}

template<class T>
T& SimpleVector<T>::operator[](int sub)
{
	if (sub < 0 || sub >= arraySize)
	{
		subError();
	}
	
	filledElement[sub] = true;
	
	return aptr[sub];
}

template<class T>
void SimpleVector<T>::print() const
{
	for (int i = 0; i < arraySize; i++)
	{
		if(!filledElement[i])
			cout << "--Empty-- ";
		else
		{
			cout << aptr[i] << " ";
			
		}
	}
	cout << endl;
}

template<class T>
string SimpleVector<T>::sprint(bool chars) const
{
	string info = "";
	for (int i = 0; i < arraySize; i++)
	{

		if (!filledElement[i])
			info += "--Empty--";
		else
		{
			if (chars)
				info += aptr[i];
			else
				info += to_string(aptr[i]);
			
		}

		info += " ";
	}
	info += "\n";
	return info;
}

template<class T>
void SimpleVector<T>::push_back(T item, bool increaseSize)
{
	int numEmptySpaces;
	bool emptyspaces = false;
	
	for (int i = 0; i < arraySize; i++)
	{
		
		if (!filledElement[i])
		{
			numEmptySpaces = i;
			if (!emptyspaces)
				emptyspaces = true;

		}

	}

	if (!emptyspaces)
	{

		cout << "Array is full.";

		if (increaseSize)
		{
			cout << " Increasing arraySize to " << arraySize + 1;
			T* aptrItems = new T[arraySize];
			bool* trueOrFalse = new bool[arraySize];

			for (int i = 0; i < arraySize; i++)
			{
				aptrItems[i] = aptr[i];
				trueOrFalse[i] = filledElement[i];
			}

			arraySize += 1;
			aptr = new T[arraySize];
			filledElement = new bool[arraySize];

			for (int i = 0; i < arraySize - 1; i++)
			{
				aptr[i] = aptrItems[i];
				filledElement[i] = trueOrFalse[i];
			}

			aptr[arraySize - 1] = T(item);
			filledElement[arraySize - 1] = true;
		}
		else
		{
			for (int i = 0; i < arraySize; i++)
			{
				if(i == arraySize-1)
				{
					aptr[i] = item;
					filledElement[i] = true;
				}
				else
				{
					aptr[i] = aptr[i + 1];
					filledElement[i] = filledElement[i + 1];
				}

			}
		}
		cout << endl;
	}
	else
	{
		
		for (int i = numEmptySpaces; i < arraySize; i++)
		{
			if (i == arraySize - 1)
			{
				aptr[i] = item;
			}
			else
			{
				aptr[i] = aptr[i + 1];
			}


			if (!filledElement[i])
				filledElement[i] = true;
		}
	}
}

template<class T>
void SimpleVector<T>::pop_back()
{
	
	if (arraySize > 0)
	{
		T* aptrIteams = new T[arraySize];
		bool* trueOrfalse = new bool[arraySize];

		for (int i = 0; i < arraySize; i++)
		{
			aptrIteams[i] = aptr[i];
			trueOrfalse[i] = filledElement[i];
		}

		arraySize -= 1;
		delete[] aptr;
		delete[] filledElement;

		aptr = new T[arraySize];
		filledElement = new bool[arraySize];

		for (int i = 0; i < arraySize; i++)
		{
			aptr[i] = aptrIteams[i];
			filledElement[i] = trueOrfalse[i];
		}

	}

}

template<class T>
void SimpleVector<T>::last_element(T iteam, bool increaseSize)
{
	int num = arraySize;
	bool check = false, notLast = false, emptyspaces = false;

	for (int i = 0; i < arraySize; i++)
	{

		if (!filledElement[i] && !check)
		{
			num = i;
			check = true;
			notLast = false;
			if (!emptyspaces)
				emptyspaces = true;

		}
		else if (filledElement[i] && check)
		{
			check = false;
			notLast = true;
		}

	}

	if ((!emptyspaces || notLast) || !emptyspaces && notLast)
	{
		push_back(iteam, increaseSize);
	}
	else
	{
		aptr[num] = iteam;
		filledElement[num] = true;
	}
}

#endif
