#ifndef DATABASE_H
#define DATABASE_H

// ======== START =========

FILE *readFile(char *filename);
FILE *writeFile(char *filename);
FILE *appendFile(char *filename);

int getUserCount();
int getActiveUserCount();
void deleteUser(int id);
void deleteAllUsers();

int genUserId();
void genRandUsers(int count);

void seedAdmin();
int getAdminCount();

void showUsername(int type);

void listUsers();
void listAdmins();

void updateName(int type, char *name);
void updateEmail(char *email);
void updatePassword(char *password);
void updatePhone(char *phone);
void updatePIN(char *pin);

int duplicatePhone(char *phone);

int getRecordCount();
int genRecordId();

// ========= END =========

#endif // DATABASE_H