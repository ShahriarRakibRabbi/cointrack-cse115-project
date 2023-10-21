#ifndef DATABASE_H
#define DATABASE_H

// ======== START =========

FILE *readFile(char *filename);
FILE *writeFile(char *filename);
FILE *appendFile(char *filename);
int getUserCount();
void incrementUserCount();
void decrementUserCount();

// ========= END =========

#endif // DATABASE_H