#include "headers/coord.h"
#include <stdlib.h> /* random */

Coord::Coord() : x(0), y(0) { }

Coord::Coord(double x, double y) : x(x), y(y) { }

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                          Getters and Setters                          */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

double Coord::getx() { return x; }

double Coord::gety() { return y; }

void Coord::randomize(int size) {
	x = rand() % size + 1; /* range from 1 to size */
	y = rand() % size + 1; 
}


void Coord::setx(double x) { this->x = x; }

void Coord::sety(double y) { this->y = y; }
