#include <stdio.h>    /* printf  */
#include <stdint.h>   /* uint8_t */
#include <stdlib.h>   /* rand    */
#include "gfx.h"
#include "asteroid.h"
#include "common.h"

static uint8_t  num_asteroids = 0;
static Asteroid ast_array[256];

static Vec2   random_speed(double);
static double random_angle();
static void   random_vertices(Asteroid *);
static void   bubble_sort(double [], uint8_t);
static Vec2   centroid(Vec2 [], uint8_t);

Asteroid ast_create(Vec2 center) {
    Asteroid a;
    a.nsides = MAX_VERTS;
    a.size   = (double)(rand() % (100 - 15 + 1)) + 15;
    a.center = center;
    a.speed  = random_speed(a.size);
    a.angsp  = (double)(rand() % (9 - 1 + 1)) + 1;

    random_vertices(&a);

    a.centroid = centroid(a.verts, a.nsides);

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

void ast_draw(Asteroid a) {
    uint8_t i;

    //gfx_point(a.center.x, a.center.y);
    gfx_point(a.centroid.x, a.centroid.y);

    for (i = 0; i < a.nsides; i++) {
        gfx_line(a.verts[i].x, a.verts[i].y,
                 a.verts[(i+1)%a.nsides].x, a.verts[(i+1)%a.nsides].y);
    }
}

void ast_draw_all_asteroids() {
    uint8_t i;
    for (i = 0; i < num_asteroids; i++) {
        ast_draw(ast_array[i]);
    }
}

void ast_move(Asteroid *a) {
    uint8_t i;

    /* Bounce using centroid due to visual issues.
     * Using the center made some bounces appear way before an edge touched
     * any border */
    if (a->centroid.x < 0 || a->centroid.x > WDTH)
        a->speed.x = -(a->speed.x);
    if (a->centroid.y < 0 || a->centroid.y > HGHT)
        a->speed.y = -(a->speed.y);

    a->center   = vec2_add(a->center, a->speed);
    a->centroid = vec2_add(a->centroid, a->speed);
    for (i = 0; i < a->nsides; i++) {
        a->verts[i] = vec2_add(a->verts[i], a->speed);
    }
}

void ast_rotate(Asteroid *a) {
    uint8_t i;
    Vec2 aux; /* vector del centro al vértice i */

    for (i = 0; i < a->nsides; i++) {
        aux   = vec2_sub(a->verts[i], a->centroid);
        aux   = vec2_rot(aux, a->angsp);
        a->verts[i] = vec2_add(aux, a->centroid);
    }

}

void ast_move_all_asteroids() {
    uint8_t i;
    for (i = 0; i < num_asteroids; i++) {
        ast_move(&ast_array[i]);
        ast_rotate(&ast_array[i]);
    }
}

static Vec2 random_speed(double size) {
    Vec2   unit_random;
    double dir;
    double magnitude;

    magnitude   = (-0.1 * size) + 11; /* cuanto más grande más lento */
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

static void random_vertices(Asteroid *a) {
    uint8_t i;
    double  random_angles[a->nsides];
    double  angle;
    Vec2    vertical = vec2_create(0, -(a->size));
    Vec2    aux, point;

    /* generate nsides random points */
    for (i = 0; i < a->nsides; i++)
        random_angles[i] = random_angle();

    bubble_sort(random_angles, a->nsides);

    for (i = 0; i < a->nsides; i++) {
        angle = random_angles[i];
        aux   = vec2_rot(vertical, angle);
        point = vec2_add(aux, a->center);
        a->verts[i] = point;
    }
}

static void bubble_sort(double arr[], uint8_t size) {
    uint8_t i;
    uint8_t changes = 0;
    double  temp;

    while (1) {
        for (i = 0; i < size; i++) {
            if (arr[i] > arr[i+1]) {
                changes  = 1;
                temp     = arr[i];
                arr[i]   = arr[i+1];
                arr[i+1] = temp;
            }
        }
        if (changes == 0)
            break;
        changes = 0;
    }
}

static Vec2 centroid(Vec2 verts[], uint8_t nsides) {
    uint8_t i;
    Vec2    centroid;
    Vec2    sum;


    sum = vec2_add(verts[0], verts[1]);
    for (i = 2; i < nsides; i++) {
        sum = vec2_add(sum, verts[i]);
    }

    centroid = vec2_div_esc(sum, (double) nsides);

    return centroid;
}
