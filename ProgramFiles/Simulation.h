#pragma once
#include <iostream>
#include <vector>
#include <ctime>
#include "EnvironmentFactors.h"
#include "PopArrays.h"
#include "Person.h"

class Simulation {
public:
	Simulation(EnvironmentFactors e, PopArrays a){
		environment = e;
		arrays = a;
		simDay = 0;
		peopleOutside = 0;
		numberInfected = 0;
		infectionChance = 1.0f;
	};

	int simInfectionChance();
	int studyLoop(int length);
	int leaveHouseLoop();
	int interactInfectLoop();

	int getSimDay() { return simDay; }
	int getPeopleOutside() { return peopleOutside; }
	void setSimDay(int sD) { simDay = sD; }
	void setPeopleOutside(int pO) { peopleOutside = pO; }

protected:
	EnvironmentFactors environment;
	PopArrays	arrays;
	
	int		simDay;
	int		peopleOutside;
	int		numberInfected;
	float	infectionChance;

};