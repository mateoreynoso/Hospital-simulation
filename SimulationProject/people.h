#ifndef people_h_
#define people_h_
#include <string>


class people
{
private:

	std::string name;
	std::string surname;

public:

	// Constructror
	people(std::string name) : name(name) {}
	people(std::string name, std::string surname) : name(name), surname(surname) {}

	// Getters

	std::string getName() { return name; }
	std::string getSurname() { return surname; }

	//Set
	void setSurname(std::string _sur) { surname = _sur; }

	// For cout

	std::string read()
	{
		return "Patient: " + getSurname() + ", " + getName();
	}

};

#endif // !people_h_
