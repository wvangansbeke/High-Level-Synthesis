#include "main.h"

#ifndef NONAME
int bmiWrapper(string name, int height, int weight){

	BMI person1(name, height, weight);
	return person1.calcBMI();
}
#else
int bmiWrapper(int height, int weight){

	BMI person1(height, weight);
	return person1.calcBMI();
}
#endif
