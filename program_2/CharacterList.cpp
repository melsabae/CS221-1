#include "CharacterList.h"


CharacterList::CharacterList()
{
	ChrPtr = NULL;
}


CharacterList::~CharacterList()
{
	
}

//delete character from list
Character* CharacterList::deleteCharacter(char *characterName)
{
	Character *temp, *back, *Character_return;

	if (ChrPtr = NULL) return false;

	temp = ChrPtr;
	back = NULL;
	while ((temp != NULL) && (strcmp(characterName,temp->getName())!=0))
	{
		back = temp;
		temp = temp->m_pNext;
	}

	if (temp == NULL) return NULL;  
	else if (back == NULL) // Check to see if item is first in list
	{
		ChrPtr = ChrPtr->m_pNext;
		temp->m_pNext = NULL;
		return temp;
		delete temp; // Dispose of the node removed from the list
	}
	else if (strcmp(temp->getName(),characterName)==0)// Delete node elsewhere in the list
	{
		
		back->m_pNext = temp->m_pNext;
		temp->m_pNext = NULL;
		return temp;
		
		delete temp; // Dispose of the node removed from the list
	}
	else
	{
		return NULL;

	}
	
}

//add item to character
bool CharacterList::addItem(char *characterName, Item *newItem)
{
	Character *temp = ChrPtr;
	if (ChrPtr == NULL)
	{
		cout << "Empty characterlist." << endl;
		return false;
	}
	else
	{ 
		int count = 0;
		while (temp!= NULL)
		{
			if (strcmp(temp->getName(), characterName) == 0)
			{
				temp->addItem(newItem);
				cout << "Successful add item." << endl;
				count++;
			}
			temp = temp->m_pNext;

		}
		if (count == 0)
		{
			cout << "can't find character" << endl;
		}
	}
	return true;
}
//get item from character
Item* CharacterList::getItem(char *characterName, char *itemName)
{
	char name[65];
	int k = 0;
	Character *temp = ChrPtr;
	if (ChrPtr == NULL)
	{
		cout << "list is empty" << endl;
		return NULL;
	
	}
	else
	{

		while (temp != NULL)
		{

			if (strcmp(characterName, temp->getName()) == 0)
			{
				return temp->getItem(itemName);
				cout << "get item succesful" << endl;
			}
			temp = temp->m_pNext;

		}
		if (k == 0)
		{
			cout << "item not found" << endl;
		}
	}
}
//drop item
Item * CharacterList::dropItem(char *characterName, char *itemName)
{
	char name[65];
	int k = 0;
	Character *temp = ChrPtr;
	if (ChrPtr == NULL)
	{
		cout << "list is empty" << endl;
		return NULL;

	}
	else
	{

		while (temp != NULL)
		{

			if (strcmp(characterName, temp->getName()) == 0)
			{
				return temp->dropItem(itemName);
				cout << "drop item succesful" << endl;
			}
			temp = temp->m_pNext;

		}
		if (k == 0)
		{
			cout << " item not found" << endl;
		}
	}

}
//add character to list
bool CharacterList::addCharacter(Character *newCharacter)
{
	char name[65];
	Character *temp, *back;
	if (newCharacter == NULL) return false;
	strcpy(name, newCharacter->getName());
	newCharacter->m_pNext = NULL; 

	if (ChrPtr==NULL)
	{
		// Insert new node as first in the list
		ChrPtr = newCharacter;
	}
	else
	{
		// Find location for new node in the list
		temp = ChrPtr;
		back = NULL;
		while ((temp != NULL) && (strcmp(temp->getName(),newCharacter->getName())<0))
		{
			back = temp;
			temp = temp->m_pNext;
		}

		if (back == NULL)
		{
			newCharacter->m_pNext = ChrPtr;
			ChrPtr = newCharacter;
		}
		else // Insert somewhere else in list
		{
			back->m_pNext = newCharacter;
			newCharacter->m_pNext = temp;
		}

	}
	return true;


}

//print character to display
void CharacterList::printCharacters()
{
	Character *temp;
	if (ChrPtr == NULL)
	{
		cout << "list is empty!!!" << endl;
	}
	else
	{
		temp = ChrPtr;
		while (temp != NULL)
		{
			//cout << temp->getName() << endl;
			temp->printAll();

			temp = temp->m_pNext;
		}
	}

}