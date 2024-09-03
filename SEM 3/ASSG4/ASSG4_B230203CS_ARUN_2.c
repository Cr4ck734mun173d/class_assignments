#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_VAL 10000
typedef struct new
{
    int patient_id;
    int severity;
    char name[100];
}
Patient;
void printLevelOrder(Patient *heap, int n)
{
    if (n == 0)
    {
        printf("-1\n");
        return;
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", heap[i].patient_id);
    }
    printf("\n");
}
void Swap(Patient *a, Patient *b)
{
    Patient temp = *a;
    *a = *b;
    *b = temp;
}
void AdmitPatient(Patient A, Patient PQ[], int *size)
{
    int idx = *size;
    PQ[idx] = A;
    *size = *size + 1;
    while (idx > 0)
    {
        int parent = (idx - 1) / 2;
        if (PQ[idx].severity > PQ[parent].severity)
        {
            break;
        }
        Swap(&PQ[idx], &PQ[parent]);
        idx = parent;
    }
    printLevelOrder(PQ, *size);
    return;
}
void TreatPatient(Patient PQ[], int *size)
{
    if (*size <= 0)
    {
        printf("-1\n");
        return;
    }
    Patient temp = PQ[0];
    PQ[0] = PQ[*size - 1];
    *size = *size - 1;
    int idx = 0;
    while (idx < (*size))
    {
        int left = 2 * idx + 1;
        int right = 2 * idx + 2;
        int smallest = idx;
        if (left < *size && PQ[left].severity < PQ[smallest].severity)
        {
            smallest = left;
        }
        if (right < *size && PQ[right].severity < PQ[smallest].severity)
        {
            smallest = right;
        }
        if (smallest != idx)
        {
            Swap(&PQ[idx], &PQ[smallest]);
            idx = smallest;
        }
        else
        {
            break;
        }
    }
    printf("%d %s\n", temp.patient_id, temp.name);
    return;
}
void HeapifyUp(Patient *heap, int i)
{
    int root = (i - 1) / 2;
    if (i > 0 && heap[i].severity > heap[root].severity)
    {
        Swap(&heap[i], &heap[root]);
        HeapifyUp(heap, root);
    }
}
void HeapifyDown(Patient *heap, int i, int n)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;
    if (left < n && heap[left].severity < heap[largest].severity)
    {
        largest = left;
    }
    if (right < n && heap[right].severity < heap[largest].severity)
    {
        largest = right;
    }
    if (largest != i)
    {
        Swap(&heap[i], &heap[largest]);
        HeapifyDown(heap, largest, n);
    }
}

int UpdateSeverity(Patient PQ[], int size, int patient_id, int severity)
{

    for (int i = 0; i < size; i++)
    {
        if (PQ[i].severity == severity)
        {
            return 0;
        }
    }
    int oldseverity = -1;
    int temp = -1;
    for (int i = 0; i < size; i++)
    {
        if (PQ[i].patient_id == patient_id)
        {
            oldseverity = PQ[i].severity;
            temp = i;
            PQ[i].severity = severity;
            break;
        }
    }
    if (oldseverity == -1)
    {
        printf("-1\n");
        return 0;
    }
    if (oldseverity > severity)
    {
        HeapifyUp(PQ, temp);
    }
    else
    {
        HeapifyDown(PQ, temp, size);
    }
    printLevelOrder(PQ, size);
    return 1;
}
void QueryPatient(Patient PQ[], int size, int patient_id)
{

    for (int i = 0; i < size; i++)
    {
        if (PQ[i].patient_id == patient_id)
        {
            printf("%s %d\n", PQ[i].name, PQ[i].severity);
            return;
        }
    }
    printf("-1\n");
    return;
}
void FindMostSevere(Patient PQ[], int size)
{
    if (size <= 0)
    {
        printf("-1\n");
        return;
    }
    printf("%s %d\n", PQ[0].name, PQ[0].severity);

    return;
}
void Find3MostSevere(Patient PQ[], int size)
{
    if (size <= 2)
    {
        printf("-1\n");
        return;
    }
    printf("%d %s %d\n", PQ[0].patient_id, PQ[0].name, PQ[0].severity);
    if (PQ[1].severity < PQ[2].severity)
    {
        printf("%d %s %d\n", PQ[1].patient_id, PQ[1].name, PQ[1].severity);
        printf("%d %s %d\n", PQ[2].patient_id, PQ[2].name, PQ[2].severity);
        return;
    }
    else
    {
        printf("%d %s %d\n", PQ[2].patient_id, PQ[2].name, PQ[2].severity);
        printf("%d %s %d\n", PQ[1].patient_id, PQ[1].name, PQ[1].severity);
    }

    return;
}
int main()
{

    Patient PriorityQue[MAX_VAL];
    int size = 0;
    while (1)
    {
        Patient A;

        char a;
        scanf("%c", &a);
        switch (a)
        {
        case 'a':
            scanf("%d %d %s", &A.patient_id, &A.severity, A.name);
            AdmitPatient(A, PriorityQue, &size);
            break;
        case 'b':
            TreatPatient(PriorityQue, &size);
            break;
        case 'c':
            scanf("%d %d", &A.patient_id, &A.severity);
            UpdateSeverity(PriorityQue, size, A.patient_id, A.severity);
            break;
        case 'd':
            scanf("%d", &A.patient_id);
            QueryPatient(PriorityQue, size, A.patient_id);
            break;
        case 'e':
            Find3MostSevere(PriorityQue, size);
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