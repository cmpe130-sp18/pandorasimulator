//============================================================================
// Name        : DynamicArray.h
// Author      : Antonio Corona-Sanchez & Mengchhay Ear
// Version     :
// Copyright   : Your copyright notice
// Description : 
//Reference from https://github.com/B1anky/CS-240-Program-2--Max-Heap--Hash-Table-with-Linked-List-chaining-/blob/master/DynamicArray.h
//============================================================================
#ifndef DYNAMICARRAY
#define DYNAMICARRAY
#include "Song.h"
#include <iostream>
#include <string>

using namespace std;

class DynamicArray
{
public:
	DynamicArray();
	DynamicArray(int maxSongs);
	Song* push_back(string title, string artist, string durationString, int playListTime, int maxSongs);
	size_t size();
	int getCapacity();
	Song& operator[](int index);
	~DynamicArray();
private:
	int numSongs, capacity, Log;
	Song* songs;
};
#endif // !DYNAMICARRAY
#pragma once
