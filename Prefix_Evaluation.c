// // #include <stdio.h>
// // #include<math.h>
// // #define max 10

// // struct stack
// // {
// //     int a[max];
// //     int top;
// // } s;

// // void push(int ele)
// // {
// //     s.a[++s.top] = ele;
// // }

// // int pop()
// // {
// //     return s.a[s.top--];
// // }

// // int compute(int opnd1, char op, int opnd2)
// // {
// //     switch (op)
// //     {
// //     case '*':
// //         return opnd1 * opnd2;
// //     case '+':
// //         return opnd1 + opnd2;
// //     case '-':
// //         return opnd2 - opnd1;
// //     case '/':
// //         return opnd1 / opnd2;
// //     case '$':
// //         return pow(opnd1, opnd2);
// //     }
// // }
// //     int main()
// //     {
// //         s.top = -1;
// //         char exp[max], sym;
// //         int opnd1, opnd2, value, i=0;
// //         printf("Enter prefix expression:\n");
// //         scanf("%s", exp);
// //         while(exp[i]!='\0'){
// //             i++;
// //         }

// //         for (--i; i>=0; i--)
// //         {
// //             sym = exp[i];
// //             if (sym >= '0' && sym <= '9')
// //             {
// //                 push(sym - '0');
// //             }
// //             else
// //             {
// //                 opnd1 = pop();
// //                 opnd2 = pop();
// //                 value = compute(opnd1, sym, opnd2);
// //                 push(value);
// //             }
// //         }
// //         printf("Result : %d\n",pop());
// //         return 0;
// //     }




/* Evaluation of Prefix  Expression */
/* Assumption: operands of single digit */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define STACKSIZE  100                                     
struct stack 
 {
     float items[STACKSIZE]   ;
     int top ;
};


void push(struct stack *s, float x)
{
     if(s->top == (STACKSIZE-1))
     {
             printf("Stack Overflow\n");
             exit(0);
     } 
    s->top ++;
    s->items[s->top] = x;
}
float pop(struct stack *s)
{
    float x;
     if(s->top == -1)
     {
             printf("Stack Underflow!\n");
             exit(0);
     } 
    
    x= s->items[s->top];
    s->top --;
    return x;
}



float Apply(char op,float a, float b)
{
    
  switch(op)
  {
     case '+' : return a+b;
     case '-' : return a-b;
     case '*' : return a*b;
     case '/' : if ( b ==0)
                { 
                   printf( "Division by Zero Error");
                   exit(0);
                }
                return a/b;
     default  : printf("\nError\n");
                exit(0);   
  }
}
float PrefixEvaluation(char prefix[])
{
 
  int i ;
  char symb;  
  float opnd1,opnd2,res,digit;

  struct stack st; 
  st.top =-1;

  i=strlen(prefix)-1;  
  
  
  while(i>=0)  
  {
        symb=prefix[i--];                 
         
        if(symb >='0' && symb <='9')   
        {        
                 digit=(float) (symb-'0');
                 push (&st,digit);
        }
        else 
        {
             opnd1=pop(&st); 
             opnd2=pop(&st);
             res=Apply(symb,opnd1,opnd2);
             push(&st,res);     
        }
   }        
   res=pop(&st);
   if(st.top !=-1)
   {
         printf("\nError\n");
         exit(0);
      
   }
   return res;
 }


int main()
{
   
   char prefix[100];
   float result;
  
     printf("\n Evaluation of Prefix Expression ");
     printf("\nEnter the prefix Expression :");  //Exampe +12
     scanf("%s",prefix);
     result = PrefixEvaluation(prefix);
     printf("\nResult = %f",result);
     return 0;
}


// #include <stdio.h>
// #include <stdlib.h>
// #include <ctype.h>
// #include <string.h>
// #define SIZE 10

// struct stack
// {
//     int top;
//     float data[SIZE];
// };
// typedef struct stack STACK;

// void push(STACK *s,float item)
// {
//     s->data[++(s->top)]=item;
// }

// float pop(STACK *s)
// {
//     return s->data[(s->top)--];
// }

// float operate(float op1,float op2,char symbol)
// {
//     switch(symbol)
//     {
//         case '+' : return op1 + op2;
//         case '-' : return op1 - op2;
//         case '*' : return op1 * op2;
//         case '/' : return op1 / op2;
//     }
// }

// float evalprefix(STACK *s,char prefix[10])
// {
//     char symbol;
//     float op1,op2,res;
//     int i;
//     for(i=strlen(prefix)-1;i>=0;i--)
//     {
//         symbol=prefix[i];
//         if(isdigit(symbol))
//             push(s,symbol-'0');
//         else
//         {
//             op1=pop(s);
//             op2=pop(s);
//             res=operate(op1,op2,symbol);
//             push(s,res);
//         }
//     }
//     return pop(s);
// }

// int main()
// {
//     char prefix[10];
//     float ans;
//     STACK s;
//     s.top=-1;
//     printf("\n Read the postfix expression\n");
//     scanf("%s",prefix);
//     ans=evalprefix(&s,prefix);
//     printf("\n The final answer is %f\n",ans);
//     return 0;
// }




// #include<stdio.h>
// #include<stdlib.h>
// #define SIZE 15
// char  infix[SIZE],postfix[SIZE];
// char stack[SIZE];
// int top=-1;
// void push(char item){
//     stack[++top]=item;
// }
// char pop(){
//     --top;
// }
// int pri(char sym){
//     if(sym=="+"||sym=="-")
//         return 0;
//     else if(sym=="*"||sym=="/"){
//         return 1;
//     }
//     else if(sym=="^"){
//         return 0;
//     }
// }
// infix[SIZE]="a+b*c";
// void infpo(){
//     int i,j;
//     char temp;
//     char symbol;
//     for(i=0;infix[i]="/0";i++)
//     {
//         symbol=infix[i];
//         if(isalnum==infix[i])
//         {
//             postfix[i]=symbol;
//         }
//         else
//         {
//             switch(symbol)
//             {
//                 case "(" :push(symbol);
//                 break;
//                 case ")" :temp=pop();
//                 while(temp!="(")
//                 {
//                     postfix[j++]=temp;

//                 }
//                 break;
//                 default:if(pri(stack[top])>infix[i]){
//                     postfix[j++]=pop();
//                     pop();
//                 }
//                 pop();
//             }
//         }
//     }
// }
// int main(){
//     void inpo();
//     for(int i=0;i<="\0";i++){
//         printf("%d",postfix[i]);
//     }
// }