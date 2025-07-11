#pragma once
#include <iostream>

class EnvironmentFactors {
public:
	EnvironmentFactors() {
		numHealthRisk = 0;
		
		masksEnforced = false;
		socialDistancing = false;
		lockdown = false;
		vaccinationRollout = false;
		asymptomaticPeriod = 3;
		minInfectionPeriod = 11;
		groupRebel = 1.0f;
		lengthSim = 100;
		initialInfections = 5;
	};

	EnvironmentFactors(int pop) { 
		population = pop; 
		numHealthRisk = 0; 
	
		masksEnforced = false;
		socialDistancing = false;
		lockdown = false;
		vaccinationRollout = false;
		asymptomaticPeriod = 3;
		minInfectionPeriod = 11;
		groupRebel = 1.0f;
		lengthSim = 100;
		initialInfections = 5;
	};

	int setEnvironmentFactors(bool mE, bool sD, bool l, bool vR, int mIP, int aP, float gR, int lS, int iI) {
		masksEnforced = mE;
		socialDistancing = sD;
		lockdown = l;
		vaccinationRollout = vR;
		minInfectionPeriod = mIP;
		asymptomaticPeriod = aP;
		groupRebel = gR;
		lengthSim = lS;
		initialInfections = iI;
		return 0;
	};

	~EnvironmentFactors() {}

	void	incrementNumHealthRisk() { numHealthRisk += 1; }

	bool	getLockdown() { return lockdown; }
	bool	getMaskEnforced() { return masksEnforced; }
	bool	getSocialDistancing() { return socialDistancing; }
	bool	getVaccinationRollOut() { return vaccinationRollout; }
	int		getMinInfectPeriod() { return minInfectionPeriod; }
	int		getAsympPeriod() { return asymptomaticPeriod; }
	int		getLengthSim() { return lengthSim; }
	int		getPopulation() { return population; }
	float	getGroupRebel() { return groupRebel; }
	int		getNumHealthRisk() { return numHealthRisk; }
	int		getInitialInfections() { return initialInfections; }


	void	setLockdown(bool l) { lockdown = l; }
	void	setSocialDistancing(bool s) { socialDistancing = s; }
	void	setMaskEnforced(bool m) { masksEnforced = m; }
	void	setVaccinationRollout(bool v) { vaccinationRollout = v; }
	void	setGroupRebeliousness(float r) { groupRebel = r; }
	void	setInitialInfections(int iI) { initialInfections = iI; }
	void	setLengthSim(int l) { lengthSim = l; }
	void	setMinInfectionPeriod(int mIP) { minInfectionPeriod = mIP; }
	void	setAsymptomaticPeriod(int aP) { asymptomaticPeriod = aP; }

	void	setNumHealthRisk(int nHR) { numHealthRisk = nHR; }

protected:
	bool	masksEnforced;
	bool	socialDistancing;
	bool	lockdown;
	bool	vaccinationRollout;

	int		minInfectionPeriod;
	int		asymptomaticPeriod;
	int		population;

	float	groupRebel;
	int		lengthSim;
	int		initialInfections;

	int		numHealthRisk;

};