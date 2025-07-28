#include "Exception.h"

Exception::Exception()
{
    setMsg("default");
}

Exception::Exception(string m)
{
    setMsg(m);
}

string Exception::getMsg() const
{
    return message;
}

void Exception::setMsg(string M)
{
    message = M;
}