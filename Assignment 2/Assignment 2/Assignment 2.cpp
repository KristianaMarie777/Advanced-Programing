#include <direct.h>
#include <iostream>
#include <fstream>
#include <string>
#include "Game.h"

#include "DynTempQueue.h"

int main()
{
    //fstream myFile_Handler;
    //string myLine;

    //// File Open
    //myFile_Handler.open("File_1.txt", ios::in);

    //// Check if the file has opened
    //if (!myFile_Handler)
    //{
    //    cout << "File did not open!";
    //    exit(1);
    //}

    //myFile_Handler.seekg(ios::beg);

    //// Read the File
    //if (myFile_Handler.is_open())
    //{
    //    // Keep reading the file
    //    while (getline(myFile_Handler, myLine))
    //    {
    //        // print the line on the standard output
    //        cout << myLine << endl;
    //    }

    //}
    //else
    //{
    //    cout << "Unable to open the file!";
    //}
    //myFile_Handler.close();
    //myFile_Handler.open("File_1.txt", ios::out);

    //// Write to the file
    //myFile_Handler << endl << "1. This is another sample test File. " << endl;
    //myFile_Handler << endl << "2. This is the second line of the file. " << endl;
    //myFile_Handler << endl << "test" << endl;


    //myFile_Handler.close();

	Game::Instance()->init();

	while (Game::Instance()->isRunning())
	{
		Game::Instance()->output();
		Game::Instance()->input();
		Game::Instance()->update();
	}
	return 0;
}