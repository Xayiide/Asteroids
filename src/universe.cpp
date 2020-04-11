#include "headers/universe.h"
#include "headers/gfx.h"
#include "headers/constants.h"

#include <unistd.h> /* usleep  */
#include <stdlib.h> /* srand() */
#include <time.h>   /* time()  */


Universe::Universe(int num) {
	numAsteroids = num;
	asteroids.reserve(num); /* NO USAR RESIZE */

	srand(time(NULL));
	gfx_open(HGHT, WDTH, "Asteroids simulation");
	gfx_color(0, 200, 100);
	gfx_clear();
}

void Universe::randomizeAsteroid() {
	/* radius in range [MINRAD, MAXRAD - MINRAD]. Same with sides */
	radius = rand() % (MAXRAD - MINRAD + 1) + MINRAD;
	sides  = rand() % (MAXSID - MINSID + 1) + MINSID;

	if (rand() % 2) {
		y = rand() % (WDTH - 10 + 1) + 10;
		if (y > 30 || y < (WDTH - 30)) {
			if (rand() % 2) x = 0;
			else            x = HGHT;
		} else {
			x = rand() % (HGHT - 10 + 1) + 10;
		}
	} else {
		x = rand() % (HGHT - 10 + 1) + 10;
		if (x > 30 || x < (HGHT - 30)) {
			if (rand() % 2) y = 0;
			else            y = WDTH;
		} else {
			y = rand() % (WDTH - 10 + 1) + 10;
		}
	}
}

void Universe::initializeAsteroids() {
	for (int i = 0; i < numAsteroids; i++) {
			randomizeAsteroid();
			Asteroid tmp(sides, x, y, radius);
			asteroids.push_back(tmp);
			asteroids[i].update();
			asteroids[i].draw();
	}

	gfx_flush();
	usleep(FRAMERATE);
}

void Universe::startEverything() {
	int i = 0;
	initializeAsteroids();

	while (1) {
		for (i = 0; i < numAsteroids; i++) {
			asteroids[i].move();
			if (asteroids[i].isout()) {
				randomizeAsteroid();
				asteroids[i].setcenter(x, y);
				asteroids[i].setsize(radius);
				asteroids[i].setnsides(sides);
				asteroids[i].initialize();
				asteroids[i].update();
			}
		}
		gfx_flush();
		gfx_clear();
		usleep(FRAMERATE);

		if (gfx_event_waiting())
			break;
	}
}