
#include "Combat.h"
#include <iostream>
#include <algorithm>
#include <utility>
#include "../Enemy/Enemy.h"
#include "../Player/Player.h"
#include "climits"

using namespace std;

class Enemy;
class Player;

bool compareSpeed(Character *a, Character *b) {
    return a->getSpeed() > b->getSpeed();
}


Combat::Combat(vector<Character *> _participants) {
    participants = std::move(_participants);
    for(auto participant: participants) {
        if(participant->getIsPlayer()) {
            teamMembers.push_back((Player*)participant);
        }
        else {
            enemies.push_back((Enemy*)participant);
        }
    }
}

Combat::Combat(vector<Player*> _teamMembers, vector<Enemy*> _enemies) {
    teamMembers = std::move(_teamMembers);
    enemies = std::move(_enemies);
}

Combat::Combat() {
    participants = vector<Character*>();
}

void Combat::addParticipant(Character *participant) {
    participants.push_back(participant);
    if(participant->getIsPlayer()) {
        teamMembers.push_back((Player*)participant);
    }
    else {

        enemies.push_back((Enemy*)participant);
    }
}

Character* Combat::createEnemy(vector<Player*> _teamMembers) {


}

void Combat::prepareCombat() {
    sort(participants.begin(), participants.end(), compareSpeed);

}

void Combat::doCombat() {
    tipeMonster(teamMembers);
    prepareCombat();

    //Este while es 1 iteracion por ronda
    while(enemies.size() != 0 && teamMembers.size() != 0) {
        checkLevel();

        registerActions();
        executeActions();

    }
    for (Player* usuario: teamMembers) {
        usuario->gainExperience(darBotin());
    }
    //No se imprime el nombre del ganador
    if(enemies.size() == 0) {

        cout<<"You have won the combat"<<endl;

        finishCombat(teamMembers,enemies);
        nuevaRonda();

    }
    else {
        cout<<"The enemies have won the combat - Game Over"<<endl;
        finishCombat(teamMembers,enemies);
    }
}

void Combat::registerActions() {
    vector<Character*>::iterator participant = participants.begin();
    //Una iteracion por turno de cada participante (player y enemigo)
    while(participant != participants.end()) {
        Character* target = nullptr;
        Action currentAction;
        if((*participant)->getIsPlayer()) {
            currentAction = ((Player*)*participant)->takeAction(enemies);
        }
        else {
            currentAction = ((Enemy*)*participant)->takeAction(teamMembers);
        }
        actions.push(currentAction);
        participant++;
    }
}

void Combat::executeActions() {
    //Aqui se ejecutan las acciones
    while(!actions.empty()) {
        Action currentAction = actions.top();
        currentAction.action();
        checkForFlee(currentAction.subscriber);
        checkParticipantStatus(currentAction.subscriber);
        checkParticipantStatus(currentAction.target);
        actions.pop();
    }
}

void Combat::checkParticipantStatus(Character *participant) {
    if (participant->getHealth()<=0) {
        if (participant->getIsPlayer()) {
            teamMembers.erase(remove(teamMembers.begin(), teamMembers.end(), participant), teamMembers.end());
        } else {
            this->setBotin();

            enemies.erase(remove(enemies.begin(), enemies.end(), participant), enemies.end());
        }
        participants.erase(remove(participants.begin(), participants.end(), participant), participants.end());
    }
}


void Combat::checkForFlee(Character *character) {
    bool fleed = character->hasFleed();
    if(fleed) {
        if(character->getIsPlayer()) {
            cout<<"You have fled the combat"<<endl;
            teamMembers.erase(remove(teamMembers.begin(), teamMembers.end(), character), teamMembers.end());
        }
        else {
            cout<<character->getName()<<" has fled the combat"<<endl;
            enemies.erase(remove(enemies.begin(), enemies.end(), character), enemies.end());
        }
        participants.erase(remove(participants.begin(), participants.end(), character), participants.end());
    }
}

string Combat::participantsToString() {
    string result = "";
    for (int i = 0; i < participants.size(); i++) {
        result += participants[i]->toString() + "\n";
    }
    return result;
}

void Combat::setBotin() {
    botin+=50;
}

int Combat::darBotin() {
    return botin;
}

Character* Combat::getBabyPlayer(vector<Player *> teamMembers) {
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

Character *Combat::getBabyEnemy(vector<Enemy *> enemies) {
    int targetIndex = 0;
    int lowestLevel = INT_MAX;
    for(int i=0; i < enemies.size(); i++) {
        if(enemies[i]->getLevel() < lowestLevel) {
            lowestLevel = enemies[i]->getLevel();
            targetIndex = i;
        }
    };
    return enemies[targetIndex];
}


//void Combat::checkLevel() {
  //  Character* baby;
    //Character* gremlin;
    //gremlin= getBabyEnemy(enemies);
    //baby = getBabyPlayer(teamMembers);

//    if (baby->getLevel() > gremlin->getLevel()){
  //      for (Enemy* noMuertos: enemies) {
    //        noMuertos->tipeMonster();
      //  }
    //}
//}

void Combat::nuevaRonda() {
    int respuesta;

    cout<<"Jugar otra ronda: \n1=si     2=no"<<endl;
    cin>>respuesta;
    if (respuesta==1){

        doCombat();
    }
}

Character * Combat :: tipeMonster(vector<Player *> teamMembers){
    Character* baby;
    baby=getBabyPlayer(teamMembers);
    if (baby->getLevel()==1) {
        Enemy *enemy = new Enemy("Goblin", 10, 8, 2, 10, 1);
        Enemy *enemy2 = new Enemy("Goblinrojo", 5, 8, 2, 10, 1);

        participants.push_back(enemy);
        participants.push_back(enemy2);
    }
    else if (baby->getLevel()==2) {
        Enemy *enemy = new Enemy("Goblin", 10, 8, 2, 10, 1);
        Enemy *enemy2 = new Enemy("Goblinrojo", 5, 8, 2, 10, 1);
        Enemy *enemy3 = new Enemy("Goblinazul", 10, 8, 2, 10, 1);

        participants.push_back(enemy);
        participants.push_back(enemy2);
        participants.push_back(enemy3);
    }
    else if (baby->getLevel()==3) {
        Enemy *enemy = new Enemy("Ogro", 25, 15, 10, 2, 1);

        participants.push_back(enemy);
    }
    else if (baby->getLevel()==4) {
        Enemy *enemy = new Enemy("Ogro", 25, 15, 10, 2, 1);
        Enemy *enemy2 = new Enemy("Goblinrojo", 5, 8, 2, 10, 1);

        participants.push_back(enemy);
        participants.push_back(enemy2);
    }
    else{
        Enemy *enemy = new Enemy("Ogro", 25, 15, 10, 2,1);
        Enemy *enemy2 = new Enemy("Ogra", 25, 15, 10, 2,1);

        participants.push_back(enemy);
        participants.push_back(enemy2);
    }
}

void Combat::finishCombat(vector<Player*> _teamMembers, vector<Enemy*> _enemies) {


        if (getBabyPlayer(teamMembers)->getLevel() >= 5 && teamMembers.size()==0) {
            for (int i = 0; i < teamMembers.size(); ++i) {
                delete teamMembers[i];
            }
        }

    for (int i = 0; i < enemies.size() ; ++i) {
            delete enemies[i];
    }

}
