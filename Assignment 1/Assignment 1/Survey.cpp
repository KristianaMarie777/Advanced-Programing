#include "Survey.h"

string Survey::getAvrDevice() const
{
	int a = 0;
	for (int i = 0; i < deviceVar;i++)
		if (numOfDevices[i] > numOfDevices[a])
			a = i;

	return gameDevices[a];

}

string Survey::getAvrStream() const
{
	int a = 0;
	for (int i = 0; i < streamVar;i++)
		if (numOfStream[i] > numOfStream[a])
			a = i;

	return streamService[a];

}

void Survey::setDevicesNames(string name[])
{
	gameDevices = name;
	numOfDevices = new int[sizeof(name)];

	for (int i = 0; i < sizeof(name); i++)
		numOfDevices[i] = 0;
	
	deviceVar = sizeof(name);
}

void Survey::setStreamNames(string name[])
{
	streamService = name;
	numOfStream = new int[sizeof(name)];

	for (int i = 0; i < sizeof(name); i++)
		numOfStream[i] = 0;
	
	streamVar = sizeof(name);
}

void Survey::setNonGamers(NonGamingStudent person)
{
	hoursAvrNotGamer += person.getHours();

	this->people[currentPerson] = new NonGamingStudent(person);
	currentPerson += 1;

	ageAvrNotGamer += person.getAge();

	for (int i = 0; i < streamVar; i++)
		if (person.getStreamService() == streamService[i])
			numOfStream[i] += 1;

	totalNotGamer += 1;

}

void Survey::setGamers(GamingStudent person)
{
	hoursAvrGamer += person.getHours();

	this->people[currentPerson] = new GamingStudent(person);
	currentPerson += 1;

	ageAvrGamer += person.getAge();

	for (int i = 0; i < deviceVar; i++)
		if (person.getGamingDevice() == gameDevices[i])
			numOfDevices[i] += 1;

	totalGamer += 1;

}

string Survey::process() const
{
	string info = "";

	for (int i = 0; i < getTotalPeople();i++)
	{
		info += people[i]->DisplayInfo();
		info += "\n\n";
	}

	info += "                       |       Gamers      \t|       Non-Gamers";
	info += "\n________________________________________________________________________________________________\n";
	info += "Total number of        |   " + to_string(getGamerNum()) + "\t\t\t|   " + to_string(getNonGamerNum());
	info += "\n________________________________________________________________________________________________\n";
	info += "Average age            |   ";
	if (getGamerNum() == 0)
		info += "-\t\t\t|   ";
	else
		info += to_string(getAveageGamerAge()) + "\t\t\t|   ";
	
	if(getNonGamerNum()==0)
		info += "-";
	else
		info += to_string(getAveageNonGamerAge());
	
	info += "\n________________________________________________________________________________________________\n";
	info += "Device/stream service  |   ";
	
	if (getGamerNum() == 0)
		info += "-\t\t\t";
	else
	{
		info += getAvrDevice() + "\t";

		if (getAvrDevice().size() <= 4)
			info += "\t\t";
		else if (getAvrDevice().size() > 4 && getAvrDevice().size() <= 8)
			info += "\t";

	}
	
	if (getNonGamerNum() == 0)
		info += "|   -";
	else
		info += "|   " + getAvrStream();


	info += "\n________________________________________________________________________________________________\n";
	info += "Average Hours(per day) |   ";
	if (getGamerNum() == 0)
		info += "-\t\t\t|   ";
	else
		info += to_string(getAvrHourGamer()) + "\t\t|   ";

	if (getNonGamerNum() == 0)
		info += "-";
	else
		info += to_string(getAvrHourNonGamer());

	return info;
}
