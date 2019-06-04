/* 
 * File:   DoublyLinkedList.c
 * Author: https://www.roytuts.com
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    struct node *left;
    int data;
    struct node *right;
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

    //point to the left and right node
    newNode->left = NULL;
    newNode->right = NULL;

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
    while (current->right != NULL) {
        current = current->right;
    }

    //create the new node
    node* newNode = createSingleNode(data);

    //point current node to the new node
    current->right = newNode;
    newNode->left = current;
    newNode->right = NULL;

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
        newNode->right = head;
        head->left = newNode;
        head = newNode;
        return head;
    }

    //point to the first node
    current = head;

    for (j = 1; j < position && current != NULL; j++) {
        current = current->right;
    }

    if (current != NULL) {
        temp = current;
        newNode->right = temp->right;
        newNode->left = temp->left;
        temp->right = newNode;
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
        head = head->right;
        free(current);
        return head;
    }

    //make next pointer of temp node to NULL
    temp = current->right;

    for (j = 1; j < position && temp != NULL; j++) {
        current = temp;
        temp = temp->right;
    }

    if (current != NULL) {
        current->right = temp->right;
        temp->left = NULL;
        temp->right = NULL;
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

    while (r->right != NULL) {
        r = r->right;
    }

    q->left = r;
    r->right = q;

    return p;
}

/*
 * Reverse LinkedList
 */
node* reverse(node* head) {
    if (head == NULL || head->right == NULL) {
        return head;
    }
    node *p;
    p = head;
    while (p->right != NULL) {
        node *temp = p->right;
        p->right = p->left;
        p->left = temp;
        p = temp;
    }
    p->right = p->left;
    p->left = NULL;
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
        current = current->right;
        if (current != NULL) {
            printf("<->");
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
