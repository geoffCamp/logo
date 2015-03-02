/***************************************************************************
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

/*
Set up drawing output space.
IN: Height and width of board.
OUT: N/A
*/
void drawOutput(int height, int width) {
    int i;
    attron(COLOR_PAIR(6));
    for (i = 0; i<width; i++) {
        mvaddch(0,i,'#');
    }
    for (i = 0; i<width; i++) {
        mvaddch(height,i,'#');
    }
    for (i = 0; i<height+1; i++) {
        mvaddch(i,width,'#');
    }
    for (i = 0; i<height; i++) {
        mvaddch(i,0,'#');
    }
    attroff(COLOR_PAIR(6));

}

/*
Set up command input space.
IN: Height and width of space and height of output space for reference.
OUT: N/A
*/
void drawInput(int oHeight,int iHeight,int width) {
    int i;
    int inOrigin = oHeight+4;

    attron(COLOR_PAIR(6));
    for (i = 0; i<width; i++) {
        mvaddch(inOrigin,i,'#');
    }
    for (i = 0; i<width; i++) {
        mvaddch(inOrigin+iHeight,i,'#');
    }
    attroff(COLOR_PAIR(6));

}

/*
Draw instructions board.
IN: Starting x and y coordinates.
OUT: N/A
*/
void drawInstruct(int originX, int originY) {
    move(originY+1,originX+1);
    printw("Commands:");
    move(originY+2,originX+1);
    printw("fd - move forward (eg. fd 5)");
    move(originY+3,originX+1);
    printw("bk - move backwards (eg. bk 6)");
    move(originY+4,originX+1);
    printw("rt - turn right in degrees (eg. rt 45)");
    move(originY+5,originX+1);
    printw("lt - turn left in degrees (eg. lt 90)");
    move(originY+6,originX+1);
    printw("setpencolour - set colour (eg. setpencolour 3)");
    move(originY+7,originX+1);
    printw("pu - pen up");
    move(originY+8,originX+1);
    printw("pd - pen down");
    move(originY+9,originX+1);
    printw("home - draw line to origin");
    move(originY+10,originX+1);
    printw("setxy - draw line to x,y. 1,1 in top right.");
    move(originY+11,originX+9);
    printw("(eg. setxy 8 9)");
    move(originY+12,originX+1);
    printw("ht - hide turtle");
    move(originY+13,originX+1);
    printw("st - show turtle");
    move(originY+14,originX+1);
    printw("print - print text in top corner. 9 chars max");
    move(originY+15,originX+1);
    printw("clean - clear drawing space");
    move(originY+16,originX+1);
    printw("new - start new drawing");
    move(originY+17,originX+1);
    printw("save - save drawing");
    move(originY+18,originX+1);
    printw("quit - exit interpreter");
    move(originY+20,originX+1);
    printw("Colour Codes:");
    move(originY+21,originX+1);
    printw("1 - white");
    move(originY+22,originX+1);
    printw("2 - blue");
    move(originY+23,originX+1);
    printw("3 - green");
    move(originY+24,originX+1);
    printw("4 - red");
    move(originY+25,originX+1);
    printw("5 - yellow ");
}

