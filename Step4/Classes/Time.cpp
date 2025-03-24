#include "Time.h"

namespace planning{

Time::Time()
{
	setHour(0);
	setMinute(0);

}
Time::~Time()
{

}

Time::Time(const Time& i)
{
	setHour(i.getHour());
	setMinute(i.getMinute());
}
Time::Time(int h, int m)
{
	setHour(h);
	setMinute(m);
}
Time::Time(int m)
{
	int h;
	h = (m /60);
	m = (m % 60);
	setHour(h);
	setMinute(m);
}

void Time::setHour(int h)
{
	hour = h;
}
void Time::setMinute(int m)
{
	minute = m;
}
int Time::getHour() const
{
	return hour;
}
int Time::getMinute() const
{
	return minute;
}
void Time::display() const
{
	cout<<getHour()<<"h";
	if (getMinute() <10) cout<<"0";

	cout<< getMinute()<<endl;
}
Time& Time::operator=(const Time& i)
{
	setHour(i.getHour());
	setMinute(i.getMinute());
	return (*this);
}
Time Time::operator+(int m)
{
	Time t(*this);
	int h;
	h = (m /60);
	m = (m % 60);
	t.setMinute(getMinute()+ m);
	t.setHour(getHour()+h);

	if(t.getMinute()>=60)
	{
		t.setMinute(t.getMinute()-60);
		t.setHour(t.getHour()+1);
	}
	if (t.getHour()>=24)
	{
		t.setHour(t.getHour()-24);

	}
	return t;

}
Time Time::operator+(const Time& temp) 
	{	
		Time t(*this);
	
	t.setMinute(getMinute()+ temp.minute);
	t.setHour(getHour()+temp.hour);

	if(t.getMinute()>=60)
	{
		t.setMinute(t.getMinute()-60);
		t.setHour(t.getHour()+1);
	}
	if (t.getHour()>24)
	{
		t.setHour(t.getHour()-24);

	}
 
		return t;
	}

Time operator+(int min, Time t) 
{	
	return t + min;
}


Time Time::operator-(int m)
{
	Time t(*this);
	int h;
	h = (m /60);
	m = (m % 60);
	t.setMinute(getMinute()- m);
	t.setHour(getHour()- h);
	if(t.getMinute()<=0)
	{
		t.setMinute(t.getMinute()+60);
		t.setHour(t.getHour()-1);
	}
	if (t.getHour()<=0)
	{
		t.setHour(t.getHour()+24);
	}

	return t;

}
Time Time::operator-(const Time& temp) 
{	
	Time t(*this);

	t.setMinute(getMinute()- temp.minute);
	t.setHour(getHour()- temp.hour);

	if(t.getMinute()<=0)
	{
		t.setMinute(t.getMinute()+60);
		t.setHour(t.getHour()-1);
	}
	if (t.getHour()<=0)
	{
		t.setHour(t.getHour()+24);

	}
 
	return t;

}
Time operator-(int min, Time t) 
{	
	Time temp;
 
		temp.setHour(min /60);
		temp.setMinute(min%60);
 
		temp.setHour(temp.getHour() - t.getHour());
		temp.setMinute(temp.getMinute() - t.getMinute());
 
		if (temp.getMinute() < 0)
		{
			temp.setMinute(temp.getMinute() + 60);
			temp.setHour(temp.getHour() - 1);
		}
 
		if (temp.getHour() < 0)
		{
			temp.setHour(temp.hour + 24);
		}
 
		return temp;
}


bool Time::operator==(const Time& i)
{
	if( (getHour() == i.getHour()) && (getMinute() == i.getMinute()) ) return true;
	return false;
}

bool Time::operator<(const Time& i)
{

	if(getHour() < i.getHour()) return true;
	if( getMinute() < i.getMinute() ) return true;
	return false;
}

bool Time::operator>(const Time& i)
{

	if(getHour() > i.getHour()) 
	if( getMinute() > i.getMinute() ) return true;
	return false;
}

ostream& operator<<(ostream& s,const Time& i)
{
	s<<i.getHour()<<"H"<<i.getMinute();
	return s;
}

istream& operator>>(istream& s, Time& i)
  {
  	string c, temph, tempm;
    int h,m;

    cout<<endl<<"inserer heure au format xxhxx: ";
    s >> c;
    temph = c.substr(0,2);
    h = stoi(temph);
    tempm = c.substr(3,2);
    m = stoi(tempm);

  	i.setHour(h);
 	i.setMinute(m);
    return s;
}


Time Time::operator++(int )
{
	Time t(*this);
	(*this)= (*this) +30;
	return t;
}

Time Time::operator++()
{
 	(*this)= (*this) +30;
 	return (*this);
}

Time Time::operator--(int )
{
	Time t(*this);
	(*this)= (*this) -30;
	return t;

}

Time Time::operator--()
{
 	(*this)= (*this) -30;
 	return (*this);
}
}
