using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace COC_character_generator
{
    enum SkillNames
    {
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

    class Skills
    {
        //const int NUM_SKILLS = 46;

        List<int> values;
        List<int> halfValues;
        List<int> fifthValues;

        public Skills()
        {
            values = new List<int>();
            halfValues = new List<int>();
            fifthValues = new List<int>();
            GenerateBaseValues();
        }

        public void SetValue(SkillNames name, int value)
        {
            values[(int)name] = value;
            halfValues[(int)name] = CalculateHalfValue(value);
            fifthValues[(int)name] = CalculateFifthValue(value);
        }

        /// <summary>
        /// Generates the initial skill values as specified in the text file "data/baseSkillValues.txt"
        /// </summary>
        private void GenerateBaseValues()
        {
            List<string> baseValues = FileHandler.ReadFile("data/baseSkillValues.txt");
            for(int i = 0; i < baseValues.Count; i++)
            {
                string[] words = baseValues[i].Split(' ');
                int valueAsNum = -1;
                int.TryParse(words[1], out valueAsNum);
                values.Add(valueAsNum);
                halfValues.Add(CalculateHalfValue(valueAsNum));
                fifthValues.Add(CalculateFifthValue(valueAsNum));
            }
        }

        public int GetValue(SkillNames name)
        {
            return values[(int)name];
        }

        public int GetHalfValue(SkillNames name)
        {
            return halfValues[(int)name];
        }

        public int GetFifthValue(SkillNames name)
        {
            return fifthValues[(int)name];
        }

        private int CalculateHalfValue(int value)
        {
            return value / 2;
        }

        private int CalculateFifthValue(int value)
        {
            return value / 5;
        }
    }
}
