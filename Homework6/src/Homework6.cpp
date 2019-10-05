//============================================================================
// Name        : Homework5.cpp
// Author      : Gus Teran
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "tests.h"
#include "production.h"
using namespace std;

int main(int argc, char *argv[]) {
	if (tests()) {
		puts("Tests Passed!");
		production(argc, argv);
	} else {
		puts("Tests did not pass.");
	}
	return EXIT_SUCCESS;
}
