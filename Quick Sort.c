#include "mylib.h"

// cut the list in partition
struct mylist* parition(struct mylist* first, struct mylist* last)
{
    // Get first node of given linked list
    struct mylist* pivot = last;   // the pivot=last element
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

// Performing quick sort in  the given linked list
void tri_Rapide(struct mylist* first, struct mylist* last)
{
    if (first == last)
        return ;     //base condition

    struct mylist* part = parition(first, last);//Selection the petition

   if (part != NULL && part->next != NULL)
         tri_Rapide(part->next, last); // cal the function recursevly


   if (part != NULL && first != part)
         tri_Rapide(first, part);   // cal the function recursevly

}
