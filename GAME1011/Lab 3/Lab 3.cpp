#include <iostream>
#include <iomanip>

using namespace std;

template <class T1>
T1 square(T1 num)
{
	return num * num;
}

int main()
{
 
	cout << setprecision(5);

	cout << "Enter an integer: ";
	int iValue;
	cin >> iValue;

	cout << "The square is " << square(iValue);
	
	cout << "\n\nEnter a double: ";
	double dValue;
	cin >> dValue;
	
	cout << "The square is " << square(dValue);

	return 0;

}
