/*
 * BMI.cpp
 *
 *  Created on: 9 jul. 2017
 *      Author: Wouter
 */

#include "BMI.h"
#include <iostream>

BMI::BMI() {
#ifndef NONAME
	newName = "Unknown";
#endif
	newHeight = 0;
	newWeight = 0;
}
BMI::~BMI() {
	// TODO Auto-generated destructor stub
}
//Overload constructor
#ifndef NONAME
BMI::BMI(string Name, t_int height, t_int weight){
	newName = Name;
#else
BMI::BMI(t_int height, t_int weight){
#endif
	newHeight = height;
	newWeight = weight;
}

void BMI::initialize(t_int height, t_int weight){
	newHeight = height;
	newWeight = weight;
}


//get name
#ifndef NONAME
string BMI::getname() const{
	return newName;
}
#endif
//get height
t_int BMI::getheight() const{
	return newHeight;
}
//get weight;
t_int BMI::getweight() const{
	return newWeight;
}

	//calculate BMI
t_int BMI::calcBMI(){
	return newWeight;
}
//get result for bloodID
bloodID setBloodValues(bloodID *in){
	t_int red = in->redBloodCells;
	t_int white = in->whiteBloodCells;
	t_int ox = in->hemoglobin;

	bloodID out;
	out.redBloodCells = red /(white + red +ox);
	out.whiteBloodCells = white /(white + red +ox);
	out.hemoglobin = ox/(white + red +ox);
	return out;
}
