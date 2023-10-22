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
void seedAdmin();
int getAdminCount();
void setAdminCount(int count);
void incrementAdminCount();
void decrementAdminCount();
void showUsername(int type);
void listUsers();

// ========= END =========

#endif // DATABASE_H