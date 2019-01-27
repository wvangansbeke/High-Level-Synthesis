#include <iostream>
#include <complex>
#include <stdio.h>
#include <stdlib.h>
#include "fft.h"
#define MAX 200

using namespace std;

int main()
{
  int n;
  /*do {
    cout << "specify array dimension (MUST be power of 2)" << endl;
    cin >> n;
  } while(!check(n));*/
  double d = 1;
  /*cout << "specify sampling step" << endl; //just write 1 in order to have the same results of matlab fft(.)
  cin >> d;*/
  n = 4;
  complex<double> vec[4] = {1,1,1,1};

  /*cout << "specify the array" << endl;
  for(int i = 0; i < n; i++) {
    cout << "specify element number: " << i << endl;
    cin >> vec[i];
  }*/
  FFT(vec, n, d);
  cout << "...printing the FFT of the array specified" << endl;
  for(int j = 0; j < n; j++)
    cout << vec[j] << endl;
  return 0;
}
