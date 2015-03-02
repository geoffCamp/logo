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

#include "drawing.h"
#include "maintain.h"

/*
Clear input line. 
IN: Output height and width. 
OUT: N/A 
*/
void clearInput(int height, int width) {
    move(height+5,0);
    clrtoeol();
    move(height+5,width+4);
    printw("5 - yellow");
}

/* 
Clear message line. 
IN: Output height and width. 
OUT: N/A
*/
void clearMessage(int height, int width) {
    move(height,0);
    clrtoeol();
    move(height,width+4);
    printw("2 - blue");
}

/* 
Clear board to prepare for new drawing. 
IN: Output height and width.
OUT: N/A
*/
void clearBoard(int height, int width) {
    for (int i = 0; i<height; i++) {
        move(i,0);
        clrtoeol();
    }
    drawOutput(height,width);
    drawInstruct(width+3,0);
}

