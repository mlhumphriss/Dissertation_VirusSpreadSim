#pragma once
#include <iostream>
#include <vector>
#include <ctime>
#include "EnvironmentFactors.h"
#include "PopArrays.h"
#include "Person.h"

class Simulation {
public:
	Simulation(){};


	int studyLoop(int length);
	int leaveHouseLoop();
	int interactInfectLoop();

	int getSimDay() { return simDay; }
	int getPeopleOutside() { return peopleOutside; }
	void setSimDay(int sD) { simDay = sD; }
	void setPeopleOutside(int pO) { peopleOutside = pO; }

protected:
	int		simDay;
	int		peopleOutside;
	EnvironmentFactors environment;
};