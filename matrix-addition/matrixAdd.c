/* 
 * File:   matrixAdd.c
 * Author: https://www.roytuts.com
 *
 */

#include <stdio.h>
#include <stdlib.h>

int ** matrixAdd(int **a, int **b, int r, int c) {
    int i, j;
    int **result = malloc(r * sizeof (int *));

    for (i = 0; i < r; i++) {
        result[i] = malloc(c * sizeof (int));
    }

    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }

    return result;
}

int main() {

    int i, j, rows, cols, **a, **b, **result;

    printf("Addition of two Matrix");

    printf("\nEnter number of rows :");
    scanf("%d", &rows);
    printf("\nEnter number of columns :");
    scanf("%d", &cols);

    // allocate rows, each row is a pointer to int
    a = malloc(rows * sizeof (int *));
    b = malloc(rows * sizeof (int *));
    //result = malloc(rows * sizeof (int *));

    // for each row allocate cols int
    for (i = 0; i < rows; i++) {
        a[i] = malloc(cols * sizeof (int));
        b[i] = malloc(cols * sizeof (int));
        //result[row] = malloc(cols * sizeof (int));
    }

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("Enter Element %d %d : ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("Enter Element %d %d : ", i, j);
            scanf("%d", &b[i][j]);
        }
    }

    /*for (i = 0; i < rows; i++) {
        for (j = 0; j < rows; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }*/

    result = matrixAdd(a, b, rows, cols);

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("\nElement at %d %d : %d", i, j, result[i][j]);
        }
    }

    return 0;
}
