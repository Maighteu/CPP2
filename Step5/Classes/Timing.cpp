#include "Time.h"
#include "Timing.h"
#include "TimeException.h"
#include "TimingException.h"

namespace planning{
 const string Timing::MONDAY("Lundi");
 const string Timing::TUESDAY("Mardi");
 const string Timing::WEDNESDAY("Mercredi");
 const string Timing::THURSDAY("Jeudi");
 const string Timing::FRIDAY("Vendredi");
 const string Timing::SATURDAY("Samedi");
 const string Timing::SUNDAY("Dimanche");
		
Timing::Timing()
{
	setDay("Lundi");
	setStart(Time());
	setDuration (Time());
}
 
Timing::Timing(const Timing& i)
{
	setDay(i.getDay());
	setStart(i.getStart());
	setDuration (i.getDuration());
}


Timing::Timing(const string day, Time s, Time D)
{
	setDay(day);
	setStart(s);
	setDuration (D);
}

void Timing::setDay(const string d)
{ 
	if (d.empty()) throw TimingException(TimingException::INVALID_DAY, "No day inserted");

	if (d == Timing::MONDAY)
	{
	    day = d;
	}
	else if (d == Timing::TUESDAY)
	{
	    day = d;
	}
	else if (d == Timing::WEDNESDAY)
	{
	    day = d;
	}
	else if (d == Timing::THURSDAY)
	{
	    day = d;
	}
	else if (d == Timing::FRIDAY)
	{
	    day = d;
	}
	else if (d == Timing::SATURDAY)
	{
	    day = d;
	}
	else if (d == Timing::SUNDAY)
	{
	    day = d;
	}
	else
	{
	    throw TimingException(TimingException::INVALID_DAY, "Non existing day inserted");
	}
}

void Timing::setStart(const Time s)
{
	start.setHour(s.getHour());
	start.setMinute(s.getMinute());
	// start = s;
}

void Timing::setDuration(const Time D)
{

	duration.setHour(D.getHour());
	duration.setMinute(D.getMinute());
	// duration =D ;
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
cout<<endl<<"Timing here"<<endl<<"day :"<<getDay()<<endl;
cout<<"start:";
start.display();
cout<<"duration:";
duration.display();
cout<<endl<<"find display";
}	

bool Timing::operator==(const Timing& i)
{
	if( (getDay()==i.getDay()) &&(getStart() == i.getStart()) && (getDuration() == i.getDuration()) ) return true;
	return false;
}

bool Timing::operator<(const Timing& i) const
{
	if(getDay() < i.getDay()) return true;
	if(getDay() > i.getDay()) return false;

	if(getStart() < i.getStart()) return true;
	if(getStart() > i.getStart()) return false;

	if( getDuration() < i.getDuration() ) return true;
	if( getDuration() < i.getDuration() ) return false;

	return false;
}

bool Timing::operator>(const Timing& i) const
{
	return i < (*this);
	
}
}