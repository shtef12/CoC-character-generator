#ifndef READER_H
#define READER_H

#include "qfile.h"

class reader
{
public:
    reader();
    static std::vector<QString> readFile(QString file);
};

#endif // READER_H
