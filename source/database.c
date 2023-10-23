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

    userCount = count;
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
    userCount = count;
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
    userCount = count;
}

void deleteUser(int id)
{
    int idMatched = 0;
    if (id < 1 || id >= genUserId())
    {
        alert("Invalid user ID!", 1.5);
        return;
    }

    FILE *file = readFile("users.dat");

    User user[userCount];
    fread(user, sizeof(User), userCount, file);

    for (int i = 0; i < userCount; i++)
    {
        if (user[i].id == id)
        {
            idMatched = 1;
            for (int j = i; j < userCount-1; j++)
            {
                user[j] = user[j+1];
            }
            break;
        }
    }

    fclose(file);

    if (!idMatched)
    {
        alert("Invalid user ID!", 1.5);
        return;
    }

    file = writeFile("users.dat");

    fwrite(user, sizeof(User), userCount-1, file);

    fclose(file);

    decrementUserCount();
}

void deleteAllUsers()
{
    FILE *file = writeFile("users.dat");
    fclose(file);

    setUserCount(0);
}

int genUserId()
{
    if (userCount == 0)
    {
        return 1;
    }

    FILE *file = readFile("users.dat");

    User user[userCount];
    fread(user, sizeof(User), userCount, file);

    int lastId = user[userCount-1].id;

    fclose(file);

    return lastId+1;
}

void genRandUsers(int count)
{
    FILE *file = appendFile("users.dat");

    User user;
    int startId = genUserId();
    for (int i = startId; i < count+startId; i++)
    {
        user.id = i;
        strcpy(user.name, "User");
        char id[10];
        sprintf(id, "%d", i);
        strcat(user.name, id);
        strcpy(user.phone, "01234567890");
        strcpy(user.pin, "12345");
        fwrite(&user, sizeof(User), 1, file);
        incrementUserCount();
    }

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

    adminCount = count;
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
    adminCount = count;
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
    adminCount = count;
}

void showUsername(int type)
{
    if (type == 1)
    {
        FILE *file = readFile("users.dat");
        User user[userCount];
        fread(user, sizeof(User), userCount, file);
        for (int i = 0; i < userCount; i++)
        {
            if (user[i].id == curUserId)
            {
                printf("%s", user[i].name);
                return;
            }
        }
        fclose(file);
    }
    else if (type == 2)
    {
        FILE *file = readFile("admins.dat");
        Admin admin[adminCount];
        fread(admin, sizeof(Admin), adminCount, file);
        for (int i = 0; i < adminCount; i++)
        {
            if (admin[i].id == curUserId)
            {
                printf("%s", admin[i].name);
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
        header("USERS");

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
        
        hLine();
        nl;
        
        command("\t<-  ");
        printf("Back");
        nl;
        command("\t 0  ");
        printf("Delete users");
        
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
        else if (command == '0')
        {
            nl;
            nl;
            showCursor();
            printf("\tEnter user ID: ");
            int id;
            textYellow();
            scanf("%d", &id);
            if (id == -1)
            {
                deleteAllUsers();
            }
            else
            {
                deleteUser(id);
            }
        }
        else
        {
            alert("Invalid key!", 1);
        }
    }
}

void changeName(int type, char *name)
{
    if (type == 1)
    {
        FILE *file = readFile("users.dat");
        User user[userCount];
        fread(user, sizeof(User), userCount, file);
        for (int i = 0; i < userCount; i++)
        {
            if (user[i].id == curUserId)
            {
                strcpy(user[i].name, name);
                break;
            }
        }
        fclose(file);

        file = writeFile("users.dat");
        fwrite(user, sizeof(User), userCount, file);
        fclose(file);
    }
    else if (type == 2)
    {
        FILE *file = readFile("admins.dat");
        Admin admin[adminCount];
        fread(admin, sizeof(Admin), adminCount, file);
        for (int i = 0; i < adminCount; i++)
        {
            if (admin[i].id == curUserId)
            {
                strcpy(admin[i].name, name);
                break;
            }
        }
        fclose(file);

        file = writeFile("admins.dat");
        fwrite(admin, sizeof(Admin), adminCount, file);
        fclose(file);
    }
}

void updateEmail(char *email)
{
    FILE *file = readFile("admins.dat");
    Admin admin[adminCount];
    fread(admin, sizeof(Admin), adminCount, file);
    for (int i = 0; i < adminCount; i++)
    {
        if (admin[i].id == curUserId)
        {
            strcpy(admin[i].email, email);
            break;
        }
    }
    fclose(file);

    file = writeFile("admins.dat");
    fwrite(admin, sizeof(Admin), adminCount, file);
    fclose(file);
}

void updatePassword(char *password)
{
    FILE *file = readFile("admins.dat");
    Admin admin[adminCount];
    fread(admin, sizeof(Admin), adminCount, file);
    for (int i = 0; i < adminCount; i++)
    {
        if (admin[i].id == curUserId)
        {
            strcpy(admin[i].password, password);
            break;
        }
    }
    fclose(file);

    file = writeFile("admins.dat");
    fwrite(admin, sizeof(Admin), adminCount, file);
    fclose(file);
}

void updatePhone(char *phone)
{
    FILE *file = readFile("users.dat");
    User user[userCount];
    fread(user, sizeof(User), userCount, file);
    for (int i = 0; i < userCount; i++)
    {
        if (user[i].id == curUserId)
        {
            strcpy(user[i].phone, phone);
            break;
        }
    }
    fclose(file);

    file = writeFile("users.dat");
    fwrite(user, sizeof(User), userCount, file);
    fclose(file);
}

void updatePIN(char *pin)
{
    FILE *file = readFile("users.dat");
    User user[userCount];
    fread(user, sizeof(User), userCount, file);
    for (int i = 0; i < userCount; i++)
    {
        if (user[i].id == curUserId)
        {
            strcpy(user[i].pin, pin);
            break;
        }
    }
    fclose(file);

    file = writeFile("users.dat");
    fwrite(user, sizeof(User), userCount, file);
    fclose(file);
}