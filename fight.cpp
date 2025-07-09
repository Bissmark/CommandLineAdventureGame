#include "fight.h"

Fight::Fight(Player* p, string enemyType) {
    player = p;
    enemy = Enemy::CreateEnemy(enemyType);
    fightActive = false;
    whosTurn = 1; // 1 being player
}

Fight::~Fight() {
    delete enemy;
}

void Fight::FightMenu() {
    string fightDecision;
    bool validInput = false;

    do {
        cout << "You are currently fighing a " << enemy->getName() << endl;
        cout << "It is level " << enemy->getLevel() << endl;
        cout << "It has " << enemy->getHP() << " hp" << endl;
        cout << "Please choose an action" << endl;
        cout << "Fight" << endl;
        cout << "Run" << endl;
        cin >> fightDecision;
    
        transform(fightDecision.begin(), fightDecision.end(), fightDecision.begin(), ::tolower);
    
        if (fightDecision == "fight") {
            FightScreen();
            validInput = true;
        } else if (fightDecision == "run") {
            Run();
            validInput = true;
        } else {
            cout << "Please Select Fight or Run" << endl;
        }
    } while (!validInput);
}

void Fight::FightScreen() {
    cout << "You attacked the " << enemy->getName() << endl;
    PlayerTurn();

    if (enemy->isAlive()) {
        EnemyTurn();
    } else {
        cout << "You have defeated " << enemy->getName() << endl;
        cout << "You have received " << enemy->getExperience() << " from winning the battle" << endl;
    }
}

void Fight::Run() {
    cout << "Your ran" << endl;
}

void Fight::PlayerTurn() {
    
    if (whosTurn == 1) {
        int damage = player->getStrength() - enemy->getStrength();
    
        if (damage < 1) {
            damage = 1;
        }

        enemy->takeDamage(damage);
        cout << "You dealt " << damage << " damage" << endl;
        cout << enemy->getName() << " has " << enemy->getHP() << " hp left" << endl;

        whosTurn = 2;
    }
}

void Fight::EnemyTurn() {
    if (whosTurn == 2) {
        int damage = player->getStrength() - enemy->getStrength();

        if (damage < 1) {
            damage = 1;
        }

        player->takeDamage(damage);
        cout << "The " << enemy->getName() << " has dealt " << damage << " to you" << endl;
        cout << "You have " << player->getHP() << " hp left" << endl;

        whosTurn = 1;
    }
}