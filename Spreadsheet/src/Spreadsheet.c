/*
 ============================================================================
 Name        : Spreadsheet.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

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

//here are some external variables, see Kernighan and Richie, pp. 31, 32


int main(int argc, char* argv[]) {
	puts("!!!Let's do the spreadsheet example!!!"); /* prints !!!Hello World!!! */
	if(tests())
	{
		production(argc, argv);
	}
	else
	{
		 puts("Tests did not pass.");
	}
	return EXIT_SUCCESS;
}
