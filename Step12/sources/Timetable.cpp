#include "Timetable.h"
#include "Schedulable.h"

Timetable Timetable::instance;
int Timetable::code = 1;

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
    {                                                           
        cout << "Id:" << it->getId() << it->toString()  << endl;
    }
}

Group Timetable::findGroupByIndex(int index) const
{
    if (index < 0 || index >= static_cast<int>(groups.size()))
	{
		cout << " group Index out of range" << endl;
    	return Group();
    }
    auto c = groups.cbegin();
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
    {
        cout<<"id found"<<endl;
        return *c;
    }

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

Timetable &Timetable::getInstance()
{
    return instance;
}

string Timetable::getProfessorTupleByIndex(int index)
{
    Professor p = findProfessorByIndex(index);
    if(p.getFirstName().empty() && p.getLastName().empty())
        return "";

    return p.tuple();
}


string Timetable::getGroupTupleByIndex(int index)
{

    Group g = findGroupByIndex(index);
    if(g.getName().empty())
        return "";

    return g.tuple();
}


string Timetable::getClassroomTupleByIndex(int index)
{

    Classroom c = findClassroomByIndex(index);
    if(c.getName().empty() && c.getSeatingCapacity() == 0)
        return "";

    return c.tuple();
}



int Timetable::save(const string &timetableName)
{
    int i;
    string Nom;
    const char* NomFichier;

    Nom = timetableName + "_config.dat";
    NomFichier= Nom.c_str();

    int fd;
    if ((fd = open(NomFichier, O_WRONLY | O_CREAT | O_APPEND, 0777)) == -1)
    {
        cerr << "Error while opening" << endl;
        return -1;
    }
    write(fd, &Schedulable::currentId, sizeof(Schedulable::currentId));
    write(fd, &Event::currentCode, sizeof(Event::currentCode));
    close(fd);



    Nom = timetableName + "_classroom.xml";
    XmlFileSerializer<Classroom> *FC = new XmlFileSerializer<Classroom>(Nom, XmlFileSerializer<Classroom>::WRITE, "Classrooms");
    
    auto c = classrooms.cbegin();
    i = 0;

    for (const auto& clas : classrooms) {
    FC->write(clas);
}
    delete FC;



    Nom = timetableName + "_group.xml";
    XmlFileSerializer<Group> *FG = new XmlFileSerializer<Group>(Nom, XmlFileSerializer<Group>::WRITE, "Groups");

    auto g = groups.cbegin();
    i = 0;

    for (const auto& group : groups) {
    FG->write(group);
}
    delete FG;


    Nom = timetableName + "_professor.xml";
    XmlFileSerializer<Professor> *FP = new XmlFileSerializer<Professor>(Nom, XmlFileSerializer<Professor>::WRITE, "Professors");

    auto p = professors.cbegin();
    i = 0;

    for (const auto& prof : professors) {
    FP->write(prof);
    }
    delete FP;


    Nom = timetableName + "_course.xml";
    XmlFileSerializer<Course> *FCO = new XmlFileSerializer<Course>(Nom, XmlFileSerializer<Course>::WRITE, "Courses");

    auto co = courses.begin();
    i = 0;

    for (const auto& cours : courses) {
    FCO->write(cours);
}
    delete FCO;
    return 1;
}



int Timetable::load(const string &timetableName)
{

    VideCont();
    string Nom;
    int i;

    const char* NomFichier;
    int fd;

    Nom = timetableName + "_config.dat";
    NomFichier= Nom.c_str();


    if ((fd = open(NomFichier, O_RDONLY, 0777)) == -1)
    {
        cerr << "File can't open" << endl;
        return -1;
    }

    if(read(fd, &Schedulable::currentId, sizeof(Schedulable::currentId)) < 1)
    {
        cerr << "error id < 1" << endl;
        close(fd);
        return -1;
    }
    if (read(fd, &Event::currentCode, sizeof(Event::currentCode)) < 1)
    {
        cerr << "Error code < 1" << endl;
        close(fd);
        return -1;
    }
    close(fd);


    Nom = timetableName + "_classroom.xml";

    XmlFileSerializer<Classroom> *FC = nullptr;
    try
    {
        FC = new XmlFileSerializer<Classroom>(Nom, XmlFileSerializer<Classroom>::READ);
        cout << "Filename: " << FC->getFilename() << endl;
        cout << "Collection name: " << FC->getCollectionName() << endl;
        cout << "Readable: " << FC->isReadable() << endl;
        cout << "Writable: " << FC->isWritable() << endl
             << endl;
    }
    catch (const XmlFileSerializerException &e)
    {
        cout << e.getMessage() << " code: " << e.getCode()<< endl;
    }

    if (FC != nullptr)
    {
        bool end = false;
        while (!end)
        {
            try
            {
                Classroom val = FC->read();
                LoadaddClassroom(val);
            }
            catch (const XmlFileSerializerException &e)
            {
                if (e.getCode() == XmlFileSerializerException::END_OF_FILE)
                    end = true;
                else
                {
                    cout << e.getMessage() << " code: " << e.getCode()<< endl;
                    break;
                }
            }
        }
        delete FC;
    }


    Nom = timetableName + "_group.xml";

    XmlFileSerializer<Group> *FG = nullptr;
    try
    {
        FG = new XmlFileSerializer<Group>(Nom, XmlFileSerializer<Group>::READ);
        cout << "Filename: " << FG->getFilename() << endl;
        cout << "Collection name: " << FG->getCollectionName() << endl;
        cout << "Readable: " << FG->isReadable() << endl;
        cout << "Writable: " << FG->isWritable() << endl
             << endl;
    }
    catch (const XmlFileSerializerException &e)
    {
        cout << e.getMessage() << " code: " << e.getCode() << endl;
    }

    if (FG != nullptr)
    {
        bool end = false;
        while (!end)
        {
            try
            {
                Group val = FG->read();
                LoadaddGroup(val);
            }
            catch (const XmlFileSerializerException &e)
            {
                if (e.getCode() == XmlFileSerializerException::END_OF_FILE)
                    end = true;
                else
                {
                    cout<< e.getMessage() << " code: " << e.getCode() << endl;
                    break;
                }
            }
        }
        delete FG;
    }


    Nom = timetableName + "_professor.xml";

    XmlFileSerializer<Professor> *FP = nullptr;
    try
    {
        FP = new XmlFileSerializer<Professor>(Nom, XmlFileSerializer<Professor>::READ);
        cout << "Filename: " << FP->getFilename() << endl;
        cout << "Collection name: " << FP->getCollectionName() << endl;
        cout << "Readable: " << FP->isReadable() << endl;
        cout << "Writable: " << FP->isWritable() << endl
             << endl;
    }
    catch (const XmlFileSerializerException &e)
    {
        cout<< e.getMessage() << " code: " << e.getCode() << endl;
    }

    if (FP != nullptr)
    {
        while (true)
        {
            try
            {
                Professor val = FP->read();
                LoadaddProfessor(val);
            }
            catch (const XmlFileSerializerException &e)
            {
                if (e.getCode() == XmlFileSerializerException::END_OF_FILE)
                    break;
                else
                {
                    cout << e.getMessage() << " code: " << e.getCode() << endl;
                    break;
                }
            }
        }
        delete FP;


    Nom = timetableName + "_course.xml";
    XmlFileSerializer<Course> *FCO = nullptr;
    try
    {
        FCO = new XmlFileSerializer<Course>(Nom, XmlFileSerializer<Course>::READ);
        cout << "Filename: " << FCO->getFilename() << endl;
        cout << "Collection name: " << FCO->getCollectionName() << endl;
        cout << "Readable: " << FCO->isReadable() << endl;
        cout << "Writable: " << FCO->isWritable() << endl
             << endl;

    }

    catch (const XmlFileSerializerException &e)
    {
        cout<< e.getMessage() << " code: " << e.getCode()<< endl;
    }

    if (FCO != nullptr)
    {
        while (true)
        {
            try
            {
                Course val = FCO->read();

                courses.push_back(val);
            }
            catch (const XmlFileSerializerException &e)
            {
                if (e.getCode() == XmlFileSerializerException::END_OF_FILE)
                    break;
                else
                {
                    cout  << e.getMessage() << endl;
                    break;
                }
            }
        }

        delete FCO;
    }
    }
    cout<<endl<<endl<<"current id"<<Schedulable::currentId<<endl<<endl;
    cout<<endl<<endl<<"id course"<<Event::currentCode<<endl<<endl;
    return 1;
}

void Timetable::VideCont()
{
    for (auto c = classrooms.begin(); c != classrooms.end();)
    {
        c = classrooms.erase(c); 
    }
    for (auto g = groups.begin(); g != groups.end();)
    {
        g = groups.erase(g);
    }

    for (auto p = professors.begin(); p != professors.end();)
    {
        p = professors.erase(p);
    }
        for (auto C = courses.begin(); C != courses.end();)
    {
        C = courses.erase(C);
    }
    Schedulable::currentId = 1;
    Event::currentCode = 1;
    return;
}

bool Timetable::isProfessorAvailable(int i, const Timing &t)
{
    bool r;

    for (auto c = courses.begin(); c != courses.end(); c++)//lis cours un a un
    {
        if (c->getProfessorId() == i)
        {
            r = c->getTiming().intersect(t);
            if (r == true)
                return false;
        }
    }
    return true;
}

bool Timetable::isGroupAvailable(int i, const Timing &t)
{
    bool r;

    for (auto c = courses.begin(); c != courses.end(); c++)
    {
        set<int> G = c->getGroupsId();

        for (auto g = G.cbegin(); g != G.cend(); g++)
        {
            if (*g == i)
            {
                r = c->getTiming().intersect(t);
                if (r == true)
                    return false;
            }
        }
    }
    return true;
}

bool Timetable::isClassroomAvailable(int i, const Timing &t)
{
    bool r;

    for (auto c = courses.begin(); c != courses.end(); c++)
    {
        if (c->getClassroomId() == i)
        {
            r = c->getTiming().intersect(t);
            if (r == true)
                return false;
        }
    }
    return true;
}

void Timetable::schedule(Course &c, const Timing &t)
{

    int ip = c.getProfessorId();
    int ic = c.getClassroomId();
    set<int> ig = c.getGroupsId();

    for (auto i = ig.cbegin(); i != ig.cend(); i++)
    {
        if(!(isProfessorAvailable(ip, t)))
            throw TimingException(TimingException::PROFESSOR_NOT_AVAIBLE, "Le professeur n'est pas disponible");

        if(!(isClassroomAvailable(ic, t)))
            throw TimingException(TimingException::CLASSROOM_NOT_AVAIBLE, "Le classroom n'est pas disponible");

        if(!(isGroupAvailable((*i), t)))
            throw TimingException(TimingException::GROUP_NOT_AVAIBLE, "Le groups n'est pas disponible");

        cout << "Professor: " << isProfessorAvailable(ip, t) << endl;
        cout << "Classroom: " << isClassroomAvailable(ic, t) << endl;
        cout << "Group: " << isGroupAvailable((*i), t) << endl;

    }

    c.setCode(code);
    c.setTiming(t);
    courses.push_back(c);

    code++;
}

string Timetable::tuple(const Course &c)
{
    Timing t;
    t = c.getTiming();
    Classroom classroom = findClassroomById(c.getClassroomId());
    Professor professor = findProfessorById(c.getProfessorId());

    string s = to_string(c.getCode()) + ";" + t.getDay() + ";" + t.getStart().toString() + ";" + t.getDuration().toString() + ";" + classroom.getName() + ";" + c.getTitle() + ";" + professor.getLastName() + " " + professor.getFirstName() + ";";
    cout<<"tuple "<<s<<endl;
    set<int> gi = c.getGroupsId();

    string g;
    for (auto it = gi.cbegin(); it != gi.cend(); it++)
    {
        Group group = findGroupById(*it);
        g += group.toString();
        if (next(it) != gi.cend()) g += ", ";
    }
    s += g;
    return s;
}

Course Timetable::findCourseByIndex(int index)
{

    auto c = courses.begin();

    int i = 0;
    while (c != courses.end() && i < index)
    {
        c++;
        i++;
    }
    if (c != courses.end())
    {
        return *c;
    }
    else
    {
        return Course();
    }
}
string Timetable::getCourseTupleByIndex(int index)
{
    Course classes = findCourseByIndex(index);
    if (classes.getProfessorId() != 0)
    {
        string tupleC = tuple(classes);
        if (Event::currentCode < classes.getCode()) Event::currentCode = classes.getCode();
        return tupleC;
    }
    return "";
}

//

Course Timetable::findCourseByCode(int code) const
{
    auto it = courses.begin();

    while (it != courses.end() && it->getCode() != code)
    {
        it++;
    }

    if (it != courses.end())
        return *it;
    return Course();
}


int Timetable::deleteCourseByCode(int Code)
{

    Course deleted = findCourseByCode(Code);

    auto it = find(courses.begin(),courses.end(),deleted);

    if (it != courses.end())
    {
        courses.erase(it);
        return 1;
    }
    return 0;
}

int Timetable::LoadaddClassroom(const Classroom& c)
{
    classrooms.insert(c);
    return 1;
}
int Timetable::LoadaddProfessor(const Professor& p)
{
    professors.insert(p);
    return 1;
}
int Timetable::LoadaddGroup(const Group& g)
{
    groups.insert(g);
    return 1;
}



void Timetable::importProfessorsFromCsv(const string &filename)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "file can't open" << endl;
        exit(1);
    }

    string s;
    string LastName;
    string FirstName;

    while (getline(file, s))
    {
        istringstream iss(s);

        getline(iss, LastName, ';');
        getline(iss, FirstName, ';');
        addProfessor(LastName, FirstName);
    }
}

