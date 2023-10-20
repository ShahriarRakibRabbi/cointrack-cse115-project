#ifndef COINTRACK_H
#define COINTRACK_H

// ======== START =========


// Defines
#define nl printf("\n")
#define maxUsers 100

// Standard header files
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <stdio.h>

// Custom header files
#include "printers.h"
#include "decor.h"
#include "authorize.h"

// Custom functions
void startScreen();
void quit();

// Structures
typedef struct User
{
    char name[50];
    char phone[12];
    char pin[6];
} user;


// ========= END =========

#endif