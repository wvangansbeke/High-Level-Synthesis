#include "main.h"
#include <string>
using namespace std;

int main() {
#ifndef NONAME
	string name = "Stijn";
#endif
	int height = 2;
	int weight = 128;

#ifndef NONAME
	int bmip1 = bmiWrapper(name, height, weight);
#else
	int bmip1 = bmiWrapper(height, weight);
#endif

//	cout << endl << "person's name: " << person1.getname() << endl <<
//			"Height: " << person1.getheight() << endl <<
//			"Weigh: " << person1.getweight() << endl <<
//			"BMI: " << person1.calcBMI() <<endl;

	cout << endl <<
#ifndef NONAME
			"person's name: " << name << endl <<
#endif
			"Height: " << height << endl <<
			"Weigh: " << weight << endl <<
			"BMI: " << bmip1 << endl;

//	int red = 30, white= 20, hemoglobin = 10;
//
//	bloodID hema;
//	hema.hemoglobin = hemoglobin;
//	hema.redBloodCells=red;
//	hema.whiteBloodCells=white;
//
//	bloodID out = setBloodValues(&hema);
//	cout << endl << "The percentage of red blood cells is " << out.redBloodCells << endl <<
//			"of white blood cells is " << out.whiteBloodCells << endl <<
//			"and of hemoglobin is: " << out.hemoglobin << endl;
	return 0;

}
