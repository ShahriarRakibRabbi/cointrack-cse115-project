#include "../headers/cointrack.h"


void quit(int error, char *filename)
{
    header("GOODBYE");
    
    if (error)
    {
        printf("\tError: '%s' doesn't exist.\n", filename);
    }
    else
    {
        printf("\tThank you for choosing CoinTrack!\n");
    }
    
    hLine();
    
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
        header("WELCOME");

        command("\t\t1  ");
        printf("Login\n");
        command("\t\t2  ");
        printf("Admin Login\n");
        command("\t\t3  ");
        printf("Register\n");
        command("\t\t4  ");
        printf("Exit\n");

        hLine();

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
    header("DASHBOARD");

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

    hLine();

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
    header("ADMIN DASHBOARD");

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

    hLine();

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
        settings();
        break;
    case '5':
        logout();
        return;
    default:
        alert("Invalid key!", 1);
        break;
    }
}

void settings()
{
    header("SETTINGS");

    command("\t\t1  ");
    printf("Change Name\n");
    command("\t\t2  ");
    printf("Update email addreses\n");
    command("\t\t3  ");
    printf("Update password\n");

    hLine();

    char command = getch();
    switch (command)
    {
    case '1':
        while (1)
        {
            header("CHANGE NAME");
            char name[50];
            printf("\tNew name: ");
            fgets(name, 50, stdin);

            if (strlen(name) < 2)
            {
                alert("Name can't be blank!", 1);
                continue;
            }
            changeName(2, name);
        }
        break;
    case '2':
        break;
    case '3':
        break;
    default:
        alert("Invalid key!", 1);
        break;
    }
}