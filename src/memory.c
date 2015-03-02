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

#include "operate.h"
#include "memory.h"

/*
Free Commands.
IN: Array of command pointers and malloc incrementer.
OUT: N/A
*/
void freeCommands(char ** commandHolder, int * counter) {
    for (int i = 0; i<*counter-1; i++) {
        free(commandHolder[i]);
    }
    commandHolder = malloc(1*sizeof(char*));
    *counter = 1;
}

/*
Save commands to text file.
IN: Array of command pointers and malloc incrementer.
OUT: N/A
*/
void saveCommands(char ** commandHolder, int counter) {
    FILE *file = fopen("assets/saves.txt", "w");
    if (file == NULL) {
        printf("file didn't open b");
    }
    for (int i = 0; i<counter-1; i++) {
        fprintf(file, "%s\n", commandHolder[i]);
    }
    fclose(file);
}

/*  
Add command to commands array.
IN: Array of command pointer, command, and malloc incrementer.
OUT: N/A
*/
void holdCommand (char ** commandHolder,char command[15],int * counter) {
    int len = strlen(command);

    if (commandHolder != NULL) {
        commandHolder[*counter-1] = malloc((sizeof(char)*len)+1);
        if (commandHolder[*counter-1] != NULL) {
            strcpy(commandHolder[*counter-1], command);
            *counter = *counter + 1;
        }
    } else {
        printf("realloc failed");
    }

}

/*
Reallocate more memory for commands array.
IN: Array of command pointer, malloc incrementer.
OUT: N/A
*/
void moreCommands(char *** commandHolder, int counter) {
    *commandHolder = realloc(*commandHolder, counter * sizeof(char*));
}

