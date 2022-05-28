#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED

class Enemy
{
    char *enemyName;
    int healthPoints;
    int attackStrength;
    int experienceWorth;

public:
    Enemy(char *EnemyName);
    Enemy(char *EnemyName, int healthPoints);
    Enemy(char *EnemyName, int healthPoints, int attackStrength);
    ~Enemy();
    int get_enemy_health_points();
    int get_enemy_attack_points();
    int get_enemy_experience_points();
    void get_enemy_name(char *&name);
    bool down_hp(int damage);
};

#endif