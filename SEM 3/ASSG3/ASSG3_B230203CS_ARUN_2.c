#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_VAL 1000
typedef struct new
{
    int key;
    struct new *next;
}
hashtable;
int hashfun(int key, int tablesize)
{
    return key % tablesize;
}
hashtable *CreateNode(int key)
{
    hashtable *newnode = (hashtable *)malloc(sizeof(hashtable));
    newnode->key = key;
    newnode->next = NULL;
    return newnode;
}
int search(hashtable table[], int key, int tablesize)
{
    int index = hashfun(key, tablesize);
    int pos = 0;
    hashtable *temp = table[index].next;
    while (temp != NULL)
    {
        if (temp->key == key)
        {
            return pos;
        }
        temp = temp->next;
        pos++;
    }
    return -1;
}
void searchF(hashtable table[], int key, int tablesize)
{
    int index = hashfun(key, tablesize);
    int pos = 1;
    hashtable *temp = table[index].next;
    while (temp != NULL)
    {
        if (temp->key == key)
        {
            printf("%d %d\n", index, pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("-1\n");
}
void insert(hashtable table[], int key, int tablesize)
{

    int index = hashfun(key, tablesize);
    if (search(table, key, tablesize) != -1)
    {
        printf("-1\n");
        return;
    }

    hashtable *newnode = CreateNode(key);
    if (table[index].next == NULL)
    {
        table[index].next = newnode;
    }
    else
    {
        hashtable *current = table[index].next;
        hashtable *previous = NULL;
        while (current != NULL && current->key < newnode->key)
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
void delete(hashtable *table, int key, int tablesize)
{
    searchF(table, key, tablesize);

    if (search(table, key, tablesize) == -1)
    {
        // printf("-1\n");
        return;
    }
    int index = hashfun(key, tablesize);
    hashtable *current = &table[index];
    hashtable *prev = NULL;

    while (current != NULL)
    {
        if (current->key == key)
        {
            if (current == &table[index])
            {
                table[index].key = current->next->key;
                table[index].next = current->next->next;
            }

            else
            {
                prev->next = current->next;
            }

            free(current);
            break;
        }
        prev = current;
        current = current->next;
    }
    return;
}
void deletef(hashtable *table, int key, int tablesize)
{
    int index = hashfun(key, tablesize);
    hashtable *current = table[index].next;
    hashtable *prev = &table[index];
    int position = 1; // Track position in the list

    while (current != NULL)
    {
        if (current->key == key)
        {
            // If deleting the first node in the chain
            if (prev == &table[index])
            {
                table[index].next = current->next;
            }
            else
            {
                prev->next = current->next;
            }

            printf("%d %d\n", index, position);
            free(current);
            return;
        }

        prev = current;
        current = current->next;
        position++;
    }

    // If the key was not found
    printf("-1\n");
}
void update(hashtable *table, int oldkey, int newkey, int tablesize)
{
    if (search(table, oldkey, tablesize) == -1)
    {
        printf("-1\n");
        return;
    }
    if (search(table, newkey, tablesize) != -1)
    {
        printf("-1\n");
        return;
    }

    deletef(table, oldkey, tablesize);
    insert(table, newkey, tablesize);
}
void printElementChain(hashtable *table, int index, int tablesize)
{
    hashtable *temp = table[index].next;
    if (temp==NULL)
    {
        printf("-1\n");
        return;
    }
    

    while (temp != NULL)
    {
        printf("%d ", temp->key);
        temp=temp->next;
    }
    printf("\n");
}
int main()
{
    int n;
    scanf("%d", &n);
    hashtable table[n];
    for (int i = 0; i < n; i++)
    {
        table[i].key = -1;
        table[i].next = NULL;
    }
    while (1)
    {
        char ch;
        int index = 0;
        int key = 0;
        int oldkey, newkey;
        scanf("%c", &ch);
        switch (ch)
        {
        case 'a':
            scanf("%d", &key);
            insert(table, key, n);
            break;
        case 'b':
            scanf("%d", &key);
            searchF(table, key, n);
            break;
        case 'c':
            scanf("%d", &key);
            deletef(table, key, n);
            break;
        case 'd':
            scanf("%d %d", &oldkey, &newkey);
            update(table, oldkey, newkey, n);
            break;
        case 'e':
            scanf("%d", &index);
            printElementChain(table, index, n);
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