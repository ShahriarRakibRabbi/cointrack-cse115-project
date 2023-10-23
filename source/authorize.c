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

        printf("\t\tYour Name: \n");
        printf("\t\tPhone Number: \n");
        printf("\t\t5-digit PIN: \n");
        nl;
        // scanf("%s", &username);
        hLine();
        nl;

        command("\t   <-  ");
        printf("Back");
        nl;
        command("\tENTER  ");
        printf("Type");


        char command = getch();
        
        if (command == 13)
        {
            showCursor();
            textYellow();

            User user;
            
            user.id = genUserId();

            moveCursor(30, 10);
            fflush(stdin);
            fgets(user.name, 50, stdin);

            moveCursor(30, 11);
            fflush(stdin);
            fgets(user.phone, 14, stdin);
            
            moveCursor(30, 12);
            fflush(stdin);
            inputPass(user.pin);

            hideCursor();
            
            if (strlen(user.name) < 2)
            {
                alert("\n\t\tName can't be blank!", 2);
                continue;
            }

            if (strlen(user.phone) != 12)
            {
                alert("\n\t\tPhone number must have 11 digits!", 2);
                continue;
            }

            if (strlen(user.pin) != 5)
            {
                alert("\n\t\tPIN must have 5 digits!", 2);
                continue;
            }

            FILE *file = appendFile("users.dat");

            fwrite(&user, sizeof(User), 1, file);

            userCount++;
            incrementUserCount();
            loggedIn = 1;
            curUserId = user.id;
            fclose(file);
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
                alert("Invalid key!", 1);
            }
        }
        else
        {
            alert("Invalid key!", 1);
        }
    }
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

        command("\t   <-  ");
        printf("Back");
        nl;
        command("\tENTER  ");
        printf("Type");


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
                alert("\n\t\tInvalid credentials!", 2);
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

void adminLogin()
{
    while (1)
    {
        system("cls");
        logo();
        hLine();
        nl;
        title("ADMIN LOGIN");
        nl;

        char email[100], password[100];
        printf("\t\tEmail: \n");
        printf("\t\tPassword: \n");
        nl;
        hLine();
        nl;

        command("\t   <-  ");
        printf("Back");
        nl;
        command("\tENTER  ");
        printf("Type");


        char command = getch();
        
        if (command == 13)
        {
            showCursor();
            textYellow();

            moveCursor(26, 10);
            scanf("%s", &email);

            moveCursor(26, 11);
            inputPass(password);
            
            hideCursor();

            FILE *file = readFile("admins.dat");

            Admin readInfo[adminCount];
            fread(readInfo, sizeof(Admin), adminCount, file);

            for (int i = 0; i < adminCount; i++)
            {
                if (strcmp(readInfo[i].email, email) == 0 && strcmp(readInfo[i].password, password) == 0)
                {
                    adminLoggedIn = 1;
                    curUserId = readInfo[i].id;
                    return;
                }
            }
            if (!adminLoggedIn)
            {
                hideCursor();
                alert("\n\t\tInvalid credentials!", 2);
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


void logout()
{
    while (1)
    {
        system("cls");
        logo();
        hLine();
        nl;
        title("LOGOUT");
        nl;
        
        textYellow();
        printf("\tAre you sure you want to logout?\n");
        textWhite();

        nl;
        hLine();
        nl;

        command("\tENTER  ");
        printf("Yes");
        nl;
        command("\t   <-  ");
        printf("No");

        char command = getch();

        switch (command)
        {
        case 13:
            loggedIn = 0;
            adminLoggedIn = 0;
            curUserId = 0;
            system("cls");
            logo();
            hLine();
            nl;
            title("GOODBYE");
            nl;
            textYellow();
            printf("\tLogged out!", 0);
            textWhite();
            nl;
            nl;
            hLine();
            Sleep(1500);
            return;
        case -32:
            command = getch();
            if (command == 75)
            {
                return;
            }
            else
            {
                alert("Invalid key!", 1);
            }
            return;
        default:
            alert("Invalid key!", 1);
            break;
        }

        nl;
        nl;
    }

}