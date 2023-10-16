#include "../headers/cointrack.h"

void login()
{
    while (1)
    {
        system("cls");
        logo();
        hline();
        nl;
        printf("\t\tLogged in!\n\n");
        hline();
        nl;
        textGreen();
        printf("\tBack (<-)");

        char command = getch();
        
        if (command == '0')
        {
            return;
        }
        else if (command == -32)
        {
            char command = getch();
            if (command == 75)
            {
                return;
            }
            else
            {
                sayInvalid();
            }
        }
        else
        {
            sayInvalid();
        }
    }
}