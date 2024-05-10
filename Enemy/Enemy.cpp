
#include "Enemy.h"
#include <iostream>
#include <vector>
#include "../Combat/Combat.h"


using namespace std;

class Combat;

//TODO: Check the circular dependency
int getRolledAttack(int attack) {
    int lowerLimit = attack * .80;
    return (rand() % (attack - lowerLimit)) + lowerLimit;
}

Enemy::Enemy( int health, int attack, int defense, int speed) : Character(name, health, attack, defense, speed,level, false) {
}

void Enemy::doAttack(Character *target) {
    int rolledAttack = getRolledAttack(getAttack());
    int trueDamage = target->getDefense() > rolledAttack ? 0 : rolledAttack - target->getDefense();
    target->takeDamage(trueDamage);
}

void Enemy::takeDamage(int damage) {
    setHealth(getHealth() - damage);
    if(getHealth() <= 0) {
        cout<<getName()<<" has died"<<endl;
    }
    else {
        cout<<getName()<<" has taken " << damage << " damage" << endl;
    }
}

Character* Enemy::getTarget(vector<Player *> teamMembers) {
    // Obtiene el miembro del equipo con menos vida
    int targetIndex = 0;
    int lowestHealth = INT_MAX;
    for(int i=0; i < teamMembers.size(); i++) {
        if(teamMembers[i]->getHealth() < lowestHealth) {
            lowestHealth = teamMembers[i]->getHealth();
            targetIndex = i;
        }
    }

    return teamMembers[targetIndex];
}

Action Enemy::takeAction(vector<Player *> player) {
    Action myAction;
    myAction.speed = getSpeed();
    myAction.subscriber = this;
    Character* target = getTarget(player);
    myAction.target = target;
    myAction.action = [this, target]() {
        doAttack(target);
    };

    return myAction;
}


Character* Enemy::getBaby(vector<Player *> teamMembers) {
    int targetIndex = 0;
    int lowestLevel = INT_MAX;
    for(int i=0; i < teamMembers.size(); i++) {
        if(teamMembers[i]->getLevel() < lowestLevel) {
            lowestLevel = teamMembers[i]->getLevel();
            targetIndex = i;
        }
    };
    return teamMembers[targetIndex];
}

int Enemy :: tipeMoster(vector<Player *> teamMembers){
    Character* baby;
    baby=getBaby(teamMembers);
    if (baby->getLevel()<=5){
        int tipe=1;
        return tipe;
    }
    else{
        int tipe=2;
        return tipe;
    }
}

void Enemy::createMonsters(vector<Player *> teamMembers) {
   // int cuantos=teamMembers.size();
    int minumlevel= getBaby(teamMembers)->getLevel();
    Goblin* goblin;

    if (tipeMoster(teamMembers)==1){
        if(minumlevel==1) {
            Enemy *enemy = new Enemy(15, 8, 5, 10);
            Enemy *enemy2 = new Enemy(15, 8, 5, 10);
        }
       else if (minumlevel==2) {
            Enemy *enemy = new Enemy(18, 10, 8, 15);
            Enemy *enemy2 = new Enemy(18, 10, 8, 15);
        }
       else if (minumlevel==3){
            Enemy *enemy= new Enemy(21,12,12,20);
            Enemy *enemy2= new Enemy(21,12,12,20);
        }
        else if(minumlevel==4){
            Enemy *enemy= new Enemy(24,14,15,15);
            Enemy *enemy2= new Enemy(24,14,15,15);
        }
        else{
            Enemy *enemy= new Enemy(30,15,20,5);
            Enemy *enemy2 = new Enemy(15, 8, 5, 10);
        }
    }
    else{
        if (minumlevel==6){
            Enemy *enemy= new Enemy(34,20,23,5);
            Enemy *enemy2 = new Enemy(18, 10, 8, 15);
        }
    }
    return ;
}
