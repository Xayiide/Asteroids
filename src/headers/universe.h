#ifndef UNIVERSE_H_
#define UNIVERSE_H_

#include "asteroid.h"

#include <vector> /* vector */


class Universe {
	private:
		int numAsteroids;
		int radius = 10;
		int x      = 0;
		int y      = 0;
		int sides  = 5;

		std::vector<Asteroid> asteroids;

	public:
		Universe(int);
		void initializeAsteroids();
		void randomizeAsteroid();
		void startEverything();
};

#endif /* UNIVERSE_H_ */