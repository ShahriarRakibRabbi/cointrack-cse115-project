#ifndef COINTRACK_H
#define COINTRACK_H

// ======== START =========


// Defines
#define nl printf("\n")


// Standard header files
#include <windows.h>
#include <stdlib.h>
#include <string.h>
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

// Structures
typedef struct
{
    int id;
    char name[50];
    char phone[12];
    char pin[6];
} User;


// Global variables
int loggedIn;
int adminLoggedIn;
char userPhone[12];
int userCount;


// ========= END =========

#endif