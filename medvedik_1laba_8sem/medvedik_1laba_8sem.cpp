﻿#include <iostream>
#include<cmath>
//#include"IntegraL.h"
using namespace std;

const double pi = acos(-1);
const int N = 10;

double x[N]; 
double a = -1;
double b = 1;
double h = (b - a) / N;

double f(double y) {
	return (y + sqrt(1 - y * y));
}

double Tn(int n, double x) {
    return cos(n * acos(x));
}

double Un(int n, double x) {
    return (sin((n + 1) * acos(x)) / sqrt(1 - x * x));
}

double Mid(double h1, double x1, double x2, int n) { //perepisat' integral
	double S = 0.0;
	h1 = (b - a) / N;
	for (double i = x1; i <= x2; i = i + h1)
	{
		if ((i * i) != 1.0) {
			S += (f(i + (h1 / 2.0)) * Tn(n, i) / (sqrt(1 - i * i)));
			//cout << "jopa1 " << f(i + (h1 / 2.0)) << endl;
			//cout << "jopa2 " << Tn(n, i) << endl;
			//cout << "jopa3 " << (sqrt(1 - i * i)) << endl;
			//cout << "jopaS = " << S << endl;
		}
		else
		{

			S += 0;
			//cout <<"\nJOPA = " << (f(i + (h / 2.0)) * Tn(n, i) / (sqrt(1.0 - ((i * i) + 0.0001)))) << endl;
			//cout << 1.0 - ((i * i) - 0.0001) << endl;
		}

	}
	return (S * h1);
}

double Mid2(double h, double x1, double x2, int n) {
	double S = 0.0;
	for (double i = x1; i < x2; i = i + h)
	{
		S += (f(i + (h / 2.0)) * Un(n, i) * (sqrt(1 - i * i)));
	}
	return (S * h);
}


double an(int n) {
	//cout << Mid(0.1, -1, 1, n) << endl;
	return (2.0 / pi) * Mid(0.01, -1, 1, n);


}

double bn(int n) {

	return (2.0 / pi) * Mid2(0.01, -1, 1, n);

}







double K[N][N];
double KK() {
	double S = 0.0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			S += K[i][j] * Tn(i, j);
		}
	}

	return 1;
}


int main()
{
	double fi[N]; // eto doljno bit ryadom i bit prakticheski sovpadat' s tipafii
	for (int i = 0; i < N; i++)
	{
		x[i] = a + i * h;
	}
	fi[0] = f(0) * Tn(0, x[0]);
	for (int i = 1; i < N; i++)
	{
		fi[i] += f(x[i]) * Tn(i, x[i]);
	}
	double Tipafii[N];
	for (int i = 0; i < N; i++) {
		if (i==0)
		{
			double o = an(0) / 2.0;
			//cout << o << endl;
			//cout << Tn(1,x[1]) << endl;
			Tipafii[i] = o * Tn(i, x[i]);
		}
		else
		{
			//cout << "an = " << an(i) << " tn = " << Tn(i, x[i]) << endl;
			Tipafii[i] += an(i) * Tn(i, x[i]);
		}
		//Tipafii[i] +=  * Tn(0, x[0]);
	}
	/*for (int i = 0; i < N; i++) {
		cout << "t= " << Tn(i, 0.1) << endl;
	
	}*/

	//Tipafii[0] = (an(0, x[0]) * Tn(0, x[0])) / 2.0;
	for (int i = 0; i < N; i++) {

		//fii[i] = f(x[i]) * Tn(i, x[i]);
		cout << "take :"<< i << endl;
		printf("%.110f\n", Tipafii[i]);
		std::cout << "\n";
		printf("%.110f\n", fi[i]);
		std::cout << "\n";
	}
	
	return 1;
}
