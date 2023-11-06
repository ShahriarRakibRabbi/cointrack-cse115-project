#include "../headers/cointrack.h"

void startScreen();

int main()
{
    mkdir("data");
    system("cls");
    hideCursor();

    printf("Press any key to start...\n\n");
    
    textGreen();
    printf("Press [C] to see a cool animation!");

    char command = getch();

    if (command == 'c' || command == 'C')
    {
        system("cls");
        icon(1);
        logo();
        Sleep(3000);
    }
    
    system("cls");
    // ==================================================

    // setUserCount(0);
    // setAdminCount(1);
    seedAdmin();
    userCount = getUserCount();
    activeUserCount = getActiveUserCount();
    adminCount = getAdminCount();
    
    // genRandUsers(5);
    // loggedIn = 1;
    // adminLoggedIn = 1;
    // curUserId = 1;


    FILE *loginFile = readFile("login_status.dat");
    fread(&loggedIn, sizeof(int), 1, loginFile);
    fread(&adminLoggedIn, sizeof(int), 1, loginFile);
    fread(&curUserId, sizeof(int), 1, loginFile);
    fclose(loginFile);

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