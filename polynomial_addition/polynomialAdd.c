/* 
 * File:   polynomialAdd.c
 * Author: http://www.roytuts.com
 *
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct termType {
    int coefficient, exponent;
} termType;

typedef struct poly {
    termType terms[100];
    int noOfTerms;
} poly;

poly * addPoly(poly *p1, poly *p2) {
    int i, j, k, l;
    poly *p3 = malloc(sizeof (poly));

    for (i = 0, j = 0, k = 0; ((i < p1->noOfTerms)&&(j < p2->noOfTerms)); k++) {
        if (p1->terms[i].exponent == p2->terms[j].exponent) {
            p3->terms[k].coefficient = p1->terms[i].coefficient + p2->terms[j].coefficient;
            p3->terms[k].exponent = p1->terms[i].exponent;
            i++;
            j++;
        } else if (p1->terms[i].exponent < p2->terms[j].exponent) {
            p3->terms[k].coefficient = p1->terms[i].coefficient;
            p3->terms[k].exponent = p1->terms[i].exponent;
            i++;
        } else {
            p3->terms[k].coefficient = p2->terms[j].coefficient;
            p3->terms[k].exponent = p2->terms[j].exponent;
            j++;
        }
    }

    if (i < p1->noOfTerms) {
        for (l = i; l < p1->noOfTerms; l++, k++) {
            p3->terms[k].coefficient = p1->terms[l].coefficient;
            p3->terms[k].exponent = p1->terms[l].exponent;
        }
    } else {
        for (l = j; l < p2->noOfTerms; l++, k++) {
            p3->terms[k].coefficient = p2->terms[l].coefficient;
            p3->terms[k].exponent = p2->terms[l].exponent;
        }
    }
    p3->noOfTerms = k;

    return p3;
}

int main() {
    termType t1, t2, t3, t4, t5, t6;
    poly *p1, *p2, *p3;

    p1 = malloc(sizeof (poly));
    p2 = malloc(sizeof (poly));

    t1.coefficient = 5;
    t1.exponent = 0;
    t2.coefficient = -2;
    t2.exponent = 2;
    t3.coefficient = 9;
    t3.exponent = 4;

    t4.coefficient = 6;
    t4.exponent = 1;
    t5.coefficient = -7;
    t5.exponent = 2;
    t6.coefficient = 10;
    t6.exponent = 3;

    p1->terms[0] = t1;
    p1->terms[1] = t2;
    p1->terms[2] = t3;
    p1->noOfTerms = 3;

    p2->terms[0] = t4;
    p2->terms[1] = t5;
    p2->terms[2] = t6;
    p2->noOfTerms = 3;

    p3 = addPoly(p1, p2);

    print(p3);
}

void print(poly *p) {
    int i, c;
    c = 0;
    for (i = 0; i < p->noOfTerms; i++) {
        if (c != 0 && c < p->noOfTerms && p->terms[i].coefficient > 0) {
            printf("+");
        }
        printf("%dx^%d", p->terms[i].coefficient, p->terms[i].exponent);
        c++;
    }
}
