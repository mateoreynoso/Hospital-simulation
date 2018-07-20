// This file was included from previous homeworks

#ifndef myRANDOM_H_
#define myRANDOM_H_

#include <cstdlib>
#include <ctime>

/** Class to encapsulate the standard random number generator. */
class myRandom {

public:

	/** Initializes the random number generator using the time
	as the seed.
	*/
	myRandom() {
		srand((unsigned int)std::time(0));
	}

	/** Initializes the randon mumber generator using a
	supplied seed.
	*/
	myRandom(int seed) {
		srand(seed);
	}

	/** Returns a random integer in the range 0 – n. */
	int nextInt(int n) {
		return int(next_double() * n);
	}

	/** Return a random double in the range 0 – 1. */
	double next_double() {
		return double(rand()) / RAND_MAX;
	}

};

#endif