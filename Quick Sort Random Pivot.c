#include "mylib.h"
// return a random pivot
struct mylist*random_Pivot(struct mylist*start){

    int k, s, i = 0;
    s = ListLength(start);


    struct mylist *pivot=start;

    k=rand()%s;

    for (i=1; i <= k; ++i)
    {
        pivot=pivot->next;
    }

    return pivot;
}
// cut the list to partition start to last
struct mylist* parition_Random(struct mylist* first, struct mylist* last)
{
    // Get first node of given linked list
    struct mylist* pivot = random_Pivot(first);
    struct mylist*part=first;
    struct mylist* front = first;
    int temp = 0;
    while (front != NULL && front != last) {
        if (front->val > pivot->val) {
            part = first;

            // Swapping  node values
            swapp(first,front);

            // Visiting the next node
            first = first->next;
        }

        // Visiting the next node
        front = front->next;
    }

    // Change last node value to current node
    swapp(first,pivot);
    return part;
}
// quick sort the list by use call recursive
void tri_Rapide_Random(struct mylist* first, struct mylist* last)
{
    if (first == last)
        return ;    //base condition

    struct mylist* part = parition(first, last); // return the partition

   if (part != NULL && part->next != NULL)
         tri_Rapide(part->next, last);


   if (part != NULL && first != part)
         tri_Rapide(first, part);

}



