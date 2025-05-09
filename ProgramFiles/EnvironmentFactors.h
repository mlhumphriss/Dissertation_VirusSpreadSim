#pragma once
#include <iostream>

class EnvironmentFactors {
public:
	EnvironmentFactors();

	int setEnvironmentFactors(bool mE, bool sD, bool pHS, bool l, bool vR, int mIP, int aP, float gR, int lS) {
		masksEnforced = mE;
		socialDistancing = sD;
		pushingHandSanitizer = pHS;
		lockdown = l;
		vaccinationRollout = vR;
		minInfectionPeriod = mIP;
		asymptomaticPeriod = aP;
		groupRebel = gR;
		lengthSim = lS;
		return 0;
	};

	~EnvironmentFactors() {}

	bool getLockdown() { return lockdown; }
	bool getMaskEnforced() { return masksEnforced; }
	bool getSocialDistancing() { return socialDistancing; }
	bool getPushHandSani() { return pushingHandSanitizer; }
	int  getMinInfectPeriod() { return minInfectionPeriod; }
	int  getAsympPeriod() { return asymptomaticPeriod; }
	float getGroupRebel() { return groupRebel; }

	void setLockdown(bool l) {
		lockdown = l;
	}
	void setSocialDistancing(bool s) {
		socialDistancing = s;
	}
	void setPushHandSani(bool h) {
		pushingHandSanitizer = h;
	}
	void setMaskEnforced(bool m) {
		masksEnforced = m;
	}

protected:
	bool	masksEnforced;
	bool	socialDistancing;
	bool	pushingHandSanitizer;
	bool	lockdown;
	bool	vaccinationRollout;

	int		minInfectionPeriod;
	int		asymptomaticPeriod;

	float	groupRebel;
	int		lengthSim;

};