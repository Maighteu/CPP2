#include "Classroom.h"

Classroom::Classroom() : Schedulable()
{
    setName("default");
    setSeatingCapacity(0);
};

Classroom::Classroom(int id, string n, int p) : Schedulable(id)
{
    setName(n);
    setSeatingCapacity(p);
};

void Classroom::setSeatingCapacity(int C)
{
    seatingCapacity = C;
}
void Classroom::setName(string n)
{
    name = n;
}

int Classroom::getSeatingCapacity() const
{
    return this->seatingCapacity;
}
string Classroom::getName() const
{
    return this->name;
}

ostream &operator<<(ostream &s, const Classroom &c)
{
    return s << c.toString();
}

string Classroom::toString() const
{
    return name + " " + to_string(seatingCapacity);
}
string Classroom::tuple() const
{
    return to_string(id) + ";" + this->name + ";" + to_string(this->seatingCapacity);
}