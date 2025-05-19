#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include "Person.h"
#include "PopArrays.h"
#include "DataRW.h"
#include "DatabaseBuilder.h"
#include "EnvironmentFactors.h"
#include "Inputs.h"
#include "Simulation.h"

using namespace std;

int pop = 100;

/**bool initialisation() {
	PopArrays population = PopArrays(pop);
	DataRW dataOutput;
	DatabaseBuilder DBBuild = DatabaseBuilder(pop);
	EnvironmentFactors environment = EnvironmentFactors(pop);

	return true;
}*/

int main() {
	time_t seedTime = time(0); //Setting time for programs random number for sim
	PopArrays population = PopArrays(pop);
	DataRW dataOutput;
	DatabaseBuilder dBBuild = DatabaseBuilder(pop);
	EnvironmentFactors environment = EnvironmentFactors(pop);
	/**if (!initialisation()) {
		cout << "Class Initialisation Failed" << "\n";
		return -1;
	}*/
	ifstream file(dataOutput.getTestDataFile());
	if (!file) {
		dBBuild.createNewSeed(pop, dataOutput);
	}
	dBBuild.loadOldSeed(pop, dataOutput);
	dBBuild.initialiseDatabase(population, pop, environment);
	cout << population.getPersonFromWorld(7).getRebel() << "\n";
}
	

	
