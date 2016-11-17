//purpose: implement the function of character.h 
#include"Character.h"
#include <iostream>

using namespace std;

Character::Character()
{
	strcpy(m_sName, "None");
	m_iClass = 0;
	m_iAlignment = 0;
	m_iHitPoints = 0;
	m_iCharTraits[0] = 0;
	m_iCharTraits[1] = 0;
	m_iCharTraits[2] = 0;
	m_iCharTraits[3] = 0;
	m_iCharTraits[4] = 0;
	m_iCharTraits[5] = 0;
	m_pBattleItems = new Possessions ;
	m_pTreasureItems = new Possessions;

}

Character::Character(char *name, int cl, int al, int hp, int str, int dex, int con, int itl, int wis, int chr)
{
	strcpy(m_sName, name);
	//check value input: if negative, set value to 0 
	//check class
	if (cl >= 0)
	{
		m_iClass = cl;
	}
	else
	{
		m_iClass = 0;
	}
	//check alignment
	if (al >= 0)
	{
		m_iAlignment = al;
	}
	else
	{
		m_iAlignment = 0;
	}
	//check Hitpoints
	if (hp >= 0)
	{
		m_iHitPoints = hp;
	}
	else
	{
		m_iHitPoints = 0;
	}
	//check str
	if (str >= 0)
	{
		m_iCharTraits[0] = str;
	}
	else
	{
		m_iCharTraits[0] = 0;
	}
	//check dex
	if (dex >= 0)
	{
		m_iCharTraits[1] = dex;
	}
	else
	{
		m_iCharTraits[1] = 0;
	}
	//check con
	if (con >= 0)
	{
		m_iCharTraits[2] = con;
	}
	else
	{
		m_iCharTraits[2] = 0;
	}
	//check itl
	if (itl >= 0)
	{
		m_iCharTraits[3] = itl;
	}
	else
	{
		m_iCharTraits[3] = 0;
	}
	//check wis
	if (wis >= 0)
	{
		m_iCharTraits[4] = wis;
	}
	else
	{
		m_iCharTraits[4] = 0;
	}
	//check charisma
	if (chr >= 0)
	{
		m_iCharTraits[5] = chr;
	}
	else
	{
		m_iCharTraits[5] = 0;
	}

	//initialize binary tree list 
	m_pBattleItems = new Possessions;
	m_pTreasureItems = new Possessions;


}
//get char name
char *Character::getName()
{
	return m_sName;
}
void Character::setName(char *name)
{
	strcpy(m_sName, name);
}

//get and set char class
int Character::getClass()
{
	return m_iClass;
}
void Character::setClass(int cl)
{
	if (cl >= 0) {
		m_iClass = cl;
	}
	else
	{
		m_iClass = 0;
	}
}

//get and setchar alignment
int Character::getAlignment()
{
	return m_iAlignment;
}
void Character::setAlignment(int al)
{
	if (al >= 0)
	{
		m_iAlignment = al;
	}
	else
	{
		m_iAlignment = 0;
	}
}
//get and set char hitpoints
int Character::getHitPoints()
{
	return m_iHitPoints;
}
void Character::setHitPoints(int hp)
{
	if (hp >= 0)
	{
		m_iHitPoints = hp;
	}
	else
	{
		m_iHitPoints = 0;
	}
}
//get and set char strength
int Character::getStrength()
{
	
	return m_iCharTraits[0];
}
void Character::setStrength(int str)
{
	if (str >= 0)
	{
		m_iCharTraits[0] = str;
	}
	else
	{
		m_iCharTraits[0] = 0;
	}
}
//get and set char dexterity
int Character::getDexterity()
{
	return m_iCharTraits[1];
}
void Character::setDexterity(int dex)
{
	if (dex >= 0)
	{
		m_iCharTraits[1] = dex;
	}
	else
	{
		m_iCharTraits[1] = 0;
	}
}
//get and set char constitution
int Character::getConstitution()
{
	return m_iCharTraits[2];
}
void Character::setConstitution(int cn)
{
	if (cn >= 0)
	{
		m_iCharTraits[2] = cn;
	}
	else
	{
		m_iCharTraits[2] = 0;
	}
}
//get and set char intelligence
int Character::getIntelligence()
{
	return m_iCharTraits[3];
}
void Character::setIntelligence(int itl)
{
	if (itl >= 0)
	{
		m_iCharTraits[3] = itl;
	}
	else
	{
		m_iCharTraits[3] = 0;
	}
}
//get and set char wisdom
int Character::getWisdom()
{
	
	return m_iCharTraits[4];
}
void Character::setWisdom(int wis)
{
	if (wis >= 0)
	{
		m_iCharTraits[4] = wis;
	}
	else
	{
		m_iCharTraits[4] = 0;
	}
}
//get and set char charisma
int Character::getCharisma()
{
	return m_iCharTraits[5];
}
void Character::setCharisma(int chr)
{
	if (chr >= 0)
	{
		m_iCharTraits[5] = chr;
	}
	else
	{
		m_iCharTraits[5] = 0;

	}

}

bool Character::addItem(Item *item)
{
	if (item->m_iType == BATTLE_ITEM)
	{
		m_pBattleItems->addItem(item);//add item to battleItems
		return true;
	}
	if (item->m_iType == TREASURE_ITEM)
	{
		m_pTreasureItems->addItem(item);//add item to treasureItems
		return true;
	}
	
	//m_pBattleItems->printTree();
	//m_pTreasureItems->printTree();
	return false;
}

Item *Character::getItem(char *itemName)
{
	if (m_pBattleItems->getItem(itemName) != NULL)
	{
		//cout << "this item is battle item" << endl;
		return m_pBattleItems->getItem(itemName);
	}
	if (m_pTreasureItems->getItem(itemName) != NULL)
	{
		//cout << "this item is treasure item" << endl;
		return m_pTreasureItems->getItem(itemName);
		
	}
	return NULL;//return nothing if both cases fail
}


Item *Character::dropItem(char *itemName)
{

	if (m_pBattleItems->getItem(itemName) != NULL)
	{
		//cout << "this item is battle item" << endl;
		return m_pBattleItems->dropItem(itemName);
	}
	if (m_pTreasureItems->getItem(itemName) != NULL)
	{
		//cout << "this item is treasure item" << endl;
		return m_pTreasureItems->dropItem(itemName);

	}
	return NULL;//return nothing if both cases fail
}

void Character::printAll()
{
	cout << "...Printing character data using printall()..." << endl;
	cout << m_sName << "	" << m_iClass << "		" << m_iAlignment << "		" << m_iHitPoints << "		" << m_iCharTraits[0] << " " << m_iCharTraits[1] << " " << m_iCharTraits[2] << " " << m_iCharTraits[3] << " " << m_iCharTraits[4] << " " << m_iCharTraits[5] << endl << endl;
	m_pBattleItems->printTree();
	m_pTreasureItems->printTree();
}