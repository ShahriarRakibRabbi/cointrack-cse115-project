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

void setUserCount(int count)
{
    FILE *file = writeFile("userCount.dat");

    fwrite(&count, sizeof(int), 1, file);

    fclose(file);
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

void seedAdmin()
{
    FILE *file = writeFile("admins.dat");

    Admin admin;
    admin.id = 1;
    strcpy(admin.name, "Shafin Rahman");
    strcpy(admin.email, "asdf");
    strcpy(admin.password, "asdf");

    fwrite(&admin, sizeof(Admin), 1, file);

    fclose(file);
}

int getAdminCount()
{
    FILE *file = readFile("adminCount.dat");

    int count;
    fread(&count, sizeof(int), 1, file);

    fclose(file);

    return count;
}

void setAdminCount(int count)
{
    FILE *file = writeFile("adminCount.dat");

    fwrite(&count, sizeof(int), 1, file);

    fclose(file);
}

void incrementAdminCount()
{
    FILE *file = readFile("adminCount.dat");

    int count;
    fread(&count, sizeof(int), 1, file);

    count++;

    fseek(file, 0, SEEK_SET);
    fwrite(&count, sizeof(int), 1, file);

    fclose(file);
}

void decrementAdminCount()
{
    FILE *file = readFile("adminCount.dat");

    int count;
    fread(&count, sizeof(int), 1, file);

    count--;

    fseek(file, 0, SEEK_SET);
    fwrite(&count, sizeof(int), 1, file);

    fclose(file);
}

void showUsername(int type)
{
    if (type == 1)
    {
        FILE *file = readFile("users.dat");
        User readInfo[userCount];
        fread(readInfo, sizeof(User), userCount, file);
        for (int i = 0; i < userCount; i++)
        {
            if (readInfo[i].id == curUserId)
            {
                puts(readInfo[i].name);
                return;
            }
        }
        fclose(file);
    }
    else if (type == 2)
    {
        FILE *file = readFile("admins.dat");
        Admin readInfo[adminCount];
        fread(readInfo, sizeof(Admin), adminCount, file);
        for (int i = 0; i < adminCount; i++)
        {
            if (readInfo[i].id == curUserId)
            {
                puts(readInfo[i].name);
                return;
            }
        }
        fclose(file);
    }
    
}

void listUsers()
{
    while (1)
    {
        system("cls");
        hideCursor();

        logo();
        hLine();
        nl;

        title("USERS");
        nl;

        if (userCount > 0)
        {

            FILE *file = readFile("users.dat");

            textYellow();
            printf("\t\t%s\t%s\t\t\t\t%s", "ID", "NAME", "PHONE");
            textWhite();

            User readInfo[userCount];
            fread(readInfo, sizeof(User), userCount, file);

            for (int i = 0; i < userCount; i++)
            {
                nl;
                hLine_thin();

                stripNewLine(readInfo[i].name);
                stripNewLine(readInfo[i].phone);

                int nameLen = strlen(readInfo[i].name);
                int maxLen = 22;
                int lines = ceil((float) nameLen / maxLen);
                int center = ((int) ceil(lines / 2.0)) * maxLen;
                int extra = maxLen - nameLen;
                
                if (nameLen <= maxLen || center-maxLen == 0)
                {
                    printf("\t\t%d\t", readInfo[i].id);
                }
                else
                {
                    printf("\t\t\t");
                }

                for (int j = 0; j < nameLen; j++)
                {
                    printf("%c", readInfo[i].name[j]);

                    
                    if (j+1 == center)
                    {
                        printf("\t\t%s", readInfo[i].phone);
                    }
                    if ((j+1) % maxLen == 0 && j != nameLen-1)
                    {
                        nl;
                        if (nameLen > maxLen && j+1 == center-maxLen)
                        {
                            printf("\t\t%d\t", readInfo[i].id);
                        }
                        else
                        {
                            printf("\t\t\t");
                        }
                    }
                }
                if (nameLen < maxLen)
                {
                    while (extra--)
                    {
                        printf(" ");
                    }
                    printf("\t\t%s", readInfo[i].phone);
                }
            }
            fclose(file);
        }
        else
        {
            printf("\t\tNo registerd users.\n");
        }
        
        nl;
        hLine();
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
                alert("Invalid key!", 1);
            }
        }
        else
        {
            alert("Invalid key!", 1);
        }
    }
}