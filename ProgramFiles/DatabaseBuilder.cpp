#include "DatabaseBuilder.h"


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

		arrays.addToWorldArray(i, (Person(healthRisk, jobImportance, rebeliousness, false, false)));
		
	}
}