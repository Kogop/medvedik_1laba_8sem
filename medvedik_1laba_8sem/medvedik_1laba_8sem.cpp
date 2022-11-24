#include <iostream>
#include<cmath>
//#include"IntegraL.h"

const double pi = acos(-1);
const int N = 10;
double x[N]; 
double a = -1;
double b = 1;
double h = (b - a) / N;

double f(double y) {
	return y + sqrt(1 - y * y);
}

double Tn(int n, double x) {
    return cos(n * acos(x));
}

double Un(int n, double x) {
    return (sin((n + 1) * acos(x)) / sqrt(1 - x * x));
}

double Mid(double h, double x1, double x2, int n) {
	double S = 0.0;
	for (double i = x1; i < x2; i = i + h)
	{
		S += (f(i + (h / 2.0))*Tn(n, i)/(sqrt(1 - i * i)));
	}
	return (S * h);
}

double Mid2(double h, double x1, double x2, int n) {
	double S = 0.0;
	for (double i = x1; i < x2; i = i + h)
	{
		S += (f(i + (h / 2.0)) * Un(n, i) * (sqrt(1 - i * i)));
	}
	return (S * h);
}


double an(int n, double x) {

	return (2.0 / pi) * Mid(0.01, -1, 1, n);

}

double bn(int n, double x) {

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
	//double fi = 0.0;
	//for (int i = 0; i < N; i++)
	//{
	//	x[i] = a + i * h;
	//}
	//fi = f(0) * Tn(0, x[0]) / 2 * log(2);
	//for (int i = 1; i < N; i++)
	//{
	//	fi += f(y) * Tn(i, y);
	//}
	double Tipafii[N];
	for (int i = 0; i < N; i++) {
		if (i==0)
		{
			double o = an(0, x[0]) / 2.0;
			Tipafii[i] = o * Tn(i, x[i]);
		}
		else
		{
			Tipafii[i] += an(i, x[i]) * Tn(i, x[i]);
		}
		//Tipafii[i] +=  * Tn(0, x[0]);
	}



	Tipafii[0] = (an(0, x[0]) * Tn(0, x[0])) / 2.0;
	for (int i = 1; i < N; i++) {

		fii[i] = f(x[i]) * Tn(i, x[i]);
		printf("%.110f\n", fii[i]);
		std::cout << "\n";
		printf("%.110f\n", f(x[i]));
		
	}
	
	return 1;
}
