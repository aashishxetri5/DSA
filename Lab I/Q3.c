#include <stdio.h>
#include <stdlib.h>

int  n, *numbers;

void takeNums() {
	int i, sum = 0;
	for(i = 0; i < n; i++) {
		printf("Enter %dth number: ", i+1);
		scanf("%d",numbers+i);
		
		sum += *(numbers+i);
		// printf("Address: %d\n", numbers+i);
	}

	printf("\nSUM: %d", sum);
}

int main() {
	
	char ans;
	
	printf("Enter the size of array: ");
	scanf("%d", &n);
	
	numbers = (int *) malloc(n * sizeof(int));
	
	takeNums();
	
	printf("\nDo you wish to enter more? ");
	scanf(" %c", &ans);
	
	if(ans == 'y' || ans == 'Y') {
		printf("Enter new size: ");
		scanf("%d", &n);
		
		numbers = (int *) realloc(numbers, n);
		takeNums();
	}
	
	return 0;
}
