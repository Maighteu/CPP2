#ifndef TIME_H
#define TIME_H
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

class Time
{
	private:
		int hour, minute;
	public:
		Time();
		~Time();
		//Time(Time& i);
		Time(int h, int m);
		Time(int m);
		void setHour(int h);
		void setMinute(int m);
		int getHour()const;
		int getMinute()const;
		void display()const;

};
#endif