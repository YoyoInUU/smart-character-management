#include <iostream>

#include "character.h"
#include "modules.h"

using namespace std;

void sharedPointerMode() {
    // create a character using `std::shared_ptr`
    auto character = std::make_shared<Character>("Yoyo", 100);

    // character data shared among different modules
    std::shared_ptr<Character> module1 = character;
    std::shared_ptr<Character> module2 = character;

    // module actions
    attack(module1, 30);
    heal(module2, 20);

    // display current health
    cout << "Character " << character->getName() << " has " << character->getHealth() << " health." << endl;

    // after leaving scope, module1 and module2 are destroyed,
    // but the character is still alive due to `character` holding it

    cout << "Game ending..." << endl;
}

void uniquePointerMode() {
    // create a character using `std::unique_ptr`
    auto character = std::make_unique<Character>("Yoyo", 100);

    // character data passed by reference
    attack(character, 30);
    heal(character, 20);

    // display current health
    cout << "Character " << character->getName() << " has " << character->getHealth() << " health." << endl;

    // transfer ownership of the character to newOwner
    auto newOwner = std::move(character);
    if (!character) {
        std::cout << "Character ownership has been transferred to newOwner." << endl;
    }
}

int main() {
    cout << "=== Running Shared Pointer Example ===" << endl;
    sharedPointerMode();

    cout << "--------------------" << endl;

    cout << "=== Running Unique Pointer Example ===" << endl;
    uniquePointerMode();

    return 0;
}