#include "characteristics.h"
#include <time.h>
#include "random"
#include <iostream>
#include "skills.h"

characteristics::characteristics()
{
    //generateRandomCharacteristics();
    skill = new skills(this);
}

characteristics::characteristics(const characteristics &src)
{
    //create new pointer to skills class so not to share same pointer as src
    skill = new skills(this);
}

characteristics::~characteristics()
{
    delete skill;
}

void characteristics::generateRandomCharacteristics(QVector<QString>& jobSkills)
{
    srand(time(0));

    //set values with a dice roll of 3D6 * 5
    setValue(CharacteristicName::Strength,helpers::rollDice(3,6,0)*5);
    setValue(CharacteristicName::Constitution,helpers::rollDice(3,6,0)*5);
    setValue(CharacteristicName::Dexterity,helpers::rollDice(3,6,0)*5);
    setValue(CharacteristicName::Appearance,helpers::rollDice(3,6,0)*5);
    setValue(CharacteristicName::Power,helpers::rollDice(3,6,0)*5);
    luck = helpers::rollDice(3,6,0) * 5;

    //set values with roll of 2D6+6 * 5
    setValue(CharacteristicName::Size,helpers::rollDice(2,6,6)*5);
    setValue(CharacteristicName::Intelligence,helpers::rollDice(2,6,6)*5);
    setValue(CharacteristicName::Education,helpers::rollDice(2,6,6)*5);

    magicPts = getFifthValue(CharacteristicName::Power);
    hitPts = (getValue(CharacteristicName::Size) + getValue(CharacteristicName::Constitution)) / 10;
    sanity = getValue(CharacteristicName::Power);
    calculateBonusAndBuild();
    calculateMovementRate();

    setSkillValue(SkillNames::Dodge,getHalfValue(CharacteristicName::Dexterity));
    setSkillValue(SkillNames::Language_Own,getValue(CharacteristicName::Education));

    randomSpendSkillPoints(jobSkills);

}

void characteristics::addToCharacteristicValue(CharacteristicName name, int amtToAdd)
{
    values[name] += amtToAdd;
}

void characteristics::randomSpendSkillPoints(QVector<QString>& jobSkills)
{
    int occSkills = getValue(CharacteristicName::Education) * 4;
    int interestSkills = getValue(CharacteristicName::Intelligence) * 2;
    //int totalPts = occSkills + interestSkills;

    //set the occupation skills
    while(occSkills > 0){
        int randIndex = rand() % jobSkills.size();
        int index = skill->indexFromName(jobSkills[randIndex]);
        int skillAmt = getSkillValue((SkillNames)index);
        skill->setValue((SkillNames)index,skillAmt + 1);
        occSkills--;
    }

    //set the personal interest skills
    while(interestSkills > 0){
        int skill = helpers::randomRange(0,skillconstants::NUM_SKILLS-1);
        if(skill != SkillNames::Cthulhu_Mythos){
            int skillAmt = getSkillValue((SkillNames)skill);
            setSkillValue((SkillNames)skill,skillAmt + 1);
            interestSkills--;
        }
    }
}

void characteristics::resetSkills()
{
    skill->resetSkills();
}

void characteristics::setValue(CharacteristicName name, int newValue)
{
    if(newValue == 0){
        values[name] = 0;
        halfValues[name] = 0;
        fifthValues[name] = 0;
        return;
    }
    values[name] = newValue;
    halfValues[name] = calculateHalfValue(newValue);
    fifthValues[name] = calculateFifthValue(newValue);
}

void characteristics::setSkillValue(SkillNames name, int value)
{
    skill->setValue(name,value);
}

int characteristics::calculateHalfValue(int value)
{
    return value / 2;
}

int characteristics::calculateFifthValue(int value)
{
    return value / 5;
}

