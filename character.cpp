#include <iostream>
#include <cstring>
#include "character.h"

using namespace std;

const int maxHPWarrior = 50;
const int maxATWarrior = 15;
const int maxHPMagician = 20;
const int maxATWMagician = 30;
const int maxHPRogue = 30;
const int maxATRogue = 20;
const int maxHPArcher = 35;
const int maxATArcher = 10;
const int maxHPPirate = 25;
const int maxATPirate = 25;
const int initializeEC = 10;


// Constructors:
/*
Character::Character()
{
    characterName = NULL;
    characterJob = Warrior;
    experience = 0;
    experienceCapacity = 0;
    level = 0;
    healthPoints = 0;
    return;
}

bool Character::()
{
    if (characterName == NULL)
        return true;
    return false;
}
*/
Character::Character(char *_characterName, job _characterJob)
{
    if (!_characterName)
    {
        throw invalid_argument("Invalid Name! Try Again!\n");
    }
    if (_characterJob < 0 || _characterJob > 4)
    {
        throw invalid_argument("Invalid Job! Try Again!\n");
    }
    int length = strlen(_characterName);
    try
    {
        characterName = new char[length + 1];
    } 
    catch (bad_alloc& badAlloc)
    {
        cerr << "No memory: " << badAlloc.what() << endl;
    }    
    strcpy(characterName, _characterName);

    characterJob = _characterJob;
    switch (characterJob)
    {
    case 0: // warrior
        attackStrength = maxATWarrior;
        healthPoints = maxHPWarrior;
        maxHealthPoints = maxHPWarrior;
        break;
    case 1: // Magician
        attackStrength = maxATWMagician;
        healthPoints = maxHPMagician;
        maxHealthPoints = maxHPMagician;

        break;
    case 2: // Rogue
        attackStrength = maxATRogue;
        healthPoints = maxHPRogue;
        maxHealthPoints = maxHPRogue;

        break;
    case 3: // Archer
        attackStrength = maxATArcher;
        healthPoints = maxHPArcher;
        maxHealthPoints = maxHPArcher;

        break;
    case 4: // Pirate
        attackStrength = maxATPirate;
        healthPoints = maxHPPirate;
        maxHealthPoints = maxHPPirate;

        break;
    default:
        cout << "No Valid Job\n";
        return;
        break;
    }

    int experience = 0;
    int experienceCapacity = initializeEC;
    int level = 1;
    cout << "\t XX Character Has Been Created XX\n";
    return;
}

Character::Character(char *_characterName, job _characterJob, int _healthPoints)
{
    if (!_characterName)
    {
        throw invalid_argument("Invalid Name! Try Again!\n");
    }
    if (_characterJob < 0 || _characterJob > 4)
    {
        throw invalid_argument("Invalid Job! Try Again!\n");
    }
    if(_healthPoints <= 0)
    {
        throw invalid_argument("Invalid Health Points! Try Again!\n");
    }
    int length = strlen(_characterName);
    characterName = new char[length + 1];
    strcpy(characterName, _characterName);

    characterJob = _characterJob;
    switch (characterJob)
    {
    case 0: // warrior
        attackStrength = maxATWarrior;

        break;
    case 1: // Magician
        attackStrength = maxATWMagician;

        break;
    case 2: // Rogue
        attackStrength = maxATRogue;

        break;
    case 3: // Archer
        attackStrength = maxATArcher;

        break;
    case 4: // Pirate
        attackStrength = maxATPirate;

        break;
    default:
        cout << "No Valid Job\n";
        return;
        break;
    }

    if (_healthPoints <= 0)
    {
        cout << "Are You Dead? Try Again!\n";
        return;
    }
    healthPoints = _healthPoints;
    maxHealthPoints = _healthPoints;
    int experience = 0;
    int experienceCapacity = initializeEC;
    int level = 1;
    cout << "\t XX Character Has Been Created XX\n";
    return;
}

