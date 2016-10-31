#include "character.h"
#include <iostream>
#include "reader.h"
#include "helpers.h"

character::character()
{

}

void character::generateRandomCharacter()
{
    generateRandomOccupation();
    chars.generateRandomCharacteristics(jobSkills);
    generateSex();
    generateAge();
    generateRandomName();
    adjustMovementRate();

    std::cout << chars.toQString().toStdString() << std::endl;
}

void character::generateSex()
{
    int r = rand() % 2;
    if(r == 0){
        gender = 0;
    }else{
        gender = 1;
    }
}

void character::generateAge()
{
    age = helpers::randomRange(15,89);
    if(age <= 19){
        //deduct 5 from size and education
        chars.addToCharacteristicValue(CharacteristicName::Size,-5);
        chars.addToCharacteristicValue(CharacteristicName::Education,-5);

        //reroll luck value and if greater, set luck to higher value
        int luck2 = helpers::rollDice(3,6,0) * 5;
        if(luck2 > chars.luck){
            chars.luck = luck2;
        }
    }else if(age >= 20 && age <= 39){
        //reroll education value and set to highest
        int edu2 = helpers::rollDice(2,6,6) * 5;
        if(edu2 > getCharacteristicValue(CharacteristicName::Education)){
            int toAdd = helpers::rollDice(1,10);
            int newVal = getCharacteristicValue(CharacteristicName::Education) + toAdd;
            setCharacteristicValue(CharacteristicName::Education,newVal);
        }
    }else if(age >= 40 && age <= 49){
        reduceRandomCharForAge(age);

        //roll twice for education and set highest
        int max = getCharacteristicValue(CharacteristicName::Education);
        //reroll education 2 times and set highest
        for(int i = 0; i < 2; i++){
            int val = helpers::rollDice(2,6,6) * 5;
            if(val > max){
                int toAdd = helpers::rollDice(1,10);
                int newVal = getCharacteristicValue(CharacteristicName::Education) + toAdd;
                setCharacteristicValue(CharacteristicName::Education,newVal);
                max = newVal;
            }
        }
    }else if(age >= 50 && age <= 59){
        reduceRandomCharForAge(age);

        int max = getCharacteristicValue(CharacteristicName::Education);
        //reroll education 3 times and set highest
        for(int i = 0; i < 3; i++){
            int val = helpers::rollDice(2,6,6) * 5;
            if(val > max){
                int toAdd = helpers::rollDice(1,10);
                int newVal = getCharacteristicValue(CharacteristicName::Education) + toAdd;
                setCharacteristicValue(CharacteristicName::Education,newVal);
                max = newVal;
            }
        }
    }else if(age >= 60 && age <= 69){
        reduceRandomCharForAge(age);
        int max = getCharacteristicValue(CharacteristicName::Education);
        //reroll education 4 times and set highest
        for(int i = 0; i < 4; i++){
            int val = helpers::rollDice(2,6,6) * 5;
            if(val > max){
                int toAdd = helpers::rollDice(1,10);
                int newVal = getCharacteristicValue(CharacteristicName::Education) + toAdd;
                setCharacteristicValue(CharacteristicName::Education,newVal);
                max = newVal;
            }
        }
    }else if(age >= 70 && age <= 79){
        reduceRandomCharForAge(age);

        int max = getCharacteristicValue(CharacteristicName::Education);
        //reroll education 4 times and set highest
        for(int i = 0; i < 4; i++){
            int val = helpers::rollDice(2,6,6) * 5;
            if(val > max){
                int toAdd = helpers::rollDice(1,10);
                int newVal = getCharacteristicValue(CharacteristicName::Education) + toAdd;
                setCharacteristicValue(CharacteristicName::Education,newVal);
                max = newVal;
            }
        }
    }else if(age >= 80){
        reduceRandomCharForAge(age);

        int max = getCharacteristicValue(CharacteristicName::Education);
        //reroll education 4 times and set highest
        for(int i = 0; i < 4; i++){
            int val = helpers::rollDice(2,6,6) * 5;
            if(val > max){
                int toAdd = helpers::rollDice(1,10);
                int newVal = getCharacteristicValue(CharacteristicName::Education) + toAdd;
                setCharacteristicValue(CharacteristicName::Education,newVal);
                max = newVal;
            }
        }
    }
}

