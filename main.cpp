#include <iostream>

#include "character.h"
#include "modules.h"
#include "skill.h"

using namespace std;

void sharedPointerMode() {
    // create a character using `std::shared_ptr`
    auto heroYoyo = make_shared<Character>("Yoyo", 100);
    auto heroYee = make_shared<Character>("Yee", 100);
    auto monster = make_shared<Character>("Monster", 100);

    // character data shared among different modules
    shared_ptr<Character> moduleYoyo = heroYoyo;
    shared_ptr<Character> moduleMonster = monster;

    // module actions
    heroYoyo->setTarget(moduleMonster);
    heroYoyo->attackTarget(30);
    monster->setTarget(moduleYoyo);
    monster->attackTarget(30);
    heroYee->setTarget(moduleYoyo);
    heroYee->healTarget(20);

    // display current health
    cout << "Character " << heroYoyo->getName() << " has " << heroYoyo->getHealth() << " health." << endl;
    cout << "Character " << heroYee->getName() << " has " << heroYee->getHealth() << " health." << endl;
    cout << "Character " << monster->getName() << " has " << monster->getHealth() << " health." << endl;

    // after leaving scope, module1 and module2 are destroyed,
    // but the character is still alive due to `character` holding it

    cout << "Game ending..." << endl;
}

void uniquePointerMode() {
    // create a character using `std::unique_ptr`
    auto heroYoyo = make_unique<Character>("Yoyo", 100);
    auto heroYee = make_unique<Character>("Yee", 100);
    auto monster = make_unique<Character>("Monster", 100);

    // character data passed by reference
    heroYoyo->useSkill(Skill::Fireball, *monster);
    monster->useSkill(Skill::Unknown, *heroYoyo);
    heroYee->useSkill(Skill::Supplement, *heroYoyo);

    // display current health
    cout << "Character " << heroYoyo->getName() << " has " << heroYoyo->getHealth() << " health." << endl;
    cout << "Character " << heroYee->getName() << " has " << heroYee->getHealth() << " health." << endl;
    cout << "Character " << monster->getName() << " has " << monster->getHealth() << " health." << endl;

    // transfer ownership of the character to newOwner
    auto newOwnerYoyo = move(heroYoyo);
    auto newOwnerYee = move(heroYee);
    auto newOwnerMonster = move(monster);
    if (!heroYoyo && !heroYee && !monster) {
        cout << "Character ownership has been transferred to newOwner." << endl;
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