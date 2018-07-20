#ifndef patientrecord_H_
#define patientrecord_H_
#include "people.h"
#include <vector>
#include <iostream>

class patientRecord
{
private:

	people * patient;
	std::vector<int> severity;
	std::vector<int> time;
	int times;

public:

	// Constructor
	patientRecord() {}

	patientRecord(people &patient, int prio, int clock) : patient(&patient)
	{
		severity.push_back(prio);
		time.push_back(clock);
	}

	void addToRecord(int prio, int clock)
	{
		severity.push_back(prio);
		time.push_back(clock);
	}

	void showRecord()
	{
		std::cout << patient->read() << std::endl;
		std::cout << "Times attended: " << times << std::endl;
		for (int i = 0; i < (int)severity.size(); i++)
		{
			std::cout << i << "th time" << std::endl;
			std::cout << "Date: " << time.at(i) << std::endl;
			std::cout << "Severity: " << severity.at(i) << std::endl;
		}
	}

};

#endif // !patientrecord_H_
