//
// Created by AmbarPC on 09/05/2024.
//

#ifndef EXAMEN_GOBLIN_H
#define EXAMEN_GOBLIN_H

#include "../Character/Character.h"
#include "../Enemy/Enemy.h"

class Goblin : public Enemy{

protected:

public:
    Goblin( int, int, int, int);

    char* getName();

};


#endif //EXAMEN_GOBLIN_H
