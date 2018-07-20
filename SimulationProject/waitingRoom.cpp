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
		patient a(peopleVille.at(ran), prio);
		patients.push_back(a);
	}

	if (!patients.empty()) // Do if there is patients in the queue
	{

		// Check if doctors are free

		for (int j = 0; j < (int)nursesStaff.size(); j++)
		{
			// To get the first from the queue with less than 10 priority
			patient *temp;
			if (patients.front().getPriority() < 11)
			{
				temp = &patients.front();
				patients.pop_front();
			}

			else
				temp = NULL;

			// If there is someone in the dequeue it makes the nurses treat the patient
			if (nursesStaff.at(j)->free() && temp != NULL)
			{
				patientRecord nurRec = nursesStaff.at(j)->treatPatient(clock, *temp->getPeople(), temp->getPriority());
				// Add the recrod to map
				recordsStorage.insert(std::make_pair(temp->getPeople()->getSurname(),nurRec));
			}
		}

		for (int i = 0; i < (int)doctorsStaff.size(); i++)
		{
			// Similar but checks to priority 20 so, the less ill people get treated by nurses
			patient *temp;
			temp = NULL;
			if (patients.front().getPriority() > 10)
			{
				temp = &patients.front();
				patients.pop_front();
			}


			// If it finds a patient with high priority, it skips this part. If not it gets someone with less than 10 prio
			else if (patients.front().getPriority() < 10)
			{
				for (int p = 0; p < (int)patients.size(); p++)
				{
					if (patients.at(p).getPriority() > 10)
					{
						temp = &patients.at(p);

						// Tried this did not worked 
						patients.erase(patients.begin()+p);
						// patients.pop_front();
						p = (int)patients.size();
					}
				}
				if (temp != NULL)
				{
					temp = &patients.front();
					patients.pop_front();
				}

			}
			// To make sure its null
			else if (patients.empty())
				temp = NULL;


			if (doctorsStaff.at(i)->free() && temp != NULL)
			{
				patientRecord docRec = doctorsStaff.at(i)->treatPatient(clock, *temp->getPeople(), temp->getPriority());
				// Add record to amp
				recordsStorage.insert(std::make_pair(temp->getPeople()->getSurname(), docRec));
			}
		}
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
	std::queue<std::string> tempName;
	std::queue<std::string> tempSurname;
	// for name
	std::string IN;
	std::ifstream nameFile;
	nameFile.open("residents_of_273ville.txt");
	if (nameFile.fail())
	{
		std::cout << "Error opening the file." << std::endl;
	}
	while (!nameFile.eof())
	{
		getline(nameFile, IN);
		tempName.push(IN);
	}
	// for surname

	std::ifstream surnameFile;
	surnameFile.open("surnames_of_273ville.txt");
	if (nameFile.fail())
	{
		std::cout << "Error opening the file. " << std::endl;
	}
	while (!surnameFile.eof())
	{
		getline(surnameFile, IN);
		tempSurname.push(IN);
	}
	
	// Now make the people object;
	while (!tempName.empty() && !tempSurname.empty())
	{
		peopleVille.push_back(people(tempName.front(), tempSurname.front()));
		tempName.pop();
		tempSurname.pop();
	}

	// Works to here, loads the names

}

void waitingRoom::records()
{

	for (std::map<std::string, patientRecord>::iterator it = recordsStorage.begin();
		it != recordsStorage.end(); it++)
	{

		std::string key = it->first;
		patientRecord value = it->second;
		value.showRecord();

	}
}

patientRecord waitingRoom::serchRecord(std::string surname)
{
	return recordsStorage[surname];
}
