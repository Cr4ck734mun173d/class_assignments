#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_LEN 50
#define MOBILE 20
#define TIME 6
typedef struct node
{
    char name[MAX_LEN];
    char mobile[MOBILE];
    char time[TIME];
    struct node *next;

} node;

node *CreateNode()
{

    node *newnode = (node *)malloc(sizeof(node));
    if (newnode == NULL)
    {
        printf("Error Mem Alloc Failed!");
        return NULL;
    }
    printf("1.Customer Name: ");
    fgets(newnode->name, MAX_LEN, stdin);
    newnode->name[strcspn(newnode->name, "\n")] = '\0';

    printf("2.Mobile Number: ");
    fgets(newnode->mobile, MOBILE, stdin);
    newnode->mobile[strcspn(newnode->mobile, "\n")] = '\0';

    printf("3.Arrival Time: ");
    fgets(newnode->time, TIME, stdin);
    newnode->time[strcspn(newnode->time, "\n")] = '\0';

    newnode->next = NULL;

    return newnode;
}
void InsertNode(node **Head)
{

    node *newnode = CreateNode();

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
    printf("Reservation added successfully for %s.\n", newnode->name);
}

void NBR(node *head)
{
    if (head == NULL)
    {
        printf("Reservation Queue is empty.\n");
    }
    else
        printf("Next Booking Request: %s (%s)\n", head->name,head->time);
}
void CancelReservation(node **head)
{
    if (*head ==NULL)
    {
        printf("Reservation Queue is empty!\n");
        return;
    }
    else
    {

        node *temp, *prev;
        prev = NULL;
        temp = *head;

        printf("Reservation to cancel: ");
        char buffer[MAX_LEN];
        fgets(buffer, MAX_LEN, stdin);
        buffer[strcspn(buffer, "\n")] = '\0';

        while (strcmp(buffer, temp->name) != 0)
        {
            prev = temp;
            temp = temp->next;
        }
        if (prev == NULL)
            *head = temp->next;
        else
            prev->next = temp->next;
        printf("Reservation for %s canceled successfully.\n", temp->name);
        free(temp);
    }
}
void DisplayReservation(node *head)
{
    if (head == NULL)
    {
        printf("Reservation Queue is empty.\n");
        return;
    }
    node *temp = head;
    printf("Reservation Queue:\n");
    int count = 1;

    while (temp != NULL)
    {
        printf(" %d. %s (%s)\n", count++, temp->name, temp->time);
        temp = temp->next;
    }
}
int main()
{
    node *head = NULL;
    while (1)
    {
        printf("Menu:\n 1.Add Reservation\n 2.View Next Booking Request\n 3.Cancel Reservation\n 4.Display Reservation Queue\n 5.Exit\n Enter Your Choice: ");
        int choice;
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
        case 1:
            InsertNode(&head);
            break;
        case 2:
            NBR(head);
            break;
        case 3:
            CancelReservation(&head);
            break;
        case 4:
            DisplayReservation(head);
            break;
        case 5:
            printf("Exiting....");
            return 0;
            break;

        default:
            printf("Error. Wrong choice.Please enter a value between 1 to 5.\n");
            break;
        }
    }
    return 0;
}