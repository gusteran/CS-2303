//============================================================================
// Name        : fopen.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include "Tests.h"
#include "Production.h"

int main(int argc, char* argv[]) {
	Tests* ts = new Tests();
	if(ts->tests())
	{
		Production* p = new Production();
		p->production(argc, argv);
		delete p;
	}
	cout << "!!!Let's do fopen for read!!!" << endl;
	delete ts;
	return 0;
}
