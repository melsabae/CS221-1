//purpose: implement the function of character.h 
#include"Character.h"

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

}

Character::Character(char *name, int cl, int al, int hp, int str, int dex, int con, int itl, int wis, int chr)
{
	strcpy(m_sName , name);
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
	if (str>=0)
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
	
	
}
//get char name
void Character::getName(char *name)
{
	strcpy(name, m_sName);
}
void Character::setName(char *name)
{
	strcpy(m_sName,name);
}

//get and set char class
void Character::getClass(int& cl)
{
	cl= m_iClass;
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
void Character::getAlignment(int& al)
{
	al = m_iAlignment;
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
void Character::getHitPoints(int& hp)
{
	hp = m_iHitPoints;
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

void Character::getStrength(int *str)
{
	*str = m_iCharTraits[0];
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

void Character::getDexterity(int *dex)
{
	*dex = m_iCharTraits[1];
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

void Character::getConstitution(int *cn)
{
	*cn = m_iCharTraits[2];
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

void Character::getIntelligence(int *itl)
{
	*itl = m_iCharTraits[3];
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

void Character::getWisdom(int *wis)
{
	*wis = m_iCharTraits[4];
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

void Character::getCharisma(int *chr)
{
	*chr = m_iCharTraits[5];
}
void Character::setCharisma(int chr)
{
	if (chr>=0)
	{
		m_iCharTraits[5] = chr;
	}
	else
	{
		m_iCharTraits[5] = 0;

	}
	
}

void Character::printAll()
{
	cout << "...Printing character data using printall()..." << endl;
	cout << m_sName << "	" << m_iClass << "		" << m_iAlignment << "		" << m_iHitPoints << "		" << m_iCharTraits[0] << " " << m_iCharTraits[1] << " " << m_iCharTraits[2] << " " << m_iCharTraits[3] << " " << m_iCharTraits[4] << " " << m_iCharTraits[5] << endl << endl;
}