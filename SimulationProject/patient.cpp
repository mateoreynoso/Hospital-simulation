#include "patient.h"

bool patient::operator<(const patient b) const
{
	return priority < b.getPriority();
}

bool patient::operator>(const patient b) const
{
	return priority > b.getPriority();
}

bool patient::operator==(const patient b) const
{
	return priority == b.getPriority();
}
