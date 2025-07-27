#ifndef SCHEDULABLE_H
#define SCHEDULABLE_H
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;
class Schedulable
{
	protected:
		int id;
	public:
		Schedulable();
		virtual ~Schedulable();
		Schedulable(int);
		Schedulable(const Schedulable&);
		void setId(int);
		int getId() const;
		void display() const;


		virtual string toString() const = 0;
		virtual string tuple() const = 0;
};


#endif