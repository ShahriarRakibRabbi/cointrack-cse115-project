#ifndef DATABASE_H
#define DATABASE_H

// ======== START =========

FILE *readFile(char *filename);
FILE *writeFile(char *filename);
FILE *appendFile(char *filename);
int getUserCount();
int setUserCount(int count);
void incrementUserCount();
void decrementUserCount();
void showUsername();
void listUsers();

// ========= END =========

#endif // DATABASE_H