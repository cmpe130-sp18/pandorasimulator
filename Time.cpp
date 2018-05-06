//============================================================================
// Name        : Time.cpp
// Author      : Antonio Corona-Sanchez & Mengchhay Ear
// Version     :
// Copyright   : Your copyright notice
// Description : 
//Reference from https://github.com/B1anky/CS-240-Program-2--Max-Heap--Hash-Table-with-Linked-List-chaining-/blob/master/DynamicArray.h
//============================================================================
#include "Time.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

Time::Time()
{
	secs = 0; 
	mins = 0;
	hours = 0;
	totalSeconds = 0;
	maxSongs = 100;
	day = 1;
}
Time::Time(string timeIn, int maxSongsIn)
{
	string tempHours = "";
	string tempMins = "";
	string tempSecs = "";
	tempHours += timeIn[0];
	tempHours += timeIn[1];
	tempMins += timeIn[3];
	tempMins += timeIn[4];
	tempSecs += timeIn[6];
	tempSecs += timeIn[7];

	hours = atoi(tempHours.c_str());
	mins = atoi(tempMins.c_str());
	secs = atoi(tempSecs.c_str());
	daysSeconds = (3600 * hours) + (60 * mins) + secs;
	totalSeconds = (3600 * hours) + (60 * mins) + secs;
	maxSongs = maxSongsIn;
	day = 1;
}
int Time::getDay() { return day; }

int Time::getHour() { return hours; }

int Time::getMin() { return mins; }

int Time::getSec() { return secs; }

int Time::getTotalSec() { return totalSeconds; }

int Time::getSongs() { return maxSongs; }

//Neatly formatted Print

string Time::getTime()
{
	string dayAndTime = "[Day ";
	dayAndTime += to_string(getDay());
	dayAndTime += ": ";
	//pad hour over to match up with hours 10 - 12 neatly;
	if ((getHour() >= 1 && getHour() <= 9) || (getHour() >= 13 && getHour() <= 21))
	{
		dayAndTime += " ";
	}
	if (getHour() > 12)
	{
		dayAndTime += to_string(getHour() - 12);
		dayAndTime += ":";
	}
		else if (getHour() == 0 || getHour() == 24)
		{
			dayAndTime += to_string(12);
			dayAndTime += ":";
		}
		else {
			dayAndTime += to_string(getHour());
			dayAndTime += ":";
		}
	if (getMin() < 10)
	{
		dayAndTime += "0";
		dayAndTime += to_string(getMin());
		dayAndTime += ":";
	}
	else {
		dayAndTime += to_string(getMin());
		dayAndTime += ":";
	}
	if (getSec() < 10)
	{
		dayAndTime += "0";
		dayAndTime += to_string(getSec());
	}
	else {
		dayAndTime += to_string(getSec());
	}
	if (getHour() >= 12 && getHour() < 24)
	{
		dayAndTime += "pm]";
	}
	else {
		dayAndTime += "am]";
	}
	
	return dayAndTime;
}
void Time::setDay(int daysIn) { day = daysIn; }

void Time::setHour(int hoursIn) { hours = hoursIn; }

void Time::setMin(int minsIn) { mins = minsIn; }

void Time::setSec(int secsIn) { secs = secsIn; }

void Time::setTotalTime(int totalTimeIn) { totalTimeIn; }

void Time::setSongs(int maxSongsIn) { maxSongs = maxSongsIn; }

void Time::deltaTime(int delta)
{
	totalSeconds += delta;
	daysSeconds += delta; 
	while (daysSeconds >= 86400)
	{
		day++;
		daysSeconds = daysSeconds - 86400;
	}
	setHour((daysSeconds / 60 / 60) % 24);
	setMin((daysSeconds / 60) % 60);
	setSec(daysSeconds % 60);
}

void Time::rest(string timeString)
{
	deltaTime(GetSecondsFromString(timeString));
}

vector<string> Time::splitstring(string a, string delim)
{
	vector<string> ret;
	size_t pos = 0;
	string token;
	while ((pos = a.find(delim)) != string::npos)
	{
		token = a.substr(0, pos);
		ret.push_back(token);
		//cout << token << endl;
		a.erase(0, pos + delim.length());
	}
	return ret;
}
int Time::GetSecondsFromString(string& a)
{
	a += ":";
	vector<string> s = splitstring(a, ":");
	int hours = 0; 
	int mins = 0; 
	int secs = 0; 
	switch (s.size())
	{
		case 3:
			hours = atoi(s[0].c_str());
			mins = atoi(s[1].c_str());
			secs = atoi(s[2].c_str());
			break; 
		case 2: 
			mins = atoi(s[0].c_str());
			secs = atoi(s[1].c_str());
			break; 
		case 1:
			secs = atoi(s[0].c_str());
			break;
		case 0: 
		default:
			break;
	}
	while (hours != 0)
	{
		mins += 60;
		hours--;
	}
	while (mins != 0)
	{
		secs += 60; 
		mins--;
	}
	return secs;
}