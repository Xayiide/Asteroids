#include "headers/asteroid.h"
#include "headers/gfx.h"

#include <stdlib.h> /* random */
#include <vector>
#include <stdio.h>

Asteroid::Asteroid() { } /* Just here cause needed on main */

Asteroid::Asteroid(int f) {
	fr = f;
	init();
}

/* Initialize the Asteroid speed with pixels or whatever gfx uses per second */
Asteroid::Asteroid(int x, int y, int r, double s, int f) :
								xsp(x), ysp(y), rotsp(r), size(s), fr(f) {
		init();
	 }



void Asteroid::init() {
	/* Randomize xsp, ysp, rotsp and size */
	rndst();

	/* Convert xsp from pixels per sec or whatever to pixels per framerate.
	   Doing it here avoids us doing it every time we move the asteroid */
	this->xsp = (fr * xsp) / 1000000.; /* 1s = 1.000.000us */
	this->ysp = (fr * ysp) / 1000000.; 

	/* Make ncoords a random number between 3 and 4 */
	ncoords = 3 + (rand() % static_cast<int>(4 - 3 + 1)); 

	/* Cambia el tamaño del vector a ncoords elementos */
	coords.resize(ncoords);
	
	/* Inicializa a valores aleatorios cada Coord */
	for (auto &c : coords)
		c.randomize(size);
}

void Asteroid::rndst() {
	// xsp   = rand() % 100 + 1; /* xsp [1-2] */
	// ysp   = rand() % 100 + 1; /* ysp [1-2] */
	// rotsp = rand() % 100 + 1; /* rotsp [1-2] */
	// size  = rand() % 100 + 1; /* size [1-100] */
	xsp = 10; ysp = 10; rotsp = 0; size = 100;
}

void Asteroid::move() {
	for (auto &c: coords) {
		c.setx(c.getx() + this->xsp);
		c.sety(c.gety() + this->ysp);
	}
}

void Asteroid::rot() {
	return;
}

void Asteroid::draw() {
	int i;
	for (i = 0; i < ncoords; i++) {
		gfx_line(coords[i].getx(), coords[i].gety(),
				 coords[(i+1)%ncoords].getx(), coords[(i+1)%ncoords].gety());
	}
}

/* Check asteroid boundaries. If we're completely out of boundaries, we delete
   the Asteroid object and create a new one */
bool Asteroid::isout(int width, int heigth) {
	int out = 0;
	for (auto &c: coords) {
		int x = c.getx();
		int y = c.gety();
		if (x < 0 || x > width || y < 0 || y > heigth)
			out++;
	}
	return (out == ncoords) ? true : false;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                          Getters and Setters                          */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

int Asteroid::getxsp() { return xsp; }

int Asteroid::getysp() { return ysp; }

int Asteroid::getrotsp() { return rotsp; }

double Asteroid::getsize() { return size; }


void Asteroid::setxsp(int sp) { this->xsp = sp; }

void Asteroid::setysp(int sp) { this->ysp = sp; }

void Asteroid::setrotsp(int sp) { this->rotsp = sp; }

void Asteroid::setsize(double size) { this->size = size; }