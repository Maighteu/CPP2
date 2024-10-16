#ifndef EVENT_H
#define EVENT_H
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include "Timing.h"

using namespace std;
static int currentCode = 1; 

class Event
{
	private:
		Timing* timing = nullptr;
		char* title;
		int code;

	public:
		Event();
		~Event();
		Event(int c,const char* t);
		Event(const Event &i);
		void setTitle(const char* t);
		void setCode(int c);


		void setTiming(Timing* tim);
		const Timing* getTiming()const;
		
		const char* getTitle()const;
		int getCode()const;
		void display()const;
};

#endif

