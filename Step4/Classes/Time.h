#ifndef TIME_H
#define TIME_H
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;
namespace planning{
class Time
{
	friend Time operator+(int min, Time t);
	friend Time operator-(int min, Time t);
	friend std::ostream& operator<<(std::ostream& s,const Time& i);
	friend std::istream& operator>>(std::istream& s, Time& i);
	private:
		int hour, minute;
	public:
		Time();
		~Time();
		Time(const Time& i);
		Time(int h, int m);
		Time(int m);
		void setHour(int h);
		void setMinute(int m);
		int getHour()const;
		int getMinute()const;
		void display()const;
		
		Time& operator=(const Time& i);
		Time operator+(int m);
		Time operator+(const Time& i);
		Time operator-(int m);
		Time operator-(const Time& i);
		bool operator==(const Time& i);
		bool operator<(const Time& i)const;
		bool operator>(const Time& i)const;
		Time operator++(int);
		Time operator++();
		Time operator--(int);
		Time operator--();

};
}
#endif