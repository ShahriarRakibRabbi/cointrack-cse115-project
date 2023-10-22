#include "../headers/cointrack.h"

void startScreen();

int main()
{
    system("cls");
    hideCursor();
    icon();
    logo();
    // Sleep(3000);

    // setUserCount(4);
    // setAdminCount(1);
    // seedAdmin();
    userCount = getUserCount();
    adminCount = getAdminCount();
    // loggedIn = 1;
    // adminLoggedIn = 1;
    // curUserId = 1;

    while(1)
    {
        if (adminLoggedIn)
        {
            adminHome();
        }
        else if (loggedIn)
        {
            userHome();
        }
        else
        {
            startScreen();
        }
    }

    return 0;
}