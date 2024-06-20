
#ifndef RPG_PLAYER_H
#define RPG_PLAYER_H

#include "../Character/Character.h"
#include "../Enemy/Enemy.h"
#include "../Combat/Action.h"

struct Action;
class Enemy;

class Player: public Character {
protected:
    int experience;
public:

    Player(const char* _name, int _health, int _attack, int _defense, int _speed, int _level);

    void doAttack(Character *target) override;
    void takeDamage(int damage) override;

    //char* serialize();
    //static const unsigned int BUFFER_SIZE = sizeof (name) + sizeof(health) + sizeof(attack) + sizeof(defense) + sizeof(speed) + sizeof(isPlayer) + sizeof(level) + sizeof(experience);

    //static Player* unserialize(char* buffer);

    Character* getTarget(vector<Enemy*> enemies);

    void flee(vector<Enemy*> enemies);
    void emote();
    void levelUp();
    int gainExperience(int exp);

    //Podemos hacer que este vector sea polimorfico?
    Action takeAction(vector<Enemy*> enemies);
    Character *getBaby(vector<Player *> teamMembers);


private:
    //char buffer[BUFFER_SIZE];

};


#endif //RPG_PLAYER_H
