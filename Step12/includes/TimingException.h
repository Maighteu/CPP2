#ifndef TIMINGEXCEPTION_H
#define TIMINGEXCEPTION_H

#include "Exception.h"

namespace planning
{
class TimingException : public Exception
{
    private:
        int code; 
    public:
        static int INVALID_DAY;
        static int NO_TIMING;
        
        static int PROFESSOR_NOT_AVAIBLE;
        static int CLASSROOM_NOT_AVAIBLE;
        static int GROUP_NOT_AVAIBLE;

        TimingException();
        TimingException(const TimingException&) = default;
        TimingException(int, string);
        ~TimingException() = default;

        void setCode(int);
        int getCode();
};
}
#endif