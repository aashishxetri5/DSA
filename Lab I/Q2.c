#include <stdio.h>
#include <stdlib.h>

int main() {
    
    int i, n, *p, sum = 0;
    
	printf("How many numbers do you want to enter? ");
    scanf("%d", &n);
    
    p = (int *) calloc(n, sizeof(int));
    
    for(i = 0; i < n; i++) {
	
		printf("Enter the %dth number: ", i+1);
    	scanf("%d", (p+i));
    	
    	sum += *(p+i);
	}
	
	printf("%d", sum);
	free(p);
    return 0;
}
