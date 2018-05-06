#include "Storage.h"
#include <iostream>

using namespace std; 

Storage::Storage() { /*literally do nothing*/}

Storage::Storage(int maxSongs) {
	setPlayOrder(maxSongs);
	setPlayList(maxSongs);
	setHashTable(maxSongs);
}

void Storage::add(string title, string artist, string durationString, int playListTime, int maxSongs) {
	Song* toAdd = playList->push_back(title, artist, durationString, playListTime, maxSongs);
	playOrder->Enqueue(toAdd, playListTime);
	Item *hashAdd = new Item();
	hashAdd->key = toAdd;
	likeTable->insertItem(hashAdd);
}

Song* Storage::playSong(int currentClockTime) {
	if (playOrder->getHeapSize() > 1) {
		Song *toPlay = playOrder->Dequeue(currentClockTime);
		if (toPlay) {
			toPlay->updateTimeLastPlayed(currentClockTime + toPlay->getDuration());
			playOrder->Enqueue(toPlay, currentClockTime);
			return toPlay;
		}
		else {
			return NULL;
		}

	}
	else if (playOrder->getHeapSize() == 1) {
		Song *toPlay = playOrder->getData(0);
		toPlay->updateTimeLastPlayed(currentClockTime + toPlay->getDuration());
		playOrder->setLastPlayed(toPlay);
		cout << "Playing " << toPlay->getAllInfo() << endl;
		return toPlay;
	}
	else {
		return NULL;
	}
}

bool Storage::likeLastPlayed() {
	if (playOrder->getLastPlayed()) {
		playOrder->getLastPlayed()->updateLikeability(1);
		return true;
	}
	else {
		return false;
	}
}

bool Storage::likeSpecificSong(string toLike) {
	if (likeTable->getItemByKey(toLike)) {
		likeTable->getItemByKey(toLike)->key->updateLikeability(1);
		return true;
	}
	else {
		return false;
	}
}

bool Storage::dislikeLastPlayed() {
	if (playOrder->getLastPlayed()) {
		playOrder->getLastPlayed()->updateLikeability(0);
		return true;
	}
	else {
		return false;
	}
}

bool Storage::dislikeSpecificSong(string toDislike) {
	if (likeTable->getItemByKey(toDislike)) {
		likeTable->getItemByKey(toDislike)->key->updateLikeability(0);
		return true;
	}
	else {
		return false;
	}
}

void Storage::setPlayOrder(int &size) { playOrder = unique_ptr<MaxHeap>(new MaxHeap(size)); }

void Storage::setPlayList(int &size) { playList = unique_ptr<DynamicArray>(new DynamicArray(size)); }

void Storage::setHashTable(int &size) { likeTable = unique_ptr<HashTable>(new HashTable(size)); }

int Storage::getPlayListCapacity() { return playList->getCapacity(); }

int Storage::getPlayListSize() { return playList->size(); }
void Storage::printList() {
	for (int i = 0; i < playOrder->getHeapSize(); i++) 
	{
		cout << playOrder->getData(i)->getAllInfo() << ". Priority: " << playOrder->getData(i)->getPriority() << endl;
	}
}