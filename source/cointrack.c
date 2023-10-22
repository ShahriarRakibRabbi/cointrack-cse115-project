#include "../headers/cointrack.h"


void quit(int error, char *filename)
{
    system("cls");
    logo();
    hLine();
    nl;
    if (error)
    {
        printf("\t\tError: '%s' doesn't exist.\n", filename);
    }
    else
    {
        printf("\t\tThank you for choosing CoinTrack!\n");
    }
    nl;
    hLine();
    nl;
    textRed();
    for (int i = 5; i > 0; i--)
    {
        moveCursor(0, 12);
        printf("\t\tClosing in %d seconds...\n", i);
        Sleep(1000);
    }
    exit(0);
}

void startScreen()
{
    while (1)
    {
        system("cls");

        logo();
        hLine();
        nl;

        printf("\t\t1  Login\n");
        printf("\t\t2  Register\n");
        printf("\t\t3  Admin Login\n");
        printf("\t\t4  Exit\n");
        printf("\t\t5  Users\n");
        
        nl;
        hLine();
        nl;
        
        textGreen();
        printf("\tPress (1 - 4)");
        textWhite();

        nl;
        nl;
        
        printf("\tUser Count: %d\n", userCount);
        hideCursor();

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
            quit(0, "");
            break;
        case '5':
            listUsers();
            break;
        default:
            alert("Invalid key!", 1);
            break;
        }
        if (loggedIn)
        {
            return;
        }
    }
}

void userHome()
{
    system("cls");
    hideCursor();

    logo();
    hLine();
    nl;

    textYellow();
    printf("\t\tWelcome, ");
    showUsername();
    textWhite();

    printf("\t\t1  Expense Tracker\n");
    printf("\t\t2  Pay Bill\n");
    printf("\t\t3  Wallet\n");
    printf("\t\t4  Calculator\n");
    printf("\t\t5  Notepad\n");
    printf("\t\t6  Calendar\n");
    printf("\t\t7  Settings\n");
    
    nl;
    hLine();
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
        quit(0, "");
        break;
    default:
        alert("Invalid key!", 1);
        break;
    }
}

void adminHome()
{
    // nothing
}