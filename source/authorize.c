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
        char phone[12], pin[6];
        printf("\t\t========== Login ==========\n");
        printf("\t\tPhone: \n");
        printf("\t\tPIN: \n");
        nl;
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

        char command = getch();
        
        if (command == 13)
        {
            showCursor();
            textYellow();

            moveCursor(23, 8);
            scanf("%s", &phone);

            moveCursor(23, 9);
            inputPass(pin);

            FILE *file;
            file = fopen("database/users.dat", "rb");

            if (file != NULL)
            {
                User readInfo[maxUsers];
                fread(readInfo, sizeof(User), maxUsers, file);

                for (int i = 0; i < maxUsers; i++)
                {
                    if (strcmp(readInfo[i].phone, phone) == 0 && strcmp(readInfo[i].pin, pin) == 0)
                    {
                        loggedIn = 1;
                        strcpy(userPhone, phone);
                        return;
                    }
                }
                if (!loggedIn)
                {
                    hideCursor();
                    moveCursor(0, 14);
                    textRed();
                    printf("\n\tInvalid credentials!\n");
                    Sleep(2000);
                }
            }
            else
            {
                printf("Error opening the file.\n");
            }
            fclose(file);

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
        User regInfo, readInfo[maxUsers];
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

        FILE *file;
        file = fopen("database/users.dat", "rb");

        if (file != NULL)
        {
            // Initialize the array with null characters
            for (int i = 0; i < maxUsers; i++)
            {
                readInfo[i].name[0] = '\0';
            }

            fread(readInfo, sizeof(User), maxUsers, file);

            for (int i = 0; i < maxUsers; i++)
            {
                if (readInfo[i].name[0] == '\0')
                {
                    break;
                }
                if (readInfo[i].name[strlen(readInfo[i].name) - 1] == '\n')
                {
                    readInfo[i].name[strlen(readInfo[i].name) - 1] = '\0';
                }
                if (readInfo[i].phone[strlen(readInfo[i].phone) - 1] == '\n')
                {
                    readInfo[i].phone[strlen(readInfo[i].phone) - 1] = '\0';
                }
                if (readInfo[i].pin[strlen(readInfo[i].pin) - 1] == '\n')
                {
                    readInfo[i].pin[strlen(readInfo[i].pin) - 1] = '\0';
                }

                printf("Name: %s\n", readInfo[i].name);
                printf("Phone: %s\n", readInfo[i].phone);
                printf("PIN: %s\n", readInfo[i].pin);
            }
            
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
            file = fopen("database/users.dat", "ab");

            if (file != NULL)
            {
                fwrite(&regInfo, sizeof(User), 1, file);
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