#include "dice.h"

Dice::Dice() {

}

int Dice::Roll() {
    int randomDiceAmount = rand() % diceFaces + 1;
    cout << randomDiceAmount << endl;

    return randomDiceAmount;
}