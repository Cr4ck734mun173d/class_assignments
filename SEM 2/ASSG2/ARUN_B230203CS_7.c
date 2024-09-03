#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20
typedef struct Stacknode
{
    char url[MAX];
    struct Stacknode* link;
}Stacknode;

typedef struct 
{
    Stacknode* top;
}Stack;
void Visit_New_Page(Stack* stack);
void Go_Back(Stack* stack);
void Clear_History(Stack* stack);
void Display_History(Stack* stack);
void Menu();

int main(){
    Stack stack={NULL};

    while (1)
    {
        printf("Menu:\n1. Visit New Page\n2. Go Back\n3. Clear History\n4. Display History\n5. Exit\nEnter your choice: ");
        int choice;
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            Visit_New_Page(&stack);
            break;
        case 2:
            Go_Back(&stack);
            break;
        case 3:
            Clear_History(&stack);
            break;
        case 4:
            Display_History(&stack);
            break;
        case 5:
            printf("Exiting..");
            return 0;
            break;
        default:
            printf("Invalid Input. Enter a value between 1 and 4.\n");
            break;
        }
    }
    

    return 0;
}
Stacknode *Create_Node(char *url)
{
    Stacknode *newnode=(Stacknode*)malloc(sizeof(Stacknode));
    if (newnode==NULL)
    {
        printf("Error.Memory Allocation failed");
        return NULL;
    }
    strcpy(newnode->url,url);
    newnode->link=NULL;
    return newnode;

    
}
void Visit_New_Page(Stack *stack)
{
  printf("Enter URL: ");
  char URL[MAX];
  scanf("%s",URL);

    Stacknode *newnode=Create_Node(URL);
    newnode->link=stack->top;
    stack->top=newnode;
    printf("Page '%s' visited successfully.\n",newnode->url);
  
    
}

void Go_Back(Stack *Stack)
{
    if (Stack->top==NULL)
    {
        printf("No pages to go back to.\n");
        return;
    }
    Stacknode* temp=Stack->top;
    Stack->top=temp->link;
    
    printf("Navigating back to page '%s'\n",temp->link->url);
    free(temp);
}
void Clear_History(Stack* stack)
{
    while (stack->top!=NULL)
    {
        Stacknode* temp=stack->top;
        stack->top=temp->link;
        free(temp);
    }
    printf("History Cleared.\n");
    
}
void Display_History(Stack* stack)
{
    if (stack->top==NULL)
    {
        printf("History empty.\n");
    }
    
    Stacknode* TempTop=stack->top;
    printf("Browsing History: \n");
    while (TempTop!=NULL)
    {
        
        printf("'%s'\n",TempTop->url);
        TempTop=TempTop->link;

    }
    
}