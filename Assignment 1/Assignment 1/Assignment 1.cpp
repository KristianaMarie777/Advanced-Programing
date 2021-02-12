
#include <iostream>
#include "People.h"
#include <string>
#include <iomanip>
#include "Survey.h"
#include <ctime>

int main()
{
	string namePerson[] = { "Marie","Desiree", "Elo", "John", "Alex", "Alexander","Chris","Joey","Jen","Theo","Noir","Aya", "Mia", "Jill", "Jack", "George","Jasper","Joe","Charlottie","Lloyd" };
	string nameCollage[] = { "Seneca", "Sheridan","George Brown","Evergreen","Olds","Red Deer", "Lakeland","Reeves","Robertson","MaKami" };
	string nameProgram[] = { "Animation","Game Programming", "Game Art", "Photography","Film","Game Design","Nursing", "Computer Sience","Health Informatics","Cyber Security" };
	string streamService[] = { "Netflix","Amazon Prime", "hulu","Disney+", "Crunchyroll","Funimation" };
	string gameDevice[] = { "Wii","Nintendo Switch","PS5","PS4","Xbox", "Xbox 360" };
	int numOfPeople, college, program,stream,device;
	Survey survey;
	NonGamingStudent* notGaming;
	GamingStudent* Gaming;
	srand(time(NULL));

	cout << "Welcome to the Survey Program\n\n\n";

	cout << "How many people are participating(500 max): ";
	cin >> numOfPeople;

	survey.setTotalPeople(numOfPeople);

	for (int i = 0;i < numOfPeople;i++)
	{
		string name = "";
		int gamer = rand() % 2;
		int age = rand() % 33 + 18;
		int semester = rand() % 10 + 1;
		float hours = rand() % 201;

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
			notGaming = new NonGamingStudent(name,nameCollage[college],nameProgram[program],streamService[stream],semester,age,hours);
			survey.setNonGamers(*notGaming);
		}
		else
		{
			device = rand() % 6;
			Gaming = new GamingStudent(name, nameCollage[college], nameProgram[program], gameDevice[device], semester, age, hours);
			survey.setGamers(*Gaming);
		}
	}

	cout << survey.process();

	survey.finalCheck();
}

