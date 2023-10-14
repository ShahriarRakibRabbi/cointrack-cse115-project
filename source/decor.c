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
    printf("\t      ____      _     _____               _    \n\t     / ___|___ (_)_ _|_   _| __ __ _  ___| | __\n\t    | |   / _ \\| | '_ \\| || '__/ _` |/ __| |/ /\n\t    | |__| (_) | | | | | || | | (_| | (__|   < \n\t     \\____\\___/|_|_| |_|_||_|  \\__,_|\\___|_|\\_\\\n");
    textWhite();
}

void hline()
{
    printf("\t");
    for (int i = 0; i < 52; i++)
        printf("%c", 220);
    printf("\n");
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
