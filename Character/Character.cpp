
#include "Character.h"
#include <string.h>

Character::Character(const char* _name, int _health, int _attack, int _defense, int _speed,int _level, bool _isPlayer) {
    strncpy(this->name,_name,20 );
    health = _health;
    attack = _attack;
    defense = _defense;
    speed = _speed;
    level= _level;
    isPlayer = _isPlayer;
    fleed = false;
}

void Character::setName(char const* _name) {
    strncpy(this->name,_name,20 );
}

char* Character::getName() {
    return name;
}

void Character::setHealth(int _health) {
    health = _health;
}

int Character::getHealth() {
    return health;
}

void Character::setAttack(int _attack) {
    attack = _attack;
}

int Character::getAttack() {
    return attack;
}

void Character::setDefense(int _defense) {
    defense = _defense;
}

int Character::getDefense() {
    return defense;
}

void Character::setSpeed(int _speed) {
    speed = _speed;
}

int Character::getSpeed() {
    return speed;
}

string Character::toString() {
    return "Name: " + string (name) + "\nHealth: " + to_string(health) + "\nAttack: " + to_string(attack) + "\nDefense: " + to_string(defense) + "\nSpeed: " + to_string(speed);
}

bool Character::getIsPlayer() {
    return isPlayer;
}

bool Character::hasFleed() {
    return fleed;
}

void Character::setLevel(int _level) {
    level= _level;
}

int Character::getLevel() {
    return level;
}