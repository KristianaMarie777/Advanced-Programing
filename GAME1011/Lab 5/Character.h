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
	Weapon* weapon;
	int numOfWeapons;
	int characterNum;
public:
	
	Character()
	{
		setCharacterName("");

	}

	//for characterNum
	void setNumOfWeapons(int a)
	{
		numOfWeapons = a;
	}
	
	void setHealthBar(int bar)
	{
		this->healthBar = bar;
	}
	
	int getHealthBar() const
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

	}
	Human(string name, int numOfWeapons = 0, string weaponListName[] = { new string("") }, string weaponListDes[] = { new string("") }, int weaponDamage[] = { 0 }, int numAbilities = 0, string abilityList[] = { new string("") })
	{

		int valueStart = 0;

		setCharacterName(name);

		setHealthBar(100);
		
		setNumOfWeapons(numOfWeapons);

		for (int i = 0;i < numOfWeapons;i++)
		{
			
			addWeapon(weaponListName[i], weaponListDes[i], weaponDamage[i], numAbilities, valueStart, abilityList);
			
		}
	}

	virtual void DisplayInfo() const
	{
		cout << "Human " << getCharacterName() << endl;
		cout << "Has " << to_string(getHealthBar()) << " Health points\n";
		if (getNumOfWeapons() == 0)
			cout << "Has no weapons\n";
		else if (getNumOfWeapons() == 1)
		{
			cout << "Uses the weapon \n";
			for (int i = 0;i < getNumOfWeapons();i++)
				cout << getWeapon(i);
		}
		else
		{
			cout << "Uses the weapons\n";
			for (int i = 0;i < getNumOfWeapons();i++)
				cout << getWeapon(i);
		}
	}
};

class Undead : public Character
{

public:
	Undead()
	{
	}
	Undead(string name, int numOfWeapons = 0, string weaponListName[] = { new string("") }, string weaponListDes[] = { new string("") }, int weaponDamage[] = { 0 }, int numAbilities = 0, string abilityList[] = { new string("") })
	{

		int valueStart = 0;

		setCharacterName(name);

		setHealthBar(200);

		setNumOfWeapons(numOfWeapons);

		for (int i = 0;i < numOfWeapons;i++)
		{
			cout << "going in " << i << endl;
			cout << weaponListName[i] << endl;
			addWeapon(weaponListName[i], weaponListDes[i], weaponDamage[i], numAbilities, valueStart, abilityList);
			valueStart += numAbilities;
		}

	}

	virtual void DisplayInfo() const
	{
		cout << "Undead " << getCharacterName() << endl;
		cout << "Has " << to_string(getHealthBar()) << " Health points\n";
		if (getNumOfWeapons() == 0)
			cout << "Has no weapons\n";
		else if (getNumOfWeapons() == 1)
		{
			cout << "Uses the weapon \n";
			for (int i = 0;i < getNumOfWeapons();i++)
				cout << getWeapon(i);
		}
		else
		{
			cout << "Uses the weapons\n";
			for (int i = 0;i < getNumOfWeapons();i++)
				cout << getWeapon(i);
		}

		
	}


};
	
class Ghost : public Character
{

public:
	Ghost()
	{
	}
	Ghost(string name, int heathBar, int numOfWeapons = 0, string weaponListName[] = { new string("") }, string weaponListDes[] = { new string("") }, int weaponDamage[] = { 0 }, int numAbilities = 0, string abilityList[] = { new string("") })
	{

		int valueStart = 0;

		setCharacterName(name);

		setHealthBar(heathBar);
	
		setNumOfWeapons(numOfWeapons);

		for (int i = 0;i < numOfWeapons;i++)
		{
			addWeapon(weaponListName[i], weaponListDes[i], weaponDamage[i], numAbilities, valueStart, abilityList);
		}

	}

	virtual void DisplayInfo() const
	{
		cout << "Ghost " << getCharacterName() << endl;
		cout << "Has " << to_string(getHealthBar()) << " Health points\n";
		if (getNumOfWeapons() == 0)
			cout << "Has no weapons\n";
		else if (getNumOfWeapons() == 1)
		{
			cout << "Uses the weapon \n";
			for (int i = 0;i < getNumOfWeapons();i++)
				cout << getWeapon(i);
		}
		else
		{
			cout << "Uses the weapons\n";
			for (int i = 0;i < getNumOfWeapons();i++)
				cout << getWeapon(i);
		}
	}
	
};

#endif // !_CHARACTER_H_