void characteristics::calculateBonusAndBuild()
{
    int val = getValue(CharacteristicName::Strength) + getValue(CharacteristicName::Size);
    if(val >= 2 && val <= 64 ){
        damageBonus = QString::number(-2);
        build = -2;
    }else if(val >= 65 && val <= 84){
        damageBonus = QString::number(-1);
        build = -1;
    }else if(val >= 85 && val <= 124){
        damageBonus = QString::number(0);
        build = 0;
    }else if(val >= 125 && val <= 164){
        damageBonus = QString("+1D4");
        build = 1;
    }else if(val >= 165 && val <= 204){
        damageBonus = QString("+1D6");
        build = 2;
    }else if(val >= 205 && val <= 284){
        damageBonus = QString("+2D6");
        build = 3;
    }else if(val >= 285 && val <= 364){
        damageBonus = QString("+3D6");
        build = 4;
    }else if(val >= 365 && val <= 444){
        damageBonus = QString("+4D6");
        build = 5;
    }else if(val >= 445){
        damageBonus = QString("+5D6");
        build = 6;
    }
}

void characteristics::calculateMovementRate()
{
    int dex = getValue(CharacteristicName::Dexterity);
    int str = getValue(CharacteristicName::Strength);
    int size = getValue(CharacteristicName::Size);

    if(dex < size && str < size){
        movementRate = 7;
    }else if(dex > size && str > size){
        movementRate = 9;
    }else{
        movementRate = 8;
    }
}

int characteristics::getValue(CharacteristicName characteristic)
{
    return values[characteristic];
}

int characteristics::getHalfValue(CharacteristicName characteristic)
{
    return halfValues[characteristic];
}

int characteristics::getFifthValue(CharacteristicName characteristic)
{
    return fifthValues[characteristic];
}

int characteristics::getSkillValue(SkillNames name)
{
    return skill->getValue(name);
}

int characteristics::getSkillHalfValue(SkillNames name)
{
    return skill->getHalfValue(name);
}

int characteristics::getSkillFifthValue(SkillNames name)
{
    return skill->getFifthValue(name);
}

CharacteristicName characteristics::getNameFromAbbr(QString abbr)
{
    if(abbr == "STR"){
        return CharacteristicName::Strength;
    }else if(abbr == "CON"){
        return CharacteristicName::Constitution;
    }else if(abbr == "SIZ"){
        return CharacteristicName::Size;
    }else if(abbr == "DEX"){
        return CharacteristicName::Dexterity;
    }else if(abbr == "APP"){
        return CharacteristicName::Appearance;
    }else if(abbr == "EDU"){
        return CharacteristicName::Education;
    }else if(abbr == "INT"){
        return CharacteristicName::Intelligence;
    }else if(abbr == "POW"){
        return CharacteristicName::Power;
    }
    return CharacteristicName::Strength;
}

int characteristics::getIndexFromAbbr(QString abbr)
{
    //TODO: organize in numerical order
    if(abbr == "STR"){
        return 0;
    }else if(abbr == "CON"){
        return 1;
    }else if(abbr == "SIZ"){
        return 5;
    }else if(abbr == "DEX"){
        return 3;
    }else if(abbr == "APP"){
        return 4;
    }else if(abbr == "EDU"){
        return 7;
    }else if(abbr == "INT"){
        return 6;
    }else if(abbr == "POW"){
        return 2;
    }
    return -1;
}

QString characteristics::getNameAtIndex(int index)
{
    switch(index){
    case 0: return QString("Strength");
    case 1: return QString("Constitution");
    case 2: return QString("Power");
    case 3: return QString("Dexterity");
    case 4: return QString("Appearance");
    case 5: return QString("Size");
    case 6: return QString("Intelligence");
    case 7: return QString("Education");
    default: return "not sure";
    }
}

QString characteristics::toQString()
{
    QString str;
    for(int i = 0; i < 8; i++){
        str.append(getNameAtIndex(i));
        str.append(" ");

        //append the value/halfvalue/fifthvalue
        str.append(QString::number(values[i]) + "/" + QString::number(halfValues[i]) + "/" + QString::number(fifthValues[i]));
        if(i != 7){
            str.append(",");
        }
        str.append("\n");
    }
    return str;
}
