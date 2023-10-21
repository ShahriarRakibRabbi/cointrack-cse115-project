#include "../headers/cointrack.h"

FILE *readFile(char *filename)
{
    FILE *file;
    char address[256] = "database/";
    strcat(address, filename);
    file = fopen(address, "rb+");
    if (file == NULL)
    {
        quit(1, filename);
    }
    return file;
}

FILE *writeFile(char *filename)
{
    FILE *file;
    char address[256] = "database/";
    strcat(address, filename);
    file = fopen(address, "wb+");
    if (file == NULL)
    {
        quit(1, filename);
    }
    return file;
}

FILE *appendFile(char *filename)
{
    FILE *file;
    char address[256] = "database/";
    strcat(address, filename);
    file = fopen(address, "ab+");
    if (file == NULL)
    {
        quit(1, filename);
    }
    return file;
}

int getUserCount()
{
    FILE *file = readFile("userCount.dat");

    int count;
    fread(&count, sizeof(int), 1, file);

    fclose(file);

    return count;
}

int setUserCount(int count)
{
    FILE *file = writeFile("userCount.dat");

    fwrite(&count, sizeof(int), 1, file);

    fclose(file);

    return count;
}

void incrementUserCount()
{
    FILE *file = readFile("userCount.dat");

    int count;
    fread(&count, sizeof(int), 1, file);

    count++;

    fseek(file, 0, SEEK_SET);
    fwrite(&count, sizeof(int), 1, file);

    fclose(file);
}

void decrementUserCount()
{
    FILE *file = readFile("userCount.dat");

    int count;
    fread(&count, sizeof(int), 1, file);

    count--;

    fseek(file, 0, SEEK_SET);
    fwrite(&count, sizeof(int), 1, file);

    fclose(file);
}

void listUsers()
{
    while (1)
    {
        system("cls");
        hideCursor();

        logo();
        hline();
        nl;

        if (userCount > 0)
        {

            FILE *file = readFile("users.dat");

            printf("\t\t%s\t\t\t%s\t\t\t%s\n", "NAME", "PHONE", "PIN");

            User readInfo[userCount];
            fread(readInfo, sizeof(User), userCount, file);

            for (int i = 0; i < userCount; i++)
            {
                stripNewLine(readInfo[i].name);
                stripNewLine(readInfo[i].phone);
                stripNewLine(readInfo[i].pin);

                printf("\t\t%s\t\t%s\t\t%s", readInfo[i].name, readInfo[i].phone, readInfo[i].pin);
            }
            
            fclose(file);
        }
        else
        {
            printf("\t\tNo registerd users.\n");
        }
        
        nl;
        hline();
        nl;
        
        textGreen();
        printf("\tBack (<-)");
        textWhite();
        
        char command = getch();

        if (command == -32)
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