void character::reduceRandomCharForAge(int age)
{
    int amtToReduce = -5;
    int amtToReduceAPP = -5;

    //adjust amount for the age
    if(age >= 50 && age <= 59){
        amtToReduce = -10;
        amtToReduceAPP = -10;
    }else if(age >= 60 && age <= 69){
        amtToReduce = -20;
        amtToReduceAPP = -15;
    }else if(age >= 70 && age <= 79){
        amtToReduce = -40;
        amtToReduceAPP = -20;
    }else if(age >= 80){
        amtToReduce = -80;
        amtToReduceAPP = -25;
    }

    //randomly reduce from STR, CON, DEX
    while(amtToReduce > 0){
        int num = rand() % 3;
        int reduceNum = rand() % abs(amtToReduce) + 1;
        switch(num){
        case 0: chars.addToCharacteristicValue(CharacteristicName::Strength,-reduceNum); break;
        case 1: chars.addToCharacteristicValue(CharacteristicName::Constitution,-reduceNum); break;
        case 2: chars.addToCharacteristicValue(CharacteristicName::Dexterity,-reduceNum); break;
        }
        amtToReduce -= reduceNum;
    }

    chars.addToCharacteristicValue(CharacteristicName::Appearance,amtToReduceAPP);
}

void character::adjustMovementRate()
{
    if(age >= 40 && age <= 49){
        chars.movementRate -= 1;
    }else if(age >= 50 && age <= 59){
        chars.movementRate -= 2;
    }else if(age >= 60 && age <= 69){
        chars.movementRate -= 3;
    }else if(age >= 70 && age <= 79){
        chars.movementRate -= 4;
    }else if(age >= 80){
        chars.movementRate = -5;
    }
}

QString character::generateFirstName()
{
    std::vector<QString> firstnames;
    if(gender == 0){
        firstnames = reader::readFile("femaleNames.txt");
    }else{
        firstnames = reader::readFile("maleNames.txt");
    }

    int firstNameIndex = helpers::randomRange(0,firstnames.size() - 1);
    return firstnames[firstNameIndex];

}

QString character::generateLastName()
{
    std::vector<QString> names = reader::readFile("surnames.txt");
    int index = helpers::randomRange(0,names.size() - 1);
    return names[index];
}

void character::generateRandomName()
{
    name = generateFirstName() + " " + generateLastName();
}

void character::generateRandomOccupation()
{
    QMap<QString, QVector<QString> > job = jobsList.getRandomOccupation();
    occupation = job.keys()[0];

    jobSkills = job[occupation];

    helpers::print("job is " + occupation);
}

void character::resetSkills()
{
    chars.resetSkills();
}

void character::setSanity(int val)
{
    chars.sanity = val;
}

void character::setHitPoints(int val)
{
    chars.hitPts = val;
}

void character::setMagicPoints(int val)
{
    chars.magicPts = val;
}

void character::setCharacteristicValue(CharacteristicName name, int val)
{
    chars.setValue(name,val);
}

void character::setSkillValue(SkillNames name, int val)
{
    chars.setSkillValue(name,val);
}

void character::setLuck(int val)
{
    chars.luck = val;
}

void character::setBuild(int val)
{
    chars.build = val;
}

void character::setDamageBonus(const QString &val)
{
    chars.damageBonus = val;
}

int character::getSkillValue(SkillNames name)
{
    return chars.getSkillValue(name);
}

int character::getCharacteristicValue(CharacteristicName name)
{
    return chars.getValue(name);
}

int character::getHitPoints()
{
    return chars.hitPts;
}

int character::getMagicPoints()
{
    return chars.magicPts;
}

int character::getSanity()
{
    return chars.sanity;
}

int character::getLuck()
{
    return chars.luck;
}

int character::getBuild()
{
    return chars.build;
}

QString& character::getDamageBonus()
{
    return chars.damageBonus;
}

QString character::toQString()
{
    QString str;
    str.append(name + ", " + QString::number(age));
    return str;

}
