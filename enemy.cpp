#include "enemy.h"
#include "gnoll.h"

Enemy::Enemy(string charName) : Character(charName) {
}

Enemy* Enemy::CreateEnemy(string enemyType) {
    if (enemyType == "Gnoll") {
        return new Gnoll("Gnoll Warrior");
    }
    return nullptr;
}