Character::Character(char *_characterName, job _characterJob, int _healthPoints, int _attackStrength)
{
    if (!_characterName)
    {
        throw invalid_argument("Invalid Name! Try Again!\n");
    }
    if (_characterJob < 0 || _characterJob > 4)
    {
        throw invalid_argument("Invalid Job! Try Again!\n");
    }
    if(_healthPoints <= 0)
    {
        throw invalid_argument("Invalid Health Points! Try Again!\n");
    }
    if(_attackStrength <= 0)
    {
        throw invalid_argument("Invalid Attack Strength! Try Again!\n");
    }
    int length = strlen(_characterName);
    characterName = new char[length + 1];
    strcpy(characterName, _characterName);

    characterJob = _characterJob;
    if (characterJob < 0 || characterJob > 4)
    {
        cout << "Invalid Job! Try Again!\n";
        return;
    }
    if (_attackStrength <= 0)
    {
        cout << "No Strength?! Try Again!\n";
        return;
    }
    attackStrength = _attackStrength;
    if (_healthPoints <= 0)
    {
        cout << "Are You Dead? Try Again!\n";
        return;
    }
    healthPoints = _healthPoints;
    maxHealthPoints = _healthPoints;
    int experience = 0;
    int experienceCapacity = initializeEC;
    int level = 1;
}

// Methodes:

int Character::get_character_health_points()
{
    return healthPoints;
}

int Character::get_character_attack_points()
{
    return attackStrength;
}

int Character::get_character_experience_points()
{
    return experience;
}

void Character::get_character_name(char *&name)
{
    /*
    if(Character_is_empty()){
        try{
            name = (char*)realloc(name, sizeof(char)*13); // "No Character"
        }
        catch(bad_alloc){
            throw "memory error!\n";
        }
        strcpy(name, "No Character");
    }
    */
    name = (char*)realloc(name, sizeof(char)*strlen(characterName));
    try{
            name = (char*)realloc(name, sizeof(char)*strlen(characterName));
        }
        catch(bad_alloc& badAlloc){
            cerr << "memory error: " << badAlloc.what() << endl;;
        }
    strcpy(name, characterName);
    return;
}

int Character::get_character_level()
{
    return level;
}

int Character::get_character_experience_capacity()
{
    return experienceCapacity;
}

// When character level up
void Character::levelUp()
{
    level++;
    experienceCapacity = experienceCapacity * 2;
    healthPoints += (int)(healthPoints/2);
    attackStrength += (int)(attackStrength/2);
    return;
}

void Character::copy_character(Character &fromCharacter)
{
    int length = strlen(fromCharacter.characterName);
    try
    {
        characterName = new char[length + 1];
    }
    catch(bad_alloc& badAlloc)
    {
        cerr << "No memory: " << badAlloc.what() << endl;
    }
    strcpy(characterName, fromCharacter.characterName);
    attackStrength = fromCharacter.attackStrength;
    characterJob = fromCharacter.characterJob;
    experience = fromCharacter.experience;
    experienceCapacity = fromCharacter.experienceCapacity;
    level = fromCharacter.level;
    healthPoints = fromCharacter.healthPoints;
    maxHealthPoints = fromCharacter.maxHealthPoints;
}

// when the experience is up
void Character::up_experience(int _experience)
{
    experience += _experience;
    if (experience >= experienceCapacity)
    {
        this->levelUp();
        experience -= experienceCapacity;
        experienceCapacity = experienceCapacity * 2;
        up_experience(0);
        return;
    }
    return;
}

void Character::down_experience(int _experience){
    if(_experience >= experience){
        experience = 0;
        return;
    }
    experience-=_experience;
    return;
}

bool Character::attack(Enemy &enemy)

{
    if (enemy.down_hp(attackStrength))
    {
        cout << "\tXX Hooray! It's A Victory! XX\n";
        return true;
    }
    return false;
}

bool Character::character_get_hit(Enemy &enemy)
{
    int damage = enemy.get_enemy_attack_points();
    healthPoints -= damage;
    if (healthPoints <= 0)
    {
        cout << "Oh No, You Died. Try Again!\n";
        return true;
    }
    return false;
}

bool Character::fight(Enemy &enemy)
{
    bool fightOn = true;
    while (fightOn)
    {
        if (attack(enemy))
        {
            fightOn = false;
            continue;
        }
        if (character_get_hit(enemy))
        {
            down_experience(enemy.get_enemy_experience_points());
            return false;
        }
    }
    up_experience(enemy.get_enemy_experience_points());
    return true;
}

// Destructor:

Character::~Character()
{
    delete[] characterName;
}

// functions:

Character makeCharacter(const char* _name, job characterJob, int health, int attack){
    try{
        char* newName = new char[strlen(_name)+1];
        strcpy(newName, _name);
        newName[strlen(_name)]=0;
        Character newCharacter = Character(newName, characterJob, health, attack);
        return newCharacter;
    }
    catch(invalid_argument err){
        cerr << err.what() << endl;
    }
    catch(const char* err){
        cerr << err << endl;
    }
}
