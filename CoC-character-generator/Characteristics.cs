using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace COC_character_generator
{
    public enum CharacteristicName
    {
        Strength,
        Constitution,
        Power,
        Dexterity,
        Appearance,
        Size,
        Intelligence,
        Education
    }

    /**
     * The characteristics class
     * Holds the information about characteristics and attributes
     * Characteristics = STR, CON, POW, DEX, APP, SIZ, INT, EDU
     */
    public class Characteristics
    {
        const int NUM_CHARACTERISTICS = 8;
        List<int> values;
        List<int> halfValues;
        List<int> fifthValues;

        public Characteristics()
        {
            values = new List<int>(NUM_CHARACTERISTICS);
            halfValues = new List<int>(NUM_CHARACTERISTICS);
            fifthValues = new List<int>(NUM_CHARACTERISTICS);

            for(int i = 0; i < NUM_CHARACTERISTICS; i++)
            {
                values.Add(0);
                halfValues.Add(0);
                fifthValues.Add(0);
            }
        }

        private int CalculateHalfValue(int value)
        {
            return value / 2;
        }

        private int CalculateFifthValue(int value)
        {
            return value / 5;
        }

        public void AddToCharacteristicValue(CharacteristicName name, int amountToAdd)
        {
            int value = GetValue(name);
            value += amountToAdd;
            SetValue(name, value);
        }

        public void SetValue(CharacteristicName name, int newValue)
        {
            if (newValue == 0)
            {
                values[(int)name] = newValue;
                halfValues[(int)name] = newValue;
                fifthValues[(int)name] = newValue;
                return;
            }
            values[(int)name] = newValue;
            halfValues[(int)name] = CalculateHalfValue(newValue);
            fifthValues[(int)name] = CalculateFifthValue(newValue);
        }

        public void GenerateRandomCharacteristics()
        {
            SetValue(CharacteristicName.Strength, Helpers.RollDice(3, 6, 0) * 5);
            SetValue(CharacteristicName.Constitution, Helpers.RollDice(3, 6, 0) * 5);
            SetValue(CharacteristicName.Dexterity, Helpers.RollDice(3, 6, 0) * 5);
            SetValue(CharacteristicName.Appearance, Helpers.RollDice(3, 6, 0) * 5);
            SetValue(CharacteristicName.Power, Helpers.RollDice(3, 6, 0) * 5);

            SetValue(CharacteristicName.Size, Helpers.RollDice(2, 6, 6) * 5);
            SetValue(CharacteristicName.Intelligence, Helpers.RollDice(2, 6, 6) * 5);
            SetValue(CharacteristicName.Education, Helpers.RollDice(2, 6, 6) * 5);
        }

        public int GetValue(CharacteristicName characteristic)
        {
            int index = (int)characteristic;
            return (int)values[index];
        }

        public int GetHalfValue(CharacteristicName characteristic)
        {
            return (int)halfValues[(int)characteristic];
        }

        public int GetFifthValue(CharacteristicName characteristic)
        {
            return (int)fifthValues[(int)characteristic];
        }
    }
}
