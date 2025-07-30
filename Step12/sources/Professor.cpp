#include "Professor.h"

Professor::Professor() : Schedulable()
{
	setLastName("");
	setFirstName("");
}



Professor::Professor(const Professor& p) : Schedulable(p)
{
	setLastName(p.getLastName());
	setFirstName(p.getFirstName());

}

Professor::Professor(int id, string l, string f) : Schedulable(id)
{
	setLastName(l);
	setFirstName(f);
}

void Professor::setLastName(string l)
{
	lastName = l;
}

void Professor::setFirstName(string f)
{
	firstName = f;
}

void Professor::display() const
{
	cout<<endl<<"lastName: "<<getLastName()<<endl<<"firstName: "<<getFirstName()<<endl;
}

string Professor::getLastName() const
{
    return lastName;
}

string Professor::getFirstName() const
{
    return firstName;
}

ostream &operator<<(ostream &s, const Professor &p)
{
    s << "<Professor>" << endl;
    s << "<id>" << endl;
    s << p.id << endl;
    s << "</id>" << endl;
    s << "<firstName>" << endl;
    s << p.firstName << endl;
    s << "</firstName>" << endl;
    s << "<lastName>" << endl;
    s << p.lastName << endl;
    s << "</lastName>" << endl;
    s << "</Professor>";
    return s;
};

istream &operator>>(istream &s, Professor &p)
{
    string line;
    getline(s, line);
    getline(s, line);
    getline(s, line);
    p.setId(stoi(line));
    getline(s, line);
    getline(s, line);
    getline(s, line);
    p.setFirstName(line);
    getline(s, line);
    getline(s, line);
    getline(s, line);
    p.setLastName(line);
    getline(s, line);
    getline(s, line);
    return s;
}

string Professor::toString() const
{
    return " " + lastName + " " + firstName;
};

string Professor::tuple() const
{
    return to_string(id) + ";" + lastName + ";" + firstName;
};

bool Professor::operator<(const Professor& c) const
{
    return this->getLastName() < c.getLastName();
}