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
	static Weapon* weapon;
	static int numOfWeapons;
	static int characterNum;
public:
	
	Character()
	{
		setCharacterName("");

	}

	//for characterNum
	static void setCharacterNumZero()
	{
		characterNum = 0;
	}
	static void addCharacterNum()
	{
		characterNum += 1;
	}
	static void deleteCharacterNum()
	{
		characterNum -= 1;
	}

	static void setWeaponNumZero()
	{
		characterNum = 0;
	}
	static void addWeaponNum()
	{
		characterNum += 1;
	}
	
	void setHealthBar(float heathBar)
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

	//string getWeaponName()
	//{
	//	string description = "";
	//	for (int i = 0; i < numOfWeapons; i++)
	//	{
	//		description += to_string(i) + ". " + weapon[i].getName();
	//	}
	//	return description;
	//}

	string getWeaponName(int a) const
	{
		return weapon[a].getName();
	}
	
	void addWeapon(string name, string description, float damageValue, int numSpecialAbilities, int startValue, string specialAbilityname[])
	{
		Weapon weapon(name, description, damageValue, numSpecialAbilities, startValue, specialAbilityname);
		addWeaponNum();
	}

	Weapon getWeapon(int i) const
	{
		return weapon[i];
	}

	virtual void DisplayInfo() const = 0;
};

class Undead : public Character
{

private:
	string* abilities;
	string weaponName[2];
	bool exsists;
public:

	Undead(string name,/*float heathBar, */ int numOfWeapons,
		string weaponListName[], string weaponListDes[], int weaponDamage[], 
		int numAbilities[], string abilityList[])
	{

		int valueStart = 0;
		
		if (!(getCharacterNum() >= 0))
		{
			setCharacterNumZero();
		}
		if(!(getNumOfWeapons()>=0))
		{
			setWeaponNumZero();
		}
		
		setCharacterName(name);
		
		setHealthBar(200.0f);

		for (int i=0;i< numOfWeapons;i++)
		{
			exsists = false;
			weaponName[i] = weaponListName[i];
			
			for(int a=0;a < getNumOfWeapons();a++)
			{
				if (weaponName[i] == getWeaponName(a))
				{
					exsists = true;
				}
			}

			if (!exsists)
			{
				addWeapon(weaponListName[i],weaponListDes[i],weaponDamage[i],numAbilities[i],valueStart,abilityList);
				valueStart += (numAbilities[i] - 1);
			}
		}

		addCharacterNum();
	}
	
	virtual void DisplayInfo() const
	{
		cout << "Undead " << getCharacterName() << endl;
		cout << "Has " << to_string( getHealthBar()) << " Health points\n";
		cout << "Uses the weapon \n";
		for(int i=0 ;i < getNumOfWeapons();i++)
		{
			if (getWeaponName(i) == weaponName[i])
			{
				cout << getWeapon(i) << endl;
			}
		}

	}
	
};
#endif // !_CHARACTER_H_
