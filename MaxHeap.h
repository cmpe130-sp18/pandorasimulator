//============================================================================
// Name        : MaxHeap.h
// Author      : Antonio Corona-Sanchez & Mengchhay Ear
// Version     :
// Copyright   : Your copyright notice
// Description : 
//Reference from https://github.com/B1anky/CS-240-Program-2--Max-Heap--Hash-Table-with-Linked-List-chaining-/blob/master/DynamicArray.h
//============================================================================
// Reference: Dr. Rick Coleman at http://www.cs.uah.edu/~rcoleman/Common/CodeVault/Code/Code211_Heap.html
#ifndef MAXHEAP
#define MAXHEAP

#include "Song.h"

class MaxHeap {
private:
	int heapLength;
	int numElements;
	Song **data;
	Song *lastPlayed;

	int getLeftInd(int nodeInd);
	int getRightInd(int nodeInd);
	int getParentInd(int nodeInd);
public:
	MaxHeap();
	MaxHeap(int size);
	MaxHeap(MaxHeap& otherHeap);
	MaxHeap& operator=(MaxHeap &otherHeap);
	~MaxHeap();

	int getMaximum();
	Song* getData(int index);
	Song** getAllData();
	int getHeapSize();
	int getArraySize();
	void ReheapUp(int root, int bottom, int currentClockTime);
	bool Enqueue(Song *song, int currentClockTime);
	void ReheapDown(int root, int bottom, int currentClockTime);
	Song* Dequeue(int currentClockTime);
	void setLastPlayed(Song *toPlay);
	Song* getLastPlayed();

};
#endif // !MAXHEAP

