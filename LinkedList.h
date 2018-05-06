//============================================================================
// Name        : LinkedList.h
// Author      : Antonio Corona-Sanchez & Mengchhay Ear
// Version     :
// Copyright   : Your copyright notice
// Description : 
//Reference from https://github.com/B1anky/CS-240-Program-2--Max-Heap--Hash-Table-with-Linked-List-chaining-/blob/master/DynamicArray.h
//============================================================================
#include "Song.h"
#ifndef LinkedList_h
#define LinkedList_h
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//to be able to set the node 
struct Item
{
	Song* key; 
	Item * next; 
	Item()
	{
		key = NULL;
		next = NULL;
	};
};
class LinkedList 
{
	public:
		LinkedList(); // empty linked list object & creates the node and sets length to zero
		~LinkedList(); 
		void clear();
		void insertItem(Item* newItem); // inserts an iteam at the next of the list
		/*
		* searches for an item by its key.
		* returns a reference to first match
		* returns a NULL pointer if no match is found.
		*/
		Item * getItem(string itemKey);

		//returns the length of the list
		int getLength();

	private:
		Item * head; 
		Item * tail; 
		int length; 
};
#endif // !LinkedList_h

