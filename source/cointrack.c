#include "../headers/cointrack.h"


void quit(int error, char *filename)
{
    header("EXIT");
    
    if (error)
    {
        FILE *file = writeFile(filename);
        if (file == NULL)
        {
            fclose(file);
            printf("\tError: Unable to create the file'%s'.\n", filename);
        }
        else
        {
            fclose(file);
            return;
        }
    }
    else
    {
        printf("\tAre you sure you want to close the app?\n");
    }
    
    hLine();
    nl;

    command("\t   <-  ");
    printf("Back");
    nl;
    command("\tENTER  ");
    printf("Exit");
    
    char command = getch();

    if (command == 13)
    {
        moveCursor(0, 10);
        printf("\tThank you for choosing CoinTrack!                    \n");
        moveCursor(0, 15);
        alert("", 0);
        textRed();
        for (int i = 5; i > 0; i--)
        {
            moveCursor(0, 14);
            printf("\tClosing in %d seconds", i);
            for (int j = 2; j < 5-i; j++)
            {
                printf(".");
            }
            nl;
            Sleep(1000);
        }
        exit(0);
    }
    else if (command == -32)
    {
        command = getch();
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

void startScreen()
{
    while (1)
    {
        header("WELCOME");

        command("\t\t1  ");
        printf("Login\n");
        command("\t\t2  ");
        printf("Admin Login\n");
        command("\t\t3  ");
        printf("Register\n");
        command("\t\t4  ");
        printf("Exit\n");

        hLine();
        nl;

        char command = getch();
        switch (command)
        {
        case '1':
            login();
            return;
        case '2':
            adminLogin();
            return;
        case '3':
            regUser();
            return;
        case '4':
            quit(0, "");
            break;
        default:
            alert("Invalid key!", 1);
            break;
        }
    }
}

void userHome()
{
    header("DASHBOARD");

    command("\t\t1  ");
    printf("Expense Tracker\n");
    command("\t\t2  ");
    printf("Pay Bill\n");
    command("\t\t3  ");
    printf("Wallet\n");
    command("\t\t4  ");
    printf("Calculator\n");
    command("\t\t5  ");
    printf("Notepad\n");
    command("\t\t6  ");
    printf("Calendar\n");
    command("\t\t7  ");
    printf("Settings\n");
    command("\t\t8  ");
    printf("Logout\n");

    hLine();
    nl;

    char command = getch();
    switch (command)
    {
    case '1':
        break;
    case '2':
        break;
    case '3':
        break;
    case '4':
        break;
    case '5':
        break;
    case '6':
        break;
    case '7':
        userSettings();
        break;
    case '8':
        logout();
        break;
    default:
        alert("Invalid key!", 1);
        break;
    }
}

void adminHome()
{
    header("ADMIN DASHBOARD");

    command("\t\t1  ");
    printf("Users\n");
    command("\t\t2  ");
    printf("Admins\n");
    command("\t\t3  ");
    printf("Add Admin\n");
    command("\t\t4  ");
    printf("Settings\n");
    command("\t\t5  ");
    printf("Logout\n");

    hLine();
    nl;

    char command = getch();
    switch (command)
    {
    case '1':
        listUsers();
        break;
    case '2':
        break;
    case '3':
        break;
    case '4':
        adminSettings();
        break;
    case '5':
        logout();
        return;
    default:
        alert("Invalid key!", 1);
        break;
    }
}

void userSettings()
{
    while (1)
    {
        header("SETTINGS");

        command("\t\t1  ");
        printf("Change Name\n");
        command("\t\t2  ");
        printf("Update phone number\n");
        command("\t\t3  ");
        printf("Update PIN\n");

        hLine();
        nl;
        command("\t<-  ");
        printf("Back");

        char key = getch();

        if (key == -32)
        {
            key = getch();
            if (key == 75)
            {
                return;
            }
            else
            {
                alert("Invalid key!", 1);
            }
        }

        switch (key)
        {
        case '1':
            changeName(1);
            break;
        case '2':
            changePhone();
            break;
        case '3':
            changePIN();
            break;
        default:
            alert("Invalid key!", 1);
            break;
        }
    }
}

void adminSettings()
{
    while (1)
    {
        header("SETTINGS");

        command("\t\t1  ");
        printf("Change Name\n");
        command("\t\t2  ");
        printf("Update email address\n");
        command("\t\t3  ");
        printf("Update password\n");

        hLine();
        nl;
        command("\t<-  ");
        printf("Back");

        char key = getch();

        if (key == -32)
        {
            key = getch();
            if (key == 75)
            {
                return;
            }
            else
            {
                alert("Invalid key!", 1);
            }
        }

        switch (key)
        {
        case '1':
            changeName(2);
            break;
        case '2':
            changeEmail();
            break;
        case '3':
            changePassword();
            break;
        default:
            alert("Invalid key!", 1);
            break;
        }
    }
}

void changeName(int type)
{
    while (1)
    {
        header("CHANGE NAME");
        char name[50];

        printf("\t\tNew name: ");

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
            moveCursor(26, 11);
            fflush(stdin);
            fgets(name, 50, stdin);
            textWhite();
            hideCursor();
            
            if (strlen(name) < 2)
            {
                alert("\tName can't be blank!", 1);
                continue;
            }
            else
            {
                updateName(type, name);
                success("\tName changed successfully!", 1);
                return;
            }
        }
        else if (command == -32)
        {
            char command = getch();
            if (command == 75)
            {
                break;
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

void changeEmail()
{
    while (1)
    {
        header("UPDATE EMAIL ADDRESS");
        char email[100];

        printf("\t\tNew Email: ");

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
            moveCursor(27, 11);
            fflush(stdin);
            fgets(email, 50, stdin);
            textWhite();
            hideCursor();
            
            if (strlen(email) < 2)
            {
                alert("\tEmail address can't be blank!", 1);
                continue;
            }
            else
            {
                updateEmail(email);
                success("\tEmail changed successfully!", 2);
                return;
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
                alert("Invalid key!", 1);
            }
        }
        else
        {
            alert("Invalid key!", 1);
        }
    }
}

void changePassword()
{
    while (1)
    {
        header("CHANGE PASSWORD");
        char password[100];

        printf("\t\tNew Password: ");

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
            moveCursor(30, 11);
            fflush(stdin);
            inputPass(password, 100);
            textWhite();
            hideCursor();
            
            if (strlen(password) < 2)
            {
                alert("\n\t\tPassword can't be blank!", 1);
                continue;
            }
            else
            {
                updatePassword(password);
                success("\n\t\tPassword changed successfully!", 2);
                return;
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
                alert("Invalid key!", 1);
            }
        }
        else
        {
            alert("Invalid key!", 1);
        }
    }
}

void changePhone()
{
    while (1)
    {
        header("CHANGE PHONE NUMBER");
        char phone[13];

        printf("\t\tNew Phone: ");

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
            moveCursor(27, 11);
            fflush(stdin);
            fgets(phone, 13, stdin);
            textWhite();
            hideCursor();
            
            if (strlen(phone) != 12)
            {
                alert("\tPhone number must have 11 digits!", 2);
                continue;
            }
            else
            {
                updatePhone(phone);
                success("\tPhone number changed successfully!", 2);
                return;
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
                alert("Invalid key!", 1);
            }
        }
        else
        {
            alert("Invalid key!", 1);
        }

        updatePhone(phone);
    }
}

void changePIN()
{
    while (1)
    {
        header("CHANGE PIN");
        char pin[7];

        printf("\t\tNew PIN: ");

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
            moveCursor(25, 11);
            fflush(stdin);
            inputPass(pin, 6);
            textWhite();
            hideCursor();
            
            if (strlen(pin) != 5)
            {
                alert("\n\t\tPIN must have 5 digits!", 2);
                continue;
            }
            else
            {
                updatePIN(pin);
                success("\n\t\tPIN changed successfully!", 2);
                return;
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
                alert("Invalid key!", 1);
            }
        }
        else
        {
            alert("Invalid key!", 1);
        }

        updatePIN(pin);
    }
}