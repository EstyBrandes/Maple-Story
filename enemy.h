#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED

class Enemy
{
    char *enemyName;
    int healthPoints;
    int attackStrength;
    int experienceWorth;

public:
    Enemy(char *EnemyName, int healthPoints = 10, int attackStrength = 10);
    ~Enemy();
    int get_enemy_health_points();
    int get_enemy_attack_points();
    int get_enemy_experience_points();
    void get_enemy_name(char *&name);
    bool down_hp(int damage);
};

Enemy makeEnemy(const char* _name, int health = 10, int attack = 10);

Enemy& nextEnemy(Enemy* enemies, int sizeOfArray);

#endif
