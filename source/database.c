#include "../headers/cointrack.h"

FILE *readFile(char *filename)
{
    FILE *file;
    char address[256] = "data/";
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
    char address[256] = "data/";
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
    char address[256] = "data/";
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
    int count = 0;
    FILE *file = readFile("users.dat");

    User user;
    while(fread(&user, sizeof(User), 1, file))
    {
        count++;
    }

    fclose(file);

    return count;
}

int getActiveUserCount()
{
    int count = 0;
    FILE *file = readFile("users.dat");

    User user;
    while(fread(&user, sizeof(User), 1, file))
    {
        if (user.active == 1)
        {
            count++;
        }
    }

    fclose(file);

    return count;
}

// void setUserCount(int count)
// {
//     FILE *file = writeFile("user_count.dat");

//     fwrite(&count, sizeof(int), 1, file);

//     fclose(file);

//     userCount = count;
// }

// void incrementUserCount()
// {
//     activeUserCount++;
// }

// void decrementUserCount()
// {
//     activeUserCount--;
// }

void deleteUser(int id)
{
    int idMatched = 0;
    if (id < 1)
    {
        alert("    Invalid user ID!", 1.5);
        return;
    }

    FILE *file = readFile("users.dat");

    User user[userCount];
    fread(user, sizeof(User), userCount, file);

    int i;
    for (i = 0; i < userCount; i++)
    {
        if (user[i].id == id && user[i].active)
        {
            idMatched = 1;
            user[i].active = 0;
            break;
        }
    }

    fclose(file);

    if (!idMatched)
    {
        alert("    Invalid user ID!", 1.5);
        return;
    }

    file = writeFile("users.dat");

    fwrite(user, sizeof(User), userCount, file);
    fclose(file);

    // decrementUserCount();
    activeUserCount--;

    textGreen();
    stripNewLine(user[i].name);
    printf("\t    User '%s' has been deleted!", user[i].name);
    Sleep(1500);
}

// void deleteAllUsers()
// {
//     FILE *file = writeFile("users.dat");
//     fclose(file);

//     setUserCount(0);
//     printf("\t    All users has been deleted!");
//     Sleep(1500);
// }

int genUserId()
{
    return getUserCount()+1;
}

void genRandUsers(int count)
{
    FILE *file = appendFile("users.dat");

    User user;
    int startId = genUserId();
    for (int i = startId; i < count+startId; i++)
    {
        user.id = i;
        user.active = 1;
        strcpy(user.name, "User");
        char id[10];
        sprintf(id, "%d", i);
        strcat(user.name, id);
        char phone[12] = "";
        strcat(phone, id);
        int stars = 11 - strlen(phone);
        while (stars--)
        {
            strcat(phone, "*");
        }
        strcpy(user.phone, phone);
        strcpy(user.pin, "12345");
        fwrite(&user, sizeof(User), 1, file);
        // incrementUserCount();
        userCount++;
        activeUserCount++;
    }

    fclose(file);
}

void seedAdmin()
{
    FILE *file = writeFile("admins.dat");
    

    Admin admin;
    admin.id = 1;
    strcpy(admin.name, "Shafin Rahman");
    strcpy(admin.email, "sfr1@nsu.edu");
    strcpy(admin.password, "asdf");

    fwrite(&admin, sizeof(Admin), 1, file);

    fclose(file);
}

int getAdminCount()
{
    int count = 0;
    FILE *file = readFile("admins.dat");

    Admin admin;
    while(fread(&admin, sizeof(admin), 1, file))
    {
        count++;
    }

    fclose(file);

    return count;
}

// void setAdminCount(int count)
// {
//     FILE *file = writeFile("admin_count.dat");

//     fwrite(&count, sizeof(int), 1, file);

//     fclose(file);

//     adminCount = count;
// }

// void incrementAdminCount()
// {
//     FILE *file = readFile("admin_count.dat");

//     int count;
//     fread(&count, sizeof(int), 1, file);

//     count++;

//     fseek(file, 0, SEEK_SET);
//     fwrite(&count, sizeof(int), 1, file);

//     fclose(file);
//     adminCount = count;
// }

// void decrementAdminCount()
// {
//     FILE *file = readFile("admin_count.dat");

//     int count;
//     fread(&count, sizeof(int), 1, file);

//     count--;

//     fseek(file, 0, SEEK_SET);
//     fwrite(&count, sizeof(int), 1, file);

//     fclose(file);
//     adminCount = count;
// }

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

            User user[userCount];
            fread(user, sizeof(User), userCount, file);

            for (int i = 0; i < userCount; i++)
            {
                if (!user[i].active)
                {
                    continue;
                }
                
                nl;
                hLine_thin();

                stripNewLine(user[i].name);
                stripNewLine(user[i].phone);

                int nameLen = strlen(user[i].name);
                int maxLen = 22;
                int lines = ceil((float) nameLen / maxLen);
                int center = ((int) ceil(lines / 2.0)) * maxLen;
                int extra = maxLen - nameLen;
                
                if (nameLen <= maxLen || center-maxLen == 0)
                {
                    printf("\t\t%d\t", user[i].id);
                }
                else
                {
                    printf("\t\t\t");
                }

                for (int j = 0; j < nameLen; j++)
                {
                    printf("%c", user[i].name[j]);

                    
                    if (j+1 == center)
                    {
                        printf("\t\t%s", user[i].phone);
                    }
                    if ((j+1) % maxLen == 0 && j != nameLen-1)
                    {
                        nl;
                        if (nameLen > maxLen && j+1 == center-maxLen)
                        {
                            printf("\t\t%d\t", user[i].id);
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
                    printf("\t\t%s", user[i].phone);
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
        command("\t -  ");
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
        else if (command == '-')
        {
            nl;
            nl;
            showCursor();
            printf("\t    Enter ID to delete: ");
            int id;
            textYellow();
            scanf("%d", &id);
            deleteUser(id);
        }
        else
        {
            alert("Invalid key!", 1);
        }
    }
}

void updateName(int type, char *name)
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
            stripNewLine(email);
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
            stripNewLine(password);
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
            stripNewLine(phone);
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
            stripNewLine(pin);
            strcpy(user[i].pin, pin);
            break;
        }
    }
    fclose(file);

    file = writeFile("users.dat");
    fwrite(user, sizeof(User), userCount, file);
    fclose(file);
}

int duplicatePhone(char *phone)
{
    FILE *file = readFile("users.dat");

    User user[userCount];
    fread(user, sizeof(User), userCount, file);

    for (int i = 0; i < userCount; i++)
    {
        if (strcmp(user[i].phone, phone) == 0)
        {
            return 1;
        }
    }
    fclose(file);

    return 0;
}

int getRecordCount()
{
    int count = 0;
    FILE *file = readFile("records.dat");

    Record record;
    while(fread(&record, sizeof(Record), 1, file))
    {
        count++;
    }

    fclose(file);

    return count;
}

int genRecordId()
{
    int recordCount = getRecordCount();

    if (recordCount == 0)
    {
        return 1;
    }

    FILE *file = readFile("records.dat");
    
    Record record[recordCount];
    fread(record, sizeof(Record), recordCount, file);
    fclose(file);

    return record[recordCount-1].id + 1;
}