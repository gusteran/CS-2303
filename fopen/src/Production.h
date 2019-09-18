/*
 * Production.h
 *
 *  Created on: Sep 5, 2019
 *      Author: Therese
 */

#ifndef PRODUCTION_H_
#define PRODUCTION_H_

#include <stdbool.h>

#define FILENAMELENGTHALLOWANCE 50

class Production {
public:
	Production();
	virtual ~Production();
	bool production(int argc, char* argv[]);
};

template < class T >
T maximum (T value1, T value2, T value3 )
{
	T maximumValue = value1;

	if( value2 > maximumValue)
	{
		maximumValue = value2;
	}

	if(value3 > maximumValue)
	{
		maximumValue = value3;
	}
	return maximumValue;
}

#endif /* PRODUCTION_H_ */
