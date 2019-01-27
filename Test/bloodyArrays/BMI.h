/*
 * BMI.h
 *
 *  Created on: 9 jul. 2017
 *      Author: Wouter
 */

#ifndef BMI_H_
#define BMI_H_

#define NONAME

#ifndef NONAME
#include <string>
//using namespace std;
#endif

typedef int t_int;

struct bloodID{
	t_int redBloodCells;
	t_int whiteBloodCells;
	t_int hemoglobin;
};

//typedef bloodID hema;

class BMI{
public:
	//Default constructor
	BMI();

	//Deconstructor
	virtual ~BMI();

	//Overload constructor
#ifndef NONAME
	BMI(string, t_int, t_int);
#else
	BMI(t_int, t_int);
#endif

	void initialize(t_int height, t_int weight);

#ifndef NONAME
	//getname
	string getname() const;
#endif

	//getheigt
	t_int getheight() const;

	//getweight;
	t_int getweight() const;

	//caculate BMI
	t_int calcBMI();

private:
#ifndef NONAME
	string newName;
#endif
	t_int newHeight;
	t_int newWeight;
};

//get result for bloodID
bloodID setBloodValues(bloodID *in);

#endif /* BMI_H_ */
