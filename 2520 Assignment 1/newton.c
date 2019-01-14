//Numan Mir
//1005381
//CIS2520 Assignment 1
//Monday September 24th, 2018

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double recursive(double, double, double);
double nonRecursive(double, double, double);

int newtonMain(){
	double x = 0.0;
	double accuracy = 0.0;
	double approx = 0.0;

	printf("Enter a value to find its square root: \n");
	scanf("%lf", &x);
	printf("Enter accuracy: \n");
	scanf("%lf", &accuracy);
	
	approx = x/2.0; //initial approximation
	approx = recursive(x, accuracy, approx); //recursive calculation
	printf("\nUsing recursion: the square root of %lf with an accuracy of\n%e is %e\n",x, accuracy, approx);
	
	approx = x/2.0; //reinitialize approximation for second method
	approx = nonRecursive(x, accuracy, approx); //while loop calculation
	printf("\nUsing a while loop: the square root of %lf with an accuracy of\n%e is %e\n",x, accuracy, approx);

	return 0;
}

double recursive(double x, double accuracy, double approx){
	if(fabs(approx * approx - x) <= accuracy){ //if the absolute value of the approximation squared minus x is less than or equal to the accuracy value, exit
		return approx; //approx is good, return
	}
	else{
		approx = (approx + (x/approx))/2.0; //else, add the approximation to the x value divided by the approximation, and divide total by 2
		return recursive(x, accuracy, approx); //recall recursive method until it can exit from the first if statement
	}
}

double nonRecursive(double x, double accuracy, double approx){
	while(fabs(approx * approx - x) > accuracy){ //as long as the absolute value is greater than the accuracy required, keep looping
		approx = (approx + (x/approx))/2.0; //keep adjusting approximation until it breaks from while
	}
	return approx;
}

