#include "headers/asteroid.h"
#include "headers/gfx.h"


#include <stdlib.h>   /* rand()          */
#include <math.h>     /* round(), sqrt() */
#include <string.h>   /* memcpy()        */

Asteroid::Asteroid() { }

Asteroid::Asteroid(int sides, int x, int y, double r) {
	nsides    = sides;
	center[0] = x;
	center[1] = y;
	size      = r;

	initialize();

}

void Asteroid::initialize() {
	verts.resize(nsides);
	for (int i = 0; i < nsides; i++) 
		verts[i].resize(2);

	setspeed(ipspeed()); /* Set the speed            */
	randdir();           /* Set the directions       */
	randangvl();         /* Set the angular velocity */

}

/* Return a speed inversely proportional to the size of the Asteroid.
   If max size is 100, we want speed to be minimal, but not negative. To
   achieve this, we multiply by -0.1 and then add a number to make it positive.
   This number is 1 unit bigger than the smaller possible size (10)
   -0.1 * 100 + 11 = 1
   -0.1 * 10  + 11 = 10 */
double Asteroid::ipspeed() {
	return ((-0.1 * size) + 11.);
}

/* Initialize directions randomly */
void Asteroid::randdir() {
	/* Range from [MINSPD, MAXSPD - MINSPD] */
	dir[0] = rand() % (MAXSPD - MINSPD + 1) + MINSPD;
	dir[1] = round(sqrt((speed * speed) - (dir[0] * dir[0])));


	/* Okay so maybe speeds on the opposite directions */
	if (rand() % 2) dir[0] *= -1;
	if (rand() % 2) dir[1] *= -1;
}

/* Initialize angular velocity randomly */
void Asteroid::randangvl() {
	/* TODO: Change this */
	angvl = -0.21 * size + 22.14;

	/* Maybe on the opposite direction */
	if (rand() % 2) angvl *= -1;
}

/* Update asteroid's coordinates */
void Asteroid::update() {
	double alpha, beta;

	for (int i = 0; i < nsides; i++) {
		alpha = i * ((2 * PI) / nsides);
		beta  = (i + 1) * ((2 * PI) / nsides);

		verts[i][0]   = center[0] + (size * cos(alpha)) + auxmov();
		verts[i][1]   = center[1] + (size * sin(alpha)) + auxmov();
		verts[i+1][0] = center[0] + (size * cos(beta))  + auxmov();
		verts[i+1][1] = center[1] + (size * sin(beta))  + auxmov();
	}
}

/* Auxiliary move calculator */
int Asteroid::auxmov() {
	int v = 3;

	if (size > 70) v = 15;
	else if (size > 40) v = 10;

	v = rand() % v + 1;

	if (rand() % 2)
		v *= (-1);

	return v;
}

/* Draw the asteroid */
void Asteroid::draw() {
	/* With this loop we guarantee that the vertices are joined in the correct
	   order and there are no crossing lines */
	int i; /* Tenemos que declarar aqui aunque quede feo por la ultima linea */
	for (i = 0; i < nsides; i++)
		gfx_line(verts[i][0], verts[i][1], verts[i+1][0], verts[i+1][i]);
	gfx_line(verts[0][0], verts[0][1], verts[i][0], verts[i][1]);
}

/* Move the asteroid */
void Asteroid::move() {
	center[0] += dir[0];
	center[1] += dir[1];

	for (int i = 0; i < nsides; i++) {
		verts[i][0] += dir[0];
		verts[i][1] += dir[1];
	}

	draw();
}

/* Check whether the asteroid is out of the screen boundaries */
bool Asteroid::isout() {
	return (center[0] > HGHT || 
	        center[0] < 0    || 
			center[1] < 0    ||
			center[1] > WDTH)
			? true : false;
}





/* Getters & Setters */
int     Asteroid::getnsides()    { return nsides; }
int    *Asteroid::getcenter()    { return center; }
int    *Asteroid::getdirection() { return dir;    }
double  Asteroid::getsize()      { return size;   }
double  Asteroid::getspeed()     { return speed;  }
double  Asteroid::getangvl()     { return angvl;  }


void Asteroid::setnsides(int n)             { nsides = n; }
void Asteroid::setcenter(int cx, int cy)    { center[0] = cx; center[1] = cy; }
void Asteroid::setdirection(int dx, int dy) { dir[0] = dx; dir[1] = dy; }
void Asteroid::setsize(double s)            { size = s;   }
void Asteroid::setspeed(double s)           { speed = s;  }
void Asteroid::setangvl(double av)          { angvl = av; }