// Author: John-Austen Francisco
// Date: 9 September 2015
//
// Preconditions: Appropriate C libraries
// Postconditions: Generates Segmentation Fault for
//                               signal handler self-hack

// Student name: Ava Kathryn Shaw
// Ilab machine used: cpp.cs.rutgers.edu
// CFLAGS = -O0 -m32

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

#define SPC     0x3c
#define BIL     0x6

void segment_fault_handler(int signum)
{
       
    printf("I am slain!\n");

   //Use the signum to construct a pointer to flag on stored stack
    void *sig_address = &signum;
    //Increment pointer down to the stored PC
	void *ptr = sig_address + SPC;
	//Increment value at pointer by length of bad instruction
	*(int *)ptr = *(int *)ptr + BIL; 
	
}


//do not change anything in main, only develop a signal handler
int main()
{
	int r2 = 0;

	signal(SIGSEGV, segment_fault_handler);

	r2 = *( (int *) 0 );
	
	printf("I live again!\n");

	return 0;
}