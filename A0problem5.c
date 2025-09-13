// convert marks to letter grades
#include <stdio.h>

int main(void){

	float marks;
	char grade;

	puts("enter marks");
	scanf("%f", &marks);

	if(marks >= 90){
		grade = 'A';
	}
	else if(marks >= 80){
		grade = 'B';
	}
	else if(marks >= 70){
		grade = 'C';
	}
	else if(marks >= 60){
		grade = 'D';
	}
	else{
		grade = 'F';
	}

	printf("The grade is %c\n", grade);
}
	
