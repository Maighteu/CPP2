#ifndef TIMING_H
#define TIMING_H
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <string.h>
#include <ctime>
#include "Time.h"

using namespace std;
class Timing
{
	private:
		string day;
		Time start, duration;
	public:
		Timing();
		~Timing();
		Timing(&Timing i);
		Timing(const char& day, Time& s, Time& D);

		const &char getDay()const;
		Time getStart()const;
		Time getDuration()const;
		setDay (const string& day);
		setStart(const Time& s);
		setDuration(const Time& D);

		void Display()const;

};
#endif