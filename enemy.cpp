#include <iostream>
#include <cstring>
#include "enemy.h"

using namespace std;

// Constructors:

Enemy::Enemy(char *EnemyName, int healthPoints, int attackStrength)
{
    if (!EnemyName)
    {
        throw invalid_argument("Null argument!\n");
    }
    if(healthPoints <= 0)
    {
        throw invalid_argument("Invalid Health Points! Try Again!\n");
    }
    if(attackStrength <= 0)
    {
        throw invalid_argument("Invalid Attack Strength! Try Again!\n");
    }
    int length = strlen(enemyName);
    enemyName = new char[length + 1];
    if(!enemyName) throw "Memory error!\n";
    strcpy(enemyName, EnemyName);
    this->healthPoints = healthPoints;
    this->attackStrength = attackStrength;
    experienceWorth = 10;
    return;
}

// Methodes:

// The way to get the health points of the enemy
int Enemy::get_enemy_health_points()
{
    return healthPoints;
}

// The way to get the attack points of the enemy
int Enemy::get_enemy_attack_points()
{
    return attackStrength;
}

// The way to get the experience points of the enemy
int Enemy::get_enemy_experience_points()
{
    return experienceWorth;
}

// The way to get the name of the enemy
void Enemy::get_enemy_name(char *&name)
{
    strcpy(name, enemyName);
    return;
}

// when the enemy gets hit
bool Enemy::down_hp(int damage)
{
    healthPoints -= damage;
    if (healthPoints <= 0)
    {
        cout << "Congrats! The Enemy Is Dead!\n";
        return true;
    }
    return false;
}

// Destructor:

Enemy::~Enemy()
{
    delete[] enemyName;
}

// functions:

Enemy& nextEnemy(Enemy* enemies, int sizeOfArray){
    for (int i = 0; i < sizeOfArray; i++)
    {
        if(enemies[i].get_enemy_health_points() > 0) 
        {
            Enemy& monsterToFight = enemies[i];
            return monsterToFight;
        }
    }
    throw "No more monsters left!\n"; 
}

Enemy makeEnemy(const char* _name, int health, int attack){
    try{
        char* newName = new char[strlen(_name)+1];
        if(!newName) throw "Memory error!\n";
        strcpy(newName, _name);
        newName[strlen(_name)]=0;
        Enemy newEnemy = Enemy(newName, health, attack);
        return newEnemy;
    }
    catch(invalid_argument err){
        cerr << err.what() << endl;
    }
    catch(const char* err){
        cerr << err << endl;
    }

}
