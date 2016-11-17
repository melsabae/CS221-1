#include "Character.h"

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

	//Initialize array to all empty places
	for (int i = 0; i<10; i++)
	{
		strcpy(m_Items[i].m_sItemName, "empty");
	}

}

Character::Character(char *name, int cl, int al, int hp, int str, int dex, int con, int itl, int wis, int chr)
{
	strcpy(m_sName, name);
	//check value input: if negative, set value to 0 
	//check class
	m_iClass = cl;

	//check alignment

	m_iAlignment = al;

	//check Hitpoints
	m_iHitPoints = hp;

	//check str

	m_iCharTraits[0] = str;

	//check dex

	m_iCharTraits[1] = dex;

	//check con
	m_iCharTraits[2] = con;

	//check itl

	m_iCharTraits[3] = itl;

	//check wis

	m_iCharTraits[4] = wis;

	//check charisma

	m_iCharTraits[5] = chr;

	for (int i = 0; i<10; i++)
	{
		strcpy(m_Items[i].m_sItemName, "empty");
	}


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
int Character::getClass(int& cl)
{
	cl = m_iClass;
	return cl;
}
void Character::setClass(int cl)
{
	m_iClass = cl;

}

//get and setchar alignment
int Character::getAlignment(int& al)
{
	al = m_iAlignment;
	return al;
}
void Character::setAlignment(int al)
{
	m_iAlignment = al;
}
//get and set char hitpoints
int Character::getHitPoints(int& hp)
{
	hp = m_iHitPoints;
	return hp;
}
void Character::setHitPoints(int hp)
{
	m_iHitPoints = hp;

}

int Character::getStrength(int *str)
{
	*str = m_iCharTraits[0];
	return *str;
}
void Character::setStrength(int str)
{
	m_iCharTraits[0] = str;

}

int Character::getDexterity(int *dex)
{
	*dex = m_iCharTraits[1];
	return *dex;
}
void Character::setDexterity(int dex)
{
	m_iCharTraits[1] = dex;

}

int Character::getConstitution(int *cn)
{
	*cn = m_iCharTraits[2];
	return *cn;
}
void Character::setConstitution(int cn)
{
	m_iCharTraits[2] = cn;
}

int Character::getIntelligence(int *itl)
{
	*itl = m_iCharTraits[3];
	return *itl;
}
void Character::setIntelligence(int itl)
{
	m_iCharTraits[3] = itl;

}

int Character::getWisdom(int *wis)
{
	*wis = m_iCharTraits[4];
	return *wis;
}
void Character::setWisdom(int wis)
{
	m_iCharTraits[4] = wis;

}

int Character::getCharisma(int *chr)
{
	*chr = m_iCharTraits[5];
	return *chr;
}
void Character::setCharisma(int chr)
{
	m_iCharTraits[5] = chr;
}
bool Character::addItem(Item *item)
{
	for (int i = 0; i<10; i++)
	{
		if (strcmp(m_Items[i].m_sItemName, "empty") == 0)
		{
			// Found an empty slot so copy this item here
			m_Items[i] = *item;
			return true;
		}
	}

	return false;
}

Item *Character::getItem(char *itemName)
{
	for (int i = 0; i<10; i++)
	{
		if (strcmp(m_Items[i].m_sItemName, itemName) == 0)
			return &m_Items[i];
	}
	return NULL; // can't find item
}

Item *Character::dropItem(char *itemName)
{
	// Search all items
	for (int i = 0; i<10; i++)
	{
		// If this it the correct item name
		if (strcmp(m_Items[i].m_sItemName, itemName) == 0)
		{
			Item *newItem = new Item();
			*newItem = m_Items[i];
			// Set the name of the item to the "Empty" string
			strcpy(m_Items[i].m_sItemName, "empty");
			return newItem;
		}
	}
	return NULL;

}


void Character::printAll()
{
	cout << "...Printing character data using printall()..." << endl;
	cout << m_sName << "	" << m_iClass << "		" << m_iAlignment << "		" << m_iHitPoints << "		" << m_iCharTraits[0] << " " << m_iCharTraits[1] << " " << m_iCharTraits[2] << " " << m_iCharTraits[3] << " " << m_iCharTraits[4] << " " << m_iCharTraits[5] << endl << endl;
	for (int i = 0; i<10; i++)
	{
		if (strcmp(m_Items[i].m_sItemName, "empty") != 0)
		{

			cout <<"item:  "<< m_Items[i].m_sItemName << endl;
		}
	}
}
