#ifndef SCHEDULABLE_H
#define SCHEDULABLE_H
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <ctime>

class  Schedulable
{

private:
	int id;
public:
		Schedulable();
		~Schedulable();
		Schedulable(const Schedulable& i);
		Schedulable(const int i);

		int getId()const;
		void setId(int i);

		const string toString() const;
		const string tuple() const;

};
#endif