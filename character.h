#ifndef CHARACTER_H
#define CHARACTER_H

#include <memory>
#include <string>

#include "skill.h"

using namespace std;

class Character {
  private:
    string name;
    int health;
    weak_ptr<Character> target;

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

    // manage target via a `std::weak_ptr` observing a `std::shared_ptr`
    void attackTarget(const int amount);
    void healTarget(const int amount);

    // public getters
    const string& getName() const;
    int getHealth() const;

    // public setters
    void setTarget(weak_ptr<Character> target);
};

#endif