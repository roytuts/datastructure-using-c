/* 
 * File:   matrixTranspose.c
 * Author: http://www.roytuts.com
 *
 */

#include <stdio.h>
#include <stdlib.h>

void matrixTranspose(int **a, int r, int c) {
    int i, j, temp;

    for (i = 0; i < r; i++) {
        for (j = i + 1; j < c; j++) {
            temp = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = temp;
        }
    }
}

int main()() {

    int i, j, rows, cols, **a;

    printf("Transpose of a Matrix");

    printf("\nEnter number of rows :");
    scanf("%d", &rows);
    printf("\nEnter number of columns :");
    scanf("%d", &cols);

    // allocate rows, each row is a pointer to int
    a = malloc(rows * sizeof (int *));

    // for each row allocate cols int
    for (i = 0; i < rows; i++) {
        a[i] = malloc(cols * sizeof (int));
    }

    printf("\nEnter Matrix\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("Enter Element %d %d : ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    matrixTranspose(a, rows, cols);

    printf("\nTranspose of the given Matrix\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < rows; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}
