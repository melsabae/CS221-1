//Name: Benjamin Hoang
//class: CS II
//Date: 2/15/2016
//Programm Assignment 1



#include <stdio.h>
#include <time.h>
#include <cstdlib>

#include <string>
#include <iostream>
using namespace std;

#include"character.h"


int main()
{
	char char_name[65];
	int cl, al, hp, str, dex, cn, itl, wis, chr;
	cout << "===================================================" << endl;
	cout << "	Programming assignment 1 Demonstration" << endl;
	cout << "===================================================" << endl;
	cout << "creating a blank character..." << endl;
	//blank character
	Character char1 = Character();
	cout << "...done"<<endl;
	cout << "setting and verifying character data..." << endl;
	//setting character data
	char1.setName("Archibald");
	char1.setClass(5);
	char1.setAlignment(1);
	char1.setHitPoints(300);
	char1.setStrength(11);
	char1.setDexterity(15);
	char1.setConstitution(14);
	char1.setIntelligence(18);
	char1.setWisdom(18);
	char1.setCharisma(14);

	//get character data
	char1.getName(char_name);
	char1.getClass(cl);
	char1.getAlignment(al);
	char1.getHitPoints(hp);
	char1.getStrength(&str);
	char1.getDexterity(&dex);
	char1.getConstitution(&cn);
	char1.getIntelligence(&itl);
	char1.getWisdom(&wis);
	char1.getCharisma(&chr);
	//display char1 data to screen
	cout << "	Name..."<<char_name<<endl;
	cout << "	Class..."<<cl << endl;
	cout << "	Alignment..."<<al << endl;
	cout << "	Hit Points..."<<hp << endl;
	cout << "	Strength..."<<str << endl;
	cout << "	Dexterity..."<<dex << endl;
	cout << "	Constitution..."<<cn << endl;
	cout << "	Intelligence..."<<itl << endl;
	cout << "	Wisdom..."<<wis << endl;
	cout << "	Charisma..."<<chr << endl;
	char1.printAll();

	cout << "Creating instance of Character using the parameterized constructor." << endl<<endl;

	//character 2 Archibald
	Character char2("Silverleaf",1,1,250,12,15,13,15,15,14);
	
	//get character2 data
	char2.getName(char_name);
	char2.getClass(cl);
	char2.getAlignment(al);
	char2.getHitPoints(hp);
	char2.getStrength(&str);
	char2.getDexterity(&dex);
	char2.getConstitution(&cn);
	char2.getIntelligence(&itl);
	char2.getWisdom(&wis);
	char2.getCharisma(&chr);
	//display char2 data to screen
	cout << "checking parameters" << endl;
	cout << "	Name..." << char_name << endl;
	cout << "	Class..." << cl << endl;
	cout << "	Alignment..." << al << endl;
	cout << "	Hit Points..." << hp << endl;
	cout << "	Strength..." << str << endl;
	cout << "	Dexterity..." << dex << endl;
	cout << "	Constitution..." << cn << endl;
	cout << "	Intelligence..." << itl << endl;
	cout << "	Wisdom..." << wis << endl;
	cout << "	Charisma..." << chr << endl;
	char2.printAll();
	cout << "...Demonstration completed..." << endl;
	//get char 2 name
	
	
}
