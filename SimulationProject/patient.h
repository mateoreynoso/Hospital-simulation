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
	patient(people &_in, int prio) : priority(prio) { subject = &_in; }

	int getPriority() const { return priority; }

	bool operator<( const patient b) const;
	bool operator>(const patient b) const;
	bool operator==(const patient b) const;

};

#endif // ! patient_H_
