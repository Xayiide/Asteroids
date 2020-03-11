#ifndef ASTEROID_H_
#define ASTEROID_H_

#include <vector>
#include "coord.h"

class Asteroid {
    private:
        int    xsp, ysp;
        int    rotsp;
        double size;

        int ncoords;
        std::vector<Coord> coords;
        
    public:
        Asteroid();
        Asteroid(int, int, int, double);

        void init();

        void move();
        void rot();
        void draw();
        
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