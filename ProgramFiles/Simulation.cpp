#include "Simulation.h"

int Simulation::simInfectionChance() { //Calculates general infection chance if restrictions of world followed
	infectionChance = 1.0;
	if (environment.getMaskEnforced()) { infectionChance = infectionChance * 0.3; }
	if (environment.getSocialDistancing()) { infectionChance = infectionChance * 0.8; }

	return 0;
}

void Simulation::initialInfection() {
	for (int i = 0; i < environment.getInitialInfections(); i++) {
		int randInt = rand() % 100;
		if (!arrays.getPersonFromWorld(randInt)->getInfected()) {
			arrays.getPersonFromWorld(randInt)->setInfected(true, 0);
			if (arrays.getPersonFromWorld(randInt)->getInfected()) {
				cout << "Infection happening on initalisation" << "\n";
			}
			totalInfections += 1;
			//cout << randInt << "\n";
			testInt = randInt;
		}
	}
	//cout << "set infections" << "\n";
}

void Simulation::leaveHouseLoop() {  //infected never leave
	peopleOutside = 0;
	numberInfected = 0;
	infectedOutside = 0;
	Person* p;
	float leaveChance;
	int dayVacc = 0;
	auto outside = arrays.getOutsidePop();
	for (int i = 0; i < environment.getPopulation(); i++) {
		outside[i] = nullptr;
	}

	//cout << "b" << "\n";
	for (int j = 0; j < environment.getPopulation(); j++) {
		p = arrays.getPersonFromWorld(j);
		if (environment.getVaccinationRollOut() && !p->getVaccinated() && dayVacc < 5) {
			std::cout << "Vaccine Rollout\n";
			if (numVaccinated <= (environment.getNumHealthRisk() - 5) && p->getHealthRisk() == 1) {
				if ((1.0f + rand() % 10) / 10.0f * p->getRebel() <= 0.5f) {
					p->setVaccinated(true);
					dayVacc += 1;
				}
			}
			else {
				if ((1.0f + rand() % 10) / 10.0f * p->getRebel() <= 0.5f) {
					p->setVaccinated(true);
					dayVacc += 1;
				}
			}
		}

		// Need to adjust infection chance depending on if vacc'd
		p = arrays.getPersonFromWorld(j);

		if (p->getInfected() == true) {
			std::cout << "Infected\n";
			//cout << "infected" << "\n";
			numberInfected += 1;
			if ((simDay - p->getDayInfected()) >= environment.getMinInfectPeriod() && (p->getDayInfected() != -1)) {
				if (rand() % 2 == 1) {
					p->setInfected(false, -1);
				}
			}
			if (p->getAsymptomatic() == true && (simDay - p->getDayInfected()) >= environment.getAsympPeriod()) {
				p->setAsymptomatic(false);
			}
			//For when vaccination rollout is applied  -    data suggested vaccinated period of 2-4 days IQR asym
			if ((simDay - p->getDayInfected()) >= 2 && p->getVaccinated()){
				if (rand() % 2 == 1) {
					p->setInfected(false, -1);
				}
				else if ((simDay - p->getDayInfected()) >= 4) {
					p->setInfected(false, -1);
				}
			}
		}

		//p = arrays.getPersonFromWorld(testInt);
		//if (p.getInfected()) {
		//	//cout << "found" << "\n";
		//}

		if (p->getJobImportance() == 0) {
			//std::cout << "Job Importance\n";
			//cout << "Job Importance 0" << "\n";
			if (p->getInfected() == true && p->getAsymptomatic() == true) {
				arrays.addToOutsideArray(peopleOutside, p, j);
				peopleOutside += 1;
				infectedOutside += 1;
				p->setDaysSinceLeft(0);
				cout << "infected outside" << "\n";
			}
			else if (p->getInfected() && !p->getAsymptomatic() && simDay - p->getDayInfected() > environment.getAsympPeriod() + 3){
				if(((1.0f + rand() % 10) / 10.0f) * p->getRebel() > 1.0f){
					arrays.addToOutsideArray(peopleOutside, p, j);
					peopleOutside += 1;
					infectedOutside += 1;
					p->setDaysSinceLeft(0);
					cout << "infected outside" << "\n";
				}
				else {
					p->setDaysSinceLeft(p->getDaySinceLeft() + 1);
				}
			}
			else {
				arrays.addToOutsideArray(peopleOutside, p, j);
				peopleOutside += 1;
				p->setDaysSinceLeft(0);
			}
		}
		
		else if (environment.getLockdown() && p->getJobImportance() != 0 /** || p.getJobImportance() == 2/**/) {
			std::cout << "Lockdown\n";
			leaveChance = (0.1f * p->getDaySinceLeft()) + (rand() % 10)/10.0f ;  //increase with days since left, * by rebel
			if (p->getHealthRisk() == 1) { leaveChance = leaveChance * 0.5f; }

			if (p->getInfected() && !p->getAsymptomatic() && simDay - p->getDayInfected() > environment.getAsympPeriod() + 3) {
				leaveChance = leaveChance * 0.5 * p->getRebel();
				if (leaveChance > 1.0f) {
					arrays.addToOutsideArray(peopleOutside, p, j);
					peopleOutside += 1;
					infectedOutside += 1;
					p->setDaysSinceLeft(0);
					//cout << "infected outside" << "\n";
				}
				else {
					p->setDaysSinceLeft(p->getDaySinceLeft() + 1);
				}
			}
			else if (leaveChance * p->getRebel() > 1.0f) {
				arrays.addToOutsideArray(peopleOutside, p, j);
				p->setDaysSinceLeft(0);
				if (p->getInfected() == true && p->getAsymptomatic() == true) {
					peopleOutside += 1;
					infectedOutside += 1;
					//cout << "infected outside" << "\n";
				}
			}
		}

		else {
			//cout << "normal people" << "\n";
			if (p->getInfected() == true && p->getAsymptomatic() == true) {
				//std::cout << "Asymptomatic\n";
				arrays.addToOutsideArray(peopleOutside, p, j);
				peopleOutside += 1;
				infectedOutside += 1;
				p->setDaysSinceLeft(0);
				cout << "infected outside" << "\n";
			}
			else if (p->getInfected() && !p->getAsymptomatic() && simDay - p->getDayInfected() > environment.getAsympPeriod() + 3) {
				//std::cout << "Recovering\n";
				if (((1.0f + rand() % 10) / 10.0f) * p->getRebel() > 1.0f) {
					arrays.addToOutsideArray(peopleOutside, p, j);
					peopleOutside += 1;
					infectedOutside += 1;
					p->setDaysSinceLeft(0);
				}
				else {
					p->setDaysSinceLeft(p->getDaySinceLeft() + 1);
				}
			}
			else {
				//std::cout << "Other\n";
				arrays.addToOutsideArray(peopleOutside, p, j);
				peopleOutside += 1;
				p->setDaysSinceLeft(0);
			}
		}
	}
	std::cout << "People outside: " << peopleOutside << std::endl;
	std::cout << "People infected: " << numberInfected << std::endl;
	std::cout << "Infected iutside: " << infectedOutside << std::endl;
}

