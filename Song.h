//============================================================================
// Name        : song.cpp
// Author      : Antonio Corona-Sanchez & Mengchhay Ear
// Version     :
// Copyright   : Your copyright notice
// Description : 
//Reference from https://github.com/B1anky/CS-240-Program-2--Max-Heap--Hash-Table-with-Linked-List-chaining-/blob/master/DynamicArray.h
//============================================================================
#ifndef SONG
#define SONG
#include <string>
#include <vector>
#include <iostream>

using namespace std; 

class Song
{
	public:
		Song();
		Song(string titleIn, string artisitIn, string durationIn, int currentClock);
		Song(const Song& s);
		Song& operator=(const Song& s);
		string getArtist() const;
		string getTitle() const;
		string getSong() const; 
		string timeConvert() const; 
		string getAllInfo() const; 
		int getLikeability() const; 
		int getTimeLastPlayed() const; 
		int getPriority() const; 
		int getDuration() const; 
		vector<string>splitstring(string a, string delim);
		int GetSecondsFromString(string& a);
		void setArtist(string artistIn);
		void setTitle(string titleIn);
		void setDuration(int duration);
		void updateLikeability(int likeOrNot);
		void updateTimeLastPlayed(int currentClock);
		void updatePriority();
		bool operator >(Song otherSong);
	private:
		string artist, title; 
		int duration, likeability, timeLastPlayed, priority;
};
#endif