#ifndef PROFESSOR_H
#define PROFESSOR_H
#include "Schedulable.h"

class Professor : public Schedulable
{
	friend std::ostream& operator<<(std::ostream& ,const Professor&);
public:
    Professor();
    Professor(int, string, string);
    ~Professor() = default;
    Professor(const Professor&);
    void setLastName(string);
    void setFirstName(string);
    string getLastName() const;
    string getFirstName() const;
    void display() const;


    string toString() const override;
    string tuple() const override;
private:
	string lastName;
	string firstName;



};
#endif