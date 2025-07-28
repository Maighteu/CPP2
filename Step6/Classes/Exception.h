#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <iostream>
#include <string>

using namespace std;

class Exception
{
private:
    string message;

public:
    Exception();
    ~Exception() = default;
    Exception(string);
    Exception(const Exception &) = default;
    string getMsg() const;
    void setMsg(string);
};
#endif