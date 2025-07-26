#include "mylib.h"

struct mylist*identifie_extremum(struct mylist*lis,int mode)
{
  struct mylist*ext=lis;
  struct mylist*t=lis->next;

  while(t!=NULL){
      if(mode==0 &&(t->val<ext->val))
        ext=t;
    if(mode==1 && (t->val>ext->val))
        ext=t;
  t=t->next;

  }
  return ext;

}


void tri_Selection(struct mylist**l){
if(*l==NULL)
    return;
struct mylist*min=identifie_extremum(l,0);
deltext(*l,min);
min->next=NULL;
min->prev=NULL;
tri_Selection(*l,min);

Insert_front(*l,min);
}

void Insert_front(struct mylist**l,struct mylist*v){

if(*l==NULL)
    *l=v;

v->next=*l;
*l->prev=v;
*l=v;

}


