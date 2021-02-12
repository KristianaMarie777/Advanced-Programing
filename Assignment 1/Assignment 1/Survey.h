#pragma once
#ifndef _SURVEY_H_
#define _SURVEY_H_

#include "People.h"
#include <string>

class Survey
{
private:
	Person* people[500];
	string* streamService,* gameDevices;
	int* numOfStream, * numOfDevices;
	int totalGamer = 0,totalNotGamer = 0, totalPeople, currentPerson = 0, ageAvrGamer = 0, ageAvrNotGamer = 0, streamVar = 0, deviceVar = 0;
	float hoursAvrGamer = 0, hoursAvrNotGamer = 0;
	bool gamer = false;
public:
	
	int getTotalPeople() const
	{
		return totalPeople;
	}

	int getGamerNum() const
	{
		return totalGamer;
	}

	int getNonGamerNum() const
	{
		return totalNotGamer;
	}

	int getAveageGamerAge() const
	{
		return (ageAvrGamer / totalGamer);
	}

	float getAvrHourGamer() const
	{
		return (hoursAvrGamer / totalGamer);
	}

	float getAvrHourNonGamer() const
	{
		return (hoursAvrNotGamer / totalNotGamer);
	}

	int getAveageNonGamerAge() const
	{
		return (ageAvrNotGamer / totalNotGamer);
	}

	string getAvrDevice() const
	{
		int a = 0;
		for (int i = 0; i < deviceVar;i++)
		{
			if (numOfDevices[i] > numOfDevices[a])
			{
				a = i;
			}
		}

		return gameDevices[a];

	}

	string getAvrStream() const
	{
		int a = 0;
		for (int i = 0; i < streamVar;i++)
		{
			if (numOfStream[i] > numOfStream[a])
			{
				a = i;
			}
		}

		return streamService[a];

	}

	
	void setTotalPeople(int totalPeople)
	{
		this->totalPeople = totalPeople;
	}

	
	void setNonGamers(NonGamingStudent person)
	{
		hoursAvrNotGamer += person.getHours();
		
		this->people[currentPerson] = new NonGamingStudent(person);
		currentPerson += 1;

		ageAvrNotGamer += person.getAge();
		

		if (totalNotGamer == 0)
		{
			streamService = new string(person.getStreamService());
			numOfStream = new int(1);

			streamVar += 1;
		}
		else
		{
			for (int i = 0; i < totalNotGamer; i++)
			{
				if (person.getStreamService() == streamService[i])
				{
					numOfStream[i] +=1;
				}
				else
				{
					streamService = new string(person.getStreamService());
					numOfStream = new int(1);
					streamVar += 1;
				}
			
			}
		}

		totalNotGamer += 1;
	
	}

	void setGamers(GamingStudent person)
	{
		hoursAvrGamer += person.getHours();

		this->people[currentPerson] = new GamingStudent(person);
		currentPerson += 1;

		ageAvrGamer += person.getAge();
		

		if (totalGamer == 0)
		{
			gameDevices = new string(person.getGamingDevice());
			numOfDevices = new int(1);
			deviceVar += 1;
		}
		else
		{
			for (int i = 0; i < totalGamer; i++)
			{
				if (person.getGamingDevice() == gameDevices[i])
				{
					numOfDevices[i] += 1;
				}
				else
				{
					gameDevices = new string(person.getGamingDevice());
					numOfDevices = new int(1);
					deviceVar += 1;
				}

			}
		}

		totalGamer += 1;

	}

	string process() const
	{
		string info = "";
		for (int i = 0; i < getTotalPeople();i++)
		{
			info += people[i]->DisplayInfo();
			info += "\n\n";
		}

		info += "						|		Gamers		|		Non-Gamers		";
		info += "\n________________________________________________________________________________________________\n";
		info += "Total number of		|	" + to_string(getGamerNum()) + "\t\t|	" + to_string(getNonGamerNum());
		info += "\n________________________________________________________________________________________________\n";
		info += "Average age			|	" + to_string(getAveageGamerAge()) + "\t\t|	" + to_string(getAveageNonGamerAge());
		info += "\n________________________________________________________________________________________________\n";
		info += "Device/stream service	|	" + getAvrDevice() + "\t\t|	" + getAvrStream();
		info += "\n________________________________________________________________________________________________\n";
		info += "Average Hours			|	" + to_string(getAvrHourGamer()) + "\b\b\b\t\t|	" + to_string(getAvrHourNonGamer()) +"\b\b\b";

		
		return info;
	}

	void finalCheck()
	{
		cout << getAvrDevice();
		for (int i = 0;i < deviceVar;i++)
		{
			cout << gameDevices[i];
		}
	}
};

#endif