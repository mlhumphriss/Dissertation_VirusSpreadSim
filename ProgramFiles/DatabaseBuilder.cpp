#include "DatabaseBuilder.h"
#include "Person.h"

void DatabaseBuilder::initialiseDatabase(PopArrays& arrays, int size, EnvironmentFactors environment) {
	srand(seed);
	int	healthRisk;
	int	jobImportance;
	float rebeliousness;
	bool vaccinated;

	for (int i = 0; i < size; ++i) {
		healthRisk = rand() % 2;
		jobImportance = rand() % 3;
		rebeliousness = (1.0f + (rand()%20)) / 10.0f;
		if (healthRisk == 1) { rebeliousness = rebeliousness * 0.5f; environment.incrementNumHealthRisk(); }
		rebeliousness = rebeliousness * environment.getGroupRebel();

		Person p = Person(healthRisk, jobImportance, rebeliousness, false);

		arrays.addToWorldArray(i, p);
	}

	for (int i = 0; i < size; ++i) {
		Person* p = arrays.getPersonFromWorld(i);
		//std::cout << "jobImportance: " << p->getJobImportance() << std::endl;
	}
}