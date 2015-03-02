
#include "a2.h"
#include "drawing.h"
#include "operate.h"
#include "maintain.h"
#include "action.h"

void calcSlope(cursor * activeCursor,int mag,int * rise,int * run) {
    
    int angle = activeCursor->drawAngle;
    
    if (angle == 0 || angle == 360){
         *rise = -1;
         *run = 0;
    } else if (angle == 90) {
         *rise = 0;
         *run = 1;
    } else if (angle == 180 ) {
         *rise = 1;
         *run = 0;
    } else if (angle == 270) {
        *rise = 0;
        *run = -1;
    } else if (angle == 45) {
        *rise = -1;
        *run = 1;
    } else if ( angle == 135) {
        *rise = 1;
        *run = 1;
    } else if (angle == 225) {
        *rise = 1;
        *run = -1;
    } else if (angle == 315 ) {
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

void highOrLow(int angle,int * rise,int * run, int quadrant) {
    double inRads = angle*(3.14159265/180);
    if (angle < 45){
        if (quadrant == 1) { 
            *rise = (trunc(1/tan(inRads)+1))*-1;
            *run = 1;  
        } else if (quadrant == 2) {
            *rise = 1;
            *run = (int) (trunc(1/tan(inRads))+1);
        } else if (quadrant == 3) {
            *rise = (int) (trunc(1/tan(inRads))+1);
            *run = -11;
        } else if(quadrant == 4) {
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
        } else if(quadrant == 4) {
            *rise = (trunc(tan(inRads))+1)*-1;
            *run = -1;
        }
    }    
    
}



int sign(int num) {
    return (num > 0)-(num < 0);
}


