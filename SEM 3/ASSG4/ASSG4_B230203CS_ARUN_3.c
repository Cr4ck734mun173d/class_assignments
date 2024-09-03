#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_VAL 100
typedef struct new
{
    int JID;
    int priority;
}
PriorityQueue;
void swap(PriorityQueue *a, PriorityQueue *b)
{
    PriorityQueue temp = *a;
    *a = *b;
    *b = temp;
}
void HeapifyUp(PriorityQueue *heap, int i)
{
    int root = (i - 1) / 2;
    if (i > 0 && heap[i].priority > heap[root].priority)
    {
        swap(&heap[i], &heap[root]);
        HeapifyUp(heap, root);
    }
}
void HeapifyDown(PriorityQueue *heap, int i, int n)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;
    if (left < n && heap[left].priority < heap[largest].priority)
    {
        largest = left;
    }
    if (right < n && heap[right].priority < heap[largest].priority)
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(&heap[i], &heap[largest]);
        HeapifyDown(heap, largest, n);
    }
}
void add(PriorityQueue que[], int jid, int priority, int *size)
{
    int idx = *size;
    que[idx].JID = jid;
    que[idx].priority = priority;
    *size = *size + 1;

    while (idx > 0)
    {
        int parent = (idx - 1) / 2;
        if (que[idx].priority > que[parent].priority)
        {
            break;
        }
        swap(&que[idx], &que[parent]);
        idx = parent;
    }
}
void scheduleJob(PriorityQueue PQ[], int *size)
{
    if (*size <= 0)
    {
        printf("-1\n");
        return;
    }
    PriorityQueue temp = PQ[0];
    PQ[0] = PQ[*size - 1];
    *size = *size - 1;
    int idx = 0;
    while (idx < (*size))
    {
        int leftchild = 2 * idx + 1;
        int rightchild = 2 * idx + 2;
        int smallest = idx;
        if (leftchild < *size && PQ[leftchild].priority < PQ[smallest].priority)
        {
            smallest = leftchild;
        }
        if (rightchild < *size && PQ[rightchild].priority < PQ[smallest].priority)
        {
            smallest = rightchild;
        }
        if (smallest != idx)
        {
            swap(&PQ[idx], &PQ[smallest]);

            idx = smallest;
        }
        else
            break;
    }
    printf("%d\n", temp.JID);
}
void NextJob(PriorityQueue que[], int size)
{
    if (size == 0)
    {
        printf("-1\n");
        return;
    }

    printf("%d\n", que[0].JID);
    return;
}
void replacePriority(PriorityQueue que[], int size, int jid, int priority)
{
    for (int i = 0; i < size; i++)
    {
        if (que[i].priority == priority)
        {
            return;
        }
    }
    int oldpriority = -1;
    int temp = -1;
    for (int i = 0; i < size; i++)
    {
        if (que[i].JID == jid)
        {
            oldpriority = que[i].priority;
            temp = i;
            que[i].priority = priority;
            break;
        }
    }
    if (oldpriority == -1)
    {
        printf("-1\n");
        return;
    }
    if (oldpriority > priority)
    {
        HeapifyUp(que, temp);
    }
    else
    {
        HeapifyDown(que, temp, size);
    }
    return;
}
void display(PriorityQueue que[], int size)
{
    if (size == 0)
    {
        printf("-1\n");
        return;
    }
    for (int i = 0; i < size; i++)
    {
        printf("%d %d\n", que[i].JID,que[i].priority);
    }
    printf("\n");
}
int main()
{
    PriorityQueue pq[MAX_VAL];
    int size = 0;

    while (1)
    {
       char choice;
       scanf("%c",&choice);
        int jid, priority;
        switch (choice)
        {
        case 'a':
            scanf("%d %d", &jid, &priority);
            add(pq, jid, priority, &size);
            break;
        case 'b':
            scheduleJob(pq, &size);
            break;
        case 'c':
            NextJob(pq, size);
            break;
        case 'd':
            scanf("%d %d", &jid, &priority);
            replacePriority(pq, size, jid, priority);
            break;
        case 'e':
            display(pq, size);
            break;
        case 'g':
            return 0;
            break;
        
        default:
            break;
        }
    }
    

    return 0;
}