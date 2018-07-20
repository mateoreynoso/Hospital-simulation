#ifndef hospitalWorker_h_
#define hospitalWorker_h_
#include "people.h"
#include "myRandom.h"

extern myRandom my_random;

class hospitalWorker
{
private:

	int minTreatment;
	int maxTreatment;
	int startTreatment;
	int treatment;
	people * patient;

public:

	// Constructor

	hospitalWorker(int min, int max) : minTreatment(min), maxTreatment(max), patient(NULL), startTreatment(NULL), treatment(NULL) {}

	// Free, checks if its free
	bool free()
	{
		if (patient == NULL)
			return true;
		else
			return false;
	}

	void treatPatient(int clock, people &_patient)
	{
		patient = &_patient;
		startTreatment = clock;
		treatment = my_random.nextInt(maxTreatment-minTreatment)+minTreatment;
	
		// To add the record
	}

	void updateW(int clock)
	{
		if (clock - startTreatment == treatment)
			patient = NULL;
	}
};


#endif // !hospitalWorker_H_
