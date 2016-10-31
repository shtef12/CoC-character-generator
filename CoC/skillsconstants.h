#ifndef SKILLSCONSTANTS
#define SKILLSCONSTANTS

#include "QString"
#include "QVector"

enum CharacteristicName {
    Strength,
    Constitution,
    Power,
    Dexterity,
    Appearance,
    Size,
    Intelligence,
    Education
};

enum SkillNames{
    Accounting,
    Anthropology,
    Appraise,
    Archaeology,
    Art,
    Charm,
    Climb,
    Credit_Rating,
    Cthulhu_Mythos,
    Disguise,
    Dodge,
    Drive,
    Elec_Repair,
    Fast_Talk,
    Fighting_Brawl,
    Firearms_Handgun,
    Firearms_Rifle,
    First_Aid,
    History,
    Intimidate,
    Jump,
    Language_Other,
    Language_Own,
    Law,
    Library_Use,
    Listen,
    Locksmith,
    Mech_Repair,
    Medicine,
    Natural_World,
    Navigate,
    Occult,
    Op_Heavy_Machine,
    Persuade,
    Pilot,
    Psychology,
    Psychoanalysis,
    Ride,
    Science,
    Sleight_of_Hand,
    Spot_Hidden,
    Stealth,
    Survival,
    Swim,
    Throw,
    Track
};

class skillconstants{
public:
    static const int NUM_CHARACTERISTICS = 8;
    static const int NUM_SKILLS = 46;
};



#endif // SKILLSCONSTANTS

