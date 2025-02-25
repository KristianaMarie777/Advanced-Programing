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
	int damageValue;
	string* specialAbilites;
	int abilityNum = 0;
public:
	Weapon()
	{
		setName("");
		setDescription("");
	}
	Weapon(string name, string description, int damageValue, int numSpecialAbilities, int valueStart, string specialAbilityname[])
	{
		setName(name);
		cout << "pass setName\n";
		setDescription(description);
		cout << "pass setDescription\n";
		setDamageValue(damageValue);
		cout << "pass setDamageValue\n";

		setNumSpecialA(numSpecialAbilities);
		cout << "Created spaces\n";

		for (int i = 0; i < numSpecialAbilities; i++)
		{
			setAbilities(specialAbilityname[valueStart], i);
			cout << "pass setAbilitiy\n";
		}
		cout << "DOne\n";
	}
	void setNumSpecialA(int num)
	{
		specialAbilites = new string[num];
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

	void setAbilities(string name, int i)
	{
		specialAbilites[i] = name;
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

	int getDramageValue() const
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
	
	friend ostream& operator<<(ostream &out, const Weapon& a)
	{
		out << a.getName() << endl;
		out << a.getDescription() << endl;
		out << "Does " << to_string(a.getDramageValue()) << " points of Damage" << endl;
	
		if (a.getAbilitiesNum() == 0)
		{
			out << "Has no abilities:" << endl;
		}
		else if (a.getAbilitiesNum() == 1)
		{
			out << "Has the ability:" << endl;
			for (int i = 0;i < a.getAbilitiesNum();i++)
				out << a.getAbilities(i) << endl;
		}
		else
		{
			out << "Has the abilities:" << endl;
			for (int i = 0;i < a.getAbilitiesNum();i++)
				out << a.getAbilities(i) << endl;
		}

		return out;
	}

	~Weapon()
	{
		cout << "destroy weapon";
	}



};

#endif // !_WEAPON_H_


