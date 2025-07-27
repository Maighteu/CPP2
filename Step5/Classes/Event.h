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
	private:

		Timing* timing;
		char* title;
		int code;

	public:
		static int currentCode; 
		Event();
		~Event();
		Event(int c,const char* t);
		Event(const Event &i);
		void setTitle(const char* t);
		void setCode(int c);

		void setTiming(const Timing& tim);
		//void setTiming( Timing* tim);
		 Timing& getTiming()const;
		
		const char* getTitle()const;
		int getCode()const;
		void display()const;
		Event& operator=(const Event& i);

};
}
#endif

