#include "LinkedList.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

LinkedList::LinkedList()
{
	//empty linked list object
	//head node and sets length to zero 
	head = NULL; 
	tail = NULL; 
	length = 0;
}
void LinkedList::clear()
{
	while (head != NULL)
	{
		Item* tmp = head->next;
		delete head; //deletes first link from memory
		head = tmp;
	}
	tail = NULL; 
}
LinkedList::~LinkedList()
{
	clear();
}
void LinkedList::insertItem(Item* newItem)
{
	if (!head)
	{
		this->head = newItem;
		tail = head;
		length++;
		return; 
	}
	tail->next = newItem; 
	tail = tail->next; 
	length++;
}
/*
* Searches for an item by its key
* returns a reference to fist match
* returns a NULL  pointer if no match is found
*/
Item *LinkedList::getItem(string itemKey)
{
	Item * p = head; 
	Item * q = head; 
	while (q)
	{
		p = q;
		if (p->key->getTitle() == itemKey)
		{
			return p; 
		}
		q = p->next; 
	}
	return NULL; 
}

//return the length of the list
int LinkedList::getLength()
{
	return length;
}