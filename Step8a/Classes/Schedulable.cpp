#include "Schedulable.h"

int Schedulable::currentId = 1;

Schedulable::Schedulable()
{
	setId(0);
}

Schedulable::~Schedulable()
{

}

Schedulable::Schedulable(const Schedulable& i)
{
	setId(i.getId());
}

Schedulable::Schedulable(int s)
{
	setId(s);
}

int Schedulable::getId() const
{
	return this->id;
}

void Schedulable::display() const
{
	cout<<endl<<"id: "<< getId()<<" " << endl;
}
void Schedulable::setId(int ID)
{
 id = ID;
}

