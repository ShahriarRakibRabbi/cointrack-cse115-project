#include "../headers/cointrack.h"

void startScreen();

int main()
{
    system("cls");
    hideCursor();
    icon();
    logo();
    // Sleep(3000);

    // setUserCount(0);
    userCount = getUserCount();

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

