#include "Timetable.h"
#include "Schedulable.h"

Timetable Timetable::instance;

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
    auto it = classrooms.cbegin();
    int i = 0;

    while (it != classrooms.cend() && i < index)
    {
        it++;
        i++;
    }

    if (it != classrooms.cend())
        return *it;
    else
    {
        // cout << "Index hors limites" << endl;
        return Classroom(); // Retourne un objet Classroom vide ou un autre objet par défaut
    }
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
    close(fd);



    Nom = timetableName + "_classroom.xml";
    XmlFileSerializer<Classroom> *FC = new XmlFileSerializer<Classroom>(Nom, XmlFileSerializer<Classroom>::WRITE, "Classrooms");
    
    auto c = classrooms.cbegin();
    i = 0;

    while(c != classrooms.cend())
    {
        Classroom t = findClassroomByIndex(i);
        FC->write(t);
        c++;
        i++;
    }
    delete FC;



    Nom = timetableName + "_group.xml";
    XmlFileSerializer<Group> *FG = new XmlFileSerializer<Group>(Nom, XmlFileSerializer<Group>::WRITE, "Groups");

    auto g = groups.cbegin();
    i = 0;

    while(g != groups.cend())
    {
        Group t = findGroupByIndex(i);
        FG->write(t);
        g++;
        i++;
    }
    delete FG;


    Nom = timetableName + "_professor.xml";
    XmlFileSerializer<Professor> *FP = new XmlFileSerializer<Professor>(Nom, XmlFileSerializer<Professor>::WRITE, "Professors");

    auto p = professors.cbegin();
    i = 0;

    while(p != professors.cend())
    {
        Professor t = findProfessorByIndex(i);
        FP->write(t);
        p++;
        i++;
    }
    delete FP;
    Schedulable::currentId = 1;
    return 1;
}



int Timetable::load(const string &timetableName)
{
    Schedulable::currentId = 1;

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
    cout << "Id: " << Schedulable::currentId << endl;
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
                addClassroom(val.getName(),val.getSeatingCapacity());
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
                addGroup(val.getName());
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
        bool end = false;
        while (!end)
        {
            try
            {
                Professor val = FP->read();
                addProfessor(val.getLastName(),val.getFirstName());
            }
            catch (const XmlFileSerializerException &e)
            {
                if (e.getCode() == XmlFileSerializerException::END_OF_FILE)
                    end = true;
                else
                {
                    cout << e.getMessage() << " code: " << e.getCode() << endl;
                    break;
                }
            }
        }
        delete FP;
    }

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
    Schedulable::currentId = 1;
    return;
}