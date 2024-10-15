#include "Time.h"
#include "Timing.h"

// const String Timing::MONDAY("Lundi");
// const String Timing::TUESDAY("Mardi");
// const String Timing::WEDNESDAY("Mercredi");
// const String Timing::THURSDAY("Jeudi");
// const String Timing::FRIDAY("Vendredi");
// const String Timing::SATURDAY("Samedi");
// const String Timing::SUNDAY("Dimanche");
		
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
cout<<"start:"<<endl;
start.display();
cout<<"duration:"<<endl;
duration.display();
}