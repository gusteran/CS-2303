/*
 ============================================================================
 Name        : Homework2.c
 Author      : Gus Teran
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
	if(tests())
	{
		puts("Tests Passed!");
		moveIterations(10);
//		production(argc, argv);
	}
	else
	{
		 puts("Tests did not pass.");
	}
	return EXIT_SUCCESS;
}
