#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define SIZE 20
typedef struct stack
{
    int top;
    char arr[SIZE];
} STACK ;
//typedef struct stack STACK;

void push(STACK *s,char item)
{
    s->arr[++(s->top)]=item;
}

char pop(STACK *s)
{
    return s->arr[(s->top)--];
}

int preced(char sym)
{
    switch(sym)
    {
        case '^': return 5;
        case '*':
        case '/': return 3;
        case '+':
        case '-': return 1;
    }
}
void infixtopostfix(STACK *s,char infix[15])
{
    int i,j=0;
    char symbol,temp,postfix[15];
    for(i=0;infix[i]!='\0';i++)
    {
        symbol=infix[i];
        if(isalnum(symbol))   
            postfix[j++]=symbol;
        else
        {
            switch(symbol)
            {
                case '(':push(s,symbol);
                break;
                case ')':temp=pop(s);
                while(temp!='(')
                {
                    postfix[j++]=temp;
                    temp=pop(s);
                }
                break;
                case '+':
                case '-':
                case '*':
                case '/':
                case '^': if(s->top == -1 || s->arr[s->top] == '(')
                             push(s,symbol);
                          else
                          {
                              while(preced(s->arr[s->top]) >= preced(symbol) && s->top!=-1 && s->arr[s->top] != '(')
                                        postfix[j++]=pop(s);
                              push(s,symbol);
                          }
                          break;
              }
        }
    }
    while(s->top != -1)
        postfix[j++]=pop(s);
    postfix[j]='\0';
    printf("\n The postfix expression is : %s\n",postfix);
}

int main()
{
    char infix[15];
    STACK s;
    s.top=-1;
    printf("\n Read the infix expression\n");
    scanf("%s",infix);
    infixtopostfix(&s,infix);
    return 0;
}





















// #include<stdio.h>
// #include<stdlib.h>
// #define STACKSIZE 5
// typedef struct stackOperation {
//     int a[STACKSIZE],top ;   // items;
//     // int top;          //top;
// } stack;
// void push(stack *s,int x) {
//     if(s->top ==STACKSIZE-1) {
//         printf("Stack is full !!!!");
//         exit(0);
//     }

//     s->top++;
//     s->a[s->top] = x;
//     printf("Element added: %d\n ",s->a[s->top]);
//     }
// int pop(stack *s) {
//     if(s->top == -1) {
//         printf("Stack Underflow");
//         exit(0);
//     }
//     int x = s->a[s->top];
//     printf("POPed Element:%d\n",x);
//     s->top--;
//     return x;
// }
// // void display(stack *s) {

// //     if(s->p == -1) {
// //         printf("no elements found\n");
// //     }
// //     for(int i = 0; i < STACKSIZE-1; i++) {
// //         printf("%d",s->a[i]);
// //     }
// // }

// void display(stack *s) {
//     if (s->top == -1) {
//         printf("no elements found\n");
//         return;
//     }

//     for (int i = 0; i <= s->top; i++) {
//         printf("%d ", s->a[i]);
//     }
//     printf("\n");
// }


// int main() {
//     int choice,x;
//     stack st;
//     st.top = -1;
//     while(1) {
//         printf("Enter the choice:\n1.push\n2.pop\n3.display\n4.exit\n");
//         scanf("%d",&choice);
//         switch (choice) {

//             case 1:
//             printf("Enter the element to push into the stack:");
//             scanf("%d",&x);
//             push(&st,x);
//             break;

//             case 2: 
//             x =  pop(&st);
//             // printf("poped element is: %d\n",x);
//             break;
            
//             case 3:
//             printf("The elements are:");
//             display(&st);
//             break;

//             case 4:
//             printf("Exiting the program.\n");
//             exit(0);


//         }
//     }
// }