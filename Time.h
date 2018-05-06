//
#ifndef TIME
#define TIME
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Time 
{
	public:
		Time();
		Time(string timeIn, int maxSongsIn);
		string getTime();
		int getDay();
		int getHour();
		int getMin();
		int getSec();
		int getTotalSec();
		int getSongs();
		void setDay(int daysIn);
		void setHour(int hourIn);
		void setMin(int minsIn);
		void setSec(int secsIn);
		void setTotalTime(int totalTimeIn);
		void setSongs(int maxSongsIn);
		void deltaTime(int delta);
		void rest(string timeString);
		vector<string> splitstring(string a, string delim);
		int GetSecondsFromString(string& a);
	private:
		int day, hours, mins, secs, daysSeconds, totalSeconds, maxSongs;
};
#endif
