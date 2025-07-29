#include "Exception.h"

Exception::Exception()
{
    setMessage("default");
}

Exception::Exception(string m)
{
    setMessage(m);
}

string Exception::getMessage() const
{
    return message;
}

void Exception::setMessage(string M)
{
    message = M;
}