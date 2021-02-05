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
	Weapon(string name, string description, float damageValue, int numSpecialAbilities, string specialAbilityname[])
	{
		setName(name);
		setDescription(description);
		setDamageValue(damageValue);
		for (int i = 0; i < numSpecialAbilities; i++)
		{
			setAbilities(specialAbilityname[i]);
		}
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
		setAbilitesNum();
	}

	void setAbilitesNum()
	{
		abilityNum += 1;
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

	~Weapon()
	{
		cout << "chect";
	}



};

#endif // !_WEAPON_H_


