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
        hLine();
        nl;
        char phone[12], pin[6];
        printf("\t\t========== Login ==========\n");
        printf("\t\tPhone: \n");
        printf("\t\tPIN: \n");
        nl;
        hLine();
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

            moveCursor(23, 9);
            scanf("%s", &phone);

            moveCursor(23, 10);
            inputPass(pin);
            
            hideCursor();

            FILE *file = readFile("users.dat");

            User readInfo[userCount];
            fread(readInfo, sizeof(User), userCount, file);

            for (int i = 0; i < userCount; i++)
            {
                if (strcmp(readInfo[i].phone, phone) == 0 && strcmp(readInfo[i].pin, pin) == 0)
                {
                    loggedIn = 1;
                    curUserId = readInfo[i].id;
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
            
            fclose(file);

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
        hLine();
        nl;
        User regInfo, readInfo[userCount];
        printf("\t\t========== Register ==========\n");
        printf("\t\tName: \n");
        printf("\t\tPhone (11-digit): \n");
        printf("\t\tPIN (5-digit): \n");
        nl;
        // scanf("%s", &username);
        hLine();
        nl;
        textGreen();
        printf("\tBack (<-)");
        printf("\tType (Enter)");
        
        textWhite();
        nl;
        nl;
        
        char command = getch();
        
        if (command == 13)
        {
            showCursor();
            textYellow();

            regInfo.id = userCount + 1;

            moveCursor(36, 9);
            fflush(stdin);
            fgets(regInfo.name, 50, stdin);

            moveCursor(36, 10);
            fflush(stdin);
            fgets(regInfo.phone, 12, stdin);

            moveCursor(36, 11);
            fflush(stdin);
            inputPass(regInfo.pin);

            hideCursor();

            FILE *file = appendFile("users.dat");

            fwrite(&regInfo, sizeof(User), 1, file);

            userCount++;
            incrementUserCount();

            fclose(file);

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