#include "helpers.h"
#include <random>
#include <iostream>

helpers::helpers()
{

}

int helpers::randomRange(int min, int max)
{
    std::random_device seeder;
    std::mt19937 engine(seeder());
    std::uniform_int_distribution<int> dist(min,max);
    int num = dist(engine);
    return num;
}

int helpers::rollDice(int numDice, int sides, int modifier)
{
    int result = 0;
    for(int i = 0; i < numDice; i++){
        int num = randomRange(1,sides);
        result += num;
    }
    result += modifier;
    return result;
}

void helpers::print(const QString &str)
{
    std::cout << str.toStdString() << std::endl;
}
