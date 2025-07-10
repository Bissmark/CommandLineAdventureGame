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
    cout << "\n=== BATTLE BEGINS! ===" << endl;
    
    // Main combat loop - continue while both are alive
    while (enemy->isAlive() && player->isAlive()) {
        
        // Player's turn
        if (whosTurn == 1) {
            cout << "\n--- Your Turn ---" << endl;
            PlayerTurn();
            
            // Check if enemy died from player attack
            if (!enemy->isAlive()) {
                cout << "\nYou have defeated " << enemy->getName() << "!" << endl;
                cout << "You have received " << enemy->getExperience() << " XP from winning the battle!" << endl;
                break;  // Exit combat loop
            }
        }
        
        // Enemy's turn (if still alive)
        if (whosTurn == 2 && enemy->isAlive()) {
            cout << "\n--- Enemy Turn ---" << endl;
            EnemyTurn();
            
            // Check if player died from enemy attack
            if (!player->isAlive()) {
                cout << "\nYou have been defeated by " << enemy->getName() << "!" << endl;
                cout << "Game Over!" << endl;
                break;  // Exit combat loop
            }
        }
    }
    
    cout << "\n=== BATTLE ENDED ===" << endl;

    FightMenu();
}

void Fight::Run() {
    cout << "You ran" << endl;
}

void Fight::PlayerTurn() {
    int damage = player->getStrength() - enemy->getStrength();

    if (damage < 1) {
        damage = 1;
    }

    enemy->takeDamage(damage);
    cout << "You dealt " << damage << " damage to " << enemy->getName() << endl;
    cout << enemy->getName() << " has " << enemy->getHP() << " hp left" << endl;

    whosTurn = 2;
}

void Fight::EnemyTurn() {
    int damage = player->getStrength() - enemy->getStrength();

    if (damage < 1) {
        damage = 1;
    }

    player->takeDamage(damage);
    cout << "The " << enemy->getName() << " has dealt " << damage << " to you" << endl;
    cout << "You have " << player->getHP() << " hp left" << endl;

    whosTurn = 1;
}