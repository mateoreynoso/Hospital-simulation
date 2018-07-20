#ifndef simulator_h_
#define simulator_h_
#include "waitingRoom.h"
#include "readInt.h"

myRandom my_random;	// Global variable

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
		int rate = read_int("Please enter the arrival rate of patients (patient/hour): ", 1, 59);
		double patientRate = rate / 60.0;
		// The duration of the simulation
		totalTime = read_int("Please enter the duration of the simulation (hours): ", 1, INT_MAX);
		// The number of doctors and nurses
		int doc = read_int("Please enter the number of doctors: ", 1, INT_MAX);
		int nur = read_int("Please enter the number of nurses: ", 1, INT_MAX);

		// To set up the number of doctors and nurses
		waitingR->addWaitingRoom(doc, nur);
		// To set up the patient rate
		waitingR->setPatientRate(patientRate);
		// Load people
		loadVille();
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
		char op = 'a';
		std::string search;
		while (op != 'x')
		{
			
			std::cout << "Enter your option: " << std::endl;
			std::cout << "1) Show all patients." << std::endl;
			std::cout << "2) Search patient history by name." << std::endl;
			std::cout << "x) Exit the program." << std::endl;
			std::cin >> op;
			switch (op)
			{
			case '1':
			{
				waitingR->records();
				break;
			}
				
			case '2':
			{
				std::cout << "Enter the surname by which you whant yo search the record: " << std::endl;
				std::cin >> search;
				waitingR->serchRecord(search).showRecord();
				break;
			}
				
			case 'x':
				return;
			default:
				break;
			}
		}
		
	}

	void loadVille()
	{
		waitingR->loadPeople();
	}

};

#endif // !simulator_h_

