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

#ifndef _GCAMP_ACTIONH
#define _GCAMP_ACTIONH

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ncurses.h>
#include <math.h>

/* 
Print message to window. 
IN: Coordinates of error output.
OUT: N/A
*/
void msgPrinter(int yError, int xError, char msg[15]);

/*
Move directly to specified coordinates.
IN: Coordinates of destination and active cursor.
OUT: N/A
*/
void moveDirect(int destX, int destY, cursor * activeCursor);

/*
Set pen colour.
IN: Selected colour and active cursor.
OUT: N/A
*/
void colour(int colour, cursor * activeCursor);

/*
Change pen, up or down.
IN: New pen status and active cursor.
OUT: N/A 
*/
void pen(int status, cursor * activeCursor);

/*
Print when pen is down.
IN: Active cursor. 
OUT: N/A
*/
void logoPrinter(cursor * activeCursor);

/* 
Rotate drawing angle.
IN: Active cursor, magnitude of turn and direction of turn.
OUT: N/A
*/
void turn(cursor * activeCursor, int mag, int dir);

/* 
Move pen forward of backward.
IN: Active cursor, magnitude of movement, dimensions of output space, and direction of movement.
OUT: N/A
*/
void movePen(cursor * activeCursor, int mag, int width, int height, int dir);

#endif
