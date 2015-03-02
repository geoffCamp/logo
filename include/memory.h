/**************************************************************************
Student Name:Geofferson Camp    Student Number:0658817 
Date: February 13th, 2015         Course Name: cis2500

I have exclusive control over this submission via my password.
By including this statement in this header comment, I certify that:
     1) I have read and understood the University policy on academic integrity;
     2) I have completed the Computing with Integrity Tutorial on Moodle; and
     3) I have achieved at least 80% in the Computing with Integrity Self Test.
I assert that this work is my own. I have appropriately acknowledged any and all material
(data, images, ideas or words) that I have used, whether directly quoted or paraphrased.
Furthermore, I certify that this assignment was prepared by me specifically for this course.

Sources:
- nCurses functions referenced from www.linux.die.net/man
- nCurses colour features referenced from www.tldp.org/HOWTO/NCURSES-Programming-HOWTO/color.html
- drawBoard approach taken from Dr. McCuaig's nCursesExample files.
- Logo Interpreter referenced from www.calormen.com/jslogo

****************************************************************************/

#ifndef _GCAMP_MEMORYH
#define _GCAMP_MEMORYH

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ncurses.h>
#include <math.h>

/*
Free Commands.
IN: Array of command pointers and malloc incrementer.
OUT: N/A
*/
void freeCommands(char ** commandHolder, int * counter);

/*
Save commands to text file.
IN: Array of command pointers and malloc incrementer.
OUT: N/A
*/
void saveCommands(char ** commandHolder, int counter);

/*
Add command to commands array.
IN: Array of command pointer, command, and malloc incrementer.
OUT: N/A
*/
void holdCommand(char ** commandHolder, char command[15], int * counter);

/*
Reallocate more memory for commands array.
IN: Array of command pointer, malloc incrementer.
OUT: N/A
*/
void moreCommands(char *** commandHolder, int counter);

#endif
