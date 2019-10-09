/*
 * AircraftCarrier.h
 *
 *  Created on: Oct 2, 2019
 *      Author: gustt
 */

#ifndef AIRCRAFTCARRIER_H_
#define AIRCRAFTCARRIER_H_
#include "Ship.h"

class AircraftCarrier: public Ship {

public:
	AircraftCarrier(int row, int col, int direction);
	int getLength();
	char toChar(int row, int col);
};

#endif /* AIRCRAFTCARRIER_H_ */
