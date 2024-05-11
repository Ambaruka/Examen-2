#include <iostream>
#include "Enemy/Enemy.h"
#include "Player/Player.h"
#include "Combat/Combat.h"
#include "vector"
#include <cstring>

using namespace std;

class Enemy;

int main() {

    int decicion;
    string nombre1="Goblin",nombre2="Orco",usuario;
    char temporal[30],name1[30] ,name2[30];

    strcpy(name1,nombre1.c_str());
    strcpy(name2,nombre2.c_str());

    cout<<"Ingresa tu nombre de usuario"<<endl;
    cin>>usuario;

    strcpy(temporal,usuario.c_str());

    Player *player = new Player(temporal, 6, 7, 4, 10,1);

    Enemy *enemy = new Enemy(name1, 5, 8, 2, 10,1);
    Enemy *enemy2 = new Enemy(name2, 5, 8, 2, 10,1);

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
