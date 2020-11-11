#include "myMath.h"
#define E 2.71828182846

double Power(double x, int y){
	double tmp = x;
	
	while (y < 1){
	x = x / tmp;
	y++;
	}
	while (y > 1){
	x = x * tmp;
	y--;
	}
	
	return x;
}
double Exponent(int x){
	return Power(E, x);
}

