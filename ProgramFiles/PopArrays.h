#pragma once
#include <iostream>
#include "Person.h"

class PopArrays {
public:
	PopArrays() {};

	PopArrays(int pop) {
		worldPop	= new Person[pop];
		outsidePop	= new Person*[pop];
		memset(outsidePop, 0, sizeof(Person*) * pop);

	};
	~PopArrays() {
		//delete worldPop;
		//delete outsidePop;
	}

	void addStatArrays(int size) {
		infectedA = new int[size + 1];
		totalInfectA = new int[size + 1];
	}
	
	void addToWorldArray(int i, Person p){
		worldPop[i] = p;
	}
	void addToOutsideArray(int i, Person* p, int r) {
		//p.setWorldArrayRef(r);
		p->setWorldArrayRef(r);
		outsidePop[i] = p;
	}

	void addToInfectedArray(int x, int i) {
		infectedA[x] = i;
	}
	void addToTotalInfectArray(int x, int t) {
		totalInfectA[x] = t;
	}

	Person*	getPersonFromWorld(int i) { return &worldPop[i]; }
	Person*	getPersonFromOutside(int i) { return outsidePop[i]; }
	int		getFromInfectA(int i) { return infectedA[i]; }
	int		getFromTotInfectA(int i) { return totalInfectA[i]; }

	Person* getWorldPop() { return worldPop; }
	Person** getOutsidePop() { return outsidePop; }
	int*	getInfectedA() { return infectedA; }
	int*	getTotalInfectA() { return totalInfectA; }
	
protected:
	Person* worldPop;
	Person** outsidePop;

	int*	infectedA;
	int*	totalInfectA;
};