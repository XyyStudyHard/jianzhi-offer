#include <stdio.h>
#include <stdlib.h>
  
typedef struct node{
    int data;
    struct node * next;
} Node;
  
void Print_TailtoHead (Node * head){
    Node * p = head;
  
    if (p != NULL){
        Print_TailtoHead (p->next);
        printf ("%d\n", p->data);
    }
}
  
int main(void){
    int input;
    Node * head = NULL;
    Node * p = NULL;
    Node * q = NULL;
  
    head = (Node *)malloc(sizeof(Node));
    head->next = NULL;
    p = head;
    while (scanf ("%d", &input) != EOF && input != -1){
        q = (Node *)malloc(sizeof(Node));
        q->data = input;
        q->next = NULL;
        p->next = q;
        p = p->next;
    }
    Print_TailtoHead (head->next);
  
    return 0;
}