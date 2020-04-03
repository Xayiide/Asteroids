#include "headers/asteroid.h"
#include "headers/constants.h"
#include "headers/gfx.h"

#include <vector>   /* vector          */
#include <unistd.h> /* usleep          */
#include <stdlib.h> /* rand            */
#include <stdio.h>  /* fprintf, stderr */
#include <time.h>   /* time            */

#define FRAMERATE 25000

void initasteroids();
void randomizeasteroid();

/* Global variables are bad and this could be solved with another class but
   i dont want to do it that way yet */

double radius       = 10;
int    numasteroids = 0;
int    x            = 0;
int    y            = 0;
int    sides        = 5;
std::vector<Asteroid> asteroids;

int main(int argc, char *argv[]) {
	if (argc != 2) {
		fprintf(stderr, "Usage: %s <# asteroids>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	/* Horrible practice needs error checking */
	numasteroids = atoi(argv[1]);
	asteroids.resize(numasteroids);

	srand(time(NULL));

	gfx_open(HGHT, WDTH, "Asteroids woo woo");
	gfx_color(0, 200, 100);
	gfx_clear();


	initasteroids();

	int i = 0;
	while (1) {
		for (i = 0; i < numasteroids; i++) {
			asteroids[i].move();
			if (asteroids[i].isout()) {
				randomizeasteroid();
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

		/* TODO: Meter esto en el while */
		if (gfx_event_waiting())
			break;
	}
	return EXIT_SUCCESS;
}


void initasteroids() {
	for (int i = 0; i < numasteroids; i++) {
		randomizeasteroid();
		Asteroid tmp(sides, x, y, radius);
		asteroids.push_back(tmp);
		asteroids[i].update();
		asteroids[i].draw();
	}

	gfx_flush();
	usleep(FRAMERATE);
}

void randomizeasteroid() {
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