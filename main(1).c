#include "mylib.h"




int main(){
    clock_t end,start;
    double timetaken;
    int Nb,rngm,num,Valserch,pos,value,valr,Valrem,answ1,answ2,answ3,answ4,exist;
    char Nbansw1;
    struct mylist*head;
    struct mylist*deb;

    printf("do you want to creat a list (Y/N):");
    scanf("%c",&answ1);
   if(answ1 ==  'y'|| answ1 ==  'Y'){
    head=Creat();
   printf("Donner le nombre des elements:");
   scanf("%d",&Nb);
   printf("Chose the fill type \n (1)-Automatic Filling (2)-Manual Filling \n (3)-Automatic Filling with a specific range:\n");
   scanf("%d",&answ2);
   if(answ2==1)
   head=Fill(head,Nb);
    else if(answ2==2){
        for(int i=1;i<=Nb;i++){
        scanf("%d",&value);
        head=Insert(head,value); //Insert one in the begining
        }
    }
    else{
        printf("Enter the max range:");
        scanf("%d",&rngm);
        head=Fill_range(head,Nb,rngm);
    }
   }
Option:// Display all options
if(head){
    printf("-------------------OPTIONS--------------------\n  (1)-Search of an element \n (2)-Remove an element \n (3)-modify an element \n (4)-Sort options  \n (5)-Delete List \n (6)-Print a List  \n " );
scanf("%d",&answ3);
switch(answ3){
//Search of an element
case 1:
    printf("What is the value do you want to find it: ");
    scanf("%d",&Valserch);
    if(Search(head,Valserch)==1)
        printf("THE VALUE %d IS EXISTED ",Valserch);
    if(Search(head,Valserch)==0)
        printf("THE VALUE %d IS NOT EXISTED ",Valserch);
    break;
case 2:
    // remove an element
    printf("What is the value do you want to remove it: ");
    scanf("%d",&Valrem);
     if(Search(head,Valrem)!=1)
      printf("WE CAN NOT REMOVE THIS VALUE BECAUSE IT IS NOT EXISTED");
     if(Search(head,Valrem)==1){
        head=Remove(head,Valrem);
    printf("THE VALUE %d WAS REMOVED ",Valrem);
    }

    break;
case 3:  // edit an element
    printf("What is the position of element do you want to edit:");
    scanf("%d",&pos); // chose the position of changed element
    printf("What is the new value of element:");
        scanf("%d",&valr); // enter the new element value
    head=edit_Node(head,pos,valr); // modify the value of element
    break;
case 4: // sort option
    goto sort1;
    break;
case 5:
    DeleatList(head); // Delete the linked list
    printf("The list is empty");
default: // Print the list
    printf("------------------My List------------------------------\n");
    PrintList(head);
    break;
}
}
else
printf("The linked list is empty");

goto OPEX;// the small options

      sort1: // sort options: 1-selection sort 2-Insertion sort 3-Quick sort 4-Quick sort random pivot

     printf("\n Choose the sort type :\n 1/Selection sort \n 2/Insertion sort: \n 3/Quick sort:\n 4/Quick sort select a Random pivot\n");
      scanf("%d",&num); //   your choice
      if(num==1){
   start = clock();
  head=tri_Selection(head); //do a selection sort
  end = clock();
 timetaken =((double)end-(double)start)/1000; // the period between start of operation and the end
    printf("\n------------------------ Selection sort------------------------\n");
PrintList(head); // print the list
timeTaken(timetaken); // print the time of operation
 printf("THE COMPLEXITYO(N^2)=%d OPERATION",CalculatComplexity(Nb,1));
      }
            else if(num==2){
        start = clock(); // determine the current time
      head=tri_Insertion(head); //do insertion sort
      end = clock();
   timetaken =((double)end-(double)start)/1000;// the period between start of operation and the end
printf("\n------------------------Insertion sort------------------------\n");
   PrintList(head);
    timeTaken(timetaken);// print the time of operation
     printf("THE COMPLEXITY O(N^2)=%d OPERATION",CalculatComplexity(Nb,2));

            }


else if(num==3){
    start = clock(); // Determine the current time
   deb=head;
   tri_Rapide(deb,last_node(head)); // do quick sort
    end = clock();
  timetaken =((double)end-(double)start)/1000;// the period between start of operation and the end
    printf("\n------------------------Quick sort ------------------------\n");
   PrintList(head); // Print sorted linked list
    timeTaken(timetaken);// print the time of operation
     printf("THE COMPLEXITY O(N*log(N)=%d OPERATION",CalculatComplexity(Nb,3));

            }
else {
        start = clock();  //Determine the current time
   deb=head;
   tri_Rapide_Random(deb,last_node(head)); // do quick sort with a random pivot
   end = clock();
 timetaken =((double)end-(double)start)/1000;// the period between start of operation and the end
 printf("\n------------------------Quick sort random pivot------------------------\n");
   PrintList(head);  // print sorted linked list
timeTaken(timetaken); // print the time of operation
        printf("THE COMPLEXITY O(N*log(N))=%d OPERATION ",CalculatComplexity(Nb,4));

}
//small options
goto OPEX ;
OPEX:
printf("\n Do you want to show option (1) \ Do you want to exit the program (2)  ");
scanf("%d",&answ4); // chose your answer
if(answ4==1)
    goto Option; // jump to all the options





}

