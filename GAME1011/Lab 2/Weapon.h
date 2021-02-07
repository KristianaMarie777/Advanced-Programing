#pragma once
#ifndef _WEAPON_H_
#define _WEAPON_H_

#include "Character.h"
#include <iostream>

using namespace std;
class Weapon
{
private:
	string weaponName, weaponDescription;
	float damageValue;
	string* specialAbilites;
	int abilityNum = 0;
public:

	Weapon(string name, string description, float damageValue, int numSpecialAbilities, int valueStart, string specialAbilityname[])
	{
		setName(name);
		cout << "pass setName\n";
		setDescription(description);
		cout << "pass setDescription\n";
		setDamageValue(damageValue);
		cout << "pass setDamageValue\n";
		for (int i = 0; i < numSpecialAbilities; i++)
		{
			setAbilities(specialAbilityname[valueStart + i]);
			cout << "pass setAbilitiy\n";
		}
		setAbilitesNum(numSpecialAbilities);
	}

	void setName(string weaponName)
	{
		this->weaponName = weaponName;
	}

	void setDescription(string weaponDescription)
	{
		this->weaponDescription = weaponDescription;
	}

	void setDamageValue(float damageValue)
	{
		this->damageValue = damageValue;
	}

	void setAbilities(string name)
	{
		specialAbilites = new string(name);
	}

	void setAbilitesNum(int num)
	{
		abilityNum = num;
	}

	string getName() const
	{
		return weaponName;
	}

	string getDescription() const
	{
		return weaponDescription;
	}

	float getDramageValue() const
	{
		return damageValue;
	}

	string getAbilities(int num) const
	{
		return specialAbilites[num];
	}

	int getAbilitiesNum() const
	{
		return abilityNum;
	}
	
	friend ostream& operator<<(ostream &out, Weapon a)
	{
		out << a.getName() << endl;
		out << a.getDescription() << endl;
		out << "Does " << to_string(a.getDramageValue()) << " points of Damage" << endl;
		out << "Has the abilities:" << endl;
		
		for(int i=0;i< a.getAbilitiesNum();i++)
			out << a.getAbilities(i) << endl;
		
		return out;
	}
	~Weapon()
	{
		cout << "chect";
	}



};

#endif // !_WEAPON_H_


