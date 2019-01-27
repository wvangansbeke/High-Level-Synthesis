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

t_int msb(t_int input) {
	t_int r = 0;
	msb_label0:while (input >>= 1) {
	    r++;
	}
	return r;
}
	//calculate BMI
t_int BMI::calcBMI(){
	return (newWeight >> msb(newHeight*newHeight))*10000;
	//return 18;
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
