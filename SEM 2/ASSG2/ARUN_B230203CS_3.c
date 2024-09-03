#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *CreateNode(int data)
{

    node *newnode = (node *)malloc(sizeof(node));
    if (newnode == NULL)
    {
        printf("Error Memory Allocation Failed!");
        return NULL;
    }
    newnode->data = data;
    newnode->next = NULL;

    return newnode;
}
void InsertNode(node **Head, int data)
{
    node *newnode = CreateNode(data);
    if (newnode == NULL) 
    {
        printf("Error. Failed to create node. Memory allocation failed!\n");
        return;
    }

    if (*Head == NULL)
    {
        *Head = newnode;
    }
    else
    {
        node *temp;
        temp = *Head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}
void Print(node *Head)
{
    node *temp = Head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void Sort(node **Head)
{
    node **temp = Head;

    int flag = 0;
    int n = 0;
    while (*temp != NULL)
    {
        n++;
        temp = &((*temp)->next);
    }

    for (int i = 0; i < n; i++)
    {
        temp = Head;
        flag = 0;
        for (int j = 0; j < n - 1 - i; j++)
        {
            node *p1 = *temp;
            node *p2 = p1->next;
            if (p1->data > p2->data)
            {
                p1->next = p2->next;
                p2->next = p1;
                *temp = p2;
                flag = 1;
            }
            temp = &((*temp)->next); 
        }
        if (flag == 0)
        {
            break;
        }
    }
}
int main()
{

    node *Head = NULL;
    int num = 0;
    while (1)
    {
        //printf("Enter choice: ");
        char a;
        scanf(" %c", &a);
        
        
        switch (a)
        {
        case 'i':
            //printf("Enter data: ");
            
            scanf("%d", &num);

            InsertNode(&Head, num);

            break;
        case 'p':
            Print(Head);
            printf("\n");
            break;
        case 's':
            Sort(&Head);
            break;
        case 'e':
            return 0;
            break;

        default:
        printf("Invalid input, try again.\n");
            break;
        }
    }
    return 0;
}