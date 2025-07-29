#include "Group.h"

Group::Group() : Schedulable()
{
	setName("Default");
}

Group::Group(int id, string n) : Schedulable(id)
{
	setName(n);
}

void Group::setName(string n)
{
	name = n;
}

string Group::getName() const
{
	return name;
}

ostream& operator<<(ostream &s,const Group &g )
{
    return s << g.toString();
}
string Group::toString() const
{
    return " " + name;
}

string Group::tuple() const
{
    return to_string(id) + ";" + name;
}

 bool Group::operator<(const Group& c) const
 {
     return this->getName() < c.getName();
 }