#include "Group.h"

Group::Group() : Schedulable()
{
	setName("");
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

ostream &operator<<(ostream &s, const Group &g)
{
    s << "<Group>" << endl;
    s << "<id>" << endl;
    s << g.id << endl;
    s << "</id>" << endl;
    s << "<name>" << endl;
    s << g.name << endl;
    s << "</name>" << endl;
    s << "</Group>";
    return s;
}

istream &operator>>(istream &s, Group &g)
{
    string line;
    getline(s, line);
    getline(s, line);
    getline(s, line);
    g.setId(stoi(line));
    getline(s, line);
    getline(s, line);
    getline(s, line);
    g.setName(line);
    getline(s, line);
    getline(s, line);
    return s;
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