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

#include "operate.h"
#include "action.h"
#include "calc.h"

/* 
Calculate slope of movement based on quadrant of angle. 
IN: Active cursor, magnitude of movement, and pointers to rise and run.
OUT: N/A
*/
void calcSlope(cursor * activeCursor,int mag,int * rise,int * run) {

    int angle = activeCursor->drawAngle;

    if (angle == 0 || angle == 360) {
         *rise = -1;
         *run = 0;
    } else if (angle == 90) {
         *rise = 0;
         *run = 1;
    } else if (angle == 180) {
         *rise = 1;
         *run = 0;
    } else if (angle == 270) {
        *rise = 0;
        *run = -1;
    } else if (angle == 45) {
        *rise = -1;
        *run = 1;
    } else if (angle == 135) {
        *rise = 1;
        *run = 1;
    } else if (angle == 225) {
        *rise = 1;
        *run = -1;
    } else if (angle == 315) {
        *rise = -1;
        *run = -1;
    } else if (angle > 0 && angle < 90) {
        highOrLow(angle,rise,run,1);
    } else if (angle > 90 && angle < 180) {
        angle = angle - 90;
        highOrLow(angle,rise,run,2);
    } else if (angle >180 && angle < 270) {
        angle = angle -180;
        highOrLow(angle,rise,run,3);
    } else if (angle > 270 && angle < 360) {
        angle = angle - 270;
        highOrLow(angle,rise,run,4);
    }

}

/*
Determine rise and run. 
IN: Angle, pointers to rise and run, active quadrant.
OUT: N/A
*/
void highOrLow(int angle,int * rise,int * run, int quadrant) {
    double inRads = angle*(3.14159265/180);
    if (angle < 45) {
        if (quadrant == 1) {
            *rise = (trunc(1/tan(inRads)+1))*-1;
            *run = 1;
        } else if (quadrant == 2) {
            *rise = 1;
            *run = (int) (trunc(1/tan(inRads))+1);
        } else if (quadrant == 3) {
            *rise = (int) (trunc(1/tan(inRads))+1);
            *run = -11;
        } else if (quadrant == 4) {
            *rise = -1;
            *run = (int) (trunc(1/tan(inRads))+1)*-1;
        }
    } else {
        if (quadrant == 1) {
            *rise = -1;
            *run = trunc(tan(inRads))+1;
        } else if (quadrant == 2) {
            *rise = trunc(tan(inRads))+1;
            *run = 1;
        } else if (quadrant == 3) {
            *rise = 1;
            *run = (trunc(tan(inRads))+1)*-1;
        } else if (quadrant == 4) {
            *rise = (trunc(tan(inRads))+1)*-1;
            *run = -1;
        }
    }

}

/* 
Return 1 for positive number -1 for negative number.
IN: Rise or run integer.
OUT: 1 or -1.
*/
int sign(int num) {
    return (num > 0)-(num < 0);
}
