//============================================================================
// Name        : HashTable.h
// Author      : Antonio Corona-Sanchez & Mengchhay Ear
// Version     :
// Copyright   : Your copyright notice
// Description : 
//Reference from https://github.com/B1anky/CS-240-Program-2--Max-Heap--Hash-Table-with-Linked-List-chaining-/blob/master/DynamicArray.h
//============================================================================
#ifndef HashTable_h
#define HashTable_h
#include "LinkedList.h"
#include <iostream>
#include <string>
#include <memory>

using namespace std; 

class HashTable
{
	public:
		HashTable();
		HashTable(int tableLength);
		//array length is set to 13 by default
		void insertItem(Item* newItem); // adds an item to the hash table
		Item* getItemByKey(string itemKey); //return
		int getLength();//return the number of location
		int getNumberOfItems();//return the number of items
	private:
		unique_ptr<LinkedList[]> array;
		int length; 
		int hash(string itemKey);
};

#endif
