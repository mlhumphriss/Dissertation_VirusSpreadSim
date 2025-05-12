#pragma once
#include <iostream>
#include "Person.h"

class PopArrays {
public:
	PopArrays() {};

	PopArrays(int pop) {
		worldPop = new Person[pop];
		outsidePop = new Person[pop];
	};
	~PopArrays() {
		//delete worldPop;
		//delete outsidePop;
	}
	
	void addToWorldArray(int i, Person p){
		worldPop[i] = p;
	}
	void addToOutsideArray(int i, Person p, int r) {
		p.setWorldArrayRef(r);
		outsidePop[i] = p;
	}

	Person getPersonFromWorld(int i) { return worldPop[i]; }
	Person getPersonFromOutside(int i) { return outsidePop[i]; }

	Person* getWorldPop() { return worldPop; }
	Person* getOutsidePop() { return outsidePop; }
	
protected:
	Person* worldPop;
	Person* outsidePop;
};