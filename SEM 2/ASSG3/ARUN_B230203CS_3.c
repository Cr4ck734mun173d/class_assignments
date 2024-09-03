#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_LEN 100
typedef struct data
{
    char formula[MAX_LEN];
}input;
typedef struct node
{
    int size;
    int top;
    char *arr;
}stack;

int isEmpty(stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull( stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
char pop(stack* ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }
    else{
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
void push(stack* ptr, char val){
    if(isFull(ptr)){
        printf("Stack Overflow! Cannot push %d to the stack\n", val);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

int parenthesisMatch(char * exp){
    
    stack *sp = (stack *)malloc(sizeof(stack));
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
 
 
    for (int i = 0; exp[i]!='\0'; i++)
    {
        if(exp[i]=='('){
            push(sp, '(');
        }
        else if(exp[i]==')'){
            if(isEmpty(sp)){
                return 0;
            }
            pop(sp); 
        }
    }
 
    if(isEmpty(sp)){
        return 1;
    }
    else{
        return 0;
    }
    
}
int main()
{
    int n;
    scanf("%d",&n);
    getchar();
    input exp[n];
    for (int i = 0; i < n; i++)
    {
        fgets(exp[i].formula,MAX_LEN,stdin);
        exp[i].formula[strcspn(exp[i].formula,"\n")]='\0';
        if (exp[i].formula[0]=='\0')
        {
            i--;
            continue;
        }
        
    }
    
    int count=0;
    for (int i = 0; i < n; i++)
    {
        if (parenthesisMatch(exp[i].formula))
        {
            count++;
        }

        
    }
    printf("%d",count);

    return 0;
}