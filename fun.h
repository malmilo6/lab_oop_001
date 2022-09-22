#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#ifndef FUN_H
#define FUN_H

struct node{
    int value;
    struct node * next;
    struct node * prev;
};
void appendDLL(struct node** head, int key);
void printDLL(struct node* head);
void swap(struct node* node);
void reverseDLL(struct node** head);
void appendNode(struct node ** head, int value);
void prependNode(struct node ** head, int value);
void reverselist(struct node ** head);
void insertAt(struct node ** head, int value, int index);
void removeFrom(struct node ** head, int index);
bool searchValue(struct node * head, int value);
struct node * mergeLists(struct node * head_1, struct node * head_2);
void writeNodes(struct node * root);
void readNodes(struct node ** root);
void print(struct node * head);
void sortedInsert(struct node** head, struct node* newNode);
void insertSort(struct node** head); 

#endif