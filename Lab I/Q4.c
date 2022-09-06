#include <stdio.h>
#include <stdlib.h>

#define size 3

void fillMatrix(int *matrix) {
    int i;
    for(i = 0; i < 9; i++) {
        printf("Matrix[%d]: ", i);
        scanf("%d", (matrix+i) );
    }
    printf("\n");
}

void display(int *mat) {
    int i;
    for(i = 0; i < 9; i++ ) {
        printf("%-3d ", *(mat+i) );
        if((i+1)%3 == 0) {
            printf("\n");
        }
    }
}

void product(int *matA, int *matB) {
    int i, j, k;
    int *matC = (int*) malloc(9*sizeof(int));

    for(i = 0; i < size; i++) {
        for(j = 0; j < size; j++) {
            *(matC+i*size+j) = 0;
            for(k = 0; k < size; k++) {
                *(matC+i*size+j) += (*(matA + i*size + k) * *(matB + size*k +j) );
            }
        }
    }

    display(matC);
}

int main() {

    int *matA, *matB;

    matA = (int*) malloc(9*sizeof(int));

    matB = (int*) malloc(9*sizeof(int));

    fillMatrix(matA);
    printf("Matrix A:\n");
    display(matA);

    fillMatrix(matB);
    printf("Matrix B:\n");
    display(matB);

    printf("\nProduct Result:\n");
    product(matA, matB);
    return 0;
}