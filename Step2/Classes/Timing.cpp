#include "Time.h"
#include "Timing.h"

 const string Timing::MONDAY("Lundi");
 const string Timing::TUESDAY("Mardi");
 const string Timing::WEDNESDAY("Mercredi");
 const string Timing::THURSDAY("Jeudi");
 const string Timing::FRIDAY("Vendredi");
 const string Timing::SATURDAY("Samedi");
 const string Timing::SUNDAY("Dimanche");
		
Timing::Timing()
{
	setDay("Default");
	setStart(Time());
	setDuration (Time());
}
Timing::Timing(const Timing& i)
{
	setDay(i.getDay());
	setStart(i.getStart());
	setDuration (i.getDuration());
}
Timing::~Timing()
{

}
Timing::Timing(const string day, Time s, Time D)
{
	setDay(day);
	setStart(s);
	setDuration (D);
}

void Timing::setDay(const string d)
{
	day= d;
}

void Timing::setStart(const Time s)
{
	// start.setHour(s.getHour());
	// start.setMinute(s.getMinute());
	start = s;
}

void Timing::setDuration(const Time D)
{

	// duration.setHour(D.getHour());
	// duration.setMinute(D.getMinute());
	duration =D ;
}

const string Timing::getDay() const
{
	return day;
}

Time Timing::getStart() const
{
	return start;
}

Time Timing::getDuration() const 
{
	return duration;
}

void Timing::display() const
{

cout<<endl<<getDay()<<endl;
printf("\ntiming here\n");
cout<<"start:";
start.display();
cout<<"duration:";
duration.display();
}