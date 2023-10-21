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