#include <math.h> /* sqrt */
#include "vec2.h"

Vec2 vec2_create(double x, double y) {
    Vec2 v = {.x = x,
              .y = y};

    return v;
}

/* sqrt(x^2 + y^2 + z^2) */
double vec2_length(Vec2 vec) {
    double r = sqrt((vec.x * vec.x) + (vec.y * vec.y));
    
    return r;
}

double vec2_squared_length(Vec2 vec) {
    double r = ((vec.x * vec.x) + (vec.y * vec.y));

    return r;
}

/* unit(vec) = vec/(length(vec)) */
Vec2 vec2_unit_vector(Vec2 vec) {
    Vec2 new = vec2_div_esc(vec, vec2_length(vec));

    return new;
}



/* Operaciones con vectores */

Vec2 vec2_add(Vec2 v1, Vec2 v2) {
    Vec2 new = {.x = v1.x + v2.x,
                .y = v1.y + v2.y};

    return new;
}


Vec2 vec2_sub(Vec2 v1, Vec2 v2) {
    Vec2 new = {.x = v1.x - v2.x,
                .y = v1.y - v2.y};

    return new;
}


Vec2 vec2_mul(Vec2 v1, Vec2 v2) {
    Vec2 new = {.x = v1.x * v2.x,
                .y = v1.y * v2.y};

    return new;
}


Vec2 vec2_div(Vec2 v1, Vec2 v2) {
    Vec2 new = {.x = v1.x / v2.x,
                .y = v1.y / v2.y};

    return new;
}


/* división de vector por escalar */
Vec2 vec2_div_esc(Vec2 v, double e) {
    Vec2 new = {.x = v.x / e,
                .y = v.y / e};

    return new;
}

/* multiplicación de vector por escalar */
Vec2 vec2_mul_esc(Vec2 v, double e) {
    Vec2 new = {.x = v.x * e,
                .y = v.y * e};

    return new;
}


/* producto escalar de dos vectores */
double vec2_dot(Vec2 v1, Vec2 v2) {
    double r = ((v1.x * v2.x) + (v1.y * v2.y));

    return r;
}
