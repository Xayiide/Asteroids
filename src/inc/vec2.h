#ifndef _VEC2_H_
#define _VEC2_H_

typedef struct {
    double x;
    double y;
} Vec2;


Vec2 vec2_create(double, double);

double vec2_length(Vec2);

double vec2_squared_length(Vec2);

Vec2 vec2_unit_vector(Vec2);


/* Operaciones con vectores */

Vec2 vec2_add(Vec2, Vec2);

Vec2 vec2_sub(Vec2, Vec2);

Vec2 vec2_mul(Vec2, Vec2);

Vec2 vec2_div(Vec2, Vec2);

/* división escalar */
Vec2 vec2_div_esc(Vec2, double);

/* multiplicación escalar */
Vec2 vec2_mul_esc(Vec2, double);


/* producto escalar */
double vec2_dot(Vec2, Vec2);

#endif
