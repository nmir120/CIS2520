//Numan Mir
//1005381
//CIS2520 Assignment 1
//Monday September 24th, 2018
#include <stdio.h>

int ackermann(int, int);

int ackermannMain(){
	int n = 0;
	int m = 0;
	int ans = 0;

	printf("Enter first value of the Ackermann's function:\n");
	scanf("%d", &n);
	printf("\nEnter second value:\n");
	scanf("%d", &m);

	ans = ackermann(n, m);
	if(ans != -1){
		printf("The answer is: %d\n", ans);
	}
	else{
		printf("Invalid input: values must be >= 0");
	}
	return 0;
}

int ackermann(int n, int m){ //computes Ackermann's function answer based on two input values
	int answer = 0;

	if(n == 0 && m >= 0){ //first case, if first value = 0 and second value is >= 0
		answer = m + 1; //answer is just second value + 1
	}
	else if(n > 0 && m == 0){ //second case, if first value > 0, second value = 0
		answer = ackermann(n - 1, 1); //recursion, call function again with (first value - 1), and 1
	}
	else if(n > 0 && m > 0){ //final case, if both values > 0
		answer = ackermann(n - 1, ackermann(n, m - 1)); //recursion twice, call function with (first value - 1), and another call to the function with first value and (second value - 1)
	}
	else{ //invalid, if either first or second values are < 0
		answer = -1;
	}

	return answer;
}
