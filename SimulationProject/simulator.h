#ifndef simulator_h_
#define simulator_h_
#include "waitingRoom.h"
#include "readInt.h"

class simulator
{
private:
	
	int totalTime;
	int clock;
	waitingRoom * waitingR;


public:

	simulator()
	{
		waitingR = new waitingRoom();
	}

	void userInput()
	{
		// The user input for the rate of patients
		int rate = read_int("Please enter the arrival rate of patients: (patient/hour)", 1, 59);
		double patientRate = rate / 60.0;
		// The duration of the simulation
		totalTime = read_int("Please enter the duration of the simulation (hours): ", 1, INT_MAX);
		// The number of doctors and nurses
		int doc = read_int("Please enter the number of doctors: ", 1, INT_MAX);
		int nur = read_int("Please enter the number of nurses: ", 1, INT_MAX);

		// To write the set up
		// To set up the number of doctors and nurses
		waitingR->addWaitingRoom(doc, nur);
	}

	void runSimulation()
	{
		for (clock = 0; clock < totalTime; clock++)
		{
			waitingR->update(clock);
		}
	}

	void showStats()
	{

	}

	void loadVille()
	{
		waitingR->loadPeople();
	}

};

#endif // !simulator_h_