void Timetable::importGroupsFromCsv(const string &filename)
{

    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "file can't open" << endl;
        exit(1);
    }

    string s;
    string Name;

    while (getline(file, s))
    {
        istringstream iss(s);
        getline(iss, Name, ';');
        addGroup(Name);
    }
}
void Timetable::importClassroomsFromCsv(const string &filename)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "file can't open" << endl;
        exit(1);
    }

    string s;
    string Name;
    string SeatingCapacity;

    while (getline(file, s))
    {
        istringstream iss(s);
        getline(iss, Name, ';');
        getline(iss, SeatingCapacity, ';');
        addClassroom(Name, stoi(SeatingCapacity));
    }
}

void Timetable::exportProfessorTimetable(int id)
{
    Professor t = findProfessorById(id);
    const string filename = t.getLastName() + "_" + t.getFirstName() + ".hor";

    ofstream file(filename);

    file << "Horaire de " + t.getLastName() + t.getFirstName() + " :" << endl <<  endl;

    for (auto it = courses.begin(); it != courses.end(); it++)
    {
        string groupsStr, ligne;
        if (it->getProfessorId() == id)
        {
            int clsint = it->getClassroomId();
            Classroom cls = findClassroomById(clsint);

            ligne = it->getTiming().getDay() + "    " + it->getTiming().getStart().toString() + "   " + it->getTiming().getDuration().toString() + "   " + cls.getName() + "    " + it->getTitle() + "   ";

            set<int> tmp = it->getGroupsId();
            for (auto itg = tmp.cbegin(); itg != tmp.cend(); itg++)
            {
                Group group = findGroupById(*itg);
                groupsStr += group.toString();
                if (next(itg) != tmp.cend())
                {
                    groupsStr += ", ";
                }
            }

            file << ligne + groupsStr << endl;
        }
    }
}
void Timetable::exportGroupTimetable(int id)
{
    Group g = findGroupById(id);
    const string NomFichier = g.getName() + ".hor";

    ofstream file(NomFichier);
    file << "Horaire de " + g.getName() + " :";
    file << endl << endl;

    for (auto it = courses.begin(); it != courses.end(); it++)
    {

        set<int> tmp = it->getGroupsId();
        for (auto itg = tmp.cbegin(); itg != tmp.cend(); itg++)
        {
            if (*itg == id)
            {
                Professor prof = findProfessorById(it->getProfessorId());
                Classroom cls = findClassroomById(it->getClassroomId());
                file << it->getTiming().getDay() + "    " + it->getTiming().getStart().toString() + "   " + it->getTiming().getDuration().toString() + "   " + cls.getName() + "    " + it->getTitle() + "   " + prof.getLastName() + " " + prof.getFirstName() << endl;

            }
        }
    }
}

void Timetable::exportClassroomTimetable(int id)
{

    Classroom cls = findClassroomById(id);
    const string NomFichier = cls.getName() + ".hor";

    ofstream file(NomFichier);
    file << "Horaire de " + cls.getName() + " :";
    file << endl << endl;

    for (auto it = courses.begin(); it != courses.end(); it++)
    {
        string groupsStr, ligne;
        if (it->getClassroomId() == id)
        {

            Professor prof = findProfessorById(it->getProfessorId());
            ligne = it->getTiming().getDay() + "    " + it->getTiming().getStart().toString() + "   " + it->getTiming().getDuration().toString() + "   " + cls.getName() + "    " + it->getTitle() + "   " + prof.getLastName() + " " + prof.getFirstName() + "  ";

            set<int> tmp = it->getGroupsId();
            for (auto itg = tmp.cbegin(); itg != tmp.cend(); itg++)
            {
                Group group = findGroupById(*itg);
                groupsStr += group.toString();
                if (next(itg) != tmp.cend())
                { 
                    groupsStr += ", ";
                }
            }

            file << ligne + groupsStr << endl;
        }
    }
}