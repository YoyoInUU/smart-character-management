#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

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
    void heal(const int amount);

    // public getter
    const string& getName() const;
    int getHealth() const;
};

#endif