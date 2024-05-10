//
// Created by AmbarPC on 09/05/2024.
//

#include "Goblin.h"

using namespace std;



Goblin::Goblin(int, int, int, int) : Enemy( health, attack, defense, speed, false) {

}


char* Goblin::getName() {
    char tipe[10]="Goblin";
    return tipe;
}