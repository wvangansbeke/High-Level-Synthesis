#ifndef MAIN1_H_
#define MAIN1_H_

#include "BMI.h"
#include <iostream>

#ifndef NONAME
int bmiWrapper(string name, int height, int weight);
#else
int bmiWrapper(t_int height, t_int weight);
#endif

#endif
