
#include <iostream>
#include "People.h"
#include <string>
#include <iomanip>
#include "Survey.h"
#include <ctime>
#include <Windows.h>

int main()
{
	string namePerson[] = { "Marie","Desiree", "Elo", "John", "Alex", "Alexander","Chris","Joey","Jen","Theo","Noir","Aya", "Mia", "Jill", "Jack", "George","Jasper","Joe","Charlottie","Lloyd" };
	string nameCollege[] = { "Seneca", "Sheridan","George Brown","Evergreen","Olds","Red Deer", "Lakeland","Reeves","Robertson","MaKami" };
	string nameProgram[] = { "Animation","Game Programming", "Game Art", "Photography","Film","Game Design","Nursing", "Computer Sience","Health Informatics","Cyber Security" };
	string streamService[] = { "Netflix","Amazon Prime", "hulu","Disney+", "Crunchyroll","Funimation" };
	string gameDevice[] = { "Wii","Nintendo Switch","PS5","PS4","Xbox", "Xbox 360" };
	int numOfPeople = 0, college, program,stream,device, leave;
	Survey survey;
	NonGamingStudent* notGaming;
	GamingStudent* gaming;
	srand(time(NULL));
	do
	{
		cout << "Welcome to the Survey Program\n\n\n";

		if (numOfPeople > 500)
		{
			cout << "Too many people. You can only put a max of 500 people into the survey.\nTry again.\n\n";
		}
		else
		{
			cout << "\n\n\n";
		}


		cout << "How many people are participating(500 max): ";
		cin >> numOfPeople;

		system("CLS");

	} while (numOfPeople > 500);

	cout << "Are you Ready to process the result? If so then type any character to proceed: ";
	cin >> leave;

	cout << endl << endl << "Loading";
	for (int i = 0; i < 3; i++)
	{
		Sleep(500);
		cout << ".";
	}
	system("CLS");

	survey.setTotalPeople(numOfPeople);
	survey.setDevicesNames(gameDevice);
	survey.setStreamNames(streamService);

	for (int i = 0;i < numOfPeople;i++)
	{
		string name = "";
		int gamer = rand() % 2;
		int age = rand() % 33 + 18;
		int semester = rand() % 10 + 1;
		float hours = rand() % 24 + 1;

		for (int a = 0; a < 2;a++)
		{
			int random = rand() % 20;
			name += namePerson[random] + " ";
		}
		college = rand() % 10;
		program = rand() % 10;

		if (gamer == 0)
		{
			stream = rand() % 6;
			notGaming = new NonGamingStudent(name,nameCollege[college],nameProgram[program],streamService[stream],semester,age,hours);
			survey.setNonGamers(*notGaming);
		}
		else
		{
			device = rand() % 6;
			gaming = new GamingStudent(name, nameCollege[college], nameProgram[program], gameDevice[device], semester, age, hours);
			survey.setGamers(*gaming);
		}
	}

	cout << survey.process();

	return 0;

}

