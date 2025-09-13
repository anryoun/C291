// compute tax based upon status and income
#include <stdio.h>


int main(void){

	int status;
	float income;
	float tax;
	const float SINGLE_LIMIT = 32000;
	const float MARRIED_LIMIT = 64000;
	const float TAX1 = 0.1;
	const float TAX2 = 0.25;

	puts("enter status: 0 for single, 1 for married");
	scanf("%d", &status);
	puts("enter income");
	scanf("%f", &income);

	// if status is single
	if(status == 0){
		// if income <= 32000
		if(income <= SINGLE_LIMIT){
			tax = TAX1 * income;
		}
		// else if income >= 32000
		else{
			tax = TAX1 * income + TAX2 * (income - SINGLE_LIMIT);
		}
	// else if status is married
	}else if(status == 1){
		// if income <= 64000
		if(income <= MARRIED_LIMIT){
			tax = TAX1 * income;
		}
		// else if income > 64000
		else{
			tax = TAX1 * income + TAX2 * (income - MARRIED_LIMIT);
		}
	}

	printf("Tax is %.2f\n", tax);
}


