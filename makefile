hexdump: hexdump.o print.o
	gcc -g -Wall -Wpedantic -o hexdump hexdump.o print.o

print.o: print.c print.h
	gcc -g -c -o print.o print.c

clean:
	rm -f hexdump print.o
