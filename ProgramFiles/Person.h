#pragma once
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

class Person {
public:

	Person() {
		rebeliousness = 1.0f;
	}
	Person(int hR, int jI, float rebel, bool vac) {
		healthRisk = hR;
		jobImportance = jI;
		rebeliousness = rebel;
		asymptomatic = false;
		dayInfected = NULL;
		timesInfected = 0;
		infected = false;
		vaccinated = vac;
		daysSinceLeft = 0;
		worldArrayReference = 0;
	};

	~Person() {}

	void infectionUpdate(int minIP, int asymP, int day) {
		int infectPeriod = day - dayInfected;
		if (infectPeriod > asymP && asymptomatic == true) {
			asymptomatic = false;
		}
		if (infectPeriod > minIP && (rand()% 2)>0) {
			infected = false;
		}
	}


	void setInfected(bool i, int d) {
		//cout << "Infection called" << "\n";
		if (infected == true) {
			infected = i;
			dayInfected = d;
			return;
		}
		else {
			//cout << "Infection added" << "\n";
			infected = i;
			//cout << infected << "\n";
			if (infected == true) {
				asymptomatic = true;
				dayInfected = d; //Fixes issues from before, but still overcomplicates infected. No longer a simple setter
				daysInfected.push_back(d);
			}
			return;
		}
	}

	void	setDaysSinceLeft(int d) { daysSinceLeft = d; }
	void	setAsymptomatic(bool a) { asymptomatic = a; }
	void	setVaccinated(bool v) { vaccinated = v; }
	void	setWorldArrayRef(int r) { worldArrayReference = r; }

	int		getDayInfected() { return dayInfected; }
	int		getTimesInfected() { return timesInfected; }
	int		getDaySinceLeft() { return daysSinceLeft; }
	bool	getInfected() { return infected; }
	bool	getAsymptomatic() { return asymptomatic; }
	bool	getVaccinated() { return vaccinated; }
	float	getRebel() { return rebeliousness; }
	int		getHealthRisk() { return healthRisk; }
	int		getJobImportance() { return jobImportance; }
	int		getWorldArrayref() { return worldArrayReference; }

protected:
	bool	asymptomatic;
	bool	infected;
	int		dayInfected;
	int		timesInfected;
	vector<int> daysInfected;

	bool	vaccinated;
	int		healthRisk; // if hR = 1, higher risk people
	int		jobImportance; //=0 high importance to =2 low importance

	int		daysSinceLeft;


	float	rebeliousness;

	int		worldArrayReference;

};