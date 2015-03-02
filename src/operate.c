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
#include "maintain.h"
#include "action.h"
#include "memory.h"

/*
Controls operation of program via input commands loop.
IN: Height and width of output space.
OUT: N/A
*/        
void run(int width, int height) {
    int xInput;
    int yInput;
    int xMsg;
    int yMsg;
    int loopStatus = 1;
    int printCounter = 1;
    char command[15];
    char preservCommand[15];
    char * commandAction;
    char * commandMag;
    int sendMag;
    int setY;
    char * setYStr;
    char ** commandHolder;
    int reallocCounter = 1;

    commandHolder = malloc(1*sizeof(char*));

    cursor activeCursor;
    activeCursor.xDraw = width/2;
    activeCursor.yDraw = height/2;
    activeCursor.drawAngle = 0;
    activeCursor.UDStatus = 1;
    activeCursor.drawColour = 1;
    activeCursor.turtle = 2;

    echo();
    yInput = height+5;
    xInput = 0;
    yMsg = height+2;
    xMsg = 0;

    while (loopStatus == 1) {
        move(yInput,xInput);
        getnstr(command,14);
        if (strcmp(command,"") == 0) {
            strcpy(command,"void");
        }
        move(yInput,xInput);
        clearInput(height,width);

        strcpy(preservCommand, command);

        commandAction = strtok(command, " ");
        
        //If a command requiring a second parameter was entered, get it with strtok. 
        if (strcmp(commandAction,"fd") == 0 || strcmp(commandAction,"bk") == 0 || strcmp(commandAction,"lt") == 0 || strcmp(commandAction,"rt") == 0 || strcmp(commandAction,"setpencolour") == 0 ||strcmp(commandAction,"setxy") == 0) {
            commandMag = strtok(NULL, " ");
            if (commandMag != NULL) {
                sendMag = strtol(commandMag,'\0',10);//or atoi
            } else {
                strcpy(commandAction,"Incorrect Format");
            }
            if (sendMag <= 0) {
                strcpy(commandAction,"Incorrect Magnitude");
            }
        }
        if (strcmp(commandAction, "print") == 0) {
            commandMag = strtok(NULL, " ");
            if (commandMag != NULL) {

            } else {
                strcpy(commandAction,"Incorrect Format");
            }
        }
        if (strcmp(commandAction,"setxy") == 0) {
            setYStr = strtok(NULL, " ");
            if (setYStr != NULL) {
                setY = strtol(setYStr,'\0',10);//or atoi
            } else {
                strcpy(commandAction,"Incorrect Format");
            }
            if (setY <= 0) {
                strcpy(commandAction,"Incorrect Magnitude");
            }
        }

        if (strcmp(commandAction,"fd") == 0) {
            movePen(&activeCursor,sendMag,width,height,1);
            holdCommand(commandHolder,preservCommand,&reallocCounter);
            moreCommands(&commandHolder,reallocCounter);
            msgPrinter(yMsg,xMsg,preservCommand);
        } else if (strcmp(commandAction,"bk") == 0) {
           movePen(&activeCursor,sendMag,width,height,2);
           holdCommand(commandHolder,preservCommand,&reallocCounter);
           moreCommands(&commandHolder,reallocCounter);
           msgPrinter(yMsg,xMsg,preservCommand);
        } else if (strcmp(commandAction,"home") == 0) {
            moveDirect(width/2,height/2,&activeCursor);
            holdCommand(commandHolder,preservCommand,&reallocCounter);
            moreCommands(&commandHolder,reallocCounter);
            msgPrinter(yMsg,xMsg,preservCommand);
        } else if (strcmp(commandAction,"setxy") == 0) {
            if (sendMag <= 0) {
                sendMag = 1;
            }
            if (setY <= 0) {
                setY = 1;
            }
            if (sendMag > width-1) {
                sendMag = width-1;
            }
            if (setY > height-1) {
                setY = height-1;
            }
            moveDirect(sendMag,setY,&activeCursor);
            holdCommand(commandHolder,preservCommand,&reallocCounter);
            moreCommands(&commandHolder,reallocCounter);
            msgPrinter(yMsg,xMsg,preservCommand);
        } else if (strcmp(commandAction,"pu") == 0) {
            pen(2,&activeCursor);
            holdCommand(commandHolder,preservCommand,&reallocCounter);
            moreCommands(&commandHolder,reallocCounter);
            msgPrinter(yMsg,xMsg,preservCommand);
        } else if (strcmp(commandAction,"pd") == 0) {
            pen(1,&activeCursor);
            holdCommand(commandHolder,preservCommand,&reallocCounter);
            moreCommands(&commandHolder,reallocCounter);
            msgPrinter(yMsg,xMsg,preservCommand);
        } else if (strcmp(commandAction,"lt")== 0) {
            turn(&activeCursor,sendMag,1);
            holdCommand(commandHolder,preservCommand,&reallocCounter);
            moreCommands(&commandHolder,reallocCounter);
            msgPrinter(yMsg,xMsg,preservCommand);
        } else if (strcmp(commandAction,"rt") == 0) {
            turn(&activeCursor,sendMag,2);
            holdCommand(commandHolder,preservCommand,&reallocCounter);
            moreCommands(&commandHolder,reallocCounter);
            msgPrinter(yMsg,xMsg,preservCommand);
        } else if (strcmp(commandAction, "ht") == 0) {
            activeCursor.turtle = 2;
            move(activeCursor.yDraw,activeCursor.xDraw);
            attron(COLOR_PAIR(activeCursor.drawColour));
            printw("*");
            attroff(COLOR_PAIR(activeCursor.drawColour));
            holdCommand(commandHolder,preservCommand,&reallocCounter);
            moreCommands(&commandHolder,reallocCounter);
            msgPrinter(yMsg,xMsg,preservCommand);
        } else if (strcmp(commandAction, "st") == 0) {
            activeCursor.turtle = 1;
            move(activeCursor.yDraw,activeCursor.xDraw);
            printw("*");
            holdCommand(commandHolder,preservCommand,&reallocCounter);
            moreCommands(&commandHolder,reallocCounter);
            msgPrinter(yMsg,xMsg,preservCommand);
        } else if (strcmp(commandAction,"setpencolour") == 0) {
            colour(sendMag,&activeCursor);
            holdCommand(commandHolder,preservCommand,&reallocCounter);
            moreCommands(&commandHolder,reallocCounter);
            msgPrinter(yMsg,xMsg,preservCommand);
        } else if (strcmp(commandAction, "print") == 0) {
            move(printCounter,1);
            printw("%s",commandMag);
            printCounter++;
            if (printCounter >= height) {
                printCounter = 1;
            }
            holdCommand(commandHolder,preservCommand,&reallocCounter);
            moreCommands(&commandHolder,reallocCounter);
            msgPrinter(yMsg,xMsg,preservCommand);
        } else if (strcmp(commandAction, "clean") == 0) {
            clearBoard(height,width);
            printCounter = 1;
            holdCommand(commandHolder,preservCommand,&reallocCounter);
            moreCommands(&commandHolder,reallocCounter);
            msgPrinter(yMsg,xMsg,preservCommand);
        } else if (strcmp(commandAction, "save") == 0) {
            saveCommands(commandHolder,reallocCounter);
            msgPrinter(yMsg,xMsg,preservCommand);
        } else if (strcmp(commandAction,"new") == 0) {
            clearBoard(height,width);
            activeCursor.xDraw = width/2;
            activeCursor.yDraw = height/2;
            activeCursor.drawAngle = 0;
            printCounter = 1;
            freeCommands(commandHolder,&reallocCounter);
            msgPrinter(yMsg,xMsg,preservCommand);
        } else if (strcmp(commandAction,"quit") == 0) {
            loopStatus = 2;
        } else { 
            if (strcmp(commandAction,"Invalid Magnitude")!=0 && strcmp(commandAction,"Invalid Format")!=0) {
                strcpy(commandAction,"Invalid Command");
            }
            msgPrinter(yMsg,xMsg,commandAction);
        }
    }

    freeCommands(commandHolder,&reallocCounter);
    free(commandHolder);
}


