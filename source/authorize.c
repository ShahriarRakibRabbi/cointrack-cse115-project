#include "../headers/cointrack.h"

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
        printf("\tType (0)");
        
        textWhite();
        nl;
        nl;
        printf("\tThe follwing was entered:\n");
        printf("\tPhone: %s\n", phone);
        printf("\tPIN: %s\n", pin);

        char command = getch();
        
        if (command == '0')
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