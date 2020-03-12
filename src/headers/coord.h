#ifndef COORD_H_
#define COORD_H_

class Coord {
	private:
		double x, y;
	public:
		Coord();
		Coord(double, double);

		void randomize(int);
		
		/* Getters and Setters */
		double getx();
		double gety();

		void setx(double);
		void sety(double);
};


#endif /* COORD_H_ */