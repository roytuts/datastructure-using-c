#include <stdio.h>
#include <stdlib.h>

typedef struct element {
    int row, col, val;
} element;

typedef struct spmat {
    element data[100];
    int noOfRows, noOfCols, noOfElements;
} spmat;

void printMatrix(spmat *s) {
    int i;

    for(i=0; i<s->noOfElements; i++) {
        printf("[%d, %d, %d] ", s->data[i].row, s->data[i].col, s->data[i].val);
    }

    printf("\n");
}

void noOfElementsInColoumn(spmat *s) {
    int i,j, count = 0;

    for(i=0; i<s->noOfCols; i++) {
        count = 0;

        for(j=0; j<s->noOfElements; j++) {
            if(s->data[j].col == i) {
                count++;
            }
        }

        printf("\nNumber of elements in column %d is %d", i , count);
    }
}

spmat* transposeMatrix(spmat *s) {
    int i, j, k=0;
    spmat *t;

    t = malloc(sizeof(spmat));

    t->noOfRows = s->noOfCols;
    t->noOfCols = s->noOfRows;
    t->noOfElements = s->noOfElements;

    for(i=0; i<s->noOfCols; i++) {
        for(j=0; j<s->noOfElements; j++) {
            if(s->data[j].col == i) {
                t->data[k].row = i;
                t->data[k].col = s->data[j].row;
                t->data[k].val = s->data[j].val;
                k++;
            }
        }
    }

    return t;
}

int main() {
    int r, c, e, rn=0, cn=0, v, i=0;
    char choice;
    element ele;
    spmat *sp, *t;
    double result;

    printf("Enter number of rows for sparse matrix: ");
    scanf("%d", &r);

    printf("Enter number of columns for sparse matrix: ");
    scanf("%d", &c);

    printf("Enter number of elements for sparse matrix: ");
    scanf("%d", &e);

    sp = malloc(sizeof(spmat));
    sp->noOfRows = r;
    sp->noOfCols = c;
    sp->noOfElements = e;


    printf("\nEnter elements into Sparse Matrix\n");
    printf("Press q to break...");
    while(1) {
        scanf("%c", &choice);

        if(choice == 'q') {
            break;
        }

        printf("\nEnter row index for matrix value: ");
        scanf("%d", &rn);

        printf("\nEnter column index for matrix value: ");
        scanf("%d", &cn);

        if(choice != 'q' && ((rn > r-1) || (cn > c-1))) {
            printf("You cannot enter row or column index greater than what you specified initially");
            continue;
        }

        printf("\nEnter matrix value for the row/column index: ");
        scanf("%d", &v);

        ele.row = rn;
        ele.col = cn;
        ele.val = v;

        sp->data[i] = ele;

        i++;
    }

    printf("\n\n::Sparse Matrix::\n\n");

    printMatrix(sp);

    noOfElementsInColoumn(sp);

    printf("\n\n::Transpose of the given Sparse Matrix::\n\n");

    t = transposeMatrix(sp);

    printMatrix(t);

    return 0;
}
