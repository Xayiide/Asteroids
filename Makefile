.PHONY = clean

CC     = gcc
CFLAGS = -g -Wall -Wextra -pedantic -lX11 -lm

CXX      = g++
CXXFLAGS = -g -Wall -Wextra -pedantic -lX11


asteroids: main.cpp gfx.o asteroid.o coord.o
	$(CXX) $(CXXFLAGS) -o $@ $^
	@rm *.o


clean:
	@rm asteroids
