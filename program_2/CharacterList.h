#pragma once
#include <iostream>
#include <string>
#include "Character.h"
#include "Item.h"

using namespace std;

class CharacterList
{

private:
	Character *ChrPtr;

public:
	CharacterList();
	~CharacterList();
	bool addCharacter(Character *newCharacter);

	Character* deleteCharacter(char *characterName);
	void DeleteAtHead();
	void DeleteAtTail();

	int Find_Same_Node();

	bool addItem(char *characterName, Item *newItem);
	Item *getItem(char *characterName, char *itemName);
	Item *dropItem(char *characterName, char *itemName);
	void printCharacters();



};
