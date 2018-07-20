#ifndef waitingroom_h_
#define waitingroom_h_
#include <iostream>
#include <vector>
#include <fstream>
#include <deque>
#include <queue>
#include <map>
#include <utility>
#include "doctor.h"
#include "nurse.h"
#include "people.h"
#include "myRandom.h"
#include "patient.h"

extern myRandom my_random;

class waitingRoom
{
private:

	std::vector<doctor*> doctorsStaff;
	std::vector<nurse*> nursesStaff;
	std::vector<people> peopleVille;
	std::deque<patient> patients;
	std::map<std::string, patientRecord> recordsStorage;
	double patientRate;

public:

	// Constructs the waiting room according to the number of doctors and nurses
	waitingRoom() {}

	void setPatientRate(double rate) { patientRate = rate; }

	// Adds the correct amount of doctors and nurses according to the input of the user
	void addWaitingRoom(int numDoc, int numNur);

	void update(int clock);

	// Loads people from CS273Ville
	void loadPeople();

	// Show all the records
	void records();

	// Search record
	patientRecord serchRecord(std::string surname);
};

#endif // !waitingroom_h_