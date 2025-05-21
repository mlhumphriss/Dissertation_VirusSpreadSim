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

int pop = 100000;

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
	Inputs dataInput;
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
	dataInput.inputEnvironmentSettings(environment);
	population.addStatArrays(environment.getLengthSim());
	dBBuild.initialiseDatabase(population, pop, environment); // Need inputs before this point else group rebel will be using 1.0f on persons no matter what
	cout << environment.getLengthSim() << "\n";
	Simulation mainProgram = Simulation(environment, population, dataOutput);
	int study = mainProgram.studyLoop(environment.getLengthSim());
}
	

	
// Still need Inputs and call simulation from main