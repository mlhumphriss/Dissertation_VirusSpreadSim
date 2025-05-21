#include "Inputs.h"
#include <chrono>
#include <thread>

int Inputs::inputEnvironmentSettings(EnvironmentFactors environment) {
	bool exit = false;
	int	inputSelect;

	while (!exit) {
		system("CLS");
		cout << "Enter Number to Toggle or Modify a Field, or 0 to Run" << "\n";
		cout << std::boolalpha;
		cout << "1) Masks  Enforced: " << environment.getMaskEnforced() << "\n";
		cout << "2) Social Distancing: " << environment.getSocialDistancing() << "\n";
		cout << "3) Lockdown: " << environment.getLockdown() << "\n";
		cout << "4) Vaccinations: " << environment.getVaccinationRollOut() << "\n";
		cout << "5) Group Rebeliousness: " << environment.getGroupRebel() << "\n";
		cout << "6) Initial Infections: " << environment.getInitialInfections() << "\n";
		cout << "7) Asymptomatic Period: " << environment.getAsympPeriod() << "\n";
		cout << "8) Min infection Period: " << environment.getMinInfectPeriod() << "\n";
		cout << "9) Length Simulation: " << environment.getLengthSim() << "\n";
		cout << "Enter 0 to continue to test, or a number to toggle or modify field" << "\n";
		cin >> inputSelect;
		
		switch (inputSelect) {
			case 1:
				environment.setMaskEnforced(!environment.getMaskEnforced());
				cout << "Masks Enforced set to " << environment.getMaskEnforced() << "\n";
				std::this_thread::sleep_for(chrono::milliseconds(500));
				break;
			case 2:
				environment.setSocialDistancing(!environment.getSocialDistancing());
				cout << "Social Distancing set to " << environment.getSocialDistancing() << "\n";
				std::this_thread::sleep_for(chrono::milliseconds(500));
				break;
			case 3:
				environment.setLockdown(!environment.getLockdown());
				cout << "Lockdown set to " << environment.getLockdown() << "\n";
				std::this_thread::sleep_for(chrono::milliseconds(500));
				break;
			case 4:
				environment.setVaccinationRollout(!environment.getVaccinationRollOut());
				cout << "Vaccination set to " << environment.getVaccinationRollOut() << "\n";
				std::this_thread::sleep_for(chrono::milliseconds(500));
				break;
			case 5:
				float input;
				bool check = false;
				cout << "Input Value for Rebeliousness Modifier between 0.0 and 2.0" << "\n";
				cin >> input;
				while (!check) {
					if (input > 0.0f && input <= 2.0f) {
						check = true;
						environment.setGroupRebeliousness(input);
					}
					else {
						cout << "Value out of Bounds, Please enter a value greater than 0 but not greater than 2.0" << "\n";
					}
				}
				break;
			case 6:
				int input;
				bool check = false;
				cout << "Input Value for Initial Infections" << "\n";
				cin >> input;
				while (!check) {
					if (input > 0) {
						check = true;
						environment.setInitialInfections(input);
					}
					else {
						cout << "Value out of Bounds, Please enter a value greater than 0" << "\n";
					}
				}
				break;
			case 7:
				int input;
				bool check = false;
				cout << "Input Value for Asymptomatic Period" << "\n";
				cin >> input;
				while (!check) {
					if (input > 0) {
						check = true;
						environment.setAsymptomaticPeriod(input);
					}
					else {
						cout << "Value out of Bounds, Please enter a value greater than 0" << "\n";
					}
				}
				break;
			case 8:
				int input;
				bool check = false;
				cout << "Input Value for Minimum Infection Period" << "\n";
				cin >> input;
				while (!check) {
					if (input > 0 && input >= environment.getAsympPeriod()) {
						check = true;
						environment.setMinInfectionPeriod(input);
					}
					else {
						cout << "Value out of Bounds, Please enter a value greater than 0 and Larger than Asymptomatic Period currently set to:" << environment.getAsympPeriod() << "\n";
					}
				}
				break;
			case 9:
				int input;
				bool check = false;
				cout << "Input Value for Simulation Length" << "\n";
				cin >> input;
				while (!check) {
					if (input > 0) {
						check = true;
						environment.setLengthSim(input);
					}
					else {
						cout << "Value out of Bounds, Please enter a value greater than 0" << "\n";
					}
				}
				break;
			case 0:
				int checkNum;
				bool check = false;
				cout << "Continue to Simulation? (1 for Yes, 0 for No)" << "\n";
				cin >> checkNum;
				while (!check) {
					if (checkNum != 1 || checkNum != 0) {
						cout << "Enter a Valid Answer (1 for Yes, 0 for No)" << "\n";
						cin >> checkNum;
					}
					else { check = true; }	
				}
				if (checkNum == 1) { exit = true; }
				break;
		}
	}

}