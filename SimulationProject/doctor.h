#ifndef doctor_h_
#define doctor_h_
#include "hospitalWorker.h"

class doctor : public hospitalWorker
{
public:

	// Constructor
	
	doctor() : hospitalWorker(1, 20) {}

};

#endif // !doctor_h_
