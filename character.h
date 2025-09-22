#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

#include "skill.h"

using namespace std;

class Character {
  private:
    string name;
    int health;

  public:
    // constructor
    Character(const string& name, const int health);

    // destructor
    ~Character();

    // public member functions
    void takeDamage(const int amount);
    void heal(Character& target, const int amount);
    void attack(Character& target, const int damage);
    void useSkill(Skill skill, Character& target);

    // public getters
    const string& getName() const;
    int getHealth() const;
};

#endif