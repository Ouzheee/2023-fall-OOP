#include <iostream>
using namespace std;
#ifndef _ORGANISM_H_
#define _ORGANISM_H_
/* cSpell:disable */
class Organism{
    public:
        Organism(int x, int y);
        virtual void move(char** array);  //要連結到現有矩陣，取得地圖
        int getcorX();
        int getcorY();
        bool isMoved();
        void changeMoved();
    protected:
        int corx;
        int cory;
        bool Hasmoved;

};

class DoodleBug : public Organism{
    public:
        DoodleBug(int x, int y);
        void move(char** array);
        char kill[2];
};

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