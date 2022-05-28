#include <iostream>
#include <cstring>
#include "user.h"

using namespace std;

bool User::LogIn(char *nameUser, char *_password)
{
    if (!nameUser || !_password)
        return false;

    int result = strcmp(nameUser, userName);
    if (result != 0)
        return false;
    result = strcmp(_password, password);
    if (result != 0)
        return false;
    return true;
}