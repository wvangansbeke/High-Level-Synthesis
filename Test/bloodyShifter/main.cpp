#include "main.h"

#ifndef NONAME
int bmiWrapper(string name, int height, int weight){

	BMI person1(name, height, weight);
	return person1.calcBMI();
}
#else

intT bmiWrapper(intT height, intT weight){

	//BMI person1(height, weight);
	//int res = person1.calcBMI();
	return weight << height;
}
#endif
