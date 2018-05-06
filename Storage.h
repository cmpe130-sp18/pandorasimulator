#ifndef STORAGE
#define STORAGE

#include "DynamicArray.h"
#include "MaxHeap.h"
#include "Time.h"
#include "HashTable.h"
#include "LinkedList.h"
#include <iostream>
#include <string>

using namespace std;

class Storage {
	public:
		Storage();
		Storage(int maxSongs);
		void add(string title, string artist, string durationString, int playListTime, int maxSongs);
		void setPlayOrder(int &size);
		void setPlayList(int &size);
		void setHashTable(int &size);
		Song* playSong(int currentClockTime);
		bool likeLastPlayed();
		bool likeSpecificSong(std::string toLike);
		bool dislikeLastPlayed();
		bool dislikeSpecificSong(std::string toDislike);
		int getPlayListSize();
		int getPlayListCapacity();
		void printList();

	private:
		unique_ptr<DynamicArray> playList;
		unique_ptr<MaxHeap> playOrder;
		unique_ptr<HashTable> likeTable;
};

#endif// end STORAGE