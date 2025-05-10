#pragma once
#include <iostream>
#include "Person.h"

class PopArrays {
public:
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
	void addToOutsideArray(int i, Person p) {
		outsidePop[i] = p;
	}

	Person* getWorldPop() { return worldPop; }
	Person* getOutsidePop() { return outsidePop; }
	
protected:
	Person* worldPop;
	Person* outsidePop;
};