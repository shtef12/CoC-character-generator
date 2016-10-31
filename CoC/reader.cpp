#include "reader.h"
#include "QTextStream"

reader::reader()
{

}

std::vector<QString> reader::readFile(QString file)
{
    std::vector<QString> contents;
    QFile inputFile(file);
    if(inputFile.open(QIODevice::ReadOnly)){
        QTextStream in(&inputFile);
        while(!in.atEnd()){
            QString line = in.readLine();
            contents.push_back(line);
        }
    }
    inputFile.close();
    return contents;
}
