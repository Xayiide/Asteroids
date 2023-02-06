#include <stdio.h>    /* printf  */
#include <stdint.h>   /* uint8_t */
#include <stdlib.h>   /* rand    */
#include "gfx.h"
#include "asteroid.h"
#include "common.h"

static uint8_t  num_asteroids = 0;
static Asteroid ast_array[256];

static Vec2   random_speed();
static double random_angle();


Asteroid ast_create(Vec2 center) {
    Asteroid a;
    a.nsides = MAX_VERTS;
    a.size   = 50.0;
    a.center = center;
    a.speed  = random_speed();

    /* Crea un cuadrado en la esquina sup. izda. y se lo suma al centro, para
     * así dejar los vértices alrededos del centro */
    a.verts[0] = vec2_add(center, vec2_create(-a.size/2, -a.size/2));
    a.verts[1] = vec2_add(center, vec2_create( a.size/2, -a.size/2));
    a.verts[2] = vec2_add(center, vec2_create(-a.size/2,  a.size/2));
    a.verts[3] = vec2_add(center, vec2_create( a.size/2,  a.size/2));

    printf("Asteroide en (%f, %f) con vértices en\n", a.center.x, a.center.y);
    printf("\t\t\t[%f, %f] [%f, %f]\n", a.verts[0].x, a.verts[0].y,
                                           a.verts[1].x, a.verts[1].y);

    printf("\t\t\t[%f, %f] [%f, %f]\n", a.verts[2].x, a.verts[2].y,
                                           a.verts[3].x, a.verts[3].y);
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
    gfx_point(ast.center.x, ast.center.y);
    gfx_line(ast.verts[0].x, ast.verts[0].y, ast.verts[1].x, ast.verts[1].y);
    gfx_line(ast.verts[1].x, ast.verts[1].y, ast.verts[3].x, ast.verts[3].y);
    gfx_line(ast.verts[3].x, ast.verts[3].y, ast.verts[2].x, ast.verts[2].y);
    gfx_line(ast.verts[2].x, ast.verts[2].y, ast.verts[0].x, ast.verts[0].y);
}

void ast_draw_all_asteroids() {
    uint8_t i;
    for (i = 0; i < num_asteroids; i++) {
        ast_draw(ast_array[i]);
    }
}

void ast_move(Asteroid *ast) {

    if (ast->center.x < 0 || ast->center.x > WDTH)
        ast->speed.x = -(ast->speed.x);
    if (ast->center.y < 0 || ast->center.y > HGHT)
        ast->speed.y = -(ast->speed.y);

    ast->center   = vec2_add(ast->center, ast->speed);
    ast->verts[0] = vec2_add(ast->verts[0], ast->speed);
    ast->verts[1] = vec2_add(ast->verts[1], ast->speed);
    ast->verts[2] = vec2_add(ast->verts[2], ast->speed);
    ast->verts[3] = vec2_add(ast->verts[3], ast->speed);
}

void ast_move_all_asteroids() {
    uint8_t i;
    for (i = 0; i < num_asteroids; i++)
        ast_move(&ast_array[i]);
}

static Vec2 random_speed() {
    Vec2   unit_random;
    double dir;
    double magnitude = 2.0;

    //magnitude   = (-0.1 * ast.size) + 11; /* cuanto más grande más lento */
    dir         = random_angle();
    unit_random = vec2_rot(vec2_create(0, 1), dir); /* unitario aleatorio */

    return vec2_mul_esc(unit_random, magnitude);
}

/* random angle 0.0 - 360.0 */
static double random_angle() {
    double r;

    r = (double)rand() / (double)(RAND_MAX/360.0);

    return r;
}
