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
	double prob = my_random.next_double();
	if (prob < patientRate)
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
		peopleVille.at(ran)->read();
		people a = *peopleVille.at(ran);
		patient *arriving = new patient(a, prio);
		patients.push(arriving);
	}

	if (!patients.empty()) // Do if there is patients in the queue
	{

		// Check if doctors are free

		for (int j = 0; j < (int)nursesStaff.size(); j++)
		{
			// To get the first from the queue with less than 10 priority
			if ((!patients.empty() && nursesStaff.at(j)->free()) && (patients.front()->getPriority() < 11)) // Had to do a lot of these, because I had trouble refrerring to the front when it was empty
			{
		
				patient* temp = patients.front();
				patients.pop();

				// If there is someone in the dequeue it makes the nurses treat the patient
				patientRecord nurRec = nursesStaff.at(j)->treatPatient(clock, *temp->getPeople(), temp->getPriority());
				// Add the recrod to map
				nurRec.showRecord();
				recordsStorage.insert(std::make_pair(temp->getPeople()->getSurname(), nurRec));
					
	
			}
		}
	}

	if (!patients.empty())
	{
		for (int i = 0; i < (int)doctorsStaff.size(); i++)
		{
			// Similar but checks to priority 20 so, the less ill people get treated by nurses
			
			if (!patients.empty() && doctorsStaff.at(i)->free())
			{
				patient *temp = patients.front();
				patients.pop();
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
		peopleVille.push_back(new people(IN));
	}
	// for surname

	std::ifstream surnameFile;
	surnameFile.open("surnames_of_273ville.txt");
	int n = 0;
	if (nameFile.fail())
	{
		std::cout << "Error opening the file. " << std::endl;
	}
	while (!surnameFile.eof())
	{
		getline(surnameFile, IN);
		peopleVille.at(n)->setSurname(IN);
		n++;
	}
	
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
