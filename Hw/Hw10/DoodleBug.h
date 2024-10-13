#include <iostream>
#ifndef _DOODLEBUG_H_
#define _DOODLEBUG_H_
#include "organism.h"
using namespace std;

class DoodleBug : public Organism{
    public:
        DoodleBug(int x, int y);
        void move(char** array);
        char kill[2];
};

#endif