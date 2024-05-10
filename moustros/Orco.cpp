//
// Created by AmbarPC on 08/05/2024.
//

#include "Orco.h"

using namespace std;



Orco:: Orco( int, int, int, int): Enemy( health, attack, defense, speed, false) {
    health=30;
    attack=15;
    defense=20;
    speed=5;

}


char* Orco::getName() {
    char tipe[10]="Orco";
    return tipe;
}