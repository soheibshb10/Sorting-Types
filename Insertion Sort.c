#include "mylib.h"

// insert sorted element and save the sorting then  linked list
struct mylist*sortedInsert(struct mylist* head, struct mylist* newNode)
{
    // special case for the head end
    if (head == NULL )
    {
        return newNode;
    }
else if(head->val <= newNode->val){   //if the node value <= newNode value
    newNode->next=head;
    newNode->next->prev=newNode;
    head=newNode;
    return newNode;
}
    // locate the node before the point of insertion
   else{    // if the node >newNode value
    struct mylist* current = head;
    while (current->next != NULL && current->next->val > newNode->val) {
        current = current->next;
    }

    newNode->next = current->next;
    if(current->next!=NULL){
    newNode->next->prev=newNode;
    }
    current->next = newNode;
    newNode->prev=current;
    return head;  //return the list
}
}

// To do Insertion sort
struct mylist*tri_Insertion(struct mylist*l){
struct mylist*ls=Creat();
struct mylist*p=l;
while(l){
    struct mylist*q=l;
    l=l->next;
    q->prev=NULL;
    q->next=NULL;
    ls=sortedInsert(ls,q);
}
return ls;  // return the linked list
}
