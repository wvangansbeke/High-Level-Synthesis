#include "main.h"

#ifndef NONAME
int bmiWrapper(string name, int height, int weight){

	BMI person1(name, height, weight);
	return person1.calcBMI();
}
#else


int bmiSummer(BMI * persons, int NBPERSONS) {
	int totalBMI = 0;
	for (int i = 0; i<NBPERSONS; i++) {
		totalBMI += persons[i].calcBMI();
	}

	return totalBMI;
}

int RedbloodCellSum(bloodID * input, int NBPERSONS) {
	int totalCells = 0;
	for (int i = 0; i<NBPERSONS; i++) {
		totalCells += input[i].redBloodCells;
	}

	return totalCells;
}

void initRedBloodCells(bloodID * bloody, int NBPERSONS) {
	//bloodID bloody[NBPERSONS];
	for (int i = 0; i<NBPERSONS; i++) {
		bloody[i].redBloodCells = i*2;
	}
	//return bloody;
}

int bmiWrapper(t_int height, t_int weight){
//	BMI person1(height, weight);
	const int NBPERSONS = 4;
//	BMI persons[NBPERSONS]; //instead of BMI* persons = new BMI[NBPERSONS]
//
//	for (int i = 0; i<NBPERSONS; i++) {
//		persons[i].initialize(height, weight);
//	}
	bloodID bloody[NBPERSONS];
	initRedBloodCells(bloody, NBPERSONS);

	//return bmiSummer(persons, NBPERSONS);
	return RedbloodCellSum(bloody, NBPERSONS);
}



#endif
