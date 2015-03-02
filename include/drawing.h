/****************************************************************************
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

#ifndef _GCAMP_DRAWINGH
#define _GCAMP_DRAWINGH

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ncurses.h>
#include <math.h>

/*
Set up drawing output space.
IN: Height and width of board.
OUT: N/A 
*/
void drawOutput(int height, int width);

/* 
Set up command input space.
IN: Height and width of space and height of output space for reference.
OUT: N/A 
*/
void drawInput(int oHeight, int height, int width);

/* 
Draw instructions board.
IN: Starting x and y coordinates.
OUT: N/A
*/
void drawInstruct(int originX, int originY);

#endif

