#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_VAL 10000
#define TABLE_VAL 4

typedef struct new
{
    char *first_name;
    char roll_number[10];
    int age;
    struct new *next;
}
hashtable;

hashtable *CreateNode(char *name, char *roll, int age)
{

    hashtable *newnode = (hashtable *)malloc(sizeof(hashtable));
    newnode->age = age;
    newnode->first_name = (char *)malloc(strlen(name) + 1);
    strcpy(newnode->first_name, name);
    strcpy(newnode->roll_number, roll);
    newnode->next = NULL;
}

int HashFun(char *name, int age)
{
    int key = 0;
    int sum = 0;
    for (int i = 0; name[i] != '\0'; i++)
    {
        sum += name[i];
    }
    key = sum + age;
    return (key % 4);
}
void Insert(hashtable *table, char *name, char *roll, int age)
{
    int index = HashFun(name, age);
    hashtable *newnode = CreateNode(name, roll, age);
    if (table[index].next == NULL)
    {
        table[index].next = newnode;
    }
    else
    {
        hashtable *current = table[index].next;
        hashtable *previous = NULL;
        while (current != NULL && strcmp(current->first_name, newnode->first_name) < 0)
        {
            previous = current;
            current = current->next;
        }
        if (previous == NULL)
        {
            newnode->next = table[index].next;
            table[index].next = newnode;
        }
        else
        {
            newnode->next = previous->next;
            previous->next = newnode;
        }
    }
}
void GroupIndexAndSplit(hashtable *table, char *name)
{
    for (int i = 0; i < 4; i++)
    {
        hashtable *temp = table[i].next;
        while (temp != NULL)
        {
            if (strcmp(temp->first_name, name) == 0)
            {
                int index = HashFun(temp->first_name, temp->age);
                printf("%d\n", i);
                return;
            }

            temp = temp->next;
        }
    }
}
void Group_CountAndList(hashtable *table, int index)
{
    hashtable *newnode = table[index].next;
    int count = 0;
    while (newnode != NULL)
    {
        count++;
        newnode = newnode->next;
    }
    newnode = table[index].next;
    // if (count==0)
    // {
    //     printf("0\n");
    //     return;
    // }
    
    printf("%d ", count);
    while (newnode != NULL)
    {
        printf("%s ", newnode->first_name);
        newnode = newnode->next;
    }
    printf("\n");
}
void Group_ListByBranch(hashtable *table, int index, char *branch)
{
    hashtable *newnode = table[index].next;
    branch[0] = toupper(branch[0]);
    branch[1] = toupper(branch[1]);
    int flag=0;
    while (newnode != NULL)
    {
        if (newnode->roll_number[7] == branch[0] && newnode->roll_number[8] == branch[1])
        {
            printf("%s ", newnode->first_name);
            flag=1;
        }

        newnode = newnode->next;
    }
    if (!flag)
    {
        printf("-1\n");
        return;
    }
    
    printf("\n");
}
void StudentDetails(hashtable *table, char *rollnumber)
{
    for (int i = 0; i < 4; i++)
    {
        hashtable *temp = table[i].next;
        while (temp != NULL)
        {
            if (strcmp(temp->roll_number, rollnumber) == 0)
            {

                printf("%s %d %c%c\n", temp->first_name, temp->age, temp->roll_number[7], temp->roll_number[8]);
                return;
            }
            temp=temp->next;
        }
    }
    printf("-1\n");
    return;
}

void InsertMod(hashtable *table, char *name, char *roll, int age, int index)
{

    hashtable *newnode = CreateNode(name, roll, age);
    if (table[index].next == NULL)
    {
        table[index].next = newnode;
    }
    else
    {
        hashtable *current = table[index].next;
        hashtable *previous = NULL;
        while (current != NULL && strcmp(current->first_name, newnode->first_name) < 0)
        {
            previous = current;
            current = current->next;
        }
        if (previous == NULL)
        {
            newnode->next = table[index].next;
            table[index].next = newnode;
        }
        else
        {
            newnode->next = previous->next;
            previous->next = newnode;
        }
    }
}
void Group_TransferAllByBranch(hashtable *table, int sindex, int tindex, char *branch)
{
    int count = 0;
    branch[0] = toupper(branch[0]);
    branch[1] = toupper(branch[1]);
    hashtable *newnode = table[sindex].next;
    while (newnode != NULL)
    {
        if (newnode->roll_number[7] == branch[0] && newnode->roll_number[8] == branch[1])
        {
            InsertMod(table, newnode->first_name, newnode->roll_number, newnode->age, tindex);
            count++;
        }
        newnode = newnode->next;
    }
    printf("%d\n", count);
}
void PrintTable(hashtable *table, int tablesize)
{
    for (int i = 0; i < tablesize; i++)
    {
        printf("Index %d:\n", i);
        hashtable *temp = table[i].next;
        while (temp != NULL)
        {
            printf("%s,  %s, %d\n", temp->first_name, temp->roll_number, temp->age);
            temp = temp->next;
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    if (n<1 || n>1000)
    {
        return 0;
    }
    
    char name[MAX_VAL];
    char roll[10];
    int age;
    hashtable table[4];
    for (int i = 0; i < 4; i++)
    {
        table[i].next = NULL;
    }

    for (int i = 0; i < n; i++)
    {
        scanf("%s %s %d", name, roll, &age);
        Insert(table, name, roll, age);
    }
    //  PrintTable(table, 4);
    while (1)
    {
        int index = 0;
        char choice;
        char branch[2];
        scanf("%c", &choice);
        switch (choice)
        {
        case 'a':
            scanf("%s", name);
            GroupIndexAndSplit(table, name);
            break;
        case 'b':
            scanf("%d", &index);
            Group_CountAndList(table, index);
            break;
        case 'c':
            scanf("%d", &index);
            scanf("%s", branch);
            Group_ListByBranch(table, index, branch);
            break;
        case 'd':
            scanf("%s", roll);
            StudentDetails(table, roll);
            break;
        case 'e':
            scanf("%d", &index);
            scanf("%d", &n);
            scanf("%s", branch);
            Group_TransferAllByBranch(table, index, n, branch);
            break;
        case 'f':
            return 0;
            break;

        default:
            break;
        }
    }

    return 0;
}