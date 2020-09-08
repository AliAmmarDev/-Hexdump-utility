

### This is a C program and was built and tested on CentOS 7.

The program replicates the core functionality of the hexdump utility.
The program prints data from the input txt file which has been provided. 
input.txt file contains sample input. Sample input can be changed. 

Instructions on how to compile and run the file:

Before compiling make sure the following files are all in the same directory:
"hexdump.o", "print.c", "print.h", "input.txt", "makefile"
Enter the right directory via terminal and enter "make"
This will create 2 executable files, hexdump and print.o

To execute in the desired format, enter the following:

  -Hexadecimal Output               ./hexdump input.txt		
  -Decimal Output                   ./hexdump -d input.txt		
  -Formatted Character Output       ./hexdump -c input.txt		
