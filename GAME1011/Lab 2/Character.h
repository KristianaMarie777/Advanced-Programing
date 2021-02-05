#pragma once
#ifndef _CHARACTER_H_
#define _CHARACTER_H_

#include <iostream>
#include <cstdlib>
#include <string>
#include "Weapon.h"

using namespace std;

class Character
{
private:
	float healthBar;
	string characterName;
	Weapon* weapon;

public:
	Character()
	{
		setCharacterName("");
	}
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
	int numAbilities;
public:

	Undead(string name, int numAbilities, string abilityList[])
	{
	
		setCharacterName(name);
		
		setHealthBar(200.0f);

		setNumAbilites(numAbilities);
		for (int i = 0; i < numAbilities-1; i++)
		{
			setAbilities(abilityList[numAbilities]);
		
		}
	
	}
	
	void setNumAbilites(int numAbilities)
	{
		this->numAbilities = numAbilities;
	}

	int getNumAbilites() const
	{
		return numAbilities;
	}

	void setAbilities(string name)
	{
		abilities = new string(name);
	}

	string getAbilities(int num)const
	{
		return abilities[num];
	}

	virtual string DisplayInfo() const
	{

		string description;
		description = "Undead " + getCharacterName() + "\n";
		description += "Has " +	to_string( getHealthBar()) + " Health points\n";
		description += "Uses the weapon \n";

		if (numAbilities == 0)
		{
			description += "Has no abilites\n";
		}
		else if (numAbilities == 1)
		{
			description += "Has the ability " + abilities[0] +"\n";
		}
		else
		{
			description += "Has the following abilities: \n";
			for (int i = 0; i < getNumAbilites(); i++)
			{
				description += getAbilities(i) + "\n";
			}
		}

		return description;
	}
};

class Human : public Character
{
private:
	string* abilities;
	int numAbilities;
public:
	Human(string name, int numAbilities, string abilityList[])
	{
		setCharacterName(name);
		setHealthBar(100.00f);

		for (int i = 0; i < numAbilities - 1; i++)
		{
			setAbilities(abilityList[numAbilities]);
		}

	}
	
	void setAbilities(string name)
	{
		abilities = new string(name);
	}

	virtual string DisplayInfo() const
	{

		string description;
		description = "Undead " + getCharacterName() + "\n";
		description += "Has " + to_string(getHealthBar()) + " Health points\n";
		
		if (numAbilities == 0)
		{
			description += "Uses the weapon \n";
		}
		else if (numAbilities == 1)
		{
			description += "Uses the weapon \n";
		}
		else
		{
			description += "Uses the following weapons: \n";
			for (int i = 0; i < 1; i++)
			{
				description += "\n";
			}
		}

		description += "Has no abilites\n";

		return description;
	}

};

class Ghost : public Character
{
private:
	string* abilities;
	int numAbilities;
public:
	
	Ghost(string name,float health ,int numAbilities, string abilityList[])
	{
		setCharacterName(name);
		setHealthBar(health);

		for (int i = 0; i < numAbilities - 1; i++)
		{
			setAbilities(abilityList[numAbilities]);
		}

	}
	
	void setNumAbilites(int numAbilities)
	{
		this->numAbilities = numAbilities;
	}

	int getNumAbilites() const
	{
		return numAbilities;
	}

	void setAbilities(string name)
	{
		abilities = new string(name);
	}

	string getAbilities(int num)const
	{
		return abilities[num];
	}

	virtual string DisplayInfo() const
	{

		string description;

		description = "Ghost " + getCharacterName() + "\n";
		description += "Has " + to_string(getHealthBar()) + " Health points\n";
		description += "Uses no weapon \n";
		
		if (numAbilities == 0)
		{
			description += "Has no abilites\n";
		}
		else if (numAbilities == 1)
		{
			description += "Has the ability " + abilities[0] + "\n";
		}
		else
		{
			description += "Has the following abilities: \n";
			for (int i = 0; i < getNumAbilites(); i++)
			{
				description += getAbilities(i) + "\n";
			}
		}

		return description;
	}

};
#endif // !_CHARACTER_H_
