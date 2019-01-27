#ifndef FFT_H
#define FFT_H
#include <complex>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

#define MAX 200
#define MY_PI 3.1415926535897932384

int log2(int N) ;
int check(int n);
int reverse(int N, int n);
void ordina(complex<double>* f1, int N);
void transform(complex<double>* f, int N);
void FFT(complex<double> f[4], int N, double d);

#endif
