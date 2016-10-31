#include "skills.h"
//#include "QString"
#include "reader.h"
#include "characteristics.h"
#include <iostream>

skills::skills(characteristics *chars)
{
    c = chars;
    generateBaseValues();
}

void skills::generateBaseValues()
{
    std::vector<QString> content = reader::readFile("baseSkillValues.txt");

    for(int i = 0; i < content.size(); i++){
        QString word = content[i];         //two words ex: Astronomy 5
        QStringList ls = word.split(" ");  //split the 2 words

        bool ok;
        int num = ls[1].toInt(&ok);        //convert 2nd word to int
        skillNames.push_back(ls[0]);       //add skill name to vector
        if(ok){
            setValue((SkillNames)i,num);
        }else{
            QString abbr = ls[1];
            int index = c->getIndexFromAbbr(abbr);
            int val = c->getValue((CharacteristicName)index);
            setValue((SkillNames)i,val);
        }
    }
}

void skills::resetSkills()
{
   generateBaseValues();
}

void skills::setValue(SkillNames name, int value)
{
    //push the value to vector if not big enough
    //else change the value at the index of skill
    if(values.size() <= (int)name){
        values.push_back(value);
        halfValues.push_back(value / 2);
        fifthValues.push_back(value / 5);
    }else{
        values[name] = value;
        halfValues[name] = value / 2;
        fifthValues[name] = value / 5;
    }
}

int skills::getValue(SkillNames name)
{
    return values[name];
}

int skills::getHalfValue(SkillNames name)
{
    return halfValues[name];
}

int skills::getFifthValue(SkillNames name)
{
    return fifthValues[name];
}

int skills::indexFromName(QString& name)
{
    for(int i = 0; i < skillNames.size(); i++){
        if(QString::compare(name,skillNames[i],Qt::CaseInsensitive) == 0){
            return i;
        }
    }
    return -1;
}

QString skills::toQString()
{
    QString str;
    for(int i = 0; i < values.size(); i++){
        str.append(skillNames[i] + ": " + QString::number(values[i]) + "/" + QString::number(halfValues[i]) + "/" + QString::number(fifthValues[i]));
        if(i != values.size() - 1){
            str.append(",");
        }
        str.append("\n");
    }
    return str;
}
