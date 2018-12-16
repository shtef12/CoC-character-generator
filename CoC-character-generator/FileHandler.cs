using System;
using System.Collections.Generic;

namespace COC_character_generator
{
    class FileHandler
    {
        public static List<string> ReadFile(string fileName)
        {
            string name = "../../" + fileName;
            List<string> contents = new List<string>();
            string[] lines = System.IO.File.ReadAllLines(name);
            foreach(string line in lines)
            {
                contents.Add(line);
            }
            return contents;
        }
    }
}
