#ifndef HELPERS_H
#define HELPERS_H
#include "qstring.h"


class helpers
{
public:
    helpers();

    static int randomRange(int min, int max);

    /*Rolls a dice and returns the result (ex: rollDice(1,6,1) = 1D6+1*/
    static int rollDice(int numDice, int sides, int modifier = 0);

    static void print(const QString& str);
};

#endif // HELPERS_H
