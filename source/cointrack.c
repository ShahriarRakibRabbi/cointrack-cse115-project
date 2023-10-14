#include "../headers/cointrack.h"

void startScreen()
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
        system("cls");
        logo();
        hline();
        nl;
        printf("\t\tRegistered!\n");
        break;
    case '3':
        system("cls");
        logo();
        hline();
        nl;
        printf("\t\t=== Admin Panel ===\n");
        break;
    case '4':
        quit();
        break;
    }
    Sleep(2000);
}

void quit()
{
    system("cls");
    logo();
    hline();
    nl;
    printf("\t\tThank you for choosing CoinTrack!\n");
    hline();
    textRed();
    nl;
    for (int i = 5; i > 0; i--)
    {
        moveCursor(0, 10);
        printf("\t\tClosing in %d seconds...\n", i);
        Sleep(1000);
    }
    exit(0);
}