#ifndef patientrecord_H_
#define patientrecord_H_
#include "people.h"
#include <vector>
#include <iostream>

class patientRecord
{
private:

	people * patient;
	int severity;
	int time;
	int times;

public:

	// Constructor
	patientRecord() {}

	patientRecord(people &patient, int prio, int clock) : patient(&patient), time(clock), severity(prio) {}

	void showRecord()
	{
		std::cout << patient->read() << std::endl;
		std::cout << "Date: " << time << std::endl;
		std::cout << "Severity: " << severity << std::endl;
	}

};

#endif // !patientrecord_H_
