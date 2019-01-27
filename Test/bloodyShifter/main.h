#ifndef MAIN1_H_
#define MAIN1_H_

#include "BMI.h"
#include <iostream>

typedef long long intT;

#ifndef NONAME
int bmiWrapper(string name, int height, int weight);
#else
intT bmiWrapper(intT height, intT weight);
#endif

#endif
