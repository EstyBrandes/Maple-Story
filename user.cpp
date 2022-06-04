#include <iostream>
#include <cstring>
#include "user.h"
#include "character.h"

using namespace std;

// Constructors:

User::User(char *_userName, char *_password)
{
    strcpy(userName, _userName);
    strcpy(password, _password);
    numOfCharacters = 0;
    indexCharacter = 0;
    for (int i = 0; i < 5; i++)
    {
        characters[i] = NULL;
    }
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

User::User(char *_userName, char *_password, Character _character[], int sizeOfCharacters)
{
    strcpy(userName, _userName);
    strcpy(password, _password);
    for (int i = 0; i < sizeOfCharacters; i++)
    {
        Character &thisCharacter = _character[i];
        characters[i]->copy_character(thisCharacter);
        numOfCharacters = i + 1;
    }
    indexCharacter = 0;
    return;
}

// Methodes:

bool User::LogIn(char *_userName, char *_password)
{
    if (!_userName || !_password)
        throw invalid_argument("NULL arguments recieved!\n");
    if (strlen(_userName) > 9 || strlen(_userName) < 1 || strlen(_password) > 9 || strlen(_password) < 1)
        throw invalid_argument("Username or Password must be 1-9 characters!\n");
    int result = strcmp(_userName, userName);
    if (result != 0)
        return false;
    result = strcmp(_password, password);
    if (result != 0)
        return false;
    return true;
}

void User::printLevel()
{
    cout << " Your Level Is:" << characters[indexCharacter]->get_character_level() << "\n";
    int toNext = characters[indexCharacter]->get_character_experience_capacity() - characters[indexCharacter]->get_character_experience_points();
    cout << "you have" << toNext << " Left For Next Level\n";
}

void User::switch_characters()
{
    if (numOfCharacters < 2)
    {
        cout << "\t XX    First, make another character!    XX\n";
        cout << "Choose character name:\n";
        char buffer[100];
        cin >> buffer;
        buffer[strlen(buffer)+1] = 0;
        char* characterName;
        try
        {
            characterName = new char[strlen(buffer)+1];
        }
        catch(bad_alloc& e)
        {
            std::cerr << "memory error!" << endl;
        }
        strcpy(characterName, buffer);
        cout << "Choose job:\n" << "1. Warrior\n2. Magician\n3. Rouge\n4. Archer\n5. Pirate\nType a number between 1-5:";
        int choice;
        cin >> choice;
        choice--;
        job characterJob = static_cast<job>(choice);
        try
        {
            addCharacter(characterName, characterJob);
        }
        catch(char* err)
        {
            cerr << err << endl;
        }       
    }
    
    char *charName;
    char *&thisCharacter = charName;
    int theChosen;
    cout << "\t XX Choose Your Character: XX\n";
    printCharacters();

    cin >> theChosen;
    if (theChosen > 5 || theChosen < 1)
    {
        cout << "No Such Character!\n";
        throw (theChosen /* int */);
    }
    theChosen--;
    indexCharacter = theChosen;
    return;
}

void User::printCharacters(){
    if(numOfCharacters == 0){
        cout << "No Characters! add a character!\n";
        return;
    }
    char *charName;
    char *&thisCharacter = charName;
    for (int i = 0; i < numOfCharacters; i++)
    {
        characters[i]->get_character_name(thisCharacter);
        cout << (i+1) << " -" << charName << "\n";
    }
    return;
}

void User::menu(Enemy &enemy)
{
    if(numOfCharacters == 0)
    {
        cout << "\t XX    First, make a character!    XX\n";
        cout << "Choose character name:\n";
        char buffer[100];
        cin >> buffer;
        buffer[strlen(buffer)+1] = 0;
        char* characterName;
        try
        {
            characterName = new char[strlen(buffer)+1];
        }
        catch(bad_alloc& e)
        {
            std::cerr << "memory error!" << endl;
        }
        strcpy(characterName, buffer);
        cout << "Choose job:\n" << "1. Warrior\n2. Magician\n3. Rouge\n4. Archer\n5. Pirate\nType a number between 1-5:";
        int choice;
        cin >> choice;
        choice--;
        job characterJob = static_cast<job>(choice);
        try
        {
            addCharacter(characterName, characterJob);
        }
        catch(char* err)
        {
            cerr << err << endl;
        }       
    }
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
        throw -1 /* int */;
        break;
    default:
        throw invalid_argument("No Such Option! Try Again!\n") /* invalid_argument */;
        break;
    }
    return;
}

// functions:

int User::howManyCharacters(){
    int counter = 0;
    for (int i = 0; i < 5 ; i++)
    {
        if (!(characters[i]))
        {
            counter++;
        }
    }
    return counter;
}

void User::addCharacter(char *_characterName, job _characterJob){
    if(numOfCharacters == 5){
        throw "too many characters!\n";
        return;
    }
    Character* newCharacter;
    try
    {
        newCharacter = new Character(_characterName, _characterJob);
    }
    catch(char* characterError)
    {
        cerr << characterError;
        throw characterError;
    }
    characters[numOfCharacters] = newCharacter;
    numOfCharacters++;
    return;
}

// Destructor:

User::~User()
{
    delete[] userName;
    delete[] password;
    delete[] characters;
}
