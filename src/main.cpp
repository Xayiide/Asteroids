#include <iostream>
#include <stdlib.h> /* strtol */
#include <errno.h>  /* errno */
#include <stdlib.h> /* random */
#include <time.h>   /* init random */

#include "headers/gfx.h"
#include "headers/asteroid.h"

/*****************************************************************************/
#define WINWIDTH   300
#define WINHEIGTH  300
#define WINNAME    "Asteroids"



void         printUsage(char **);
unsigned int checkArguments(int, char **);

int main(int argc, char *argv[]) {

    unsigned int numAsteroids = 0;
    numAsteroids = checkArguments(argc, argv);

    std::cout << "num asteroids: " << numAsteroids << std::endl;


    srand(time(NULL));

    gfx_open(WINWIDTH, WINHEIGTH, WINNAME);
    gfx_color(0, 200, 100);
    
    Asteroid a1;
    a1.setsize(200); a1.draw();

    while (1) {
        char c = gfx_wait();
        if (c == 'q') break;
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