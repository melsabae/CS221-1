//character header file

#ifndef Char_H
#define Char_H

#include <iostream>
#include <string>
using namespace std;

class Character
{
	
private:
	char m_sName[65];
	int m_iClass, m_iAlignment, m_iHitPoints;
	int m_iCharTraits[6];
	
public:
	//define constructor
	Character();
	Character(char *name, int cl, int al, int hp, int str, int dex, int con, int itl, int wis, int chr);
	//accessor, mutator, manipulation funtions
	void getName(char *name);
	void setName(char *name);

	void getClass(int& cl);
	void setClass(int cl);

	void getAlignment(int& al);
	void setAlignment(int al);

	void getHitPoints(int& hp);
	void setHitPoints(int hp);

	//pointers 
	void getStrength(int *str);
	void setStrength(int str);

	void getDexterity(int *dex);
	void setDexterity(int dex);

	void getConstitution(int *cn);
	void setConstitution(int cn);

	void getIntelligence(int *itl);
	void setIntelligence(int itl);

	void getWisdom(int *wis);
	void setWisdom(int wis);

	void getCharisma(int *chr);
	void setCharisma(int chr);
	
	//print character to display
	void printAll();
};

#endif