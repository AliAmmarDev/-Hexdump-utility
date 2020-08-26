#include <stdio.h> //standard I/O library
#include "print.h" // Print header file 
#include <ctype.h>  //for character handling functions

// routine to print out in hexadecimal format
void printHexadecimal(int nBytes, unsigned char *data)
{
	unsigned int characters;             //characters
	const int linewidth = 16;  	    //width of line
	
	for (characters = 0; characters < nBytes; characters++, data++) //loop through each character
	{
		if (0 == characters % (linewidth/2)) // if character position is at the centre middle of line
		{
			printf(" "); //print a space
		}
		if(0 == (characters % linewidth)) // If there is no remainder, i.e every 16 times
		{
			printf("\n%06x  %02x ", characters, *data); //print the offset in hexadecimal that describes the distance from the beginning of the block of data.
		}						   //followed by hexadecimal format of characters
		else
		{
			printf("%02x ", *data); //print the hexadecimal format of each character
		}
	}
	printf("\n"); // print new line 
}
// routine to print out in decimal format
void printDecimal(int nBytes, unsigned char *data)
{
	unsigned int characters;  //characters
	const int linewidth = 8;  //width of line 
	int bytes = nBytes / 2; //Decimal uses 8 bytes
	unsigned short *decimaldata = (unsigned short *) data;	//cast: convert pointer to int type
	
		for (characters = 0; characters < bytes; characters++, data++) //looping through characters
	{	
		if(0 == (characters % linewidth)) //if character is at the beginning of the line
		{
			printf("\n%06x  %05d ", characters*2, decimaldata[characters]); //print offset followed by decimal format (*2 because the print is in hexadecimal)
		}
		else 
		{
			printf ("%05d ", decimaldata[characters]); //print decimal format
		}
	}
	printf("\n"); 
}
// routine to print out in character format
void printCharacter(int nBytes, unsigned char *data)
{ 
	int character;        		 //character
	const int linewidth =8;     		 // width of line
	unsigned int rows;		//number of rows
	long reposition;		//position for printing characters
	
	for(rows = 0; rows <= nBytes/linewidth ; rows++) // loops through the rows of file
	{
		printf("%06x ", rows*8); //prints offset in hexadecimal that describes the distance from the beginning of the block of data.
	
		for (character = 0;character < linewidth ; character++, data++) // loops through each character
		{ 
			if (*data == '\0') //if pointer is pointing at NUll
			{
				printf("   "); //print a space (equivalent to the space 1 printable character takes up)
			}
			else 
			printf("%02x ", *data); //print the character the pointer is pointing at
			
			if (7 == character % linewidth) //if character is the last character in th line 
			{
				printf("|"); //print the opening border for the characters
				
				for (reposition = 0; reposition < 8 ; reposition++) //jumping back to beginning of line
				{					
					if (isprint(data[reposition-character])) // checks whether the passed character is printable.
					{
						printf("%c", data[reposition-character]); //print the character
					}
					else if (data[reposition-character] == '\0') //if passed character is Null 
					{
						printf(" "); //print a space
					}
					else  // For all other characters that are not printable 
					{
						printf("."); //print a full stop						
					}									
				}
				printf("|"); //print the closing border for the characters
			}
		}
		printf("\n");	//end of row print a new line		 
	}
}

