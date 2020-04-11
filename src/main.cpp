#include "headers/asteroid.h"
#include "headers/constants.h"
#include "headers/gfx.h"
#include "headers/universe.h"

#include <vector>   /* vector          */
#include <unistd.h> /* usleep          */
#include <stdlib.h> /* rand            */
#include <stdio.h>  /* fprintf, stderr */
#include <time.h>   /* time            */
#include <errno.h>  /* errno           */

int checkArguments(int, char**);

int main(int argc, char *argv[]) {
	int numasteroids;
	if (argc != 2) {
		fprintf(stderr, "Usage: %s <# asteroids>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	numasteroids = checkArguments(argc, argv);

	Universe universe(numasteroids);
	universe.startEverything();

	return EXIT_SUCCESS;
}

int checkArguments(int argc, char *argv[]) {
	long  numAsteroids = 0;
	char *endptr;

	errno = 0;

	if (argc != 2) {
		fprintf(stderr, "Usage: %s <# asteroids>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	numAsteroids = strtol(argv[1], &endptr, 10);

	if (endptr == argv[1]) {
		fprintf(stderr, "El argumento debe ser un entero\n");
		exit(EXIT_FAILURE);
	}

	if (numAsteroids < 0) {
		fprintf(stderr, "El agumento debe ser >= 0\n");
		exit(EXIT_FAILURE);
	}

	return (int) numAsteroids;
}