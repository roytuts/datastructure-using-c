/* 
 * File:   LinkedList.c
 * Author: https://www.roytuts.com
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

/*
 *Create a new node
 */
node* createSingleNode(int data) {
    //allocate the memory for new node
    node* newNode = (node*) malloc(sizeof (node));

    //error allocating memory to new node
    if (newNode == NULL) {
        printf("Error creating new node. So exiting...\n");
        exit(0);
    }

    //put the data
    newNode->data = data;

    //point to the next node
    newNode->next = NULL;

    return newNode;
}

/*
 *Append new node at the end of the list
 */
node* appendNode(node* head, int data) {
    //if root node not found
    if (head == NULL) {
        return NULL;
    }

    //point to the first node
    node* current = head;

    //go to the last node
    while (current->next != NULL) {
        current = current->next;
    }

    //create the new node
    node* newNode = createSingleNode(data);

    //point current node to the new node
    current-> next = newNode;

    return head;
}

/*
 * Create multiple nodes
 */
node* createMultipleNodes() {
    int i, noOfNodes, data;

    printf("Enter no. of nodes to be created: ");
    scanf("%d", &noOfNodes);

    printf("Enter data for node: ");
    scanf("%d", &data);

    node* head = createSingleNode(data);

    for (i = 1; i < noOfNodes; i++) {
        printf("Enter data for node: ");
        scanf("%d", &data);
        head = appendNode(head, data);
    }
    return head;
}

/*
 * Insert new node into the existing linked list
 */
node* insertNode(node* head, int position, node* newNode) {
    int j;
    node *current, *temp;

    //if root node not found
    if (head == NULL) {
        return NULL;
    }

    //if  new node not found
    if (newNode == NULL) {
        return head;
    }

    //if new node to be inserted at first position
    if (position == 0) {
        newNode->next = head;
        head = newNode;
        return head;
    }

    //point to the first node
    current = head;

    for (j = 1; j < position && current != NULL; j++) {
        current = current->next;
    }

    if (current != NULL) {
        temp = current;
        newNode->next = temp->next;
        temp->next = newNode;
        return head;
    }

    return NULL;
}

/*
 *Remove node at specified position
 */
node* removeNode(node* head, int position) {
    int j;
    node *current, *temp;

    //if root node not found
    if (head == NULL) {
        return NULL;
    }

    current = head;

    if (position == 0) {
        head = head->next;
        free(current);
        return head;
    }

    //make next pointer of temp node to NULL
    temp = current->next;

    for (j = 1; j < position && temp != NULL; j++) {
        current = temp;
        temp = temp->next;
    }

    if (current != NULL) {
        current->next = temp->next;
        temp->next = NULL;
        free(temp);
        return head;
    }

    return NULL;
}

/*
 * Concatenate two LinkedLists
 */
node* concatenate(node* p, node* q) {
    node* r;
    if (p = NULL) {
        p = q;
    }

    r = p;

    while (r->next != NULL) {
        r = r->next;
    }

    r->next = q;

    return p;
}

/*
 * Reverse LinkedList
 */
node* reverse(node* head) {
    node *p, *q, *r;
    p = head;
    q = NULL;
    r = p->next;
    while (p->next != NULL) {
        p->next = q;
        q = p;
        p = r;
        r = p->next;
    }
    p->next = q;
    return p;
}

/*
 * Print LinkedList
 */
void printLinkedList(node* head) {
    //if root node not found
    if (head == NULL) {
        return;
    }
    node* current = head;

    printf("\n");

    //traverse and print data
    while (current != NULL) {
        printf("%d", current->data);
        current = current->next;
        if (current != NULL) {
            printf("->");
        }
    }

    printf("\n");

    head = current;
}

void main() {
    //create single node
    node* head = createSingleNode(5);
    //append node one after another
    appendNode(head, 10);
    appendNode(head, 15);
    appendNode(head, 20);
    appendNode(head, 25);
    printf("\nLinkedList with created nodes");
    printLinkedList(head);

    //create multiple nodes
    head = createMultipleNodes();
    //print nodes
    printf("\nLinkedList with created nodes");
    printLinkedList(head);

    //create single node
    node* newNode = createSingleNode(25);
    //insert new node at position 2
    head = insertNode(head, 2, newNode);
    //print nodes
    printf("\nLinkedList after inserting new node at position 2");
    printLinkedList(head);

    //remove node from position 2
    head = removeNode(head, 2);
    //print nodes
    printf("\nLinkedList after removing node from position 2");
    printLinkedList(head);

    //reverse LinkedList
    head = reverse(head);
    //print nodes
    printf("\nLinkedList after reversing");
    printLinkedList(head);
}
