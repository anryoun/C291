// recommend a song based upon user's taste
#include <stdio.h>

int main(void){

	int choice;
	puts("enter your music choice");
	puts("0 - pop");
	puts("1 - hip hop");
	puts("2 - rock");
	puts("3 - metal");
	scanf("%d", &choice);

	switch(choice){
		case 0:
			puts("karma - taylor swift");
			break;
		case 1:
			puts("just wanna rock - lil uzi");
			break;
		case 2:
			puts("dream on - aerosmith");
			break;
		case 3:
			puts("combustion - meshuggah");
			break;
	}

}
