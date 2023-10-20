#include "../headers/cointrack.h"

void startScreen();

int main()
{
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

