#include "../headers/cointrack.h"

void login()
{
    system("cls");
    logo();
    hline();
    nl;
    printf("\t\tLogged in!\n");
    hline();
    printf("\t\tPress 'H' to go home\n");
    char command = getch();
    
    if (command == 'h' || command == 'H')
    {
        startScreen();
    }
}