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
ostream &operator<<(ostream &s, const Timing &o)
{
    s << "<Timing>" << endl;

    s << "<day>" << endl;
    s << o.getDay() << endl;
    s << "</day>" << endl;

    s << "<start>" << endl;
    s << o.getStart() << endl;
    s << "</start>" << endl;

    s << "<duration>" << endl;
    s << o.getDuration() << endl;
    s << "</duration>" << endl;

    s << "</Timing>" << endl;

    return s;
}

istream &operator>>(istream &s, Timing &i)
{
    string line;

    getline(s, line);

    getline(s, line);
    getline(s, line);
    i.setDay(line); //pas de stoi ici
    getline(s, line);
    getline(s, line);
    s >> i.start;
    getline(s, line);
    getline(s, line);
    s >> i.duration;
    getline(s, line);
    getline(s, line);
    getline(s, line);

    return s;
}
 string Timing::toString()
 {
     return " Day: " + day + " Start: " + start.toString() + " Duration: " + duration.toString();
 }


int Timing::d_int(const Timing &d)
{
    if (d.day == "Lundi") return 1;
    if (d.day == "Mardi") return 2;
    if (d.day == "Mercredi") return 3;
    if (d.day == "Jeudi") return 4;
    if (d.day == "Vendredi") return 5;
    if (d.day == "Samedi") return 6;
    if (d.day == "Dimanche") return 7;
    return 0;
}

bool Timing::intersect(const Timing &i)
{

    if(d_int((*this)) != d_int(i))
        return false;

    Time s = this->getStart(); // 10h00
    Time S = i.getStart(); //12h00

    Time d = this->getDuration(); //1h00
    Time D = i.getDuration(); // 00h30

    if (s < S)
    {
        if ((s + d) < S)
            return false;
        else
            return true;
    }
    else
    {
        if ((S + D) < s)
            return false;
        else
            return true;

    }
}
}