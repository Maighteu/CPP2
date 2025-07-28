#include "XmlFileSerializerException.h"

int XmlFileSerializerException::NOT_ALLOWED = 6;
int XmlFileSerializerException::FILE_NOT_FOUND = 7;
int XmlFileSerializerException::END_OF_FILE = 8;

XmlFileSerializerException::XmlFileSerializerException()
{
    code = 0;
}

XmlFileSerializerException::XmlFileSerializerException(int c, string m) : Exception(m)
{
    setCode(c);
}

int XmlFileSerializerException::getCode() const
{
    return code;
}
void XmlFileSerializerException::setCode(int c)
{
    code = c;
}