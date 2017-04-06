#include <stdio.h>
#define DAYS 17
int prices[DAYS] = {100,113,110,85,105,102,86,63,81,101,94,106,101,79,94,90,97};
int main(void){
	int change[DAYS] = {0};
	for(int i =1; i < DAYS; ++i){
		change[i] = prices[i] - prices[i-1];

	}	

	for(int i=0; i < DAYS ;++i){
		printf("%d \t", change[i]);
	}
	printf("\n");
}

	
