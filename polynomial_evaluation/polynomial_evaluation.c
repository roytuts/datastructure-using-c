#include <stdio.h>
#include <stdlib.h>

typedef struct termType {
    int coefficient, exponent;
} termType;

typedef struct poly {
    termType terms[100];
    int noOfTerms;
} poly;

double evaluate(poly *p, double x) {
    int i, j;
    double term, result = 0;

    term = 1;

    for(i=0; i<p->noOfTerms; i++) {
        for(j=0; j<p->terms[i].exponent; j++) {
            term *= x;
        }

        result += term*p->terms[i].coefficient;
        term = 1;
    }

    return result;
}

int main() {
    termType t1, t2, t3;
    poly *p;
    double result;

    p = malloc(sizeof (poly));

    t1.coefficient = 5;
    t1.exponent = 4;

    t2.coefficient = 3;
    t2.exponent = 2;

    t3.coefficient = 2;
    t3.exponent = 0;

    p->terms[0] = t1;
    p->terms[1] = t2;
    p->terms[2] = t3;
    p->noOfTerms = 3;

    result = evaluate(p, 1);
    printf("Result: %lf", result);

    result = evaluate(p, 2);
    printf("\nResult: %lf", result);

    return 0;
}
