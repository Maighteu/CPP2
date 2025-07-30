#ifndef EVENT_H
#define EVENT_H
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include "Timing.h"

using namespace std;

namespace planning{
class Event
{
    friend ostream &operator<<(ostream &, const Event &);
    friend istream &operator>>(istream &, Event &);
    
	protected:

		Timing* timing;
		char* title;
		int code;

	public:
		static int currentCode; 
		Event();
		~Event();
		Event(int c,const char* t);
		Event(const Event &i) ;
		void setTitle(const char* t);
		void setCode(int c);

		void setTiming(const Timing& t);
		//void setTiming( Timing* tim);
		 Timing getTiming()const;
		
		const char* getTitle()const;
		int getCode()const;
		void display()const;
		string toString();
};
}
#endif

