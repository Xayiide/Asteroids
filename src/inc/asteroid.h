#ifndef _ASTEROID_H_
#define _ASTEROID_H_

#include <stdint.h>
#include "vec2.h"

#define MAX_VERTS 4

typedef struct {
    uint8_t nsides;
    Vec2    center;
    double  size;
    Vec2    speed;
    Vec2    verts[MAX_VERTS];
} Asteroid;

Asteroid ast_create(Vec2);
//void     ast_destroy(Asteroid);

void ast_destroy_all();

void ast_draw(Asteroid);

void ast_draw_all_asteroids();

#endif
