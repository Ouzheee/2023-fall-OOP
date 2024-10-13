#include "LivingEntity.h"
#include <iostream>
using namespace std;
 //write constructor

LivingEntity::LivingEntity(string _name, int _health,int _damage)
: name(_name), health(_health), damage(_damage) {}

bool LivingEntity::takeDamage(int damage) {
    health -= damage;
    cout << name << " takes " << damage << " damage!" << endl;

    if (health >0){
        return true;
    }
    else{
        cout << name << " has been defeated!" << endl;
        health =0;
        return false;
    }
}

bool LivingEntity::isAlive() {

    return (health > 0);
}


std::string LivingEntity::getName() const {
    //your turn
    return name;
}
int LivingEntity::getHealth()const{
    //your turn
    return health;
}
void LivingEntity::print()const{
std::cout << "\n=== Monster Stats ===" << std::endl;
    std::cout << "Name: " << name<< std::endl;
    std::cout << "Health: " <<health<< std::endl;
     cout<<"====================="<<endl<<endl;}