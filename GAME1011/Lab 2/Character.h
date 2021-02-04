#pragma once
#ifndef _CHARACTER_H_
#define _CHARACTER_H_

#include <iostream>
#include <string>
#include "Weapon.h"

using namespace std;

class Character
{
private:
	float healthBar;
	string characterName;
	Weapon weapon;

public:
	
	void setHealthBar(float heathBar)
	{
		this->healthBar = healthBar;
	}
	
	float getHealthBar() const
	{
		return healthBar;
	}
	
	void setCharacterName(string characterName)
	{
		this->characterName = characterName;
	}
	
	string getCharacterName() const
	{
		return characterName;
	}
	
	virtual string DisplayInfo() const = 0;
};

class Undead : public Character
{

private:
	string* abilities;
public:

	Undead(string name, float health, int numAbilities, string abilitesNames[])
	{
	
		setCharacterName(name);
		
		setHealthBar(health);

		for (int i = 0; i < numAbilities; i++)
		{
		
			setAbilities(abilitesNames[i]);
		
		}
	
	}
	
	void setAbilities(string name)
	{
	
		abilities = new string(name);
	
	}
	
	string DisplayInfo() const
	{
		string description;

		description = "Undead ";
		description += getCharacterName();

		return description;
	}
};

class Human
{
public:
	Human();
	
private:

};

class Ghost
{
public:
	Ghost();
	
private:

};

#endif // !_CHARACTER_H_
