/* 
 * File:   Stack.c
 * Author: https://www.roytuts.com
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct element {
    int item;
    struct element *next;
} element;

typedef struct stack {
    element *top;
} stack;

void push(int item, stack *s) {
    element *e;
    e = (element*) malloc(sizeof (element));
    e->item = item;
    e->next = s->top;
    s->top = e;
}

int pop(stack *s) {
    int *item;
    element *e;
    if (s->top == NULL) {
        printf("\nStack is empty\n");
        item = NULL;
        return 0;
    }
    *item = s->top->item;
    e = s->top;
    s->top = s->top->next;
    free(item);
    return 1;
}

void display(stack *s) {
    if (s->top == NULL) {
        printf("\nStack is Empty\n");
    } else {
        while (s->top->next != NULL) {
            printf("%d->", s->top->item);
            s->top = s->top -> next;
        }
        printf("%d->NULL", s->top->item);
    }
}

int main() {
    int choice, value;
    stack *s = (stack*) malloc(sizeof (stack));
    printf("\n:: Stack using Linked List ::\n");
    while (1) {
        printf("\nChoose from below Menu\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: printf("Enter the value to be inserted: ");
                scanf("%d", &value);
                push(value, s);
                break;
            case 2: pop(s);
                break;
            case 3: display(s);
                break;
            case 4: exit(0);
            default: printf("\nWrong selection!!! Please try again!!!\n");
        }
    }
}
