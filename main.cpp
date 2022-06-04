#include <iostream>
#include <cstring>
#include "user.h"
#include "Enemy.h"
#include "Character.h"

using namespace std;



int main()
{
    Enemy* monsters;
    Character* heroes;
    User* mainUser;
    // Enemies:
    try{
        Enemy monster1 = Enemy("Goblin", 5, 5);
        Enemy monster2 = Enemy("Wolf");
        Enemy monster3 = Enemy("Soldier");
        Enemy monster4 = Enemy("Ogre", 20);
        Enemy monster5 = Enemy("Dragon", 30, 12);
        monsters = new Enemy[5] {monster1,monster2, monster3, monster4, monster5}; 
    }
    catch(bad_alloc& badAlloc){
        cerr << "No memory: " << badAlloc.what() << endl;
        return 1;
    }

    // Characters:
    try{
        Character hero1 = Character("Gojo",Magician);
        Character hero2 = Character("Itadori",Warrior);
        Character hero3 = Character("Fushiguro",Pirate);
        Character hero4 = Character("Kugisaki",Rouge, 40);
        Character hero5 = Character("Yuta", Archer, 60, 30);
        heroes = new Character[5]{hero1, hero2, hero3, hero4, hero5};
    }
    catch(bad_alloc& badAlloc){
        cerr << "No memory: " << badAlloc.what() << endl;
        return 1;
    }
    // User:
    try{
        User _mainUser("YuviVerse", "TwitchTTV",heroes, 5);
        *mainUser = _mainUser;
    }
    catch(bad_alloc& badAlloc){
        cerr << "No memory: " << badAlloc.what() << endl;
        return 1;
    }

    char logName[10];
    char logPass[10];
    bool loginFlag = false;
    do
    {
        cout << " \tXX Please Enter Your User Name: XX\n";
        cin >> logName;
        cout << " \tXX Please Enter Your Password: XX\n";
        cin >> logPass;
        
        try
        {
            loginFlag = mainUser->LogIn(logName, logPass);
        }
        catch(invalid_argument& e)
        {
            cerr << e.what() << endl;
        }
        if (!loginFlag)
        {
            cout << "Wrong UserName / Password\n";
            cout << " ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~";
        }
        
    }while (!loginFlag);
    Enemy toFight = monsters[0];
    Enemy& EnemyRef = toFight;
    while (1)
    {
        try{
        toFight = nextEnemy(monsters,5);
        }
        catch( char* enemy_error){
            cout << enemy_error << "you won!\n";
            break;
        }
        try
        {
            mainUser->menu(toFight);
        }
        catch(int& numError)
        {
            return numError;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            return 1;
        }
        
        
    }
    
    
    
}

// delete globalUser;
/*
    ~ get enemy into array [Almog: "Done!"]
    ~ get characters into array [Almog: "Done!"]
    ~ make a function (in enemy.h/cpp) that gets an array of enemies and 
        returning a referance(&) to the first enemy that isn't dead. and use it in menu(*here*). [Almog: "Done!"]
    ~ make a method to add a character to user (only name & job). [Almog: "Done!"]
    ~ [FIX] in Character::get_character_name(char *&name) - if empty - return "No Character" [Almog: "Done!"]
    ~ in character.h/cpp - add a function: down_experience(enemy.get_enemy_experience_points()); [Almog: "Done!"]
    ~ [FIX] bool Character::fight(Enemy &enemy) - 
        call down_experience() if character lost in a fight. [Almog: "Done!"]
    ~ Level up: next level is X2 the expirience capacity, Attack power & Health points is X1.5 [Almog: "Done!"]
    ~ manage exeptions in all constractors (try, throw, catch)
    ~ manage exceptions if all functions and methods (try, throw, catch)
*/
