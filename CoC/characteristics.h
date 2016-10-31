#ifndef CHARACTERISTICS_H
#define CHARACTERISTICS_H


#include "qstring.h"
#include "skillsconstants.h"
#include "helpers.h"

/*enum CharacteristicName {
    Strength,
    Constitution,
    Power,
    Dexterity,
    Appearance,
    Size,
    Intelligence,
    Education
};*/

class skills;

/**
 * @brief The characteristics class
 * Holds the information about characteristics and attributes
 * Characteristics = STR, CON, POW, DEX, APP, SIZ, INT, EDU
 * Attributes = LUCK, MP, DAMAGE BONUS AND BUILD, HP, SAN
 */
class characteristics
{
    /*Class of skills, holds info for skill values*/
    skills* skill;

    /*Holds the characteristic values*/
    int values[8];

    /*Holds the characteristic half values*/
    int halfValues[8];

    /*Holds the characteristic fifth values*/
    int fifthValues[8];

    /*Returns value / 2 */
    int calculateHalfValue(int value);

    /*Returns value / 5 */
    int calculateFifthValue(int value);

    void calculateBonusAndBuild();
    void calculateMovementRate();

    /*Randomly assigns skill points*/
    void randomSpendSkillPoints(QVector<QString> &jobSkills);

public:
    characteristics();
    characteristics(const characteristics& src);
    ~characteristics();

    int hitPts;
    int sanity;
    int luck;
    int magicPts;
    QString damageBonus;
    int build;
    int movementRate;

    /*Adds to the characteristic by the amout given, enter a negative number to reduce*/
    void addToCharacteristicValue(CharacteristicName name, int amtToAdd);

    void generateRandomCharacteristics(QVector<QString> &jobSkills);

    void setValue(CharacteristicName name, int newValue);
    int getValue(CharacteristicName characteristic);
    int getHalfValue(CharacteristicName characteristic);
    int getFifthValue(CharacteristicName characteristic);

    int getSkillValue(SkillNames name);
    int getSkillHalfValue(SkillNames name);
    int getSkillFifthValue(SkillNames name);

    void resetSkills();

    CharacteristicName getNameFromAbbr(QString abbr);

    /*Returns the index of the characteristic name from the abbreviation*/
    int getIndexFromAbbr(QString abbr);

    /*Returns the characteristic name at the given index*/
    QString getNameAtIndex(int index);

    void setSkillValue(SkillNames name, int value);

    QString toQString();
};

#endif // CHARACTERISTICS_H
