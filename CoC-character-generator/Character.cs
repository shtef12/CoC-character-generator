using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace COC_character_generator
{
    public class Character
    {
        //false = female, true = male
        public bool gender { get; set; }
        public string name { get; set; }
        public int age { get; set; }
        public string player { get; set; }
        public string occupation { get; set; }
        public string residence { get; set; }
        public string birthplace { get; set; }

        Characteristics characteristics;
        Skills skills;

        int hitPts { get; set; }
        int sanity { get; set; }
        int luck { get; set; }
        int magicPts { get; set; }
        int build { get; set; }
        public int movementRate { get; set; }
        public string damageBonus { get; set; }

        public Character()
        {
            luck = 0;
            gender = false;
            characteristics = new Characteristics();
            skills = new Skills();
        }

        public void GenerateRandomCharacter()
        {
            GenerateRandomOccupation();
            GenerateSex();
            characteristics.GenerateRandomCharacteristics();
            GenerateAge();
            GenerateRandomName();
            CalculateBonusAndBuild();
            CalculateMovementRate();
            AdjustMovementRate();
            //generate skills
        }

        private void GenerateSex()
        {
            int num = Helpers.RollDice(1, 2);
            if (num == 1) gender = false;
            else gender = true;
        }

        /// <summary>
        /// Updates the character's characteristics based on their age
        /// </summary>
        private void GenerateAge()
        {
            age = Helpers.RandomRange(15, 89);

            if (age <= 19)
            {
                //deduct 5 from size and education
                characteristics.AddToCharacteristicValue(CharacteristicName.Size, -5);
                characteristics.AddToCharacteristicValue(CharacteristicName.Education, -5);

                //reroll luck value and if greater, set luck to higher value
                int luck2 = Helpers.RollDice(3, 6, 0) * 5;
                if (luck2 > luck)
                {
                    luck = luck2;
                }

            }
            else if (age >= 20 && age <= 39)
            {
                //reroll education value and if higher than original, add 1d10 to it
                int edu2 = Helpers.RollDice(2, 6, 6) * 5;
                if (edu2 > GetCharacteristicValue(CharacteristicName.Education))
                {
                    int toAdd = Helpers.RollDice(1, 10);
                    int newVal = GetCharacteristicValue(CharacteristicName.Education) + toAdd;
                    SetCharacteristicValue(CharacteristicName.Education, newVal);
                }
            }
            else if (age >= 40 && age <= 49)
            {
                ReduceCharacteristicsByAge(age);

                //roll twice for education and set highest
                int max = GetCharacteristicValue(CharacteristicName.Education);
                //reroll education 2 times and add 1d10 to it if roll was higher than original
                for (int i = 0; i < 2; i++)
                {
                    int val = Helpers.RollDice(2, 6, 6) * 5;
                    if (val > max)
                    {
                        int toAdd = Helpers.RollDice(1, 10);
                        int newVal = GetCharacteristicValue(CharacteristicName.Education) + toAdd;
                        SetCharacteristicValue(CharacteristicName.Education, newVal);
                        max = newVal;
                    }

                }
            }
            else if (age >= 50 && age <= 59)
            {
                ReduceCharacteristicsByAge(age);

                //roll twice for education and set highest
                int max = GetCharacteristicValue(CharacteristicName.Education);
                //reroll education 3 times and add 1d10 to it if roll was higher than original
                for (int i = 0; i < 3; i++)
                {
                    int val = Helpers.RollDice(2, 6, 6) * 5;
                    if (val > max)
                    {
                        int toAdd = Helpers.RollDice(1, 10);
                        int newVal = GetCharacteristicValue(CharacteristicName.Education) + toAdd;
                        SetCharacteristicValue(CharacteristicName.Education, newVal);
                        max = newVal;
                    }

                }
            }
            else if (age >= 60 && age <= 69)
            {
                ReduceCharacteristicsByAge(age);

                //roll twice for education and set highest
                int max = GetCharacteristicValue(CharacteristicName.Education);
                //reroll education 4 times and add 1d10 to it if roll was higher than original
                for (int i = 0; i < 4; i++)
                {
                    int val = Helpers.RollDice(2, 6, 6) * 5;
                    if (val > max)
                    {
                        int toAdd = Helpers.RollDice(1, 10);
                        int newVal = GetCharacteristicValue(CharacteristicName.Education) + toAdd;
                        SetCharacteristicValue(CharacteristicName.Education, newVal);
                        max = newVal;
                    }

                }
            }
            else if (age >= 70 && age <= 79)
            {
                ReduceCharacteristicsByAge(age);

                //roll twice for education and set highest
                int max = GetCharacteristicValue(CharacteristicName.Education);
                //reroll education 4 times and add 1d10 to it if roll was higher than original
                for (int i = 0; i < 4; i++)
                {
                    int val = Helpers.RollDice(2, 6, 6) * 5;
                    if (val > max)
                    {
                        int toAdd = Helpers.RollDice(1, 10);
                        int newVal = GetCharacteristicValue(CharacteristicName.Education) + toAdd;
                        SetCharacteristicValue(CharacteristicName.Education, newVal);
                        max = newVal;
                    }

                }
            }
            else if (age >= 80)
            {
                ReduceCharacteristicsByAge(age);

                //roll twice for education and set highest
                int max = GetCharacteristicValue(CharacteristicName.Education);
                //reroll education 2 times and add 1d10 to it if roll was higher than original
                for (int i = 0; i < 4; i++)
                {
                    int val = Helpers.RollDice(2, 6, 6) * 5;
                    if (val > max)
                    {
                        int toAdd = Helpers.RollDice(1, 10);
                        int newVal = GetCharacteristicValue(CharacteristicName.Education) + toAdd;
                        SetCharacteristicValue(CharacteristicName.Education, newVal);
                        max = newVal;
                    }

                }
            }
        }

        private string GenerateFirstName()
        {
            List<string> names;
            if (gender == false)
            {
                names = FileHandler.ReadFile("data/femaleNames.txt");
            }
            else
            {
                names = FileHandler.ReadFile("data/maleNames.txt");
            }

            int index = Helpers.RandomRange(0, names.Count - 1);
            return names[index];
        }

        private string GenerateLastName()
        {
            List<string> names = FileHandler.ReadFile("data/surnames.txt");
            int index = Helpers.RandomRange(0, names.Count - 1);
            return names[index];
        }

        private void GenerateRandomName()
        {
            name = GenerateFirstName() + " " + GenerateLastName();
        }

        /// <summary>
        /// Randomly reduce from STR, CON, DEX based on age
        /// </summary>
        /// <param name="age"></param>
        private void ReduceCharacteristicsByAge(int age)
        {
            int amountToReduce = -5;
            int amountToReduceAPP = -5;

            //set the number of points to reduced based on age
            if (age >= 50 && age <= 59)
            {
                amountToReduce = -10;
                amountToReduceAPP = -10;
            }
            else if (age >= 60 && age <= 69)
            {
                amountToReduce = -20;
                amountToReduceAPP = -15;
            }
            else if (age >= 70 && age <= 79)
            {
                amountToReduce = -40;
                amountToReduceAPP = -20;
            }
            else if (age >= 80)
            {
                amountToReduce = -80;
                amountToReduceAPP = -25;
            }

            //reduce from STR, CON, or DEX
            while (amountToReduce > 0)
            {
                int num = Helpers.RandomRange(0, 2);         //the characteristic to remove from
                int reduceNum = Helpers.RandomRange(1, 10);  //the amount to reduce
                switch (num)
                {
                    case 0: characteristics.AddToCharacteristicValue(CharacteristicName.Strength, -reduceNum); break;
                    case 1: characteristics.AddToCharacteristicValue(CharacteristicName.Constitution, -reduceNum); break;
                    case 2: characteristics.AddToCharacteristicValue(CharacteristicName.Dexterity, -reduceNum); break;
                }
                amountToReduce -= reduceNum;
            }

            characteristics.AddToCharacteristicValue(CharacteristicName.Appearance, amountToReduceAPP);
        }

        public void CalculateBonusAndBuild()
        {
            int StrPlusSize = GetCharacteristicValue(CharacteristicName.Strength) + GetCharacteristicValue(CharacteristicName.Size);
            if (StrPlusSize >= 2 && StrPlusSize <= 64)
            {
                damageBonus = "-2";
                build = -2;
            }
            else if (StrPlusSize >= 65 && StrPlusSize <= 84)
            {
                damageBonus = "-1";
                build = -1;
            }
            else if (StrPlusSize >= 85 && StrPlusSize <= 124)
            {
                damageBonus = "0";
                build = 0;
            }
            else if (StrPlusSize >= 125 && StrPlusSize <= 164)
            {
                damageBonus ="+1D4";
                build = 1;
            }
            else if (StrPlusSize >= 165 && StrPlusSize <= 204)
            {
                damageBonus = "+1D6";
                build = 2;
            }
            else if (StrPlusSize >= 205 && StrPlusSize <= 284)
            {
                damageBonus = "+2D6";
                build = 3;
            }
            else if (StrPlusSize >= 285 && StrPlusSize <= 364)
            {
                damageBonus = "+3D6";
                build = 4;
            }
            else if (StrPlusSize >= 365 && StrPlusSize <= 444)
            {
                damageBonus = "+4D6";
                build = 5;
            }
            else if (StrPlusSize >= 445)
            {
                damageBonus = "+5D6";
                build = 6;
            }
        }

        public void CalculateMovementRate()
        {
            int dex = GetCharacteristicValue(CharacteristicName.Dexterity);
            int str = GetCharacteristicValue(CharacteristicName.Strength);
            int size = GetCharacteristicValue(CharacteristicName.Size);

            if (dex < size && str < size)
            {
                movementRate = 7;
            }
            else if (dex > size && str > size)
            {
                movementRate = 9;
            }
            else
            {
                movementRate = 8;
            }
        }

        private void AdjustMovementRate()
        {
            if (age >= 40 && age <= 49)
                movementRate -= 1;
            else if (age >= 50 && age <= 59)
                movementRate -= 2;
            else if (age >= 60 && age <= 69)
                movementRate -= 3;
            else if (age >= 70 && age <= 79)
                movementRate -= 4;
            else if (age >= 80)
                movementRate -= 5;
        }

        /// <summary>
        /// Gets a random occupation
        /// </summary>
        private void GenerateRandomOccupation()
        {
            Dictionary<string, string[]> occupations = GetOccupationData();
            int randIndex = Helpers.RollDice(1, occupations.Count - 1);
            KeyValuePair<string, string[]> data = occupations.ElementAt(randIndex);
            occupation = data.Key;
        }

        /// <summary>
        /// Reads the data from occupations.txt and returns dictionary of skills associated with the occupation
        /// </summary>
        /// <returns>dictionary of occupation skills</returns>
        private Dictionary<String, String[]> GetOccupationData()
        {
            Dictionary<String, String[]> occupationDictionary = new Dictionary<string, string[]>();
            List<string> occupations = FileHandler.ReadFile("data/occupations.txt");
            foreach(string occupation in occupations)
            {
                string[] occupationSkills = occupation.Split(new Char[] { ':', ',' });
                string[] temp = new string[occupationSkills.Length];
                //copy the skills for the occupation to a temp array
                Array.Copy(occupationSkills, 1, temp, 0, occupationSkills.Length - 1);
                //add the occupation to a dict and the skills as the value
                occupationDictionary.Add(occupationSkills[0], temp);
            }
            return occupationDictionary;
        }

        public int GetCharacteristicValue(CharacteristicName name)
        {
            return characteristics.GetValue(name);
        }

        public void SetCharacteristicValue(CharacteristicName name, int value)
        {
            characteristics.SetValue(name, value);
        }
    }
}
