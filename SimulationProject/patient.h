#ifndef  patient_H_
#define patient_H_
#include "people.h"

class patient
{
private:

	people * subject;
	int priority;

public:

	// Constructor
	patient(people *_in, int prio) : priority(prio) { subject = _in; }

	int getPriority() const { return priority; }
	people* getPeople() const { return subject; }

	// Originally I was going to use priority queue, then realized it was not very helpful
	bool operator<( const patient b) const;
	bool operator>(const patient b) const;
	bool operator==(const patient b) const;

};

#endif // ! patient_H_
