#include <unistd.h> /* usleep */
#include <stdio.h>
#include <time.h>   /* time   */
#include <stdlib.h> /* rand   */
#include "gfx.h"
#include "asteroid.h"
#include "vec2.h"
#include "common.h"

#define FMRT 25000

double rand_range(int min, int max) {
    int res;

    res = (rand() % (max - min + 1)) + min;

    return (double) res;
}

Vec2 random_center() {
    Vec2 r;
    uint16_t x_min, x_max;
    uint16_t y_min, y_max;
    uint16_t size = 50;

    x_min = size;
    x_max = WDTH - size;
    y_min = size;
    y_max = HGHT - size;

    r.x = rand_range(x_min, x_max);
    r.y = rand_range(y_min, y_max);

    return r;
}

void init_asteroids() {
    int i;
    Asteroid a;
    for (i = 0; i < 10; i++) {
        a = ast_create(random_center());
    }
}

void draw_limits() {
    gfx_line(0, 0, WDTH, 0);
    gfx_line(WDTH, 0, WDTH, HGHT);
    gfx_line(WDTH, HGHT, 0, HGHT);
    gfx_line(0, HGHT, 0, 0);
}

int main() {

    srand(time(NULL));

    gfx_open(WDTH, HGHT, "Asteroides");
    gfx_color(0, 200, 100);
    gfx_clear();

    init_asteroids();
    //gfx_line(ast.center.x, ast.center.y, ast.verts[1].x, ast.verts[1].y);
    gfx_flush();
    draw_limits();
    ast_draw_all_asteroids();
    gfx_wait();

    while (1) {
        
        gfx_flush();
        gfx_clear();
        usleep(FMRT);
        draw_limits();
        ast_draw_all_asteroids();
        ast_move_all_asteroids();
    }

    printf("Asteroides\n");
	return 0;
}
