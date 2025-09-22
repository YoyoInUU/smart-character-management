#ifndef SKILL_H
#define SKILL_H

#include <unordered_map>

using namespace std;

enum class SkillType {
    Attack,
    Heal
};

struct SkillEffect {
    SkillType type;
    int amount;
};

enum class Skill {
    Fireball,
    Waterball,
    Shield,
    Supplement,
    Unknown
};

inline unordered_map<Skill, SkillEffect> skillMap = {
    {Skill::Fireball, {SkillType::Attack, 30}},
    {Skill::Shield, {SkillType::Heal, 20}},
    {Skill::Waterball, {SkillType::Attack, 25}},
    {Skill::Supplement, {SkillType::Heal, 20}},
    {Skill::Unknown, {SkillType::Attack, 30}},
};

#endif