
#include "XmlFileSerializerException.h"
using namespace std;

template <typename T>
const char XmlFileSerializer<T>::READ = 'r';

template <typename T>
const char XmlFileSerializer<T>::WRITE = 'w';

template <typename T>
XmlFileSerializer<T>::XmlFileSerializer(const string &fn, char m, const string &cn)
{
    filename = fn;
    mode = m;
    collectionName = cn;

    if (isWritable())
    {
        file.open(getFilename(), ios::out); // ouvre en ecriture
        file << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl;
        file << "<" << getCollectionName() << ">" << endl;

    }

    if (isReadable())
    {
        string ligne;
        file.open(fn, ios::in);
        if (!file.is_open()) throw XmlFileSerializerException(XmlFileSerializerException::FILE_NOT_FOUND, "Unknown file");
        getline(file, ligne);
        getline(file, ligne);
        ligne = ligne.substr(1, ligne.length() - 2); // Supprime les caractères <
        collectionName = ligne;
    }
}

template <typename T>
string XmlFileSerializer<T>::getFilename()
{
    return filename;
}

template <typename T>
string XmlFileSerializer<T>::getCollectionName()
{
    return collectionName;
}

template <typename T>
bool XmlFileSerializer<T>::isReadable()
{
    if (mode == READ) return true;
    return false;
}

template <typename T>
bool XmlFileSerializer<T>::isWritable()
{
    if (mode == WRITE) return true;
    return false;
}

template <typename T>
void XmlFileSerializer<T>::write(const T &val)
{
    if (isReadable()) throw XmlFileSerializerException(XmlFileSerializerException::NOT_ALLOWED, "File opened in read mode");

    file << val << endl;
}

template <typename T>
T XmlFileSerializer<T>::read()
{
    if (isWritable()) throw XmlFileSerializerException(XmlFileSerializerException::NOT_ALLOWED, "File in writing mode");

    string ligne;
    string endCollectionName = "</" + collectionName + ">";
    streampos currentPos = file.tellg();

    file >> ligne;

    if (ligne == endCollectionName) throw XmlFileSerializerException(XmlFileSerializerException::END_OF_FILE, "File ended");

    file.seekg(currentPos);
    T type;
    file >> type;

    return type;
}

template <typename T>
XmlFileSerializer<T>::~XmlFileSerializer()
{

    file << "</" << collectionName << ">" << endl;
    file.close();
}
