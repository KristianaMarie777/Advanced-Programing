#include <direct.h>
#include <iostream>
#include <fstream>

int main()
{
	std::ofstream outfile("test.txt");

	outfile << "my text here!" << std::endl;

	outfile.close();

	_mkdir("CAT");
	system("pause");
	return 0;
}