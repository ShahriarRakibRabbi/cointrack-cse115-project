#ifndef COINTRACK_H
#define COINTRACK_H

// ======== START =========


// Defines
#define nl printf("\n")
#define tab printf("\t")


// Standard header files
#include <sys/stat.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <conio.h>
#include <time.h>
#include <stdio.h>



// Custom header files
#include "decor.h"
#include "authorize.h"
#include "database.h"
#include "expense_tracker.h"


// Custom functions
void quit(int error, char *filename);
void startScreen();
void userHome();
void adminHome();
void userSettings();
void adminSettings();
void changeName(int type);
void changeEmail();
void changePassword();
void changePhone();
void changePIN();
void calendar();
void printCalendar(int month, int year);
void unitConverter();
void calculator();

// Structures

typedef struct
{
    int day;
    int month;
    int year;
} Date;
typedef struct
{
    int id;
    char name[50];
    char phone[13];
    char pin[7];
    int active;
} User;

typedef struct
{
    int id;
    char name[50];
    char email[100];
    char password[100];
    int active;
} Admin;

typedef struct
{
    int id;
    int userId;
    char details[512];
    long long amount;
    Date date;
} Record;

// Global variables
int loggedIn;
int adminLoggedIn;
int curUserId;
int userCount;
int activeUserCount;
int adminCount;

// ========= END =========

#endif