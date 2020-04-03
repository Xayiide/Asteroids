#ifndef ASTEROID_H_
#define ASTEROID_H_

#include "constants.h"

#include <vector>  /* vector */





class Asteroid {
	private:
		int    nsides;        /* Number of sides                    */
		int    center[2];     /* Coordinates of the center          */
		int    dir[2];        /* Direction in Cartesian coordinates */
		double size;          /* Size of the Asteroid (radius)      */
		double speed;         /* Speed of the Asteroid              */
		double angvl;         /* Angular velocity                   */

		std::vector<std::vector<int>> verts;

	public:
		Asteroid();
		Asteroid(int, int, int, double);
		void   initialize();  /* Initialize the Asteroid values        */
		double ipspeed();     /* Speed Inversely Proportional to speed */
		void   randdir();     /* Randomize direction of the asteroid   */
		void   randangvl();   /* Randomize angular velocity            */
		void   update();      /* Update asteroid's coordinates         */
		int    auxmov();      /* Calculates movement auxiliary value   */
		void   draw();        /* Draw rectangle using gfx library      */
		void   move();        /* Move the asteroid                     */
		bool   isout();       /* Is the asteroid out of bounds?        */


		/* Getters & Setters */
		int     getnsides();
		int    *getcenter();
		int    *getdirection();
		double  getsize();
		double  getspeed();
		double  getangvl();
	
		void setnsides(int);
		void setcenter(int, int);
		void setdirection(int, int);
		void setsize(double);
		void setspeed(double);
		void setangvl(double);


};



#endif  /* ASTEROID_H_ */