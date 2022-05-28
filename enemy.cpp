#include <iostream>
#include <cstring>
#include "enemy.h"

using namespace std;

Enemy::Enemy(char *EnemyName)
{
    // check what is happening when the name is invalid
    int length = strlen(enemyName);
    enemyName = new char[length + 1];
    strcpy(enemyName, EnemyName);
    healthPoints = 10;
    attackStrength = 10;
    experienceWorth = 10;
    return;
}

Enemy::Enemy(char *EnemyName, int healthPoints)
{
    int length = strlen(enemyName);
    enemyName = new char[length + 1];
    strcpy(enemyName, EnemyName);
    strcpy(enemyName, EnemyName);
    this->healthPoints = healthPoints;
    attackStrength = 10;
    experienceWorth = 10;
    return;
}

Enemy::Enemy(char *EnemyName, int healthPoints, int attackStrength)
{
    int length = strlen(enemyName);
    enemyName = new char[length + 1];
    strcpy(enemyName, EnemyName);
    strcpy(enemyName, EnemyName);
    this->healthPoints = healthPoints;
    this->attackStrength = attackStrength;
    experienceWorth = 10;
    return;
}
// destroy
Enemy::~Enemy()
{
    delete[] enemyName;
}

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