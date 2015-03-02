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
