#pragma once
#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include "EnvironmentFactors.h"
#include "PopArrays.h"

using namespace std;

class DataRW {
public:
	DataRW() {
		testDataFile = "popDataSeed.txt";
	};

	int writePopDataFile(int pop, time_t seed);

	int writeTestDataFile(EnvironmentFactors environment, PopArrays arrays, int size);

	int readPopDataFile();

	//need write for sim results but need to work that out later

	string getTestDataFile() { return testDataFile; }
	int		getReadPop() { return readPop; }
	time_t	getReadSeed() { return readSeed; }

protected:
	string	testDataFile;
	int		readPop;
	time_t	readSeed;
};