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
        printf("Error Mem Alloc Failed!");
        return NULL;
    }
    newnode->data = data;
    newnode->next = NULL;

    return newnode;
}
void Insert_Node(node **Head, int data)
{
    node *newnode = CreateNode(data);
    if (newnode==NULL)
    {
        return;
    }
    

    if (*Head == NULL)
    {
        *Head = newnode;
        newnode->next = *Head;
    }
    else
    {
        node *temp;
        temp = *Head;
        while (temp->next != *Head)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = *Head;
    }
}
void NGE(int x, node *head)
{
    if (head == NULL)
    {
        printf("Empty list!");
        return;
    }
    node *temp = head;
    int flag=0;
    while (temp->next!=head)
    {
        if (temp->data==x)
        {
        flag=1;
        }
        temp=temp->next;
    }
    if (temp->data==x)
    {
         flag=1;
    }
    
    if (flag==0)
    {
        printf("No such element in the list.\n");
        return;
    }
    
    
    temp = head;
    int max = 0;
    while (temp->next != head)
    {
        if (temp->data > max)
        {
            max = temp->data;
        }

        temp = temp->next;
    }
    if (temp->data > max)
        {
            max = temp->data;
        }
    if (x >= max)
    {
        printf("-1\n");
        //printf("%d",max);
    }
    else
    {
        temp = head;
        while (temp->data <= x)
        {
            temp = temp->next;
        }

        printf("%d\n", temp->data);
    }
}
void Print(node *Head)
{
    node *temp = Head;
    while (temp->next != Head)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d \n", temp->data);
}
int main()
{
    char c;
    node *head;
    head = NULL;
    while (1)
    {
        int num;
        int data;

       // printf("Enter choice: ");
        scanf("%c", &c);
        getchar();
        switch (c)
        {
        case 'i':
            //printf("Enter data: ");
            
            scanf("%d", &data);
            getchar();
            Insert_Node(&head,data);

            break;
        case 'g':
           // printf("Enter num: ");
            

            scanf("%d", &num);
            getchar();
            NGE(num, head);
            break;
        case 'p':
            Print(head);

            break;
        case 'e':
            return 0;
            break;

        default:
            printf("Wrong choice!");
            break;
        }
    }

    return 0;
}