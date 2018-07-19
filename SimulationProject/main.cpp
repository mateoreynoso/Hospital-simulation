//////////////////////////
// Mateo Reynoso
// Data Structures Project
// Hospital Simulation
// 2018/07/19
///////////////////////////

#include <iostream>
#include "simulator.h"
using namespace std;

int main()
{
	simulator hospital;

	hospital.userInput();
	hospital.runSimulation();
	hospital.showStats();

	return 0;
}