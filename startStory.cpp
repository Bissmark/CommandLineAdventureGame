#include "startStory.h"

StartStory::StartStory(Player* player) : player(player) {

}

string StartStory::GetRandomEnemy() {
    cout << player->getLevel() << endl;
    if (player->getLevel() == 1) {
        vector<string> enemies = {"Gnoll"};
        int randomIndex = rand() % enemies.size();
        return enemies[randomIndex];
    }

    return "Gnoll";
}

void StartStory::RandomEncounter() {
    string enemyType = GetRandomEnemy();
    cout << "A wild " << enemyType << " has appeared" << endl;

    Fight fight(player, enemyType);
    fight.FightMenu();
}