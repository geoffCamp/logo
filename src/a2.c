#include "a2.h"
#include "drawing.h"
#include "operate.h"
#include "maintain.h"
#include "action.h"

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

