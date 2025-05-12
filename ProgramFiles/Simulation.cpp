#include "Simulation.h"

int Simulation::simInfectionChance() { //Calculates general infection chanceif restrictions of world followed
	infectionChance = 1.0;
	if (environment.getMaskEnforced()) { infectionChance = infectionChance * 0.3; }
	if (environment.getSocialDistancing()) { infectionChance = infectionChance * 0.8; }

	return 0;
}

int Simulation::leaveHouseLoop() {
	peopleOutside = 0;
	numberInfected = 0;

	for (int j = 0; j < environment.getPopulation(); j++) {

	}

	return 0;
}

int Simulation::interactInfectLoop() { //Plan Is will check if infect was today as if is will ignore
	float rulebreakChance;

	for (int k = 0; k < peopleOutside; k++) {
		rulebreakChance = environment.getGroupRebel() * (arrays.getPersonFromOutside(k).getRebel());
	}
	
	return 0;
}

int Simulation::studyLoop(int length) {

	for (int i = 0; i < length; i++) {
		simDay += 1;

	}
	return 0;
}