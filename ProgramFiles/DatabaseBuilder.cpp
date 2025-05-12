#include "DatabaseBuilder.h"
#include "Person.h"

void DatabaseBuilder::initialiseDatabase(PopArrays arrays, int size, EnvironmentFactors environment) {
	srand(seed);
	int	healthRisk;
	int	jobImportance;
	float rebeliousness;
	bool vaccinated;

	for (int i = 0; i < size; ++i) {
		healthRisk = rand() % 2;
		jobImportance = rand() % 3;
		rebeliousness = (1.0f + rand()%15) / 10;
		if (healthRisk == 1) { rebeliousness = rebeliousness * 0.5; }
		rebeliousness = rebeliousness * environment.getGroupRebel();

		Person p = Person(healthRisk, jobImportance, rebeliousness, false);

		arrays.addToWorldArray(i, p);
	}

}