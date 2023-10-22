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
        title("LOGIN");
        nl;

        char phone[12], pin[6];
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

        char command = getch();
        
        if (command == 13)
        {
            showCursor();
            textYellow();

            moveCursor(23, 10);
            scanf("%s", &phone);

            moveCursor(23, 11);
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
                alert("\tInvalid credentials!", 2);
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
                alert("Invalid key!", 1);
            }
        }
        else
        {
            alert("Invalid key!", 1);
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

        title("REGISTER");
        nl;

        User regInfo, readInfo[userCount];
        printf("\t\tFull Name: \n");
        printf("\t\tPhone Number: \n");
        printf("\t\t5-digit PIN: \n");
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

            moveCursor(30, 10);
            fflush(stdin);
            fgets(regInfo.name, 50, stdin);

            if (strlen(regInfo.name) < 2)
            {
                hideCursor();
                moveCursor(0, 16);
                alert("Name can't be blank!", 2);
                continue;
            }

            moveCursor(30, 11);
            fflush(stdin);
            fgets(regInfo.phone, 14, stdin);
            
            if (strlen(regInfo.phone) != 12)
            {
                hideCursor();
                moveCursor(0, 16);
                alert("Phone number must have 11 digits!", 2);
                continue;
            }

            moveCursor(30, 12);
            fflush(stdin);
            inputPass(regInfo.pin);
            printf("%d", strlen(regInfo.pin));

            if (strlen(regInfo.pin) != 5)
            {
                hideCursor();
                moveCursor(0, 17);
                alert("PIN must have 5 digits!", 2);
                continue;
            }
            

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
                alert("Invalid key!", 1);
            }
        }
        else
        {
            alert("Invalid key!", 1);
        }
    }
}