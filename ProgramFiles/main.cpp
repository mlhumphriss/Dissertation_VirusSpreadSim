#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Person.h"
#include "PopArrays.h"

using namespace std;

int pop = 100;

//Think this should create an array of pointers to Person class but unsure
//Person* worldPop = new Person[pop];
//Person* outsidePop = new Person[pop];

int main() {
	time_t seedTime = time(0); //Setting time for programs random number for sim
	PopArrays population = PopArrays(pop);

	

	//Need to declare fixed array of All people beforehand
}
