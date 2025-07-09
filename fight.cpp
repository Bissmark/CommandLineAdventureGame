#include "fight.h"

Fight::Fight() {

}

void Fight::FightMenu() {
    string fightDecision;
    bool validInput = false;

    do {
        cout << "Please choose an action" << endl;
        cout << "Fight" << endl;
        cout << "Run" << endl;
        cin >> fightDecision;
    
        transform(fightDecision.begin(), fightDecision.end(),fightDecision.begin(), ::tolower);
    
        if (fightDecision == "fight") {
            cout << "You attacked the ___" << endl;
            validInput = true;
        } else if (fightDecision == "run") {
            cout << "Your ran" << endl;
            validInput = true;
        } else {
            cout << "Please Select Fight or Run" << endl;
        }
    } while (!validInput);
}