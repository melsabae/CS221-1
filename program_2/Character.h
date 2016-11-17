#pragma once
#include <iostream>
#include <string>
#include "Item.h"

using namespace std;


class Character
{

private:
	char m_sName[65];
	int m_iClass, m_iAlignment, m_iHitPoints;
	int m_iCharTraits[6];
	Item m_Items[10];

public:
	Character *m_pNext;

	//define constructor
	Character();
	Character(char *name,
		int cl, int al, int hp, int str, int dex, int con, int itl, int wis, int chr);
	//accessor, mutator, manipulation funtions
	char *getName();
	void setName(char *name);

	int getClass(int& cl);
	void setClass(int cl);

	int getAlignment(int& al);
	void setAlignment(int al);

	int getHitPoints(int& hp);
	void setHitPoints(int hp);

	//pointers 
	int getStrength(int *str);
	void setStrength(int str);

	int getDexterity(int *dex);
	void setDexterity(int dex);

	int getConstitution(int *cn);
	void setConstitution(int cn);

	int getIntelligence(int *itl);
	void setIntelligence(int itl);

	int getWisdom(int *wis);
	void setWisdom(int wis);

	int getCharisma(int *chr);
	void setCharisma(int chr);

	bool addItem(Item *item);
	Item *dropItem(char *itemName);
	Item *getItem(char *item);

	//print character to display
	void printAll();
};
