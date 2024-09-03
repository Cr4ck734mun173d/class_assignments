#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_VAL 10000

void Swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void printHeap(int *heap, int n)
{
    if (n == 0)
    {
        printf("-1\n");
        return;
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", heap[i]);
    }
    printf("\n");
}
void HeapifyUp(int *heap, int i)
{
    int root = (i - 1) / 2;
    if (i > 0 && heap[i] > heap[root])
    {
        Swap(&heap[i], &heap[root]);
        HeapifyUp(heap, root);
    }
}
void HeapifyDown(int *heap, int i, int n)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;
    if (left < n && heap[left] > heap[largest])
    {
        largest = left;
    }
    if (right < n && heap[right] > heap[largest])
    {
        largest = right;
    }
    if (largest != i)
    {
        Swap(&heap[i], &heap[largest]);
        HeapifyDown(heap, largest, n);
    }
}
int FindMax(int *heap, int n)
{
    if (n > 0)
    {
        return heap[0];
    }
    else
    {
        return -1;
    }
}
int ExtractMax(int *heap, int *size)
{
    if (*size == 0)
    {
        return -1;
    }
    int max = heap[0];
    heap[0] = heap[*size - 1];
    *size = *size - 1;
    HeapifyDown(heap, 0, *size);
    return max;
}
int KthLargest(int *heap, int size, int k)
{
    if (k > size)
    {
        return -1;
    }
    int temp[MAX_VAL];
    for (int i = 0; i < size; i++)
    {
        temp[i] = heap[i];
    }
    for (int i = 0; i < k - 1; i++)
    {
        temp[0] = temp[--size];
        HeapifyDown(temp, i, size);
    }

    return temp[0];
}
void deletekey(int *heap, int *size, int key)
{
    int idx = -1;
    for (int i = 0; i < *size; i++)
    {
        if (heap[i] == key)
        {
            idx = i;
            break;
        }
    }
    if (idx == -1)
    {
        printf("-1\n");
        return;
    }
    heap[idx] = heap[*size - 1];
    *size = *size - 1;
    HeapifyDown(heap, idx, *size);
    // HeapifyUp(heap, idx);

    if (*size == 0)
    {
        printf("0\n");
    }
    else
    {
        printHeap(heap, *size);
    }

    return;
}
void insertkey(int *heap, int *n, int key)
{
    for (int i = 0; i <*n; i++)
    {
        if (heap[i] == key)
            return;
    }
    heap[*n] = key;
    HeapifyUp(heap, *n);
    *n = *n + 1;
    return;
}
int absolute(int a,int b){
    return a>b ? a-b:b-a;
}
void replaceKey(int *heap, int size, int oldkey, int newkey)
{
    int idx = -1;
    for (int i = 0; i < size; i++)
    {
        if (heap[i] == oldkey)
        {
            idx = i;
            break;
        }
    }
    if (idx ==-1)
    {
        printf("%d\n", absolute(oldkey,newkey));
        return;
    }
    heap[idx] = newkey;

    if (newkey > oldkey)
    {
        HeapifyUp(heap, idx);
    }
    else
    {
        HeapifyDown(heap, idx, size);
    }
    printHeap(heap, size);
}

int main()
{
    int n;
    int k;
    int BinaryHeap[MAX_VAL];
    int size = 0;

    while (1)
    {
        char choice;
        scanf("%c", &choice);
        switch (choice)
        {
        case 'a':
            scanf("%d", &n);
            insertkey(BinaryHeap, &size, n);
            break;
        case 'b':
            printf("%d\n", FindMax(BinaryHeap, size));
            break;
        case 'c':
            printf("%d ", ExtractMax(BinaryHeap, &size));
            printHeap(BinaryHeap, size);
            break;
        case 'd':
            scanf("%d", &n);
            printf("%d\n", KthLargest(BinaryHeap, size, n));
            break;
        case 'e':
            scanf("%d", &n);
            deletekey(BinaryHeap, &size, n);

            break;
        case 'f':
            scanf("%d %d", &n, &k);
            replaceKey(BinaryHeap, size, n, k);
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