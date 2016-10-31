#ifndef OCCUPATIONS_H
#define OCCUPATIONS_H

#include "reader.h"
#include "QMap"
#include "skillsconstants.h"

class occupations
{
    QMap<QString,QVector<QString> > occupationInfo;

    void setupOccupations();

    QString getInterpersonalSkill();
public:
    occupations();

    QMap<QString,QVector<QString> > getRandomOccupation();
};

#endif // OCCUPATIONS_H
