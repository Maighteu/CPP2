#ifndef COURSE_H
#define COURSE_H

#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <set>
#include <algorithm>

#include "Event.h"


using namespace planning;
class Course : public Event
{
friend ostream &operator<<(ostream &, const Course &);
friend istream &operator>>(istream &, Course &);
private:
    int professorId;
    int classroomId;
    set<int> groupsIds;
public:
    Course();
    ~Course() = default;
    Course(int , const char *, int , int , const set<int> &);
    Course(const Course &x) = default;

    void setProfessorId(int);
    void setClassroomId(int);
    void setGroupsId(const set<int> &);
    int getProfessorId() const;
    int getClassroomId() const;
    set<int> getGroupsId() const;

    bool operator==(const Course &) const;
    bool operator<(const Course &) const;

    void addGroupId(int );
    bool isGroupIdPresent(int );
};

#endif