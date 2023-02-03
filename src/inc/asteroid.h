#ifndef _ASTEROID_H_
#define _ASTEROID_H_

#include <stdint.h>
#include "vec2.h"

typedef struct {
    uint8_t  nsides;
    Vec2    *sides;
    double   size;
    Vec2     vel;
} Asteroid;

Asteroid ast_create(double, Vec2);
void     ast_destroy(Asteroid);

void ast_draw(Ast);

#endif
