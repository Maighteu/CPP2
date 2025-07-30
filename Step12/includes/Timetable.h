#ifndef TIMETABLE_H
#define TIMETABLE_H

#include <set>
#include <fcntl.h>
#include <unistd.h>
#include <list>
#include <fstream>
#include <sstream>

#include "Event.h"
#include "Classroom.h"
#include "Professor.h"
#include "Group.h"
#include "Schedulable.h"
#include "XmlFileSerializer.hpp"
#include "XmlFileSerializerException.h"
#include "Course.h"
#include "TimingException.h"

class Timetable
{
private:
    set<Classroom> classrooms;
    set<Professor> professors;
    set<Group> groups;
    list<Course> courses;

    Timetable();
    Timetable(const Timetable &x) = delete; // constructeur de copie
    const Timetable &operator=(const Timetable &) = delete;

    static Timetable instance;
public:
    static int code;
    ~Timetable();

    int addClassroom(const string &name, int seatingCapacity);
    void displayClassrooms() const;
    Classroom findClassroomByIndex(int index) const;
    Classroom findClassroomById(int id) const;
    void deleteClassroomByIndex(int index);
    void deleteClassroomById(int id);

    int addProfessor(const string &lastName, const string &firstName);
    void displayProfessors() const;
    Professor findProfessorByIndex(int index) const;
    Professor findProfessorById(int id) const;
    void deleteProfessorByIndex(int index);
    void deleteProfessorById(int id);

    int addGroup(const string &name);
    void displayGroups() const;
    Group findGroupByIndex(int index) const;
    Group findGroupById(int id) const;
    void deleteGroupByIndex(int index);
    void deleteGroupById(int id);

    static Timetable &getInstance();

    string getProfessorTupleByIndex(int);
    string getGroupTupleByIndex(int);
    string getClassroomTupleByIndex(int);
    int save(const string& timetableName);
    int load(const string& timetableName);
    void VideCont();

    bool isProfessorAvailable(int id, const Timing& timing);
    bool isGroupAvailable(int id, const Timing& timing);
    bool isClassroomAvailable(int id, const Timing& timing);
    void schedule(Course& c, const Timing& t);

    string tuple(const Course&);
    string getCourseTupleByIndex(int);
    Course findCourseByIndex(int);
    Course findCourseByCode(int) const;
    int deleteCourseByCode(int);

    int LoadaddClassroom(const Classroom&);
    int LoadaddProfessor(const Professor&);
    int LoadaddGroup(const Group&);

    void importProfessorsFromCsv(const string& filename);
    void importGroupsFromCsv(const string& filename);
    void importClassroomsFromCsv(const string& filename);
    void exportProfessorTimetable(int id);
    void exportGroupTimetable(int id);
    void exportClassroomTimetable(int id);



};

#endif