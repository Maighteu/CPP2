#include "Classroom.h"

Classroom::Classroom() : Schedulable()
{
    setName("");
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
    s << "<Classroom>" << endl;
    s << "<id>" << endl;
    s << c.id  << endl;
    s << "</id>" << endl;
    s << "<name>" << endl;
    s << c.getName() << endl;
    s << "</name>" << endl;
    s << "<seatingCapacity>" << endl;
    s << c.getSeatingCapacity() << endl;
    s << "</seatingCapacity>" << endl;
    s << "</Classroom>";

    return s;
}

istream &operator>>(istream &s, Classroom &i)
{
    string line;
    getline(s,line);
    getline(s,line);
    getline(s,line);
    i.setId(stoi(line));
    getline(s,line);
    getline(s,line);
    getline(s,line);
    i.setName(line);
    getline(s,line);
    getline(s,line);
    getline(s,line);
    i.setSeatingCapacity(stoi(line));
    getline(s,line);
    getline(s,line);

        return s;
    }
string Classroom::toString() const
{
    return " " + name + " " + to_string(seatingCapacity);
}
string Classroom::tuple() const
{
    return to_string(id) + ";" + this->name + ";" + to_string(this->seatingCapacity);
}

 bool Classroom::operator<(const Classroom& c) const
 {
     return this->getName() < c.getName();
 }