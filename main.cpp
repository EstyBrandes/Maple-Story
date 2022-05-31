#include <iostream>
#include <cstring>
#include "user.h"
#include "Enemy.h"
#include "Character.h"

using namespace std;

// making global characters and enemies and user to check modules:

// Enemies:
Enemy monster1 = Enemy("Goblin", 5, 5);
Enemy monster2 = Enemy("Wolf");
Enemy monster3 = Enemy("Soldier");
Enemy monster4 = Enemy("Ogre", 20);
Enemy monster5 = Enemy("Dragon", 30, 12);
Enemy* monsters = new Enemy[5] {monster1,monster2, monster3, monster4, monster5}; 

// Characters:
Character hero1 = Character("Gojo",Magician);
Character hero2 = Character("Itadori",Warrior);
Character hero3 = Character("Fushiguro",Pirate);
Character hero4 = Character("Kugisaki",Rouge, 40);
Character hero5 = Character("Yuta", Archer, 60, 30);
Character* heroes = new Character[5]{hero1, hero2, hero3, hero4, hero5};

// User:
User globalUser("YuviVerse", "TwitchTTV",heroes);

int main()
{
    
    char logName[10];
    char logPass[10];
    cout << " \tXX Please Enter Your User Name: XX\n";
    cin >> logName;
    cout << " \tXX Please Enter Your Password: XX\n";
    cin >> logPass;
    while (!globalUser.LogIn(logName, logPass))
    {
        cout << "Wrong UserName / Password\n";
        cout << " ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~";
        cout << " \tXX Please Enter Your User Name: XX\n";
        cin >> logName;
        cout << " \tXX Please Enter Your Password: XX\n";
        cin >> logPass;
    }
}

// delete globalUser;
/*
    ~ get enemy into array [Almog: "Done!"]
    ~ get characters into array [Almog: "Done!"]
    ~ Level up: next level is X2 the expirience capacity, Attack power & Health points is X1.5
    ~ manage exeptions in all constractors
    ~ manage exceptions if all functions and methods


*/
