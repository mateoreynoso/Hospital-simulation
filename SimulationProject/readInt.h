// This code was added from previous excercises
#pragma once
#include <iostream>
#include <string>

int read_int(const std::string &prompt, int low, int high)
{
	if (low >= high) // invalid range
		throw std::invalid_argument("invalid range specified");

	std::cin.exceptions(std::ios_base::failbit);
	int num = 0;
	while (true) {
		try {
			while (true) {
				std::cout << prompt;
				std::cin >> num;
				if (num >= low && num <= high) { // within the specified range
					std::cout << std::endl;
					return num;
				}
			}
		}
		catch (std::ios_base::failure) {
			std::cout << "Bad numeric string -- try again\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<int>::max(), '\n');
		}
	}
}