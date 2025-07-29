#ifndef XMLFILESERIALIZER_H
#define XMLFILESERIALIZER_H

#include <fstream>
#include <string>

template <typename T>
class XmlFileSerializer
{

private:
    fstream file;
    string filename;
    char mode;
    string collectionName;

public:
    static const char READ;
    static const char WRITE;

    XmlFileSerializer() = delete;
    XmlFileSerializer(const XmlFileSerializer &fs) = delete;
    XmlFileSerializer<T> operator=(const XmlFileSerializer<T> &) = delete;
    XmlFileSerializer(const string &fn, char m, const string &cn = "entities");
    ~XmlFileSerializer();

    string getFilename();
    string getCollectionName();
    bool isReadable();
    bool isWritable();

    void write(const T &val);
    T read();
};

#include "XmlFileSerializer.ipp"

#endif