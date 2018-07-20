#include "waitingRoom.h"

void waitingRoom::addWaitingRoom(int numDoc, int numNur)
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

void waitingRoom::update(int clock)
{
	// According to rate check if new patient arrives

	if (my_random.next_double() < patientRate)
	{
		double type = my_random.next_double();
		int ran = my_random.nextInt(peopleVille.size());
		int prio;
		if (0.0 < type && type < 0.7)
		{
			prio = my_random.nextInt(9) + 1;
		}
		else if (0.7 < type && type < 0.9)
		{
			prio = my_random.nextInt(4) + 11;
		}
		else if (0.9 < type && type < 1.0)
		{
			prio = my_random.nextInt(20) + 16;
		}
		else
			std::cout << "Something bad happend :c " << std::endl;
		patient a(*peopleVille.at(ran), prio);
		patients.push(a);
	}

	// Check if doctors are free

	for (int j = 0; j < (int)nursesStaff.size(); j++)
	{
		if (nursesStaff.at(j)->free())
			nursesStaff.at(j)->treatPatient(clock, /* add priority patient*/);
	}

	for (int i = 0; i < (int)doctorsStaff.size(); i++)
	{
		if (doctorsStaff.at(i)->free() )
			doctorsStaff.at(i)->treatPatient( clock, /* add priority patient*/);
	}

	// Update doctors

	for (int j = 0; j < (int)nursesStaff.size(); j++)
	{
		if (nursesStaff.at(j)->free())
			nursesStaff.at(j)->updateW(clock);
	}

	for (int i = 0; i < (int)doctorsStaff.size(); i++)
	{
		if (doctorsStaff.at(i)->free())
			doctorsStaff.at(i)->updateW(clock);
	}

}

void waitingRoom::loadPeople()
{
	std::vector<std::string> tempName;
	std::vector<std::string> tempSurname;
	// for name
	std::string IN;
	std::ifstream nameFile;
	nameFile.open("residents_of_273ville.txt");
	while (!nameFile.eof())
	{
		getline(nameFile, IN);
		tempName.push_back(IN);
	}
	// for surname
	std::ifstream surnameFile;
	surnameFile.open("surnames_of_273ville.txt");
	while (!surnameFile.eof())
	{
		getline(surnameFile, IN);
		tempSurname.push_back(IN);
	}

	// Now make the people object;
	for (int i = 0; i < (int)tempName.size(); i++)
	{
		peopleVille.push_back(new people(tempName.at(i), tempSurname.at(i)));
	}

}

void waitingRoom::records()
{
}
