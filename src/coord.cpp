#include "headers/coord.h"
#include <stdlib.h> /* random */

Coord::Coord() : x(0), y(0) { }

Coord::Coord(int x, int y) : x(x), y(y) { }

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                          Getters and Setters                          */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

int Coord::getx() { return x; }

int Coord::gety() { return y; }

void Coord::randomize(int size) {
    x = rand() % size + 1; /* range from 1 to size */
    y = rand() % size + 1; 
}


void Coord::setx(int x) { this->x = x; }

void Coord::sety(int y) { this->y = y; }
