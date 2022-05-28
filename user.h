#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED
#include "character.h"

class User
{
    char userName[10];
    char password[10];
    Character characters[5]; // Notice it’s an array of the next Class

public:
    User(char *userName, char *password);
    User(char *userName, char *password, Character &character);
    User(char *userName, char *password, Character character[]);
    bool LogIn(char *userName, char *_password);
    ~User();
};

#endif