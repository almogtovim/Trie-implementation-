#include <stdio.h>
#include "myMath.h"

int main(){
	double x = 0;
	printf("Please insert a real number: ");
	scanf("%lf", &x);

	float x1 = Exponent(x);
	float x2 = Power(x, 3);
	float x3 = add(x1, x2);
	float ans1 = sub(x3, 2);
	printf("The value of f(x) = e^x + x^3 - 2 at the point %.4f is: %.4f\n", x, ans1);
	
	x1 = mul(x, 3);
	x2 = Power(x, 2);
	x3 = mul(2, x2);
	float ans2 = add(x1, x3);
	printf("The value of f(x) = 3x + 2x^2 at the point %.4f is: %.4f\n", x, ans2);
	
	x1 = mul(4, Power(x,3));
	x2 = div(x1, 5);
	x3 = mul(2, x);
	float ans3 = sub(x2, x3);
	printf("The value of f(x) = (4x^3) / 5 - 2x at the point %.4f is: %.4f\n", x, ans3);
	
	return 0;
}
