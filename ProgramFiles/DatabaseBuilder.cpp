#include "DatabaseBuilder.h"
#include "Person.h"

void DatabaseBuilder::initialiseDatabase(PopArrays arrays, int size) {
	srand(seed);
	int	healthRisk;
	int	jobImportance;
	float rebeliousness;
	bool vaccinated;

	for (int i = 0; i < size; ++i) {
		healthRisk = rand() % 2;
		jobImportance = rand() % 3;
		rebeliousness = (1.0f + rand()%20) / 10;
		Person p = Person(healthRisk, jobImportance, rebeliousness, false, false);

		arrays.addToWorldArray(i, p);
	}

}