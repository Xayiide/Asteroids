#include "headers/asteroid.h"
#include "headers/gfx.h"

#include <stdlib.h> /* random */
#include <vector>
#include <stdio.h>
#include <math.h>   /* round and stuff */

Asteroid::Asteroid() { } /* Needed to create the vector on main */

Asteroid::Asteroid(int f) {
	this->fr     = f;
	rndstats(); /* Randomize xsp, ysp, rotsp and size */
	init();
}

void Asteroid::init() {
	/* Convert xsp from pixels per sec or whatever to pixels per framerate.
	   Doing it here avoids us doing it every time we move the asteroid */
	this->xsp = (fr * xsp) / 1000000.; /* 1s = 1.000.000us */
	this->ysp = (fr * ysp) / 1000000.; 

	/* Make ncoords a random number between 3 and 4 */
	ncoords = 3 + (rand() % static_cast<int>(4 - 3 + 1)); 

	/* Cambia el tamaño del vector a ncoords elementos */
	coords.resize(ncoords);
}

void Asteroid::rndstats() {
	this->xsp   = -10 + (rand() % static_cast<int>(10+10+1));
	this->ysp   = -10 + (rand() % static_cast<int>(10+10+1));
	this->rotsp = -10 + (rand() % static_cast<int>(10+10+1)); /* TODO: cambiar por unidades de giro que sean */
	this->size  = rand() % 100;
}

void Asteroid::rndcoords() {
	/* Elegir un punto fuera de la pantalla */
	/* Generar ncoords - 1 puntos que estén a como mucho distancia size de el */
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

double Asteroid::getxsp() { return xsp; }

double Asteroid::getysp() { return ysp; }

double Asteroid::getrotsp() { return rotsp; }

int    Asteroid::getsize() { return size; }


void Asteroid::setxsp(double sp) { this->xsp = sp; }

void Asteroid::setysp(double sp) { this->ysp = sp; }

void Asteroid::setrotsp(double sp) { this->rotsp = sp; }

void Asteroid::setsize(int size) { this->size = size; }