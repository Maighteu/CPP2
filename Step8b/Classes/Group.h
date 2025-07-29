#ifndef GROUP_H
#define GROUP_H
#include "Schedulable.h"

class Group : public Schedulable
{
    friend ostream &operator<<(ostream&, const Group&);
private:
    string name;
    

public:
    Group();
    Group(int, string);
    ~Group() = default;
    Group(const Group &) = default;
    void setName(string);
    string getName() const;

    string toString() const override;
    string tuple() const override;

    bool operator<(const Group& c) const;

};
#endif