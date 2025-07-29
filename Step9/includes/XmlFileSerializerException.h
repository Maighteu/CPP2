#ifndef XMLFILESERIALIZEREXCEPTION_H
#define XMLFILESERIALIZEREXCEPTION_H
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>

#include "Exception.h"

class XmlFileSerializerException : public Exception
{
private:
    int code;

public:
    static int NOT_ALLOWED;
    static int FILE_NOT_FOUND;
    static int END_OF_FILE;

    // Constructeurs
    XmlFileSerializerException();
    ~XmlFileSerializerException() = default;
    XmlFileSerializerException(int, string);
    XmlFileSerializerException(const XmlFileSerializerException &) = default;
    
    int getCode() const;
    void setCode(int);
};

#endif