#include "Possessions.h"
#include <iostream>
#include <string.h>
using namespace std;

Possessions::Possessions()//constructor
{
	m_pRoot = NULL;
}


Possessions::~Possessions()//desctructor
{
	destroyTree(m_pRoot);
}

Item * CopyItemValue(Item * newItem)
{
	Item * k = new Item;
	strcpy(k->m_sItemName, newItem->m_sItemName);
	strcpy(k->m_sDesc, newItem->m_sDesc);
	k->m_iType = newItem->m_iType;
	k->m_dWeight = newItem->m_dWeight;
	k->m_dValue = newItem->m_dValue;
	k->left = newItem->left;
	k->right = newItem->right;
	return k;

}

bool Possessions::addItem(Item *newItem)
{
	if (m_pRoot == NULL)
	{
		m_pRoot = newItem;
	}
	else
	{
		temp = m_pRoot;
		back = NULL;
		int k;
		while (temp != NULL)
		{
			back = temp;
			k = strcmp(newItem->m_sItemName, temp->m_sItemName);
			if (k < 0)
				temp = temp->left;
			else
				temp = temp->right;
		}
		k = strcmp(newItem->m_sItemName, back->m_sItemName);
		if (k<0)
			back->left = newItem;
		else
			back->right = newItem;
	}
	return(true);
}
Item* Possessions::dropItem(char *itemName)// Delete an item from this list
{
	Item* temp_node=NULL;
	temp = m_pRoot;
	Item* parent = NULL;
	while (temp != NULL && (strcmp(itemName,temp->m_sItemName)!=0))
	{
		parent = temp;
		if (strcmp(itemName,temp->m_sItemName)<0)
			temp = temp->left;
		else
			temp = temp->right;
	}
	if (temp == NULL)
		return NULL;
	else
	{
		// case 1: no children
		if (temp->left == NULL && temp->right == NULL)
		{
			if (parent == NULL) 
				m_pRoot = NULL;
			else
			{
				if (parent->left == temp)
					parent->left = NULL;
				else
					parent->right = NULL;
			}
			//copy values and return pointer
			strcpy(temp_node->m_sItemName, temp->m_sItemName);
			strcpy(temp_node->m_sDesc, temp->m_sDesc);
			temp_node = CopyItemValue(temp);//copy value to temp node
			delete temp;
			
		}

		// case 2: one child on the left
		else if (temp->right == NULL)
		{
			if (parent == NULL)
				m_pRoot = temp->left;
			else
			{
				if (parent->left == temp)
					parent->left = temp->left;
				else
					parent->right = temp->left;
			}
			temp_node = CopyItemValue(temp);
			delete temp;
		}

		//case 3: one child on the right
		else if (temp->left == NULL)
		{
			if (parent == NULL)
				m_pRoot = temp->right;
			else
			{
				if (parent->left == temp)
					parent->left = temp->right;
				else
					parent->right = temp->right;
			}
			temp_node = CopyItemValue(temp);
			delete temp;
		}

		// case 4: two children
		else
		{
			Item* temp2 = temp->left;
			Item* parent2 = temp;
			while (temp2->right != NULL)
			{
				parent2 = temp2;
				temp2 = temp2->right;
			}
			// copy the values in the node pointed to by "temp2" into the values in the node pointed to by "temp"
			temp->m_dValue = temp2->m_dValue;
			temp->m_dWeight = temp2->m_dWeight;
			temp->m_iType = temp2->m_iType;
			strcpy(temp->m_sDesc, temp2->m_sDesc);
			strcpy(temp->m_sItemName , temp2->m_sItemName);
			if (parent2 == temp)
				parent2->left = temp2->left;
			else
				parent2->right = temp2->left;
			temp_node = CopyItemValue(temp2);
			delete temp2;
		}
		return temp_node;
	}
}
Item* Possessions::search(char *itemName)//search function to find the node in binary search tree
{
	temp = m_pRoot;
	while ((temp != NULL) && strcmp(temp->m_sItemName, itemName) != 0)
	{
		if (strcmp(itemName, temp->m_sItemName)<0)
			temp = temp->left;
		else
			temp = temp->right;
	}
	if (temp == NULL)
		return NULL;
	else
	{
		// duplicate the found node
		// and return the duplicate
		Item *n = new Item;
		n = temp;
		return n;
	}
}
Item* Possessions::getItem(char *itemName)
{
	//call search function
	return search(itemName);

}
//all the print funtions
void Possessions::printOne(Item *T)
{
	cout << T->m_sItemName << "\t\t" << T->m_sDesc << "\t\t" << T->m_iType << "\t\t" << T->m_dWeight << T->m_dValue << "\t\t" << "\n";
}
void Possessions::printTree()
{
	printAll(m_pRoot);
}
void Possessions::printAll(Item *T)
{
	if (T != NULL)
	{
		printAll(T->left);
		printOne(T);
		printAll(T->right);
	}
}
//delete tree
void Possessions::destroyTree(Item *rt)
{
	if (rt != NULL)
	{
		destroyTree(rt->left);
		destroyTree(rt->right);
		delete rt;
	}
}

//copy values function for item
