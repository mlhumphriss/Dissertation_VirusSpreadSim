#pragma once
#include <iostream>
#include <vector>
#include <cstdlib>
#include "EnvironmentFactors.h"

using namespace std;

class Inputs {
public:
	Inputs();

	int setEnvironmentAttributes(EnvironmentFactors e) {
		int c = e.setEnvironmentFactors(iMasksEnforced, iSocialDistancing, iLockdown, iVaccinationRollout, iMinInfectionPeriod, iAsymptomaticPeriod, iGroupRebel, iLengthSim);
		return c;
	}

	bool getILockdown() { return iLockdown; }
	bool getIMaskEnforced() { return iMasksEnforced; }
	bool getISocialDistancing() { return iSocialDistancing; }
	int  getIMinInfectPeriod() { return iMinInfectionPeriod; }
	int  getIAsympPeriod() { return iAsymptomaticPeriod; }
	float getIGroupRebel() { return iGroupRebel; }
	bool getIVaccinationRollout() { return iVaccinationRollout; }
	int getILengthSim() { return iLengthSim; }

	void setILockdown(bool l) {
		iLockdown = l;
	}
	void setISocialDistancing(bool s) {
		iSocialDistancing = s;
	}
	void setIMaskEnforced(bool m) {
		iMasksEnforced = m;
	}
	void setIVaccinationRollout(bool v) {
		iVaccinationRollout = v;
	}


protected:
	bool	iMasksEnforced;
	bool	iSocialDistancing;
	bool	iLockdown;
	bool	iVaccinationRollout;

	int		iMinInfectionPeriod;
	int		iAsymptomaticPeriod;

	float	iGroupRebel;

	int		iLengthSim;
};