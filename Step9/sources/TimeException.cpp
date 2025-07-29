#include "TimeException.h"

namespace planning
{
int TimeException::INVALID_HOUR = 1;
int TimeException::INVALID_MINUTE = 2;
int TimeException::OVERFLOW = 3;

TimeException::TimeException() : Exception()
{
    code = 0;
}

TimeException::TimeException(int c, string m) : Exception(m)
{
    code = c;
}

int TimeException::getCode()
{
    return code;
}

void TimeException::setCode(int C)
{
    code = C;
}
}