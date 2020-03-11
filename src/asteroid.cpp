#include "headers/asteroid.h"
#include "headers/gfx.h"

#include <stdlib.h> /* random */
#include <vector>


Asteroid::Asteroid() {
    xsp   = 0;
    ysp   = 0;
    rotsp = 0;
    size  = 300;
    init();
}

Asteroid::Asteroid(int x, int y, int r, double s) :
                                        xsp(x), ysp(y), rotsp(r), size(s) {
        init();
     }



void Asteroid::init() {
    /* Make ncoords a random number between 3 and 4 */
    ncoords = 3 + (rand() % static_cast<int>(4 - 3 + 1)); 

    /* Cambia el tamaño del vector a ncoords elementos */
    coords.resize(ncoords);
    
    /* Inicializa a valores aleatorios cada Coord */
    for (auto &c : coords)
        c.randomize(size);
}

void Asteroid::move() {
    return;
}

void Asteroid::rot() {
    return;
}

void Asteroid::draw() {
    int i;
    for (i = 0; i < ncoords; i++) {
        gfx_line(coords[i].getx(), coords[i].gety(),
                 coords[(i+1)%ncoords].getx(), coords[(i+1)%ncoords].gety());
    }
}


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                          Getters and Setters                          */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

int Asteroid::getxsp() { return xsp; }

int Asteroid::getysp() { return ysp; }

int Asteroid::getrotsp() { return rotsp; }

double Asteroid::getsize() { return size; }


void Asteroid::setxsp(int sp) { this->xsp = sp; }

void Asteroid::setysp(int sp) { this->ysp = sp; }

void Asteroid::setrotsp(int sp) { this->rotsp = sp; }

void Asteroid::setsize(double size) { this->size = size; }