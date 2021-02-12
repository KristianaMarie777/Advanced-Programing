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
	 
	int getTotalPeople() const { return totalPeople; }
	int getGamerNum() const { return totalGamer; }
	int getNonGamerNum() const { return totalNotGamer; }
	int getAveageGamerAge() const { return (ageAvrGamer / totalGamer); }
	float getAvrHourGamer() const { return (hoursAvrGamer / totalGamer); }
	float getAvrHourNonGamer() const { return (hoursAvrNotGamer / totalNotGamer); }
	int getAveageNonGamerAge() const { return (ageAvrNotGamer / totalNotGamer); }

	string getAvrDevice() const;

	string getAvrStream() const;

	void setDevicesNames(string name[]);

	
	void setStreamNames(string name[]);

	void setTotalPeople(int totalPeople) { this->totalPeople = totalPeople; }
	
	void setNonGamers(NonGamingStudent person);
	void setGamers(GamingStudent person);
	string process() const;

};

#endif