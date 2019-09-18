/*
 * Tests.h
 *
 *  Created on: Sep 5, 2019
 *      Author: Therese
 */

#ifndef TESTS_H_
#define TESTS_H_

#include <stdbool.h>

class Tests {
public:
	Tests();
	virtual ~Tests();
	bool tests();
	bool testEmptyList();
	bool testSingletonList();
	bool testAddNode();
	bool testDeleteList();
};

#endif /* TESTS_H_ */
