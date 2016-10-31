#ifndef CHARACTER_H
#define CHARACTER_H

#include "characteristics.h"
#include "occupations.h"

class character
{

    occupations jobsList;

    //may make functions public if we want random buttons on ui
    void generateSex();
    void generateAge();
    QString generateFirstName();
    QString generateLastName();
    QVector<QString> jobSkills;

    /*Generates a random first and last name*/
    void generateRandomName();

    /*Reduces either DEX,CON or STR based on the character's age*/
    void reduceRandomCharForAge(int age);

    /*Sets the character's movement rate based on SIZ and STR*/
    void adjustMovementRate();

    /*Generates a random job for the character*/
    void generateRandomOccupation();

public:
    character();

    /*Holds the skills/characteristics of character*/
    characteristics chars;

    QString name;
    unsigned int age;

    /*0 for male, 1 for female*/
    bool gender;

    /*Where the character lives*/
    QString residence;

    /*Where the character was born*/
    QString birthplace;

    /*Job of character, in game this affects skill scores. Will have to find
      a way to implement that or just have user change skills manually*/
    QString occupation;

    /*Brief description of character*/
    QString description;

    /*Characters beliefs/ideologies*/
    QString beliefs;

    /*Anyone significant to character*/
    QString significantPeople;

    /*Any locations that are important to character*/
    QString meaningfulLocations;

    /*Special possessions to character*/
    QString treasuredPossessions;

    /*Any traits this character has*/
    QString traits;

    /*Injuries sustained*/
    QString injuries;

    /*Fears, manias inflicting the character*/
    QString phobiaManias;

    /*Encounters with strange creatures/events*/
    QString strangeEncounters;

    /*Spells, artifacts, tomes character has*/
    QString spellsArtifacts;

    /*Gear and possessions the player has*/
    QString gear;

    /*Holds any notes the player adds to the character*/
    QString notes;

    void setSanity(int val);
    void setHitPoints(int val);
    void setMagicPoints(int val);
    void setLuck(int val);
    void setSkillValue(SkillNames name, int val);
    void setCharacteristicValue(CharacteristicName name, int val);
    void setBuild(int val);
    void setDamageBonus(const QString& val);

    int getSkillValue(SkillNames name);
    void resetSkills();
    int getCharacteristicValue(CharacteristicName name);
    int getHitPoints();
    int getMagicPoints();
    int getSanity();
    int getLuck();
    int getBuild();
    QString& getDamageBonus();

    /*Generates  a random character*/
    void generateRandomCharacter();

    QString toQString();
};

#endif // CHARACTER_H
