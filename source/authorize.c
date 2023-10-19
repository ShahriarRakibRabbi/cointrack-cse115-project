#include "../headers/cointrack.h"

void inputPass(char *pass)
{
    int i = 0;
    char c;
    while(1) {
        c = getch();

        if(c == '\r') { // '\r' is the Enter key
            pass[i] = '\0';
            break;
        } else if(c == '\b') { // '\b' is the Backspace key
            if(i > 0) {
                i--;
                printf("\b \b"); // Erase the last '*'
            }
        } else {
            pass[i++] = c;
            printf("*");
        }
    }
    pass[i] = '\0';
}

void login()
{
    while (1)
    {
        system("cls");
        logo();
        hline();
        nl;
        char phone[256], pin[256];
        printf("\t\t========== Login ==========\n");
        printf("\t\tPhone: \n");
        printf("\t\tPIN: \n");
        nl;
        // scanf("%s", &username);
        hline();
        nl;
        textGreen();
        printf("\tBack (<-)");
        printf("\tType (Enter)");
        
        textWhite();
        nl;
        nl;
        printf("\tThe follwing was entered:\n");
        printf("\tPhone: %s\n", phone);
        printf("\tPIN: %s\n", pin);

        char command = getch();
        
        if (command == 13)
        {
            showCursor();
            textYellow();
            moveCursor(23, 8);
            scanf("%s", &phone);
            moveCursor(23, 9);
            inputPass(pin);
            hideCursor();
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


void regUser()
{
    while (1)
    {
        system("cls");
        logo();
        hline();
        nl;
        user regInfo;
        printf("\t\t========== Register ==========\n");
        printf("\t\tName: \n");
        printf("\t\tPhone (11-digit): \n");
        printf("\t\tPIN (5-digit): \n");
        nl;
        // scanf("%s", &username);
        hline();
        nl;
        textGreen();
        printf("\tBack (<-)");
        printf("\tType (Enter)");
        
        textWhite();
        nl;
        nl;
        // printf("\tThe follwing was entered:\n");
        // printf("\tPhone: %s\n", phone);
        // printf("\tPIN: %s\n", pin);

        FILE *file;
        file = fopen("database/users.dat", "r");

        if (file != NULL)
        {
            fread(&regInfo, sizeof(user), 1, file);
            
            if(regInfo.name[strlen(regInfo.name) - 1] == '\n')
               regInfo.name[strlen(regInfo.name) - 1] = '\0';
            
            printf ("Name: %s\n", regInfo.name);
            printf ("Phone: %s\n", regInfo.phone);
            printf ("PIN: %s\n", regInfo.pin);
            fclose(file);
        }
        else
        {
            printf("Error opening the file.\n");
        }

        char command = getch();
        
        if (command == 13)
        {
            showCursor();
            textYellow();

            moveCursor(36, 8);
            fflush(stdin);
            fgets(regInfo.name, 50, stdin);

            moveCursor(36, 9);
            fflush(stdin);
            fgets(regInfo.phone, 12, stdin);

            moveCursor(36, 10);
            fflush(stdin);
            inputPass(regInfo.pin);

            hideCursor();

            FILE *file;
            file = fopen("database/users.dat", "wb");

            if (file != NULL)
            {
                fwrite(&regInfo, sizeof(user), 1, file);
                fclose(file);
            }
            else
            {
                printf("Error opening the file.\n");
            }



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