#include <iostream>
#include <memory>

#include "modules.h"

using namespace std;

/*
 * These module functions provide optional wrappers to trigger Character behavior externally.
 * Useful for scenarios like automated testing, UI event handling, or enforcing game rules.
 */

// shared pointer version: shared ownership of character data
void attack(shared_ptr<Character> character, const int damage) {
    cout << "[Attack Module]: Attacking " << character->getName() << "..." << endl;
    character->takeDamage(damage);
}
void heal(shared_ptr<Character> character, const int amount) {
    cout << "[Heal Module]: Healing " << character->getName() << "..." << endl;
    character->heal(*character, amount);
}

// unique pointer version: use references to avoid ownership transfer
void attack(unique_ptr<Character>& character, int damage) {
    cout << "[Attack Module]: Attacking " << character->getName() << "..." << endl;
    character->takeDamage(damage);
}

void heal(unique_ptr<Character>& character, int amount) {
    cout << "[Heal Module]: Healing " << character->getName() << "..." << endl;
    character->heal(*character, amount);
}