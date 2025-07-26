#include "mylib.h"
#include <time.h>
#include <math.h>

//Creat a new list
struct mylist*Creat(){
struct mylist*list=NULL;
return list;
}
// Insert a new element
struct mylist*Insert(struct mylist*head,int value){
struct mylist*p;
p=(struct mylist*)malloc(sizeof(struct mylist));
p->val=value;
p->next=head;
p->prev=NULL;
if(head!=NULL)
head->prev=p;

return p;
}
// Fill the list
struct mylist*Fill(struct mylist*head,int N){
for(int i=N;i>0;i--){

    head=Insert(head,rand());
}
return head;
}
struct mylist*Fill_range(struct mylist*head,int N,int rg){
for(int i=N;i>0;i--){
    head=Insert(head,rand()%rg);

}
}
// Search of a specific element
int Search(struct mylist*head,int value){
struct mylist*p=head;
while(p!=NULL&&p->val!=value){//go to the next element until we find the value
    p=p->next;
}
if(p==NULL)    // if we find empty linked list
    return 0;

if(p->val==value)  // if we find the specific value
    return 1;

}
// Remove one element
struct mylist*Remove(struct mylist*head,int value){
    struct mylist*p=head;
    struct mylist*q=head->next;
    if(p->val==value)//THE FIRST ELEMENT==Number
        {
        free(p);
        return q;
        }
    else{
while(q->val!=value){ //go to the next element until we find the value
     q=q->next;
    p=p->next;
}

if(q->val==value) // if linked list node=value
{
 p->next=q->next;
 free(q);
return head;
    }

    }

}
// Calculate the length of the list
int ListLength (struct mylist *list)
{
    struct mylist *temp = list;

    int i=0;
    while(temp!=NULL)
    {
        i++;
        temp=temp->next;

    }
    return i;
}
// swapping between two elements
void swapp(struct mylist*q,struct mylist*p){
struct mylist*tmp;
tmp=q->val;
q->val=p->val;
p->val=tmp;

}
// return the last node
struct mylist* last_node(struct mylist* head)
{
    struct mylist* temp = head;
    while (temp != NULL && temp->next != NULL) { //go the last node which is before the NULL
        temp = temp->next;
    }
    return temp;
}
// edit a value insted of the element  position
struct mylist*edit_Node(struct mylist*l,int pos,int valeur){
    struct mylist*p=l;
for(int i=1;i<=pos;i++)
p=p->next;

p->val=valeur;

return l;
}
// Delete a list
void DeleatList(struct mylist*head){
struct mylist;

while(head){
    head->next=NULL;
    head->prev=NULL;
    free(head);

}

}
// Print a list
void PrintList(struct mylist*head){

while(head!=NULL){
    printf("->%d",head->val);
    head=head->next;
}
}
// to calculate operation  time
void timeTaken(double timeTak){ // return the period of operation

printf("\n Time of operation =%f s\n",timeTak);
}

// to calculate operation complexity
int CalculatComplexity(int n,int i){


if(i==1|| i==2)
    return n*n;

else
    return n*log(n);


}






