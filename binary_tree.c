#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/* BST node */

struct node
{
int data;
struct node *left_child;
struct node *right_child;
};

typedef struct node* NODE;

/* Function to create a newnode */
NODE getnode()
{
NODE p;
p = (NODE) malloc(sizeof(struct node));
if(p== NULL)
{
 printf("Insufficient Memory");
 exit(0);
}
p->left_child= NULL;
p->right_child = NULL;
return p;
}


NODE  Create()
{
NODE q;
int x;
printf( "\nEnter the data to be inserted ");
scanf("%d",&x);
if( x == -1)
    return NULL;

q= getnode();
q->data =x;
printf("\nEnter the Left child of %d",x);
q->left_child=Create();
printf("\nEnter the Right child of %d",x);
q->right_child=Create();
return q;
}

void InOrder( NODE p)
{
  if( p )    // p != NULL
  {
        InOrder(p->left_child);
        printf(" %d ",p->data);
        InOrder(p->right_child);
  }
}
void PreOrder( NODE p)
{
  if( p != NULL)
  {
        printf(" %d",p->data);
        PreOrder(p->left_child);
        
        PreOrder(p->right_child);
  }
}
void PostOrder( NODE p)
{
  if( p)
  {
        PostOrder(p->left_child);
        PostOrder(p->right_child);
        printf(" %d",p->data);
  }
}
int Count( NODE p)
{
int c1,c2,c;
  if( p== NULL)
      return 0;
  c1 = Count(p->left_child);
  c2 = Count(p->right_child);
  c = 1+ c1 + c2;
  return c;
  
}

int CountLeaf( NODE p)
{
int c1,c2,c;
  if( p== NULL)
      return 0;
  if(p->left_child==NULL && p->right_child==NULL)
      return 1;
  c1 = CountLeaf(p->left_child);
  c2 = CountLeaf(p->right_child);
  c = c1 + c2;
  return c;
  
}
int main()
{
   
  int choice,c;
  NODE root=NULL;
  
  printf("Demonstration of BST Insert ,Delete, Display");
  while(1)
  {
     
     printf("\n1:Create\n2:Preorder Display\n3:Postorder Display \n4:Inorder Display\n5:Number of Nodes\n6:Number of leaf nodes\n Any other number:exit ");
     printf("\nEnter the Choice :");
     scanf("%d",&choice);
     switch(choice)
     {
        case 1:printf("\nEnter the Root node data");
               root=Create();
               break;
        
        case 2 :printf("\nTraversal of BT : Preorder");
                PreOrder(root);
                break;
        case 3 :printf("\nTraversal of BT : Postorder");
                PostOrder(root);
                break;       
        case 4 :printf("\nTraversal of BT : inorder");
                InOrder(root);
                break;
        case 5 :c=Count(root);
                printf("Number of Nodes in the tree is %d",c);
                break; 
         case 6 :c=CountLeaf(root);
                printf("Number of Leaf Nodes in the tree is %d",c);
                break;
        default:exit(0);

     } //switch
  
  }//while
    return 0;
}//main
