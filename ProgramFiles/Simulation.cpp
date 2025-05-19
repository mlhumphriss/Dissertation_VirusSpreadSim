#include "Simulation.h"

int Simulation::simInfectionChance() { //Calculates general infection chance if restrictions of world followed
	infectionChance = 1.0;
	if (environment.getMaskEnforced()) { infectionChance = infectionChance * 0.3; }
	if (environment.getSocialDistancing()) { infectionChance = infectionChance * 0.8; }

	return 0;
}

void Simulation::initialInfection() {
	for (int i = 0; i < 5; i++) {
		int randInt = rand() % 100;
		if (!arrays.getPersonFromWorld(randInt).getInfected()) {
			arrays.getPersonFromWorld(randInt).setInfected(true, 0);
			totalInfections += 1;
		}
	}
}

int Simulation::leaveHouseLoop() {
	peopleOutside = 0;
	numberInfected = 0;
	infectedOutside = 0;
	Person p;
	float leaveChance;
	int dayVacc = 0;

	for (int j = 0; j < environment.getPopulation(); j++) {

		if (environment.getVaccinationRollOut() && !arrays.getPersonFromWorld(j).getVaccinated() && dayVacc < 5) {
			if (numVaccinated <= (environment.getNumHealthRisk() - 5) && arrays.getPersonFromWorld(j).getHealthRisk() == 1) {
				if ((1.0f + rand() % 10) / 10 * arrays.getPersonFromWorld(j).getRebel() <= 0.5f) {
					arrays.getPersonFromWorld(j).setVaccinated(true);
					dayVacc += 1;
				}
			}
			else {
				if ((1.0f + rand() % 10) / 10 * arrays.getPersonFromWorld(j).getRebel() <= 0.5f) {
					arrays.getPersonFromWorld(j).setVaccinated(true);
					dayVacc += 1;
				}
			}
		}

		// Need to adjust infection chance depending on if vacc'd

		if (arrays.getPersonFromWorld(j).getInfected() == true) {
			numberInfected += 1;
			if ((simDay - arrays.getPersonFromWorld(j).getDayInfected()) >= environment.getMinInfectPeriod() && (arrays.getPersonFromWorld(j).getDayInfected() != -1)) {
				if (rand() % 2 == 1) {
					arrays.getPersonFromWorld(j).setInfected(false, -1);
				}
			}
			if (arrays.getPersonFromWorld(j).getAsymptomatic() == true && (simDay - arrays.getPersonFromWorld(j).getDayInfected()) >= environment.getAsympPeriod()) {
				arrays.getPersonFromWorld(j).setAsymptomatic(false);
			}
			//For when vaccination rollout is applied  -    data suggested vaccinated period of 2-4 days IQR asym
			if ((simDay - arrays.getPersonFromWorld(j).getDayInfected()) >= 2 && arrays.getPersonFromWorld(j).getVaccinated()){
				if (rand() % 2 == 1) {
					arrays.getPersonFromWorld(j).setInfected(false, -1);
				}
				else if ((simDay - arrays.getPersonFromWorld(j).getDayInfected()) >= 4) {
					arrays.getPersonFromWorld(j).setInfected(false, -1);
				}
			}
		}

		p = arrays.getPersonFromWorld(j);

		if (p.getJobImportance() == 0) {
			if (p.getInfected() == true && p.getAsymptomatic() == true) {
				arrays.addToOutsideArray(peopleOutside, p, j);
				peopleOutside += 1;
				infectedOutside += 1;
				arrays.getPersonFromWorld(j).setDaysSinceLeft(0);
			}
			else if (p.getInfected() && !p.getAsymptomatic() && simDay - p.getDayInfected() > environment.getAsympPeriod() + 3){
				if(((1.0f + rand() % 10) / 10) * p.getRebel() > 1.0f){
					arrays.addToOutsideArray(peopleOutside, p, j);
					peopleOutside += 1;
					infectedOutside += 1;
					arrays.getPersonFromWorld(j).setDaysSinceLeft(0);
				}
				else {
					arrays.getPersonFromWorld(j).setDaysSinceLeft(arrays.getPersonFromWorld(j).getDaySinceLeft() + 1);
				}
			}
			else {
				arrays.addToOutsideArray(peopleOutside, p, j);
				peopleOutside += 1;
				arrays.getPersonFromWorld(j).setDaysSinceLeft(0);
			}
		}
		
		else if (environment.getLockdown() && p.getJobImportance() != 0 || p.getJobImportance() == 2) {
			leaveChance = (0.1f * p.getDaySinceLeft()) + (rand() % 10)/10 ;  //increase with days since left, * by rebel
			if (p.getHealthRisk() == 1) { leaveChance = leaveChance * 0.5f; }

			if (p.getInfected() && !p.getAsymptomatic() && simDay - p.getDayInfected() > environment.getAsympPeriod() + 3) {
				leaveChance = leaveChance * 0.5 * p.getRebel();
				if (leaveChance > 1.0f) {
					arrays.addToOutsideArray(peopleOutside, p, j);
					peopleOutside += 1;
					infectedOutside += 1;
					arrays.getPersonFromWorld(j).setDaysSinceLeft(0);
				}
				else {
					arrays.getPersonFromWorld(j).setDaysSinceLeft(arrays.getPersonFromWorld(j).getDaySinceLeft() + 1);
				}
			}
			else if (leaveChance * p.getRebel() > 1.0f) {
				arrays.addToOutsideArray(peopleOutside, p, j);
				arrays.getPersonFromWorld(j).setDaysSinceLeft(0);
				if (p.getInfected() == true && p.getAsymptomatic() == true) {
					peopleOutside += 1;
					infectedOutside += 1;
				}
			}
		}

		else {
			if (p.getInfected() == true && p.getAsymptomatic() == true) {
				arrays.addToOutsideArray(peopleOutside, p, j);
				peopleOutside += 1;
				infectedOutside += 1;
				arrays.getPersonFromWorld(j).setDaysSinceLeft(0);
			}
			else if (p.getInfected() && !p.getAsymptomatic() && simDay - p.getDayInfected() > environment.getAsympPeriod() + 3) {
				if (((1.0f + rand() % 10) / 10) * p.getRebel() > 1.0f) {
					arrays.addToOutsideArray(peopleOutside, p, j);
					peopleOutside += 1;
					infectedOutside += 1;
					arrays.getPersonFromWorld(j).setDaysSinceLeft(0);
				}
				else {
					arrays.getPersonFromWorld(j).setDaysSinceLeft(arrays.getPersonFromWorld(j).getDaySinceLeft() + 1);
				}
			}
			else {
				arrays.addToOutsideArray(peopleOutside, p, j);
				peopleOutside += 1;
				arrays.getPersonFromWorld(j).setDaysSinceLeft(0);
			}
		}
	}

	return 0;
}

