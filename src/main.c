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
#include "operate.h"

int main(void) {

    int oHeight = 20;
    int oWidth = 50;
    int iHeight = 2;
    int iWidth = 50;
    int originX = oWidth+3;
    int originY = 0;
    
    initscr();
    wresize(stdscr,100,100);
   
    start_color();
    init_color(COLOR_WHITE,0,0,0);
    init_pair(1,COLOR_WHITE,COLOR_WHITE);//background is the third param
    init_pair(2,COLOR_BLUE,COLOR_BLUE);
    init_pair(3,COLOR_GREEN,COLOR_GREEN);
    init_pair(4,COLOR_RED,COLOR_RED);
    init_pair(5,COLOR_YELLOW,COLOR_YELLOW);
    init_pair(6,COLOR_BLACK,COLOR_BLACK);
 
    use_default_colors();
 
    drawOutput(oHeight,oWidth);
    drawInput(oHeight,iHeight,iWidth);
    drawInstruct(originX,originY);
    refresh();

    run(oWidth,oHeight);

    endwin();

    return 0;
}

