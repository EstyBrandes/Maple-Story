#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED
#include "character.h"

class User
{
    char userName[10];
    char password[10];
    Character *characters[5]; // Notice it’s an array of the next Class
    int numOfCharacters;
    int indexCharacter;

public:
    User(char *_userName, char *_password);
    User(char *_userName, char *_password, Character &_character);
    User(char *_userName, char *_password, Character _character[], int sizeOfCharacters);
    bool LogIn(char *_userName, char *_password);
    void printLevel();
    void addCharacter(char *_characterName, job _characterJob);
    int howManyCharacters();
    void printCharacters();
    void switch_characters();
    void menu(Enemy &enemy);
    ~User();
};



#endif
