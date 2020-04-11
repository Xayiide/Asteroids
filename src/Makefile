.PHONY = clean

CC     = gcc
CFLAGS = -g -Wall -Wextra -pedantic -lX11 -lm

CXX      = g++
CXXFLAGS = -g -Wall -Wextra -pedantic -lX11


asteroids: main.cpp gfx.o asteroids.o universe.o
	$(CXX) $(CXXFLAGS) -o $@ $^
	@rm *.o


clean:
	@rm asteroids
