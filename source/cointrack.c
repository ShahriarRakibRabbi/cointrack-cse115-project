#include "../headers/cointrack.h"

int loggedIn = 0;

void startScreen()
{
    while (1)
    {
        system("cls");
        hideCursor();

        logo();
        hline();
        nl;
        
        printf("\t\t1  Login\n");
        printf("\t\t2  Register\n");
        printf("\t\t3  Admin Login\n");
        printf("\t\t4  Exit\n");
        
        nl;
        hline();
        nl;
        
        textGreen();
        printf("\tPress (1 - 4)");
        textWhite();

        char command = getch();
        switch (command)
        {
        case '1':
            login();
            break;
        case '2':
            regUser();
            break;
        case '3':
            login();
            break;
        case '4':
            quit();
            break;
        default:
            sayInvalid();
            break;
        }
    }
}

void quit()
{
    system("cls");
    logo();
    hline();
    nl;
    printf("\t\tThank you for choosing CoinTrack!\n\n");
    hline();
    nl;
    textRed();
    for (int i = 5; i > 0; i--)
    {
        moveCursor(0, 11);
        printf("\t\tClosing in %d seconds...\n", i);
        Sleep(1000);
    }
    exit(0);
}
