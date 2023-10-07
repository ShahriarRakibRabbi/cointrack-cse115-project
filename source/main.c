#include "../headers/cointrack.h"


int main()
{
    
    hideCursor();

    while (1)
    {
        system("cls");

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
            system("cls");
            logo();
            hline();
            nl;
            printf("\t\tLogged in!\n");
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
            exit(0);
            break;
        }
        Sleep(2000);
    }

    return 0;
}
