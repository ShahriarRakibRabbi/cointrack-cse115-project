#ifndef DATABASE_H
#define DATABASE_H

// ======== START =========

FILE *readFile(char *filename);
FILE *writeFile(char *filename);
FILE *appendFile(char *filename);

int getUserCount();
void setUserCount(int count);
void incrementUserCount();
void decrementUserCount();
void deleteUser(int id);
void deleteAllUsers();

void seedAdmin();
int getAdminCount();
void setAdminCount(int count);
void incrementAdminCount();
void decrementAdminCount();

void showUsername(int type);

void listUsers();
void listAdmins();

// ========= END =========

#endif // DATABASE_H