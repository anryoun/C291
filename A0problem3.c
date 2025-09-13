// comparing numbers
#include <stdio.h>

int main(void){

	int no1, no2;
	puts("enter two numbers");
	scanf("%d %d", &no1, &no2);

	if(no1 == no2){
		printf("%d and %d are equal\n", no1, no2);
	}
	if(no1 != no2){
		printf("%d and %d are not equal\n", no1, no2);
	}
	if(no1 < no2){
		printf("%d is less than %d\n", no1, no2);
	}
	if(no1 <= no2){
		printf("%d is less than or equal to %d\n", no1, no2);
	}
	if(no1 > no2){
		printf("%d is greater than %d\n", no1, no2);
	}
	if(no1 >= no2){
		printf("%d is greater than or equal to %d\n", no1, no2);
	}
}
