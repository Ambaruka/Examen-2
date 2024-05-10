#include <iostream>
#include "Enemy/Enemy.h"
#include "Player/Player.h"
#include "Combat/Combat.h"
#include "vector"

using namespace std;

class Enemy;

int main() {

    int decicion;
    char temporal[30], nombre1[30]="Goblin",nombre2[30]="Orco";
    cout<<"Ingresa tu nombre de usuario"<<endl;
    cin>>temporal;


    Player *player = new Player(temporal, 6, 7, 4, 10,1);

    Enemy *enemy = new Enemy(nombre1, 5, 8, 2, 10,1);
    Enemy *enemy2 = new Enemy(nombre2, 5, 8, 2, 10,1);
    vector<Character*> participants;
    participants.push_back(player);
    participants.push_back(enemy);
    participants.push_back(enemy2);

    Combat* combat = new Combat(participants);

    do {
        do {
            combat->doCombat();

            cout<<"Pasar al siguiente combate? \n1=si   2=no"<<endl;
            cin>>decicion;
        } while (decicion>=3 && decicion<=0);

    } while (decicion==2);



    delete player;
    delete enemy;
    delete enemy2;
    delete combat;

    return 0;
}
