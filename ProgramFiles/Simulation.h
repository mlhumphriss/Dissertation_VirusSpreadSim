#pragma once
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "EnvironmentFactors.h"
#include "PopArrays.h"
#include "Person.h"
#include "DataRW.h"


class Simulation {
public:
	Simulation(EnvironmentFactors e, PopArrays& a, DataRW output){
		environment = e;
		arrays = a;
		simDay = 0;
		peopleOutside = 0;
		numberInfected = 0;
		infectedOutside = 0;
		infectionChance = 1.0f;
		avgPeopleInteractions = 17;
		numVaccinated = 0;
		totalVacc = 0;
		dayVaccFin = 0;
	};

	int simInfectionChance();
	int studyLoop(int length);
	void leaveHouseLoop();
	void interactInfectLoop();
	void initialInfection();
	

	int getSimDay() { return simDay; }
	int getPeopleOutside() { return peopleOutside; }
	int getNumVaccinated() { return numVaccinated; }
	void setSimDay(int sD) { simDay = sD; }
	void setPeopleOutside(int pO) { peopleOutside = pO; }
	void setNumVaccinated(int nV) { numVaccinated = nV; }

protected:
	EnvironmentFactors environment;
	PopArrays	arrays;
	DataRW	output;
	
	int		simDay;
	int		peopleOutside;
	int		numberInfected;
	int		infectedOutside;
	int		numVaccinated;
	int		totalInfections;
	int		totalVacc;
	int		dayVaccFin;

	int		testInt;

	int		avgPeopleInteractions;
	float	infectionChance;

};