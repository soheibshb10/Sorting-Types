#ifndef MYLIB_H_INCLUDED
#define MYLIB_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct mylist{
int val;
struct mylist*next;
struct mylist*prev;
};


struct mylist*Creat();
struct mylist*Insert(struct mylist*head,int value);
struct mylist*Fill(struct mylist*head,int N);
int Search(struct mylist*head,int value);
struct mylist*Remove(struct mylist*head,int value);
int ListLength (struct mylist *list );
void swapp(struct mylist*q,struct mylist*p);
struct mylist* last_node(struct mylist* head);
struct mylist*edit_Node(struct mylist*l,int pos,int valeur);
void DeleatList(struct mylist*head);
void PrintList(struct mylist*head);







#endif  MYLIB_H_INCLUDED









