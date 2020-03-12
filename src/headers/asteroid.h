#ifndef ASTEROID_H_
#define ASTEROID_H_

#include <vector>
#include "coord.h"

class Asteroid {
	private:
		int    xsp, ysp;
		int    rotsp;
		double size;


		int fr;
		int ncoords;
		std::vector<Coord> coords;
		
	public:
		Asteroid();
		Asteroid(int fr);
		Asteroid(int, int, int, double, int);

		void init();
		void rndst(); /* Randomize stats */

		void move();
		void rot();
		void draw();
		bool isout(int, int);
		
		/* Getters and Setters */
		int    getxsp();
		int    getysp();
		int    getrotsp();
		double getsize();

		void setxsp(int);
		void setysp(int);
		void setrotsp(int);
		void setsize(double);

};


#endif /* ASTEROID_H_*/