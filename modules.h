#ifndef MODULES_H
#define MODULES_H

#include <memory>

#include "character.h"

// shared pointer version: shared ownership of character data
void attack(shared_ptr<Character> character, const int damage);
void heal(shared_ptr<Character> character, const int amount);

// unique pointer version: use references to avoid ownership transfer
void attack(unique_ptr<Character>& character, const int damage);
void heal(unique_ptr<Character>& character, const int amount);

#endif