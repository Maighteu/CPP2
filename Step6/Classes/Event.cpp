#include "Event.h"
#include "TimeException.h"
#include "TimingException.h"

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

    if (title) delete[] title;
    if (timing) delete timing;
}

 
Event::Event(int c,const char* t)
{
   setCode(c);
   title = nullptr;
   setTitle(t);
   timing = nullptr;
}
Event::Event(const Event& i)
{
    setCode(i.getCode());
    title = nullptr;
    setTitle(i.getTitle());
    timing = new Timing(*(i.timing));
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
	if (timing != nullptr)	
	{
		timing->display();
	}
}
// void Event::setTiming( Timing* tim)
// {
//  timing= new Timing(*tim);
// }

 Timing Event::getTiming()const
{
	if (timing == nullptr) throw TimingException(TimingException::NO_TIMING, "No data inserted");
	return *timing;
}

void Event::setTiming(const Timing& tim)
{
    if (timing != nullptr)
      delete timing;
    timing = new Timing(tim);
 }
 ostream &operator<<(ostream &s, const Event &o)
 {
   s << "<Event>" << endl;
   s << "<code>" << endl;
   s << o.getCode() << endl;
   s << "</code>" << endl;
   s << "<title>" << endl;
   s << o.getTitle() << endl;
   s << "</title>" << endl;
   if (o.timing != nullptr) 
   {
     s << "<timing>" << endl;
     s << *(o.timing);
     s << "</timing>"<< endl;
   }
   s << "</Event>"<< endl;
   return s;
 }

 istream &operator>>(istream &s, Event &i)
 {
   string line;

   getline(s, line);
   getline(s, line);
   getline(s, line);
   i.setCode(stoi(line));
   getline(s, line);
   getline(s, line);
   getline(s, line);
   i.setTitle(line.c_str()); // String doit passer en char
   getline(s, line);
   getline(s, line);
   if (line == "<timing>")
   {  
     Timing t;
     s >> t;
     i.setTiming(t);
     getline(s, line);
     getline(s, line);
   }    
   getline(s, line);
   return s;
 }
}