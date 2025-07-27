#include "Event.h"
namespace planning{
int Event::currentCode =1;
Event::Event()
{
	setTitle("default");
	setCode(1);
	timing = nullptr;
}
Event::~Event()
{
	if(title) delete title;
	//if (timing) delete timing; si présent double free
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
	if (i.timing)
	{
		timing = i.timing;
	}
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
	cout<< endl<< "Code: "<<getCode()<<endl<<"Titre: "<< getTitle()<<endl;
	if (timing)	
	{
		printf("\naffiche timing\n");
		timing->display();
	}
}
// void Event::setTiming( Timing* tim)
// {
//  timing= new Timing(*tim);
// }

 Timing& Event::getTiming()const
	{
	return *timing;
}

void Event::setTiming(Timing tim)
{
	timing = &tim;
}
Event& Event::operator=(const Event& i)
{
	setTitle(i.getTitle());
	setCode(i.getCode());
	if (i.timing)
	{
		timing = i.timing;
	}
	return(*this);
}

}