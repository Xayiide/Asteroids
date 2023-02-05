#include <stdint.h>   /* uint8_t */
#include <stdlib.h>   /* rand    */
#include "gfx.h"
#include "asteroid.h"

static uint8_t  num_asteroids = 0;
static Asteroid ast_array[256];

static void   init_speed(Asteroid);
static double random_angle();


Asteroid ast_create(Vec2 center) {
    Asteroid a;
    a.nsides = MAX_VERTS;
    a.size   = 50.0;
    a.center = center;

    init_speed(a);

    /* Crea un cuadrado en la esquina sup. izda. y se lo suma al centro, para
     * así dejar los vértices alrededos del centro */
    a.verts[0] = vec2_add(center, vec2_create(0, 0));
    a.verts[1] = vec2_add(center, vec2_create(0, 1 * a.size));
    a.verts[2] = vec2_add(center, vec2_create(1 * a.size, 1 * a.size));
    a.verts[3] = vec2_add(center, vec2_create(1 * a.size, 0));

    ast_array[num_asteroids] = a;
    num_asteroids++;

    return a;
}

//void ast_destroy(Asteroid ast) {
//    /* quitarlo del array       */
//    /* array -> lista enlazada? */
//    /* free sides */
//    return;
//}

void ast_destroy_all() {
    num_asteroids = 0;
}

void ast_draw(Asteroid ast) {

    gfx_line(ast.center.x, ast.center.y, ast.verts[0].x, ast.verts[0].y);
    //gfx_line(ast.center.x, ast.center.y, ast.verts[2].x, ast.verts[2].y);
    gfx_line(ast.center.x, ast.center.y, ast.verts[1].x, ast.verts[1].y);
    //gfx_line(ast.center.x, ast.center.y, ast.verts[3].x, ast.verts[3].y);

    gfx_line(ast.verts[0].x, ast.verts[0].y, ast.verts[1].x, ast.verts[1].y);
    gfx_line(ast.verts[1].x, ast.verts[1].y, ast.verts[2].x, ast.verts[2].y);
    gfx_line(ast.verts[2].x, ast.verts[2].y, ast.verts[3].x, ast.verts[3].y);
    gfx_line(ast.verts[3].x, ast.verts[3].y, ast.verts[0].x, ast.verts[0].y);
}

void ast_draw_all_asteroids() {
    uint8_t i;
    for (i = 0; i < num_asteroids; i++) {
        ast_draw(ast_array[i]);
    }
}


static void init_speed(Asteroid ast) {
    Vec2   unit_random;
    double dir;
    double magnitude = 2.0;

    //magnitude   = (-0.1 * ast.size) + 11; /* cuanto más grande más lento */
    dir         = random_angle();
    unit_random = vec2_rot(vec2_create(0, 1), dir); /* unitario aleatorio */

    ast.speed = vec2_mul_esc(unit_random, magnitude);
}

/* random angle 0.0 - 360.0 */
static double random_angle() {
    double r;

    r = (double)rand() / (double)(RAND_MAX/360.0);

    return r;
}
