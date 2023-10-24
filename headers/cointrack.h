#ifndef COINTRACK_H
#define COINTRACK_H

// ======== START =========


// Defines
#define nl printf("\n")
#define tab printf("\t")


// Standard header files
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <conio.h>
#include <stdio.h>


// Custom header files
#include "decor.h"
#include "authorize.h"
#include "database.h"


// Custom functions
void quit(int error, char *filename);
void startScreen();
void userHome();
void adminHome();
void settings();
void changeName();
void changeEmail();
void changePassword();
void changePhone();
void changePIN();

// Structures
typedef struct
{
    int id;
    char name[50];
    char phone[13];
    char pin[7];
} User;

typedef struct
{
    int id;
    char name[50];
    char email[100];
    char password[100];
} Admin;


// Global variables
int loggedIn;
int adminLoggedIn;
int curUserId;
int userCount;
int adminCount;


// ========= END =========

#endif