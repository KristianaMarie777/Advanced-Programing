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
	static int weaponNum;
public:
	Weapon()
	{
		
	}

	void setName(string weaponName)
	{
		this->weaponName = weaponName;
	}

	void setDescription(string weaponDescription)
	{
		this->weaponDescription = weaponDescription;
	}

	void setDramageValue(float damageValue)
	{
		this->damageValue = damageValue;
	}

	void setAbilities(string name)
	{
		specialAbilites = new string(name);
		setWeaponNum();
	}

	static void setWeaponNum()
	{
		if (weaponNum == NULL)
			weaponNum = 1;
		else
			weaponNum += 1;
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

	int getWeaponNum() const
	{
		return weaponNum;
	}

	~Weapon()
	{
		cout << "chect";
	}



};

#endif // !_WEAPON_H_


