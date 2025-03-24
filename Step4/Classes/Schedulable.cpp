#include "Schedulable.h"

Schedulable::Schedulable()
{
	setId(-1);
}
Schedulable::~Schedulable()
{

}
Schedulable::Schedulable(const Schedulable& i)
{
	setId(i.getId());
}
Schedulable::Schedulable(const int i)
{
	setId(i);
}
int Schedulable::getId()const
{
	return id;
}
void Schedulable::setId(int i)
{
	id = i;
}
const string Schedulable::toString() const
{

}
const string Schedulable::tuple() const
{

}