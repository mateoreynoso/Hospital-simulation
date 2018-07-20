#ifndef waitingroom_h_
#define waitingroom_h_
#include <vector>
#include "doctor.h"
#include "nurse.h"
#include "people.h"
#include "random.h"


class waitingRoom
{
private:

	std::vector<doctor*> doctorsStaff;
	std::vector<nurse*> nursesStaff;
	std::vector<people*> patientQueue;
	int patientRate;

public:

	// Constructs the waiting room according to the number of doctors and nurses
	waitingRoom() {}

	void setPatientRate(int rate) { patientRate = rate; }

	void addWaitingRoom(int numDoc, int numNur)
	{
		for (int i = 0; i < numDoc; i++)
		{
			doctorsStaff.push_back(new doctor());

		}

		for (int j = 0; j < numNur; j++)
		{
			nursesStaff.push_back(new nurse());
		}
	}

	void update( int clock )
	{

	}

};

#endif // !waitingroom_h_