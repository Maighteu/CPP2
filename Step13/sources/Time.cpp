#include "Time.h"
#include "TimeException.h"

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
	if (m < 0) throw TimeException(TimeException::INVALID_MINUTE, "minute must be 0 or more");

	setHour(h);
	setMinute(m);
}

void Time::setHour(int h)
{
	 if (h < 0 || h >= 24) throw TimeException(TimeException::INVALID_HOUR, "Hour must be between 0 and 23");
	hour = h;
}
void Time::setMinute(int m)
{
	 if (m < 0 || m >= 60)
     throw TimeException(TimeException::INVALID_MINUTE, "Minute must be between 0 and 59");
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
	m = t.getMinute()+(m % 60);


	if(m >=60)
	{
		m= m-60;
		h = h + 1;
	}
	t.setMinute( m);
	t.setHour(getHour()+h);
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
	// if (t.getHour()>24)
	// {
	// 	t.setHour(t.getHour()-24);

	// }
 
		return t;
	}

Time operator+(int min, Time t) 
{	
	return t + min;
}


Time Time::operator-(int m)
{
    Time t(*this);
    int h = m / 60;
    int min = m % 60;

    int newMinute = getMinute() - min;
    int newHour = getHour() - h;

    if (newMinute < 0)
    {
        newMinute += 60;
        newHour -= 1;
    }

  
    t.setMinute(newMinute);
    t.setHour(newHour);

    return t;
}

Time Time::operator-(const Time& temp) 
{	
	Time t(*this);

	t.setMinute(getMinute()- temp.minute);
	t.setHour(getHour()- temp.hour);

	if(t.getMinute()<0)
	{
		t.setMinute(t.getMinute()+60);
		t.setHour(t.getHour()-1);
	}

 
	return t;

}
Time operator-(int min, Time t) 
{	
	Time temp;

	int newHour = (min / 60);
	int newMinute = (min % 60);

	newHour = (t.getHour() - newHour);
	newMinute = (t.getMinute() - newMinute);

	if (newMinute < 0)
	{
		newMinute = (newMinute + 60);
		newHour= (newHour - 1);
	}

	temp.setMinute(newMinute);
	temp.setHour(newHour);

	return temp;
}



bool Time::operator==(const Time& i)
{
	if( (getHour() == i.getHour()) && (getMinute() == i.getMinute()) ) return true;
	return false;
}

bool Time::operator<(const Time& i) const
{

	if(getHour() < i.getHour()) return true;
	if(getHour() > i.getHour()) return false;
	if( getMinute() < i.getMinute() ) return true;
	if( getMinute() > i.getMinute() ) return false;
	return false;
}

bool Time::operator>(const Time& i) const
{

	return (i < *this);
}

ostream& operator<<(ostream& s,const Time& i)
{
	s<<"<Time>"<<endl; //endl place un \n à la fin (ce qui permet au getline de savoir ou se stop)
	s<<"<hour>"<<endl;
	s<<i.getHour()<<endl;
	s<<"</hour>"<<endl;
	s<<"<minute>"<<endl;
	s << i.getMinute() << endl;
  s << "</minute>" << endl;
  s << "</Time>";
	return s;
}
istream& operator>>(istream& s, Time& i)
{
  string line;

	getline(s, line);
	getline(s, line);
	getline(s, line);
	i.setHour(stoi(line));
	getline(s, line);
	getline(s, line);
	getline(s, line);
	i.setMinute(stoi(line));
	getline(s, line);
	getline(s, line);
	return s;
}


Time Time::operator++(int )
{
	int M = (*this).getMinute();
	int H = (*this).getHour();
	M = H * 60 + M;
	if (M > 1440) throw TimeException(TimeException::OVERFLOW, "More than 24:00");

	Time t(*this);
	(*this)= (*this) +30;
	return t;
}

Time Time::operator++()
{
	int M = (*this).getMinute();
	int H = (*this).getHour();
	M = H * 60 + M;
	if (M > 1440) throw TimeException(TimeException::OVERFLOW, "More than 24:00");
 	(*this)= (*this) +30;
 	return (*this);
}

Time Time::operator--(int )
{
	int M = (*this).getMinute();
	int H = (*this).getHour();	M = H * 60 + M;
	if (M < 0) throw TimeException(TimeException::OVERFLOW, "Less than 00:00");
	Time t(*this);
	(*this)= (*this) -30;
	return t;

}

Time Time::operator--()
{
	int M = (*this).getMinute();
	int H = (*this).getHour();
	M = H * 60 + M;
	if (M < 0) throw TimeException(TimeException::OVERFLOW, "Less than 00:00");
 	(*this)= (*this) -30;
 	return (*this);
}


string Time::toString()
{ 
	string SH, SM;
	if (minute<10)
    	SM = to_string(minute) + "0";
	else
    	SM= to_string(minute);
    if (hour<10)
    	SH = "0" + to_string(hour); 
    else
    	SH = to_string(hour);
    
    return SH + "h" +SM;
}
}
