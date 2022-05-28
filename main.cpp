#include <iostream>
#include <cstring>
#include "user.h"

using namespace std;

User globalUser("YuviVerse", "TwitchTTV");

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
/*  ~create / destroy user
    ~ get enemy into array
    ~ get characters into array
*/
