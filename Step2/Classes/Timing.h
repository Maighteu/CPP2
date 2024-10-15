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

	public:
		// static const Timing MONDAY;
		// static const Timing TUESDAY;
		// static const Timing WEDNESDAY;
		// static const Timing THURSDAY;
		// static const Timing FRIDAY;
		// static const Timing SATURDAY;
		// static const Timing SUNDAY;
		Timing();
		~Timing();
		Timing(const Timing& i);
		Timing(const string d, Time s, Time D);

		const string getDay()const;

		Time getStart()const;
		Time getDuration()const;

		void setDay (const string d);
		void setStart(const Time s);
		void setDuration(const Time D);

		void display()const;
	private:
		string day="default";
		Time start, duration;

};
#endif