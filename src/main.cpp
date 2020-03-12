#include <iostream>
#include <stdlib.h> /* strtol */
#include <errno.h>  /* errno */
#include <stdlib.h> /* random */
#include <time.h>   /* init random */
#include <unistd.h> /* (u)sleep */

#include "headers/gfx.h"
#include "headers/asteroid.h"
#include "headers/coord.h"

/*****************************************************************************/
#define WINNAME    "Asteroids"
#define FRAMERATE  10000 /* Update screen every n microseconds */

const int WWDTH = 900;
const int WHGHT = 900;


void         printUsage(char **);
unsigned int checkArguments(int, char **);
void         initspawnpts(std::vector<Coord>);

// TODO: Create vector of Asteroids
//     · For every asteroid, move it
//     · For every asteroid, draw it
//     · For every asteroid, check its bounds
//              -> If out of bounds, delete it
//     · Hacer que los asteroides no crucen segmentos al dibujarse

int main(int argc, char *argv[]) {
	unsigned int          nast;      /* Number of asteroids                */
	std::vector<Asteroid> asts;      /* Vector containing all asteroids    */


	srand(time(NULL));
	nast = checkArguments(argc, argv);
	asts.resize(nast);


	for (auto &ast: asts) {
		ast = Asteroid(FRAMERATE);
	}

	gfx_open(WWDTH, WHGHT, WINNAME);
	gfx_color(0, 200, 100);


	while (1) {
		gfx_clear();
		for (auto &ast: asts) {
			ast.draw();
			ast.move();
		}
		gfx_flush();
		usleep(FRAMERATE);
	}

}








void printUsage(char *argv[]) {
	std::cerr << "Usage: " << argv[0] << " <# of asteroids>" << std::endl;
}

unsigned int checkArguments(int argc, char *argv[]) {
	long  numAsteroids = 0;
	char *endptr;

	errno = 0;

	if (argc != 2) {
		printUsage(argv);
		exit(EXIT_FAILURE);
	}

	numAsteroids = strtol(argv[1], &endptr, 10);

	if (endptr == argv[1]) {
		std::cerr << "Argument must be an integer" << std::endl;
		exit(EXIT_FAILURE);
	}

	if (numAsteroids < 0) {
		std::cerr << "Argument must be >= 0" << std::endl;
		exit(EXIT_FAILURE);
	}

	return (unsigned int) numAsteroids;
}
