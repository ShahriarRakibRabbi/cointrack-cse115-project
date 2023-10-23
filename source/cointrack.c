#include "../headers/cointrack.h"


void quit(int error, char *filename)
{
    system("cls");
    logo();
    hLine();
    nl;
    title("GOODBYE");
    nl;
    if (error)
    {
        printf("\tError: '%s' doesn't exist.\n", filename);
    }
    else
    {
        printf("\tThank you for choosing CoinTrack!\n");
    }
    nl;
    hLine();
    nl;
    textRed();
    for (int i = 6; i > 0; i--)
    {
        moveCursor(0, 14);
        printf("\tClosing in %d seconds", i);
        for (int j = 2; j < 6-i; j++)
        {
            printf(".");
        }
        nl;
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

        title("WELCOME");
        nl;

        command("\t\t1  ");
        printf("Login\n");
        command("\t\t2  ");
        printf("Admin Login\n");
        command("\t\t3  ");
        printf("Register\n");
        command("\t\t4  ");
        printf("Exit\n");

        nl;
        hLine();
        nl;

        char command = getch();
        switch (command)
        {
        case '1':
            login();
            return;
        case '2':
            adminLogin();
            return;
        case '3':
            regUser();
            return;
        case '4':
            quit(0, "");
            break;
        default:
            alert("Invalid key!", 1);
            break;
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

    title("DASHBOARD");
    nl;

    tab;
    textYellow();
    showUsername(1);
    textWhite();
    nl;

    command("\t\t1  ");
    printf("Expense Tracker\n");
    command("\t\t2  ");
    printf("Pay Bill\n");
    command("\t\t3  ");
    printf("Wallet\n");
    command("\t\t4  ");
    printf("Calculator\n");
    command("\t\t5  ");
    printf("Notepad\n");
    command("\t\t6  ");
    printf("Calendar\n");
    command("\t\t7  ");
    printf("Settings\n");
    command("\t\t8  ");
    printf("Logout\n");

    
    nl;
    hLine();
    nl;
    

    char command = getch();
    switch (command)
    {
    case '1':
        login();
        return;
    case '2':
        regUser();
        return;
    case '3':
        login();
        break;
    case '4':
        quit(0, "");
        break;
    case '8':
        logout();
        return;
    default:
        alert("Invalid key!", 1);
        break;
    }
}

void adminHome()
{
    system("cls");
    hideCursor();

    logo();
    hLine();
    nl;

    title("ADMIN DASHBOARD");
    nl;

    tab;
    textYellow();
    showUsername(2);
    textWhite();

    int x = 63 - log10(userCount ? userCount : 2);
    moveCursor(x, 10);
    textYellow();
    printf("Total Users: %d\n", userCount);
    textWhite();
    nl;

    command("\t\t1  ");
    printf("Users\n");
    command("\t\t2  ");
    printf("Admins\n");
    command("\t\t3  ");
    printf("Add Admin\n");
    command("\t\t4  ");
    printf("Settings\n");
    command("\t\t5  ");
    printf("Logout\n");

    
    nl;
    hLine();
    nl;
    

    char command = getch();
    switch (command)
    {
    case '1':
        listUsers();
        break;
    case '2':
        break;
    case '3':
        break;
    case '4':
        break;
    case '5':
        logout();
        return;
    default:
        alert("Invalid key!", 1);
        break;
    }
}