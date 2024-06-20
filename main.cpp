#include <iostream>
#include "Enemy/Enemy.h"
#include "Player/Player.h"
#include "Combat/Combat.h"
#include "vector"

using namespace std;

class Enemy;

int main() {

    int decicion=1;
    char temporal[30];

    cout<<"Ingresa tu nombre de usuario"<<endl;
    cin>>temporal;


    Player *player = new Player(temporal, 15, 8, 4, 10,1);

  vector<Character*> participants;
  participants.push_back(player);

  Combat* combat = new Combat(participants);

           combat->doCombat();

           delete combat;

           return 0;
       }

