#include <iostream>
#ifndef _ANT_H_
#define _ANT_H_
#include "organism.h"
using namespace std;

class Ant : public Organism{
    public:
        Ant(int x, int y);
        void move(char** array);
        bool isAlive();
        void Infilled(char[]);

    private:
        bool alive;
};




#endif