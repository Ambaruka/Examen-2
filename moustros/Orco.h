//
// Created by AmbarPC on 08/05/2024.
//
#ifndef EXAMEN_ORCO_H
#define EXAMEN_ORCO_H

#include "../Character/Character.h"
#include "../Enemy/Enemy.h"

class Orco : public Enemy{

protected:

public:
    Orco( int, int, int, int);

    char* getName();

};



#endif //EXAMEN_ORCO_H
