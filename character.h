
#ifndef CHARACTER_H_INCLUDED
#define CHARACTER_H_INCLUDED
#include "enemy.h"

enum job
{
    Warrior,
    Magician,
    Rouge,
    Archer,
    Pirate
};

class Character
{
    char *characterName;
    enum job characterJob;
    int experience;         // The amount of experience the player have right now
    int experienceCapacity; // How much experience needed for next level
    int level;              // Character level
    int healthPoints;       // Character health
    int attackStrength;
    int maxHealthPoints;

public:
    //Character();
    Character(char *_characterName, job _characterJob);
    Character(char *_characterName, job _characterJob, int _healthPoints);
    Character(char *_characterName, job _characterJob, int _healthPoints, int _attackStrength);
    bool attack(Enemy &enemy);
    ~Character();
    void copy_character(Character &fromCharacter);
    // bool Character_is_empty();
    int get_character_health_points();
    int get_character_attack_points();
    int get_character_experience_points();
    void get_character_name(char *&name);
    int get_character_level();
    int get_character_experience_capacity();
    void levelUp();
    void up_experience(int _experience);
    void down_experience(int _experience);
    bool character_get_hit(Enemy &enemy);
    bool fight(Enemy &enemy);
};

#endif
