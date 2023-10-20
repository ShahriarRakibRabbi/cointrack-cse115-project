#include "../headers/cointrack.h"

void showUsername()
{
    FILE *file;
    file = fopen("database/users.dat", "rb");

    if (file != NULL)
    {
        user readInfo[maxUsers];
        fread(readInfo, sizeof(user), maxUsers, file);

        for (int i = 0; i < maxUsers; i++)
        {
            if (strcmp(readInfo[i].phone, userPhone) == 0)
            {
                puts(readInfo[i].name);
                return;
            }
        }
    }
    else
    {
        printf("Error opening the file.\n");
    }
    fclose(file);
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
    hline();
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

void adminHome()
{
    // nothing
}