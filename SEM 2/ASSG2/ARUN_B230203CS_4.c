#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;

} node;
node *CREATE_NODE(int data)
{
    node *newnode = (node *)malloc(sizeof(node));
    if (newnode == NULL)
    {
        printf("Error Memory allocation failed");
        return NULL;
    }
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

void LIST_INSERT(node **Head, int data)
{
    node *newnode = CREATE_NODE(data);

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
void REVERSE_LIST(node **Head)
{

    node *prev, *next, *current;
    prev =NULL;
     next = current = *Head;

    while (next != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *Head = prev;
}
void INITIAL_LIST(node *Head)
{
    node *temp = Head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    char c;
    node *head;
    head = NULL;
    while (1)
    {

        //printf("Enter choice: ");
        scanf("%c", &c);
        getchar();
        int x;
        switch (c)
        {
        case 'i':
           // printf("Enter data: ");
            
            scanf("%d", &x);
            getchar();
            LIST_INSERT(&head, x);

            break;
        case 'r':
            REVERSE_LIST(&head);
            break;
        case 'p':
            INITIAL_LIST(head);
            
            break;
        case 'e':
            return 0;
            break;

        default:
            printf("Invalid input. Please try again");
            break;
        }
    }
    return 0;
}