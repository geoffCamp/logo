/*************************************************************************
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
#include "operate.h"
#include "maintain.h"
#include "action.h"
#include "calc.h"

/* 
Print message to window. 
IN: Coordinates of error output.
OUT: N/A
*/
void msgPrinter(int yMsg, int xMsg, char msg[15]) {
    clearMessage(yMsg,50);
    move(yMsg,xMsg);
    printw("%s",msg);
}

/*
Move directly to specified coordinates. 
IN: Coordinates of destination and active cursor. 
OUT: N/A 
*/
void moveDirect(int destX, int destY, cursor * activeCursor) {
    int nowX;
    int nowY;
    int rise;
    int run;
    int diffCounter;

    nowX = activeCursor->xDraw;
    nowY = activeCursor->yDraw;
 
    //Assign direction of movement.
    if (nowX > destX) {
        run = -1;
    } else {
        run = 1;
    }
    if (nowY > destY) {
        rise = -1;
    } else {
        rise = 1;
    }

    //Move at 45 degrees until the destination row or column is reached.
    while (nowX != destX && nowY != destY) {
        move(nowY+rise,nowX+run);
        getyx(stdscr,nowY,nowX);
        logoPrinter(activeCursor);

    }

    //Move in a straight line until the destination coordinates are reached.
    if (nowX == destX) {
        diffCounter = abs(destY-nowY);
        for (int i = 0; i < diffCounter; i++) {
            if (destY > nowY) {
                move(nowY+1,nowX);
                getyx(stdscr,nowY,nowX);
                logoPrinter(activeCursor);
            } else {
                move(nowY-1,nowX);
                getyx(stdscr,nowY,nowX);
                logoPrinter(activeCursor);
            }
        }
    } else if (nowY == destY) {
        diffCounter = abs(destX-nowX);
        for (int i = 0; i < diffCounter; i++) {
            if (destX > nowX) {
                move(nowY,nowX+1);
                getyx(stdscr,nowY,nowX);
                logoPrinter(activeCursor);
            } else {
                move(nowY,nowX-1);
                getyx(stdscr,nowY,nowX);
                logoPrinter(activeCursor);
            }
        }
    }
    if (activeCursor->turtle == 1) {
        printw("*");
    }
    activeCursor->xDraw = destX;
    activeCursor->yDraw = destY;
}

/*
Set pen colour. 
IN: Selected colour and active cursor. 
OUT: N/A 
*/
void colour(int colour, cursor * activeCursor) {
    activeCursor->drawColour = colour;
}

/*
Change pen, up or down. 
IN: New pen status and active cursor.
OUT: N/A
*/
void pen(int status, cursor * activeCursor) {
    if (status == 1) {
        activeCursor->UDStatus = 1;
    } else {
        activeCursor->UDStatus = 2;
    }
}

/*
Print when pen is down.
IN: Active cursor.
OUT: N/A
*/
void logoPrinter(cursor * activeCursor) {
    if (activeCursor->UDStatus == 1) {
        attron(COLOR_PAIR(activeCursor->drawColour));
        printw("*");
        attroff(COLOR_PAIR(activeCursor->drawColour));
    }
}

/*
Rotate drawing angle.
IN: Active cursor, magnitude of turn and direction of turn.
OUT: N/A
*/
void turn(cursor * activeCursor, int mag, int dir) {
    if (dir == 1) {
        activeCursor->drawAngle = activeCursor->drawAngle - mag;
        if (activeCursor->drawAngle < 0) {
            activeCursor->drawAngle = 360 + activeCursor->drawAngle;
        }
        
    } else if (dir == 2) {
        activeCursor->drawAngle = activeCursor->drawAngle + mag;
        if (activeCursor->drawAngle > 360) {
            activeCursor->drawAngle = activeCursor->drawAngle - 360;
        }
        
    }

}

/*
Move pen forward of backward.
IN: Active cursor, magnitude of movement, dimensions of output space, and direction of movement.
OUT: N/A
*/
void movePen(cursor * activeCursor,int mag,int width, int height, int dir) {
    int rise;
    int run;
    int nextX;
    int nextY;
    int i,j;
    int riser;
    int runner;

    nextX = activeCursor->xDraw;
    nextY = activeCursor->yDraw;
    calcSlope(activeCursor,mag,&rise,&run);
    if (dir == 2) {
        rise = rise*-1;
        run = run*-1;
    }
    move(nextY,nextX);

    logoPrinter(activeCursor);

    riser = sign(rise);
    runner = sign(run);
    
    //Move the amount of rise and run for every magnitude specified and print at each movement.
    for (i = 0; i<mag; i++) {
        for (j = 0; j<abs(rise); j++) {
            nextY = nextY + riser;
            if (nextY >= height || nextY <= 0) {
                nextY = nextY - riser;
                runner = 0;
                riser = 0;
            }
            move(nextY,nextX);
            logoPrinter(activeCursor);
        }
        for (j = 0; j<abs(run); j++) {
            nextX = nextX + runner;
            if (nextX >= width || nextX <= 0) {
                nextX = nextX - runner;
                runner = 0;
                riser = 0;
            }
            move(nextY,nextX);
            logoPrinter(activeCursor);
        }
    }                   
    move(nextY,nextX);
    if (activeCursor->turtle == 1) {
       printw("*");
    }
    move(nextY,nextX);
    getyx(stdscr,activeCursor->yDraw,activeCursor->xDraw);
    
}