int Simulation::interactInfectLoop() {
	Person p;
	int worldRef;

	for (int k = 0; k < peopleOutside; k++) {
		p = arrays.getPersonFromOutside(k);

		if (p.getInfected()) {
			continue;
		}
		if (environment.getLockdown() && p.getJobImportance() != 0) {
			for (int x = 0; x < (avgPeopleInteractions / 2); x++) {
				if ((rand() % peopleOutside) < infectedOutside) {
					if (((1.0f + (rand() % 10)) / 10) * infectionChance * p.getRebel() >= 0.5f) { // need data based infection chance between 0 and 1
						worldRef = p.getWorldArrayref();
						arrays.getPersonFromWorld(worldRef).setInfected(true, simDay);
						totalInfections += 1;
						continue;
					}
				}
			}
		}
		else {
			for (int x = 0; x < avgPeopleInteractions; x++) {
				if ((rand() % peopleOutside) < infectedOutside) {
					if (((1.0f + (rand() % 10)) / 10) * infectionChance * p.getRebel() >= 0.6f) { // need data based infection chance between 0 and 1
						worldRef = p.getWorldArrayref();
						arrays.getPersonFromWorld(worldRef).setInfected(true, simDay);
						totalInfections += 1;
						continue;
					}
				}
			}
		}

	}
	
	return 0;
}

int Simulation::studyLoop(int length) {
	srand(time(0));
	simInfectionChance();
	totalInfections = 0;
	initialInfection();



	for (int i = 0; i < length; i++) {
		simDay += 1;

		leaveHouseLoop();

		interactInfectLoop();

//need to put infections into buffer for output, also work out vaccinations

	}
	return 0;
}