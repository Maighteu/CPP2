#ifndef CLASSROOM_H
#define CLASSROOM_H

#include "Schedulable.h"

class Classroom : public Schedulable
{
    friend ostream &operator<<(ostream &, const Classroom &);

private:
    string name;
    int seatingCapacity;

public:
    Classroom();
    ~Classroom() = default;
    Classroom(int, string, int);
    Classroom(const Classroom &) = default;
    void setSeatingCapacity(int);
    void setName(string);
    int getSeatingCapacity() const;
    string getName() const;

    string toString() const override;
    string tuple() const override;
};

#endif