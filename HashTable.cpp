#include "HashTable.h"
#include <iostream>
#include <string>

using namespace std; 
HashTable::HashTable()
{
	array = unique_ptr<LinkedList[]>();
	length = 0;
}
HashTable::HashTable(int tableLength)
{
	array = unique_ptr<LinkedList[]>(new LinkedList[tableLength]);
	length = tableLength;
}
//returns the array's location for a given item key
int HashTable::hash(string itemKey)
{
	int value = 0; 
	for (int i = 0; i < itemKey.length(); i++)
	{
		value += itemKey[i];
	}
	return (value * itemKey.length()) % length;
}
void HashTable::insertItem(Item *newItem)
{
	int index = hash(newItem->key->getTitle());
	array[index].insertItem(newItem);
}
Item * HashTable::getItemByKey(string itemKey)
{
	int index = hash(itemKey);
	return array[index].getItem(itemKey);
}
int HashTable::getLength()
{
	return length;
}
int HashTable::getNumberOfItems()
{
	int itemCount = 0; 
	for (int i = 0; i < length; i++)
	{
		itemCount += array[i].getLength();
	}
	return itemCount;
}