void Simulation::interactInfectLoop() {
	Person* p;
	int worldRef;
	//cout << "c" << "\n";
	for (int k = 0; k < environment.getPopulation(); k++) {
		p = arrays.getPersonFromOutside(k);
		if (p == nullptr) { 
			cout << "nullptr removed at addr: " << p << "\n";
			continue; }

		if (p->getInfected()) {
			cout << k << ": Infected ignored at addr: " << p << "\n";
			continue;
		}
		if (environment.getLockdown() && p->getJobImportance() != 0) {
			for (int x = 0; x < (avgPeopleInteractions / 2); x++) {
				if ((rand() % peopleOutside) < infectedOutside) {
					if (((1.0f + (rand() % 10)) / 10.0f) * infectionChance * p->getRebel() >= 0.5f) { // need data based infection chance between 0 and 1
						worldRef = p->getWorldArrayref();
						p->setInfected(true, simDay);
						totalInfections += 1;
						continue;
					}
				}
			}
		}
		else {
			//cout <<"Average People Interactions: "<< avgPeopleInteractions << "\n";
			for (int x = 0; x < avgPeopleInteractions; x++) {
				//cout << "Average People Interactions: " << infectedOutside << "\n";
				//char g = '\0';
				//while (g != '\n') {
				//	cin >> g;
				//}
				if ((rand() % peopleOutside) < infectedOutside) {
					cout << "Maybe Infect\n";
					if (((1.0f + (rand() % 10)) / 10.0f) * infectionChance * p->getRebel() >= 0.2f) { // need data based infection chance between 0 and 1
						worldRef = p->getWorldArrayref();
						p->setInfected(true, simDay);
						totalInfections += 1;
						continue;
					}
				}
			}
		}
	}
}

int Simulation::studyLoop(int length) {
	srand(time(0));
	simInfectionChance();
	totalInfections = 0;
	initialInfection();
	simDay = 0;
	arrays.addToInfectedArray(simDay, environment.getInitialInfections());
	arrays.addToTotalInfectArray(simDay, totalInfections);

	//cout << "test int infected before loops"<< arrays.getPersonFromWorld(testInt).getInfected() << "\n";

	//if (arrays.getPersonFromWorld(testInt).getInfected()) {
	//	//cout << "test int infected before loops" << "\n";
	//}

	for (int i = 0; i < length; i++) {
		//cout << "A" << "\n";
		simDay += 1;
		leaveHouseLoop();
		arrays.addToInfectedArray(simDay, numberInfected);
		arrays.addToTotalInfectArray(simDay, totalInfections);
		interactInfectLoop();
	}

	int save = output.writeTestResultsFile(environment, arrays, simDay);
	if (save == 0) {
		cout << "Results Saved to File" << "\n";
	}

	return 0;
}