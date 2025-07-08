#pragma once
#include <iostream>
#include <cstdlib>
using namespace std;

class Dice
{
    public:
        Dice();
        int Roll();

    private:
        int diceFaces = 20;
};