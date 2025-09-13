#include <stdio.h>

int main(void){

	// declare two int variables for taking input
	int no1;
	int no2;
	// declare a variable to store output
	int sum;

	// prompt for first input
	printf("enter first number\n");
	scanf("%d", &no1);
	
	// prompt for second input
	printf("enter second number\n");
	scanf("%d", &no2);

	// add the two numbers
	sum = no1 + no2;

	// print the sum
	printf("the sum of %d and %d is %d\n", no1, no2, sum);
}
