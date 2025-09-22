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

void Character::heal(Character& target, const int amount) {
    target.health += amount;
    cout << name << " heals " << target.name << " for " << amount << " health. "
         << target.name << "'s health now: " << target.health << "." << endl;
}

void Character::attack(Character& target, const int damage) {
    cout << name << " attacks " << target.name << " for " << damage << " damage." << endl;
    target.takeDamage(damage);
}

void Character::useSkill(Skill skill, Character& target) {
    auto it = skillMap.find(skill);
    SkillEffect data = it->second;

    cout << name << " uses skill on " << target.name << "." << endl;

    switch (data.type) {
    case SkillType::Attack:
        target.takeDamage(data.amount);
        break;

    case SkillType::Heal:
        target.heal(target, data.amount);
        break;
    }
}

// public getters
const string& Character::getName() const {
    return name;
}

int Character::getHealth() const {
    return health;
}