#ifndef COORD_H_
#define COORD_H_

class Coord {
	private:
		int x, y;
	public:
		Coord();
		Coord(int, int);

		void randomize(int);
		
		/* Getters and Setters */
		int getx();
		int gety();

		void setx(int);
		void sety(int);
};


#endif /* COORD_H_ */