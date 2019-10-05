/*
 * Checker.h
 *
 *  Created on: Sep 25, 2019
 *      Author: gustt
 */

#ifndef CHECKER_H_
#define CHECKER_H_
#include <vector>
#include <string>
#define RED 1
#define BLACK 2
#define EMPTY 0
#define NOT 4

using namespace std;

typedef struct {
	int row;
	int col;
}Location;

typedef struct {
	int team;
	Location location;
	vector<Location> nextLocations;
	vector<Location> jumps;
} Path;

class Checker {
protected:
	int team;
public:
	Checker();
	Checker(int team);
	virtual ~Checker();
	virtual string toString();
	int getTeam();
	virtual Path possibleMoves(Location location);
};





#endif /* CHECKER_H_ */
