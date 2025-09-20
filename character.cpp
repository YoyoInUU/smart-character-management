#include <iostream>
#include <string>

#include "character.h"

using namespace std;

// constructor
Character::Character(const string& name, const int health)
    : name(name), health(health) {
    cout << "Character " << name << " created with " << health << " health." << endl;
}

// destructor
Character::~Character() {
    cout << "Character " << name << " destroyed." << endl;
}

// public member functions
void Character::takeDamage(const int amount) {
    health -= amount;
    cout << name << " takes " << amount << " damage. Health now: " << health << "." << endl;
}

void Character::heal(const int amount) {
    health += amount;
    cout << name << " heals " << amount << " health. Health now: " << health << "." << endl;
}

// public getters
const string& Character::getName() const {
    return name;
}

int Character::getHealth() const {
    return health;
}