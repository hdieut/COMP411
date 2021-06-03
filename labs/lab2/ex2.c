#include <stdio.h>

double  x;
double sum1 = 0;
double min1 = 0;
double max1 = 0;
double product1 = 1;

double sum(double x);
double min(double x);
double max(double x);
double product(double x);

double main() {
	printf("Enter 10 floating-point numbers:\n");
	
	for (int y = 0; y < 10; y++) {
		scanf("%lf", &x);
		
		sum(x);
		min(x);
		max(x);
		product(x);
		
	}
	printf("Sum is %3.5f\n", sum1);
	printf("Min is %3.5f\n", min1);
	printf("Max is %3.5f\n", max1);
	printf("Product is %3.5f\n", product1);

}

double sum(double x) {
	sum1 += x;
	return sum1;
}

double min(double x) {
	if (x < min1) {
		min1 = x;
	}
	return min1;
}

double max(double x) {
	if (x > max1) {
		max1 = x;
	}
	return max1;
}

double product(double x) {
	product1 = x * product1;
	return product1;
}
