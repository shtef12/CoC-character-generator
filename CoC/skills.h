#ifndef SKILLS_H
#define SKILLS_H

#include <vector>
#include "qstring.h"
#include "skillsconstants.h"

//#include "characteristics.h"

class characteristics;

class skills
{
    characteristics* c;
    std::vector<QString> skillNames;
    std::vector<int> values;
    std::vector<int> halfValues;
    std::vector<int> fifthValues;

    void generateBaseValues();
public:
    skills(characteristics* chars);

    void setValue(SkillNames name, int value);
    int getValue(SkillNames name);
    int getHalfValue(SkillNames name);
    int getFifthValue(SkillNames name);

    int indexFromName(QString& name);
    void resetSkills();

    QString toQString();
};

#endif // SKILLS_H
