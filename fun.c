#include "fun.h"

void appendDLL(struct node** head, int key)
{
    struct node* node = (struct node *)malloc(sizeof(struct node));
    node->value = key;
    node->prev = NULL;
    node->next = *head;
 
    if (*head!= NULL)
        (*head)->prev = node;
 
    *head = node;
}

void printDLL(struct node* head)
{
    while (head != NULL)
    {
        printf("%d —> ", head->value);
        head = head->next;
    }
 
    printf("NULL\n");
}

void swap(struct node* node)
{
    struct node* prev = node->prev;
    node->prev = node->next;
    node->next = prev;
}

void reverseDLL(struct node** head)
{
    struct node* prev = NULL;
    struct node* temp = *head;
 
    while (temp != NULL)
    {
        // swap `next` and `prev` pointers 
        swap(temp);
 
        // update the previous node after move to the next node
        prev = temp ;

        temp = temp->prev;
    }
    
    if (prev != NULL) {
        *head = prev;
    }
}
void appendNode(struct node ** head, int value)
{
    struct node * newNode = (struct node *) malloc(sizeof(struct node));
    struct node * lastNode = *head;
    newNode -> value = value;
    newNode -> next = NULL;
    
    if(*head == NULL)
    {
        *head = newNode;
        return;
    }
    
    while(lastNode->next != NULL)
    {
        lastNode = lastNode -> next;
    }
    
    lastNode -> next = newNode;
}
void prependNode(struct node ** head, int value)
{
    struct node * newNode = (struct node*) malloc(sizeof(struct node));
    
    newNode -> value = value;
    newNode -> next = (*head);
    (*head) = newNode;
}

 void reverselist(struct node** head)
{
    struct node* prev = NULL;
    struct node* current = *head;
    struct node* next = NULL;
    while (current != NULL) {

        next = current->next;

        current->next = prev;

        prev = current;
        current = next;
    }
    *head = prev;
}

void insertAt(struct node ** head, int value, int index)
{
    struct node * newNode = (struct node*) malloc(sizeof(struct node));
    struct node * tempHead;
    tempHead = *head;
    newNode->value = value;
    
    for(int i = 2; i < index; i++)
    {
        if(tempHead -> next != NULL)
        tempHead = tempHead -> next;
    }
    newNode -> next = tempHead -> next;
    tempHead -> next = newNode;
    
}

void removeFrom(struct node ** head, int index)
{
    struct node * tempHead = *head;
    struct node * tempNext = (*head) -> next;
    
    for(int i = 0; i < index - 1; i++)
    {
        tempHead = tempHead -> next;
        tempNext = tempNext -> next;
    }
    tempHead -> next = tempNext -> next;
}

bool searchValue(struct node * head, int value)
{
    struct node * tempHead = head;
    while(tempHead != NULL)
    {
        if(tempHead -> value == value)
            return true;
        tempHead = tempHead -> next;
    }
    return false;
}


struct node * mergeLists(struct node * head_1, struct node * head_2)
{
    struct node *head, *n;

    n = head = NULL;

    while (head_1 != NULL && head_2 != NULL) {
        if (head_1->value <= head_2->value) {
            if (n == NULL) {
                n = head = head_1;
            } else {
                n = n->next = head_1;
            }
            head_1 = head_1->next;
        } else {
            if (n == NULL) {
                n = head = head_2;
            } else {
                n = n->next = head_2;
            }
            head_2 = head_2->next;
        }
    }                
    if (head_1 != NULL) {
        if (n == NULL) {
            head = head_1;
        } else {
            n->next = head_1;
        }
    } else {
        if (n == NULL) {
            head = head_2;
        } else {
            n->next = head_2;
        }
    }
    return head;
}
void writeNodes(struct node * root) {
    FILE* file = fopen("list.txt", "w");
    if (file == NULL) {
        exit(1);
    }

    for (struct node * curr = root; curr != NULL; curr = curr->next) {
        fprintf(file, "%d, ", curr->value);
    }
    fclose(file);
}

void readNodes(struct node ** root) {
    FILE* file = fopen("list.txt", "r");
    if (file == NULL) {
        exit(2);
    }

    int val;
    while(fscanf(file, "%d, ", &val) > 0) {
        appendNode(root, val);
    }
    fclose(file);
}
void print(struct node * head)
{
    while( head != NULL)
    {
        printf("%d -> ",head->value);
        head = head ->next;
    }
    printf("\n");
}

void sortedInsert(struct node** head, struct node* newNode)
{
    struct node dummy;
    struct node* current = &dummy;
    dummy.next = *head;
 
    while (current->next != NULL && current->next->value < newNode->value) {
        current = current->next;
    }
 
    newNode->next = current->next;
    current->next = newNode;
    *head = dummy.next;
}
 
void insertSort(struct node** head)
{
    struct node* result = NULL;    
    struct node* current = *head;   
    struct node* next;
 
    while (current != NULL)
    {
        next = current->next;
 
        sortedInsert(&result, current);
        current = next;
    }
 
    *head = result;
}
