#ifndef ASTEROID_H_
#define ASTEROID_H_

#include <vector>
#include "coord.h"

class Asteroid {
	private:
		double xsp, ysp;
		double rotsp;
		int size;


		int fr;
		int ncoords;
		std::vector<Coord> coords;
		
	public:
		Asteroid();
		Asteroid(int);

		void init();
		void rndstats();
		void rndcoords();

		void move();
		void rot();
		void draw();
		bool isout(int, int);
		
		/* Getters and Setters */
		double getxsp();
		double getysp();
		double getrotsp();
		int    getsize();

		void setxsp(double);
		void setysp(double);
		void setrotsp(double);
		void setsize(int);

};


#endif /* ASTEROID_H_*/