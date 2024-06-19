
#include "Enemy.h"
#include <iostream>
#include <vector>
#include "../Combat/Combat.h"
#include "climits"


using namespace std;

class Combat;

//TODO: Check the circular dependency
int getRolledAttack(int attack) {
    int lowerLimit = attack * .80;
    return (rand() % (attack - lowerLimit)) + lowerLimit;
}

Enemy::Enemy(const char* name, int health, int attack, int defense, int speed,int level) : Character(name, health, attack, defense, speed,level, false) {
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


void Enemy::enemyLevel() {
    level++;
    setHealth(getHealth() + 8);
    setAttack(getAttack() + 6);
    setDefense(getDefense() + 5);
    setSpeed(getSpeed() + 5);
    cout<<"El enemigo a subido a nivel "<<level<<endl;
}



int Enemy :: tipeMoster(vector<Player *> teamMembers){
    Character* baby;
    baby=getBaby(teamMembers);
    switch (baby->getLevel()) {
        case 1:
            Enemy *enemy = new Enemy("Goblin", 10, 8, 2, 10,1);
            Enemy *enemy2 = new Enemy("Goblinrojo", 5, 8, 2, 10,1);
            break;
        case 2:
            Enemy *enemy = new Enemy("Goblin", 10, 8, 2, 10,1);
            Enemy *enemy2 = new Enemy("Goblinrojo", 5, 8, 2, 10,1);
            Enemy *enemy3 = new Enemy("Goblinazul", 10, 8, 2, 10,1);
            break;
        case 3:
            Enemy *enemy = new Enemy("Ogro", 25, 15, 10, 2,1);
            break;
        case 4:
            Enemy *enemy = new Enemy("Ogro", 25, 15, 10, 2,1);
            Enemy *enemy2 = new Enemy("Goblinrojo", 5, 8, 2, 10,1);
            break;
        case 5:
            Enemy *enemy = new Enemy("Ogro", 25, 15, 10, 2,1);
            Enemy *enemy2 = new Enemy("Ogra", 25, 15, 10, 2,1);
    }
}


Character *getBaby(vector<Player *> teamMembers){
    int targetIndex = 0;
    int lowestlevel = INT_MAX;
    for(int i=0; i < teamMembers.size(); i++) {
        if(teamMembers[i]->getLevel() < lowestlevel) {
            lowestlevel = teamMembers[i]->getLevel();
            targetIndex = i;
        }
}}