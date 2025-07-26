#include "Professor.h"

Professor::Professor() : Schedulable()
{
	setLastName("default LN");
	setFirstName("default FN");
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
    s << p.toString();
    return s;
};

string Professor::toString() const
{
    return lastName + " " + firstName;
};

string Professor::tuple() const
{
    return to_string(id) + ";" + lastName + ";" + firstName;
};