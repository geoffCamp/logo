*******************************************************
Geofferson Camp 
Logo Interpreter
Feb 2015
*******************************************************

************
Enhancments
************

- All angles.
- setxy, print, st, ht, clean


************
Compilation
************

all:runMe

runMe: drawing.o operate.o maintain.o action.o calc.o memory.o main.o
        gcc drawing.o operate.o maintain.o action.o calc.o memory.o main.o -o bin/runMe -lncurses -lm -Iinclude

drawing.o: src/drawing.c
        gcc -Wall -std=c99 -pedantic -c src/drawing.c -Iinclude

operate.o: src/operate.c
        gcc -Wall -std=c99 -pedantic -c src/operate.c -Iinclude

maintain.o: src/maintain.c
        gcc -Wall -std=c99 -pedantic -c src/maintain.c -Iinclude

action.o: src/action.c
        gcc -Wall -std=c99 -pedantic -c src/action.c -Iinclude

calc.o: src/calc.c
        gcc -Wall -std=c99 -pedantic -c src/calc.c -Iinclude

memory.o: src/memory.c
        gcc -Wall -std=c99 -pedantic -c src/memory.c -Iinclude

main.o: src/main.c
        gcc -Wall -std=c99 -pedantic -c src/main.c -Iinclude


***********************
Running the program(s)
***********************

- Enter commands to draw in output space.
- Enter submits commands.

*****************
Known Limitations
*****************

- Turtle doesn't show at the start.
- Commands can be a maximum of 14 characters.
- Print commands can be a maximum of 8 characters.
- Angles above 720 degrees will crash the program.
- Negative angles will not be accepted.
- Angles with slopes that do not correspond to whole numbers are approximated.
- The size of one magnitude unit will vary depending on the the angle.
- nCurses window is set to 100x100.

*****************
Testing Done
*****************

- Player unable to draw outside drawing window.
- Invalid command types and formats.

*****************
Sources
*****************

- nCurses functions referenced from linux.die.net/man
- nCurses colour features referenced from tldp.org/HOWTO/NCURSES-Programming-HOWTO/color.html
- Logo Interpreter referenced from www.calormen.com/jslogo

