using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace COC_character_generator
{
    class Helpers
    {
        static Random rand = new Random();

        public static int RandomRange(int min, int max)
        {
            return rand.Next(min, max + 1);
        }

        /// <summary>
        /// Rolls the specified amount of dice and adds modifier to final result
        /// </summary>
        /// <param name="numDice">the amount of dice to roll</param>
        /// <param name="sides">how many sides the die has</param>
        /// <param name="modifier">how much to add to final result</param>
        /// <returns></returns>
        public static int RollDice(int numDice, int sides, int modifier = 0)
        {
            int result = 0;
            for (int i = 0; i < numDice; i++)
            {
                int num = RandomRange(1, sides);
                result += num;
            }
            result += modifier;
            return result;
        }
    }
}
