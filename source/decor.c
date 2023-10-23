#include "../headers/cointrack.h"

void icon()
{
    textGreen();
    printf("\n\t                $$$$$$$$$$$$$$$$$$                \n\t             $$$$$$$$$$$$$$$$$$$$$$$$$            \n\t         $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$         \n\t       $$$$$$$$$$$$$$$      $$$$$$$$$$$$$$$       \n\t     $$$$$$$$$$$$         $$$     $$$$$$$$$$$     \n\t    $$$$$$$$$            $$$$$$$$$   $$$$$$$$$    \n\t   $$$$$$$$$             $$$$$$$$$$$$  $$$$$$$$   \n\t  $$$$$$$$               $$$$$$$$$$$$$  $$$$$$$$  \n\t $$$$$$$                      $$$$$$$$$$  $$$$$$$ \n\t $$$$$$$             $$$$$$$$$  $$$$$$$$$  $$$$$$$\n\t$$$$$$$           $$$$$$$$$$$$$$  $$$$$$$  $$$$$$$\n\t$$$$$$$          $$$$$$$$$$$$$$$$ $$$$$$$$  $$$$$$\n\t$$$$$$           $$$$$$$   $$$$$$$ $$$$$$$  $$$$$$\n\t$$$$$$           $$$$$$     $$$$$$ $$$$$$$  $$$$$$\n\t$$$$$$  $$$$$$$  $$$$$$$           $$$$$$$        \n\t$$$$$$$ $$$$$$$$ $$$$$$$$$         $$$$$$$        \n\t$$$$$$$  $$$$$$$  $$$$$$$$        $$$$$$$         \n\t $$$$$$$ $$$$$$$$$  $$$$$       $$$$$$$$$         \n\t $$$$$$$  $$$$$$$$$$          $$$$$$$$$$          \n\t  $$$$$$$$  $$$$$$$$$$$$$$$$$$$$$$$$$$            \n\t   $$$$$$$$   $$$$$$$$$$$$$$$$$$$$$$$             \n\t    $$$$$$$$$   $$$$$$$$$$$$$$$$$$                \n\t      $$$$$$$$$$     $$$$$$$$                     \n\t       $$$$$$$$$$$$$$                             \n\t         $$$$$$$$$$$$$$$$$                        \n\t             $$$$$$$$$$$$$                        \n\t                $$$$$$$$$$                         \n\t\n");
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
    system("cls");
    hideCursor();
    logo();
    hLine();
    nl;
    if (loggedIn)
    {
        tab;
        textYellow();
        showUsername(1);
        textWhite();

        int x = 62 - floor(log10(userCount ? userCount : 1));
        moveCursor(x, 8);
        textYellow();
        printf("Wallet Balance: %d\n", userCount);
        textWhite();
    }
    else if (adminLoggedIn)
    {
        tab;
        textYellow();
        showUsername(2);
        textWhite();

        int x = 62 - floor(log10(userCount ? userCount : 1));
        moveCursor(x, 8);
        textYellow();
        printf("Total Users: %d\n", userCount);
        textWhite();
    }

    title(text);
    nl;
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
    printf("\t%s                                ", message);
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
