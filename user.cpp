#include <iostream>
#include <cstring>
#include "user.h"
#include "character.h"

using namespace std;

bool User::LogIn(char *_userName, char *_password)
{
    if (!_userName || !_password)
        return false;

    int result = strcmp(_userName, userName);
    if (result != 0)
        return false;
    result = strcmp(_password, password);
    if (result != 0)
        return false;
    return true;
}

User::User(char *_userName, char *_password)
{
    strcpy(userName, _userName);
    strcpy(password, _password);
    numOfCharacters = 0;
    indexCharacter = 0;
    return;
}

User::User(char *_userName, char *_password, Character &_character)
{
    strcpy(userName, _userName);
    strcpy(password, _password);
    characters[0]->copy_character(_character);
    numOfCharacters++;
    indexCharacter = 0;
    return;
}
User::User(char *_userName, char *_password, Character _character[])
{
    strcpy(userName, _userName);
    strcpy(password, _password);
    for (int i = 0; i < 5 && _character[i].Character_is_empty() == false; i++)
    {
        Character &thisCharacter = _character[i];
        characters[i]->copy_character(thisCharacter);
        numOfCharacters = i + 1;
    }
    indexCharacter = 0;
    return;
}

void User::printLevel()
{
    cout << " Your Level Is:" << characters[indexCharacter]->get_character_level() << "\n";
    int toNext = characters[indexCharacter]->get_character_experience_capacity() - characters[indexCharacter]->get_character_experience_points();
    cout << "you have" << toNext << " Left For Next Level\n";
}

void User::switch_characters()
{
    char *charName;
    char *&thisCharacter = charName;
    int theChosen;
    cout << "\t XX Choose Your Character: XX\n";
    characters[0]->get_character_name(thisCharacter);
    cout << "1 -" << charName << "\n";
    characters[1]->get_character_name(thisCharacter);
    cout << "2 -" << charName << "\n";
    characters[2]->get_character_name(thisCharacter);
    cout << "3 -" << charName << "\n";
    characters[3]->get_character_name(thisCharacter);
    cout << "4 -" << charName << "\n";
    characters[4]->get_character_name(thisCharacter);
    cout << "5 -" << charName << "\n";

    cin >> theChosen;
    if (theChosen > 5 || theChosen < 1)
    {
        cout << "No Such Character!\n";
        throw;
    }
    theChosen--;
    indexCharacter = theChosen;
    return;
}

void User::menu(Enemy &enemy)
{
    cout << "\t XX    MENU:    XX\n";
    cout << "1. Fight!\n";
    cout << "2. Print Level\n";
    cout << "3. Switch Character\n";
    cout << "4. Exit Game\n";
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
        characters[indexCharacter]->fight(enemy);
        break;
    case 2:
        printLevel();
        break;
    case 3:
        switch_characters();
        break;
    case 4:
        throw;
        break;
    default:
        cout << "No Such Option! Try Again!\n";
        break;
    }
}
User::~User()
{
    delete[] userName;
    delete[] password;
    delete[] characters;
}
