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

int genUserId();
void genRandUsers(int count);

void seedAdmin();
int getAdminCount();
void setAdminCount(int count);
void incrementAdminCount();
void decrementAdminCount();

void showUsername(int type);

void listUsers();
void listAdmins();

void changeName(int type, char *name);
void updateEmail(char *email);
void updatePassword(char *password);
void updatePhone(char *phone);
void updatePIN(char *pin);

// ========= END =========

#endif // DATABASE_H