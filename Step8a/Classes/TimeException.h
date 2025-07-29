#ifndef TIMEEXCEPTION_H
#define TIMEEXCEPTION_H
#include "Exception.h"

namespace planning{
class TimeException : public Exception
{
    private:
        int code;

    public:
        static int INVALID_HOUR;
        static int INVALID_MINUTE;
        static int OVERFLOW;

        TimeException();
        ~TimeException() = default;
        TimeException(int, string);
        TimeException(const TimeException &) = default;
        int getCode();
        void setCode(int);
};
}
#endif