#include "DataRW.h"

int DataRW::writePopDataFile(int pop, time_t seed) {
    ofstream saveFile;
    saveFile.open(testDataFile.c_str());
    saveFile << pop << " "  << seed << " " << "\n";
    saveFile.close();
    return 0;
}

int DataRW::readPopDataFile() {
    int pop;
    int seed;
    ifstream infile(testDataFile);
    if (!infile.is_open()) {
        cerr << "Error: Could not open file " << testDataFile << endl;
        return -1;
    }
    infile >> pop;
    infile >> seed;
    infile.close();
    readPop = pop;
    readSeed = seed;
    return 0;
}

int DataRW::writeTestDataFile(EnvironmentFactors environment, PopArrays arrays, int size) {
    time_t now = time(0);
    string timeStr = ctime(&now);
    timeStr.pop_back();
    string filename = ("DatFile" + timeStr);

    ofstream saveFile;
    saveFile.open(filename.c_str());
    saveFile << "Masks:" << environment.getMaskEnforced() << " " << "SocialDist:" << environment.getSocialDistancing() << " " << "LockDown:" << environment.getLockdown() << " " << "Vaccinations:" << environment.getVaccinationRollOut() << " " << "Population:" << environment.getPopulation() << " " << "Rebeliousness:" << environment.getGroupRebel() << " " << "InitialInfections:" << environment.getInitialInfections() << " " << "MinInfectionPeriod:" << environment.getMinInfectPeriod() << " " << "AsymptomaticPeriod:" << environment.getAsympPeriod() << " " << "\n";
    for (int i = 0; i < size; i++) {
        saveFile << i << "," << arrays.getFromInfectA(i) << "," << arrays.getFromTotInfectA(i) << "\n";
    }
    saveFile.close();
    return 0;
}