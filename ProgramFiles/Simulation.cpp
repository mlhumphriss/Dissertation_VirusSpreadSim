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
	infectedOutside = 0;
	Person p;
	float leaveChance;

	for (int j = 0; j < environment.getPopulation(); j++) {

		if (arrays.getPersonFromWorld(j).getInfected() == true) {
			numberInfected += 1;
			if ((simDay - arrays.getPersonFromWorld(j).getDayInfected()) >= environment.getMinInfectPeriod() && (arrays.getPersonFromWorld(j).getDayInfected()!= -1)) {
				if (rand() % 2 == 1) {
					arrays.getPersonFromWorld(j).setInfected(false, -1);
				}
			}
			if (arrays.getPersonFromWorld(j).getAsymptomatic() == true && (simDay - arrays.getPersonFromWorld(j).getDayInfected()) >= environment.getAsympPeriod()) {
				arrays.getPersonFromWorld(j).setAsymptomatic(false);
			}
		}

		p = arrays.getPersonFromWorld(j);

		if (p.getJobImportance() == 0) {
			if (p.getInfected() == true && p.getAsymptomatic() == true) {
				arrays.addToOutsideArray(peopleOutside, p, j);
				peopleOutside += 1;
				infectedOutside += 1;
			}
			else if (p.getInfected() && !p.getAsymptomatic() && simDay-p.getDayInfected()> environment.getAsympPeriod()+3){
				if(((1.0f + rand() % 10) / 10) * p.getRebel() > 1.0f){
					arrays.addToOutsideArray(peopleOutside, p, j);
					peopleOutside += 1;
					infectedOutside += 1;
				}
				else {
					continue;
				}
			}
			else {
				arrays.addToOutsideArray(peopleOutside, p, j);
				peopleOutside += 1;
			}
			continue;
		}
		
		if (environment.getLockdown() && p.getJobImportance() != 0) {
			leaveChance = 1.0f;  //increase with days since left, * by rebel
		}
	}

	return 0;
}

int Simulation::interactInfectLoop() { //Plan Is will check if infect was today as if is will ignore


	for (int k = 0; k < peopleOutside; k++) {
		
	}
	
	return 0;
}

int Simulation::studyLoop(int length) {

	for (int i = 0; i < length; i++) {
		simDay += 1;

	}
	return 0;
}