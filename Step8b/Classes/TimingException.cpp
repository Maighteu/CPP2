
#include "TimingException.h"

namespace planning
{
int TimingException::INVALID_DAY = 4;
int TimingException::NO_TIMING = 5;

TimingException::TimingException() : Exception()
{
    code = 0;
}

TimingException::TimingException(int c, string m) : Exception(m)
{	
    code = c;
}

void TimingException::setCode(int C)
{
    code = C;
}

int TimingException::getCode()
{
    return code;
}
}