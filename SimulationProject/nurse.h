#ifndef nurse_h_
#define nurese_h_
#include "hospitalWorker.h"


class nurse : public hospitalWorker
{
public:

	// Constructor

	nurse() : hospitalWorker(1, 10) {}

};

#endif // !nurse_h_
