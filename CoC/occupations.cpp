#include "occupations.h"
#include <iostream>
#include "helpers.h"

occupations::occupations()
{
    setupOccupations();
}

void occupations::setupOccupations()
{
    //TODO: Need to replace "interpersonal" or "any skill" with
    //      a skill name
    std::vector<QString> info = reader::readFile("occupations.txt");

    foreach(QString str, info){
        QStringList ls = str.split("-");
        QString occName = ls[0];
        QString s = ls[1].trimmed();
        QStringList skills = s.split(",");
        QVector<QString> skillsVec;

        //add job's skills to vector
        foreach(QString x , skills){
            QString trim = x.trimmed();
            if(trim.contains("interpersonal")){
                helpers::print(trim[0] + " interpersonal skill");
                int amount = QString(trim[0]).toInt();
                QString iSkill;
                for(int i = 0; i < amount; i++){
                   //get an interpersonal skill
                    QString str = getInterpersonalSkill();
                    while(str == iSkill){
                        str = getInterpersonalSkill();
                    }
                    skillsVec.removeAll(x);
                    skillsVec.push_back(str);
                    iSkill = str;
                }
            }else if(trim.contains("any")){
                //helpers::print(trim[0] + " any skill");
            }
            skillsVec.append(trim);
        }
        occupationInfo.insert(occName,skillsVec);
    }
}

QString occupations::getInterpersonalSkill()
{
    int randNum = helpers::rollDice(1,4);
    switch(randNum){
    case 1: return QString("Charm");
    case 2: return QString("Fast_Talk");
    case 3: return QString("Intimidate");
    case 4: return QString("Persuade");
    }
}

QMap<QString, QVector<QString> > occupations::getRandomOccupation()
{
    QMap<QString, QVector<QString> > job;
    int randIndex = rand() % occupationInfo.size();
    int count = 0;
    for(auto key : occupationInfo.keys()){
        if(count == randIndex){
            job.insert(key,occupationInfo[key]);
            return job;
        }
        count++;
    }
    return job;
}

