#include "Timetable.h"
#include "Schedulable.h"

Timetable::Timetable()
{

}
Timetable::~Timetable()
{

}

int Timetable::addClassroom(const string& name, int seatingCapacity)
{
	classrooms.insert(Classroom(Schedulable::currentId, name, seatingCapacity));
	Schedulable::currentId++;
	return 1;
}

void Timetable::displayClassrooms() const
{
    for (auto it = classrooms.cbegin(); it != classrooms.cend(); it++)
    {
        cout<< " Id :  " << it->getId()<< it->toString() << endl;
    }
}

Classroom Timetable::findClassroomByIndex(int index) const
{
	auto c = classrooms.cbegin();
	if(index < 0 || index >= classrooms.size())
	{
		cout << "Index out of range" << endl;
    	return Classroom();
    }
    std::advance(c, index);
    return *c;
}

Classroom Timetable::findClassroomById(int id) const
{
	auto c = classrooms.cbegin();

    while (c != classrooms.cend() && c->getId() != id)
    {
        c++;
    }

    if (c != classrooms.cend())
        return *c;

    cout << "id not found" << endl;
    return Classroom();
}

void Timetable::deleteClassroomByIndex(int index)
{
	auto c = classrooms.cbegin();

	if(index < 0 || index >= classrooms.size())
	{
		cout << "Index out of range" << endl;
		return;
    }

    std::advance(c, index);
    classrooms.erase(c);
}

void Timetable::deleteClassroomById(int id)
{
	Classroom search = findClassroomById(id);
	auto c =classrooms.find(search);

    if (c != classrooms.cend()) classrooms.erase(c);
    
    cout << "Id not found" << endl;

}

int Timetable::addProfessor(const string &lastName, const string &firstName)
{
    professors.insert(Professor(Schedulable::currentId, lastName, firstName));
    Schedulable::currentId++;
    return 1;
}

void Timetable::displayProfessors() const
{
    for (auto it = professors.cbegin(); it != professors.cend(); it++)
    {
        cout<< " Id :  " << it->getId()<< it->toString()<< endl;
    }
}

Professor Timetable::findProfessorByIndex(int index) const
{
	auto c = professors.cbegin();
	if(index < 0 || index >= professors.size())
	{
		cout << "Index out of range" << endl;
    	return Professor();
    }
    std::advance(c, index);
    return *c;
}

Professor Timetable::findProfessorById(int id) const
{
	auto c = professors.cbegin();

    while (c != professors.cend() && c->getId() != id)
    {
        c++;
    }

    if (c != professors.cend())
        return *c;

    cout << "id not found" << endl;
    return Professor();
}

void Timetable::deleteProfessorByIndex(int index)
{
	auto c = professors.cbegin();

	if(index < 0 || index >= professors.size())
	{
		cout << "Index out of range" << endl;
		return;
    }

    std::advance(c, index);
    professors.erase(c);
}

void Timetable::deleteProfessorById(int id)
{
	Professor search = findProfessorById(id);
	auto c =professors.find(search);

    if (c != professors.cend()) professors.erase(c);
    
    cout << "Id not found" << endl;
}

int Timetable::addGroup(const string &name)
{
    groups.insert(Group(Schedulable::currentId, name));
    Schedulable::currentId++;
    return 1;
}

void Timetable::displayGroups() const
{
    for (auto it = groups.cbegin(); it != groups.cend(); it++)
    {                                                                            // cbegin = debutde la liste groups (constant);
        cout << "Id:" << it->getId() << it->toString()  << endl; // cend = fin de la liste groups (constant)
    }
}

Group Timetable::findGroupByIndex(int index) const
{
	auto c = groups.cbegin();
	if(index < 0 || index >= groups.size())
	{
		cout << "Index out of range" << endl;
    	return Group();
    }
    std::advance(c, index);
    return *c;
}

Group Timetable::findGroupById(int id) const
{
	auto c = groups.cbegin();

    while (c != groups.cend() && c->getId() != id)
    {
        c++;
    }

    if (c != groups.cend())
        return *c;

    cout << "Id not found" << endl;
    return Group();
}

void Timetable::deleteGroupByIndex(int index)
{
	auto c = groups.cbegin();

	if(index < 0 || index >= groups.size())
	{
		cout << "Index out of range" << endl;
		return;
    }

    std::advance(c, index);
    groups.erase(c);
}

void Timetable::deleteGroupById(int id)
{
	Group search = findGroupById(id);
	auto c =groups.find(search);

    if (c != groups.cend()) groups.erase(c);
    
    cout << "Id not found" << endl;
}
