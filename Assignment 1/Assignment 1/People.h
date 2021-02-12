#pragma once
#ifndef _PEOPLE_H_
#define _PEOPLE_H_

#include <string>
#include <iomanip>

using namespace std;

class Person
{
private:
	int age;
	string name;
public:
	
	Person()
	{
		setName("");
		setAge(0);
	}

	Person(string name, int age)
	{
		setName(name);
		setAge(age);
	}

	string getName() const { return name; }
	int getAge() const { return age; }
	void setName(string name) { this->name = name; }
	void setAge(int age) { this->age = age; }
	virtual string DisplayInfo() = 0;
};

class Student : public Person
{
private:
	string college, program;
	int semester;
public:
	
	Student(string name, string college, string program, int semester, int age) : Person(name,age)
	{
		setCollege(college);
		setProgram(program);
		setSemester(semester);
	}

	string getCollege() const { return college; }
	int getSemester() const { return semester; }
	string getProgram() const { return program; }
	void setCollege(string college) { this->college = college; }
	void setSemester(int semester) { this->semester = semester; }
	void setProgram(string program) { this->program = program; }
	virtual string DisplayInfo() = 0;
};

class NonGamingStudent : public Student
{
private:
	string streamService;
	float hours;
public:
	
	NonGamingStudent(string name, string college, string program,string streamService, int semester, int age, float hours) : Student(name,college,program,semester,age)
	{
		setHours(hours);
		setStreamService(streamService);
	}

	float getHours() const { return hours; }
	string  getStreamService() const { return streamService; }
	void setStreamService(string streamService) { this->streamService = streamService; }
	void setHours(float hours) { this->hours = hours; }

	virtual string DisplayInfo()
	{
		string info = "Non-gaming student " + getName() + "\n";
		info += to_string(getAge()) + " years old\n";
		info += "Goes to " + getCollege() + " collage for " + getProgram() + " and is in their " + to_string(getSemester());
		if (getSemester() == 1)
			info += "st Semester\n";
		else if (getSemester() == 2)
			info += "nd Semester\n";
		else if (getSemester() == 3)
			info += "rd Semester\n";
		else
			info += "th Semester\n";

		info += "likes to use " + getStreamService() + " for " + to_string(getHours()) + "\b\b\b\b hours a day";
		return info;
	}
};

class GamingStudent : public Student
{
private:
	string gamingDevice;
	float hours;
public:
	GamingStudent(string name, string college, string program, string gamingDevice, int semester, int age, float hours) : Student(name, college, program, semester, age)
	{
		setHours(hours);
		setGamingDevice(gamingDevice);
	}

	float getHours() const { return hours; }
	string  getGamingDevice() const { return gamingDevice; }
	void setGamingDevice(string gamingDevice) { this->gamingDevice = gamingDevice; }
	void setHours(float hours) { this->hours = hours; }
	
	virtual string DisplayInfo()
	{
		string info = "Gaming student " + getName() + "\n";
		info += to_string(getAge()) + " years old\n";
		info += "Goes to " + getCollege() + " collage for " + getProgram() + " and is in their " + to_string(getSemester());
		if (getSemester() == 1)
			info += "st Semester\n";
		else if (getSemester() == 2)
			info += "nd Semester\n";
		else if (getSemester() == 3)
			info += "rd Semester\n";
		else
			info += "th Semester\n";

		info += "likes to use " + getGamingDevice() + " for " + to_string(getHours()) + "\b\b\b\b hours a day";
	
		return info;
	}
};
#endif // !_PEOPLE_H_

