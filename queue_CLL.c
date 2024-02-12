
#include <stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node* next;
};

typedef struct node *NODE;
NODE last=NULL;

struct node *getnode()
{
struct node *p;
p = (NODE) malloc(sizeof(struct node));
if(p== NULL)
{
 printf("Insufficient Memory");
 exit(0);
}
p->next = p;
return p;
}
void enqueue(int x)
{
    NODE p;
    p =getnode();
    p->data =x;
    if (last == NULL)
    {
         last =p;
         return;
    }
    p->next =last->next;
    last->next =p;
    last=p;
}
void dequeue()
{
    NODE p;
   
    if (last == NULL)
    {
         printf("Empty Queue");
         return;
    }
    p=last->next;
    printf("Deleted lement is %d",p->data);
    if(last == p)
      last = NULL;
    else  
      last->next =p->next;
    free(p);;
}
void display()
{
   NODE p;
   
    if (last == NULL)
    {
         printf("Empty Queue");
         return;
    } 
    p=last->next;
    printf(" \n Elements of queue :");
    do{
        printf(" %d ",p->data);
        p=p->next;
    }while(p != last ->next);
}
int main() {
    int x,ch;
    // Write C code here
   while(1)
   {
       printf(" \n 1. Insert 2. Delete 3. Display 4. Exit \n");
       printf("Enter the choicec:");
       scanf("%d",&ch);
       switch(ch)
       {
           case 1: printf("Enter the element to be inserted :");
                   scanf("%d",&x);
                   enqueue(x);
                   break;
           case 2: dequeue();
                   break;
           case 3: display();
                   break;
           default: exit(0);
       }
   }

    return 0;
}