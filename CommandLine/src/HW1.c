/*
 ============================================================================
 Name        : HW1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "tests.h"
#include "production.h"
#include "TMSName.h"

int main(int argc, char* argv[]) {
	puts("!!!Let's do HW1!!!"); /* prints !!!Hello World!!! */
	if(tests())
	{
		puts("Invoking production.");
		fflush(stdout);
		if(production(argc, argv))
		{
			puts("Production succeeded.");
		}
	}
	else
	{
		 puts("Tests did not pass.");
	}
	return EXIT_SUCCESS;
}
