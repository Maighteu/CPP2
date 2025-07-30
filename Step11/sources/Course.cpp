#include "Course.h"
using namespace planning;

Course::Course() : Event()
{
    setProfessorId(0);
    setClassroomId(0);
    groupsIds.clear();
}

Course::Course(int c, const char *t, int pId, int cId, const set<int> &gId) : Event(c, t)
{
    setProfessorId(pId);
    setClassroomId(cId);
    setGroupsId(gId);
}

void Course::setProfessorId(int pId)
{
    professorId = pId;
}

void Course::setClassroomId(int cId)
{
    classroomId = cId;
}

void Course::setGroupsId(const set<int> &gId)
{
    this->groupsIds = gId;
}

int Course::getProfessorId() const
{
    return professorId;
}
int Course::getClassroomId() const
{
    return classroomId;
}
set<int> Course::getGroupsId() const
{
    return groupsIds;
}

bool Course::operator==(const Course &c) const
{
    return this->getCode() == c.getCode();
}

bool Course::operator<(const Course &c) const
{

    Timing t = this->getTiming();
    Timing T = c.getTiming();

    if (t.d_int(t) < T.d_int(T))
        return true;
    if (t.d_int(t) > T.d_int(T))
        return false;

    return t.getStart() < T.getStart();
}

void Course::addGroupId(int i)
{
    getGroupsId().insert(i);
}

bool Course::isGroupIdPresent(int i)
{
    auto G = getGroupsId();

    auto g = G.find(i);

    if (g != G.end())
    {
        cout << "group id present " << *g << endl;
        return true;
    }
    else
    {
        cout << "group id non present" << endl;
        return false;
    }
}
ostream &operator<<(ostream &s, const Course &x)
{

    s << "<Course>" << endl;
    s << static_cast<const Event &>(x);

    s << "<professorId>" << endl;
    s << x.getProfessorId() << endl;
    s << "</professorId>" << endl;
    s << "<classroomId>" << endl;
    s << x.getClassroomId() << endl;
    s << "</classroomId>" << endl;
    set<int> test = x.getGroupsId();

    for (auto it = test.cbegin(); it != test.cend(); it++)
    {
        s << "<groupsIds>" << endl;
        s << *it << endl;
        s << "</groupsIds>" << endl;
        if (next(it) == test.cend())
            break;
    }
    s << "</Course>";
    return s;
}

istream &operator>>(istream &s, Course &x)
{
    string line;
    getline(s, line);
    s >> static_cast<Event &>(x);
    getline(s, line);
    getline(s, line);
    x.setProfessorId(stoi(line));
    getline(s, line);
    getline(s, line);
    getline(s, line);
    x.setClassroomId(stoi(line));
    getline(s, line);
    set<int> Envoyer;
    while (true)
    {
        getline(s, line); 

        if (line == "</Course>")
            break;
        else
        {

            getline(s, line);

            Envoyer.insert(stoi(line));

            getline(s, line);
        }
    }
    x.setGroupsId(Envoyer); 
    return s;
}