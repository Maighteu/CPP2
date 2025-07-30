#ifndef TIMING_H
#define TIMING_H
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <ctime>
#include <SDL/SDL.h>

#include "Time.h"


using namespace std;
namespace planning{
class Timing
{

    friend ostream &operator<<(ostream &, const Timing &);
    friend istream &operator>>(istream &, Timing &);

	public:
		static const string MONDAY;
		static const string TUESDAY;
		static const string WEDNESDAY;
		static const string THURSDAY;
		static const string FRIDAY;
		static const string SATURDAY;
		static const string SUNDAY;
		Timing();
		~Timing() = default;
		Timing(const Timing& i);
		Timing(const string d, Time s, Time D);

		const string getDay()const;

		Time getStart()const;
		Time getDuration()const;

		void setDay (const string d);
		void setStart(const Time s);
		void setDuration(const Time D);


		void display()const;

		bool operator==(const Timing& i);
		bool operator<(const Timing& i)const;
		bool operator>(const Timing& i)const;
		string toString();
		int d_int(const Timing &);
		bool intersect(const Timing& t);
	private:
		string day="";
		Time start, duration;

};
}
#endif