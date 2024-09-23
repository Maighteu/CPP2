#ifndef EVENT_H
#define EVENT_H
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;
class Event
{
	private:
		char* title;
		int code;
	public:
		Event();
		~Event();
		Event(int c,const char* t);
		Event(const Event &i);
		void setTitle(const char* t);
		void setCode(int c);
		const char* getTitle()const;
		int getCode()const;
		void display()const;
};

#endif