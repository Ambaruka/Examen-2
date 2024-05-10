#include <iostream>
#include "Enemy/Enemy.h"
#include "Player/Player.h"
#include "Combat/Combat.h"
#include "vector"

using namespace std;

class Enemy;

int main() {

    char temporal[30];
    cout<<"Ingresa tu nombre de usuario"<<endl;
    cin>>temporal;


    Player *player = new Player(temporal, 4, 7, 2, 10,1);

    vector<Character*> participants;

    Enemy* enemy;
    Enemy* enemy2;


    participants.push_back(player);
    participants.push_back(enemy);
    participants.push_back(enemy2);

    Combat* combat = new Combat(participants);


    combat->doCombat();

    delete player;
    delete enemy;
    delete enemy2;
    delete combat;

    return 0;
}
