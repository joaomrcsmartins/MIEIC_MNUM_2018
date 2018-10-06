// TP2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;

double func(double x) {
	return (x - pow(x,2));
}

bool criteria(double error, double a, double b, int &nsteps,double x) {
	if (nsteps == 0)
		return false;
	--nsteps;
	if (abs(b - a) < error)
		return false;
	if (abs(func(x)) < error)
		return false;
	else return true;
}
void bissectionmethod()
{
	double a, b, y, x;
	double e = 0.001;
	int steps;
	cout << "Select the interval [a,b], and number of steps for the function: ";
	cin >> a >> b >> steps;
	x = (a + b) / 2;
	for (int i = 0; criteria(e,a,b,steps,x) || steps > 0; i++) {
		
		y = func(x);
		if (abs(y) < e)
			break;
		if (func(a)*y < 0)
			b = x;
		else a = x;
		cout << setprecision(3) << "Intermediate solution: " << x << endl;
		x = (a + b) / 2;
	}

	cout << setprecision(3) <<  "The final solution is: " << x << endl;
}

void newtonmethod() {

}

int main() {
	cout << "Select the method of resolving equations you want (number): " << endl;
	cout << " 1 - bissection method" << endl;

	int n;
	cin >> n;
	switch (n) {
	case 1: bissectionmethod();
		break;
	}

	return 0;
}