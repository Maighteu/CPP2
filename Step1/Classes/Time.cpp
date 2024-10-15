#include <"Time.h">
Time::Time()
{
	setHour(1);
	setMinute(1);

}
Time::~Time
{
	if (hour || minute) delete;
}
Time::(Time &i)
{
	setHour(i.getHour());
	setMinute(i.getMinute());
}
Time::Time(int h, int m);
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

void Time::setHour(int h);
{
	hour = h;
}
void Time::setMinute(int m);
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
	cout<<endl<< "hour:"<< getHour<< endl<<"minute:"<< getMinute<<endl;
}