// ternary operator
#include <stdio.h>

int main(void){

	int grade;
	puts("enter grade");
	scanf("%d", &grade);

	puts((grade >= 60) ? "passed" : "failed");

}
