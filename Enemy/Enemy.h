//
// Created by Victor Navarro on 13/02/24.
//

#ifndef RPG_ENEMY_H
#define RPG_ENEMY_H
#include "../Character/Character.h"
#include "../Player/Player.h"
#include "../Combat/Action.h"
#include <vector>
#include "../moustros/Goblin.h"
#include "../moustros/Orco.h"

struct Action;
class Player;
class Goblin;
class Orco;

class Enemy: public Character {
protected:
    int tipe;
public:
    Enemy( int, int, int, int, int);
    void doAttack(Character *target) override;
    void takeDamage(int damage) override;
    Character* getTarget(vector<Player*> teamMembers);
    Action takeAction(vector<Player*> player);
    int tipeMoster(vector<Player *> teamMembers);
    Character* getBaby(vector<Player *> teamMembers);
    void createMonsters(vector<Player *> teamMembers);

};


#endif //RPG_ENEMY_H
