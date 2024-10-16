#include "Event.h"


Event::Event()
{
	setTitle("default");
	setCode(1);
}
Event::~Event()
{
	if(title) delete title;
}
Event::Event(int c,const char* t)
{
	setTitle(t);
	setCode(c);
}
Event::Event(const Event& i)
{
	setTitle(i.getTitle());
	setCode(i.getCode());

}

void Event::setTitle(const char*t)
{
	title = new char[strlen(t)+1];
	strcpy(title,t);
}
void  Event::setCode(int c)
{
	code = c;
}
const char* Event::getTitle()const
{
	return title;
}
int Event::getCode()const
{
	return code;

}
void Event::display()const
{
	cout<< endl<< getCode()<<endl<< getTitle()<<endl ;

	timing->display();
}

void Event::setTiming(Timing* tim)
{
 timing= tim;
}
const Timing* Event::getTiming()const
{
	return *timing;
}