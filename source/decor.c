#include "../headers/cointrack.h"

void icon(int animate)
{    
    char iconString[] ="\n\t\t                $$$$$$$$$$$$$$$$$$                \n\t\t             $$$$$$$$$$$$$$$$$$$$$$$$$            \n\t\t         $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$         \n\t\t       $$$$$$$$$$$$$$$      $$$$$$$$$$$$$$$       \n\t\t     $$$$$$$$$$$$         $$$     $$$$$$$$$$$     \n\t\t    $$$$$$$$$            $$$$$$$$$   $$$$$$$$$    \n\t\t   $$$$$$$$$             $$$$$$$$$$$$  $$$$$$$$   \n\t\t  $$$$$$$$               $$$$$$$$$$$$$  $$$$$$$$  \n\t\t $$$$$$$                      $$$$$$$$$$  $$$$$$$ \n\t\t $$$$$$$             $$$$$$$$$  $$$$$$$$$  $$$$$$$\n\t\t$$$$$$$           $$$$$$$$$$$$$$  $$$$$$$  $$$$$$$\n\t\t$$$$$$$          $$$$$$$$$$$$$$$$ $$$$$$$$  $$$$$$\n\t\t$$$$$$           $$$$$$$   $$$$$$$ $$$$$$$  $$$$$$\n\t\t$$$$$$           $$$$$$     $$$$$$ $$$$$$$  $$$$$$\n\t\t$$$$$$  $$$$$$$  $$$$$$$           $$$$$$$        \n\t\t$$$$$$$ $$$$$$$$ $$$$$$$$$         $$$$$$$        \n\t\t$$$$$$$  $$$$$$$  $$$$$$$$        $$$$$$$         \n\t\t $$$$$$$ $$$$$$$$$  $$$$$       $$$$$$$$$         \n\t\t $$$$$$$  $$$$$$$$$$          $$$$$$$$$$          \n\t\t  $$$$$$$$  $$$$$$$$$$$$$$$$$$$$$$$$$$            \n\t\t   $$$$$$$$   $$$$$$$$$$$$$$$$$$$$$$$             \n\t\t    $$$$$$$$$   $$$$$$$$$$$$$$$$$$                \n\t\t      $$$$$$$$$$     $$$$$$$$                     \n\t\t       $$$$$$$$$$$$$$                             \n\t\t         $$$$$$$$$$$$$$$$$                        \n\t\t             $$$$$$$$$$$$$                        \n\t\t                $$$$$$$$$$                         \n\t\t\n";

    textGreen();

    for (int i = 0; i < strlen(iconString); i++)
    {
        printf("%c", iconString[i]);
        Sleep(animate);
    }

    textWhite();
}

void logo()
{
    textGreen();
    printf("\t\t      ____      _     _____               _    \n\t\t     / ___|___ (_)_ _|_   _| __ __ _  ___| | __\n\t\t    | |   / _ \\| | '_ \\| || '__/ _` |/ __| |/ /\n\t\t    | |__| (_) | | | | | || | | (_| | (__|   < \n\t\t     \\____\\___/|_|_| |_|_||_|  \\__,_|\\___|_|\\_\\\n");
    textWhite();
}

void hLine()
{
    nl;
    tab;
    for (int i = 0; i < 68; i++)
        printf("%c", 220);
    nl;
}

void hLine_thin()
{
    tab;
    for (int i = 0; i < 68; i++)
        printf("%c", 205);
    nl;
}

void title(char *title)
{
    tab;
    int length = strlen(title) + 4;
    int bars = (68 - length) / 2;
    for (int i = 0; i < bars; i++)
    {
        printf("%c", 178);
    }
    printf("  %s  ", title);
    for (int i = 0; i < bars; i++)
    {
        printf("%c", 178);
    }
    if (length & 1)
    {
        printf("%c", 178);
    }
    nl;
}

void header(char *text)
{
    hideCursor();
    system("cls");
    logo();
    hLine();
    nl;
    if (loggedIn)
    {
        tab;
        textYellow();
        showUsername(1);
        textWhite();

        int x = 59 - floor(log10(activeUserCount ? activeUserCount : 1));
        moveCursor(x, 8);
        textYellow();
        printf("Wallet Balance: %d\n", activeUserCount);
        textWhite();
    }
    else if (adminLoggedIn)
    {
        tab;
        textYellow();
        showUsername(2);
        textWhite();

        int x = 62 - floor(log10(activeUserCount ? activeUserCount : 1));
        moveCursor(x, 8);
        textYellow();
        printf("Total Users: %d\n", activeUserCount);
        textWhite();
    }

    title(text);
    nl;

    hideCursor();
}

void hideCursor()
{
    CONSOLE_CURSOR_INFO cursor;
    cursor.bVisible = FALSE;
    cursor.dwSize = sizeof(cursor);
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorInfo(handle, &cursor);
}

void showCursor()
{
    CONSOLE_CURSOR_INFO cursor;
    cursor.bVisible = TRUE;
    cursor.dwSize = sizeof(cursor);
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorInfo(handle, &cursor);
}

void moveCursor (int x, int y)
{
    COORD cursorPos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPos);
}

void textWhite()
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(consoleHandle, 7 | 0);
}

void textGreen()
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(consoleHandle, 2 | 0);
}

void textRed()
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(consoleHandle, 4 | 0);
}

void textBlue()
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(consoleHandle, 3 | 0);
}

void textYellow()
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(consoleHandle, 6 | 0);
}

void alert(char *message, float time)
{
    int wait = time * 1000;
    textRed();
    printf("\t%s                             ", message);
    Sleep(wait);
}

void success(char *message, float time)
{
    int wait = time * 1000;
    textGreen();
    printf("\t%s                             ", message);
    Sleep(wait);
}

void command(char *command)
{
    textGreen();
    printf("%s", command);
    textWhite();
}


void stripNewLine(char *str)
{
    if (str[strlen(str) - 1] == '\n')
    {
        str[strlen(str) - 1] = '\0';
    }
}

// Date strToDate(char *str)
// {
//     Date date;
//     char *token = strtok(str, "-");
//     date.day = atoi(token);
//     token = strtok(NULL, "-");
//     date.month = atoi(token);
//     token = strtok(NULL, "-");
//     date.year = atoi(token);
//     return date;
// }