/* 
 * File:   Queue.c
 * Author: http://www.roytuts.com
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct element {
    int item;
    struct element *next;
} element;

typedef struct queue {
    element *front;
    element *rear;
} queue;

void add(int item, queue *q) {
    element *e;
    e = (element*) malloc(sizeof (element));
    e->item = item;
    e->next = NULL;
    if (q->front == NULL) {
        q->front = e;
        q->rear = e;
        return;
    }
    q->rear->next = e;
    q->rear = e;
}

int delete(queue *q) {
    element *e;
    if (q->front == NULL) {
        printf("\nQueue is empty\n");
        return 0;
    }
    e = q->front;
    q->front = q->front->next;
    if (q->rear == e) {
        q->rear = NULL;
    }
    free(e);
    return 1;
}

void display(queue *q) {
    element *t;
    if (q->front == NULL) {
        printf("\nQueue is Empty\n");
    } else {
        printf("\n");
        t = q->front;
        while (t->next != NULL) {
            printf("%d->", t->item);
            t = t->next;
        }
        printf("%d->NULL\n", t->item);
    }
}

int main() {
    int choice, value;
    queue *q = (queue*) malloc(sizeof (queue));
    q->front = q->rear = NULL;
    printf("\n:: Queue using Linked List ::\n");
    while (1) {
        printf("\nChoose from below Menu\n");
        printf("1. Add\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: printf("Enter the value to be added: ");
                scanf("%d", &value);
                add(value, q);
                break;
            case 2: delete(q);
                break;
            case 3: display(q);
                break;
            case 4: exit(0);
            default: printf("\nWrong selection!!! Please try again!!!\n");
        }
    }
}
