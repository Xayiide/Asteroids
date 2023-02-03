#include <stdint.h>   /* uint8_t */
#include "asteroid.h"

static uint8_t  num_asteroids = 0;
static Asteroid ast_array[256];


Asteroid ast_create(double s, Vec2 v) {
    Asteroid a = {.nsides = 4,
                  .size   = s,
                  .vel    = v};

    /* TODO */
    /* malloc sides */
    ast_array[num_asteroids] = a;
    num_asteroids++;

    return a;
}

void ast_destroy(Asteroid ast) {
    /* quitarlo del array       */
    /* array -> lista enlazada? */
    /* free sides */
}

void ast_draw(Asteroid ast) {
    uint8_t i;
}


