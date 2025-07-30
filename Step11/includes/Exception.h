#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <stdio.h>

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
    string getMessage() const;
    void setMessage(string);
};
#endif