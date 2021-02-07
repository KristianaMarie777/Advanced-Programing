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
	int healthBar;
	string characterName;

	int numOfWeapons;
	int characterNum;
public:
	Weapon* weapon;
	Character()
	{
		setCharacterName("");

	}

	//for characterNum
	void setCharacterNumZero()
	{
		characterNum = 0;
	}
	void addCharacterNum()
	{
		characterNum += 1;
	}
	void deleteCharacterNum()
	{
		characterNum -= 1;
	}

	void setWeaponNumZero()
	{
		characterNum = 0;
	}
	void addWeaponNum()
	{
		characterNum += 1;
	}
	
	void setHealthBar(int heathBar)
	{
		this->healthBar = healthBar;
	}
	
	float getHealthBar() const
	{
		return healthBar;
	}
	
	int getCharacterNum()
	{
		return characterNum;
	}
	
	void setCharacterName(string characterName)
	{
		this->characterName = characterName;
	}
	
	string getCharacterName() const
	{
		return characterName;
	}

	int getNumOfWeapons() const
	{
		return numOfWeapons;
	}

	string getWeaponName(int a) const
	{
		return weapon[a].getName();
	}
	
	void addWeapon(string name, string description, int damageValue, int numSpecialAbilities, int startValue, string specialAbilityname[])
	{
		weapon = new Weapon{ Weapon(name, description, damageValue, numSpecialAbilities, startValue, specialAbilityname) };
		cout << "passing";
	}

	Weapon getWeapon(int i) const
	{
		return weapon[i];
	}

	virtual void DisplayInfo() const = 0;
};

class Human : public Character
{

public:
	Human()
	{
		setCharacterNumZero();
		setWeaponNumZero();
	}
	Human(string name, int numOfWeapons,
		string weaponListName[], string weaponListDes[], int weaponDamage[],
		int numAbilities[], string abilityList[])
	{

		int valueStart = 0;

		if (!(getCharacterNum() >= 0))
		{
			setCharacterNumZero();
		}
		if (!(getNumOfWeapons() >= 0))
		{
			setWeaponNumZero();
		}

		setCharacterName(name);

		setHealthBar(100);

		for (int i = 0;i < numOfWeapons;i++)
		{
			
			addWeapon(weaponListName[i], weaponListDes[i], weaponDamage[i], numAbilities[i], valueStart, abilityList);
			
		}

		addCharacterNum();
	}

	virtual void DisplayInfo() const
	{
		cout << "Undead " << getCharacterName() << endl;
		cout << "Has " << to_string(getHealthBar()) << " Health points\n";
		cout << "Uses the weapon \n";

		cout << *weapon;

	}
};

class Undead : public Character
{

public:
	Undead()
	{
		setCharacterNumZero();
		setWeaponNumZero();
	}
	Undead(string name, int numOfWeapons,
		string weaponListName[], string weaponListDes[], int weaponDamage[],
		int numAbilities[], string abilityList[])
	{

		int valueStart = 0;

		if (!(getCharacterNum() >= 0))
		{
			setCharacterNumZero();
		}
		if (!(getNumOfWeapons() >= 0))
		{
			setWeaponNumZero();
		}

		setCharacterName(name);

		setHealthBar(200);

		for (int i = 0;i < numOfWeapons;i++)
		{
			cout << "going in " << i << endl;
			cout << weaponListName[i] << endl;
			addWeapon(weaponListName[i], weaponListDes[i], weaponDamage[i], numAbilities[i], valueStart, abilityList);
			valueStart = numAbilities[i];
		}

		addCharacterNum();
	}

	virtual void DisplayInfo() const
	{
		cout << "Undead " << getCharacterName() << endl;
		cout << "Has " << to_string(getHealthBar()) << " Health points\n";
		cout << "Uses the weapon \n";

		cout << *weapon;

	}


};
	
class Ghost : public Character
{

public:
	Ghost()
	{
		setCharacterNumZero();
		setWeaponNumZero();
	}
	Ghost(string name,int heathBar, int numOfWeapons,
		string weaponListName[], string weaponListDes[], int weaponDamage[],
		int numAbilities[], string abilityList[])
	{

		int valueStart = 0;

		if (!(getCharacterNum() >= 0))
		{
			setCharacterNumZero();
		}
		if (!(getNumOfWeapons() >= 0))
		{
			setWeaponNumZero();
		}

		setCharacterName(name);

		setHealthBar(heathBar);

		for (int i = 0;i < numOfWeapons;i++)
		{
			addWeapon(weaponListName[i], weaponListDes[i], weaponDamage[i], numAbilities[i], valueStart, abilityList);
		}

		addCharacterNum();
	}

	virtual void DisplayInfo() const
	{
		cout << "Undead " << getCharacterName() << endl;
		cout << "Has " << to_string(getHealthBar()) << " Health points\n";
		cout << "Uses the weapon \n";

		cout << *weapon;

	}
	
};

#endif // !_CHARACTER_H_
