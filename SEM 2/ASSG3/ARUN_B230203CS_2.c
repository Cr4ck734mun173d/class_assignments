#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 20

typedef struct {
    int ID;
    int priority;
} PQue;

void heapify(PQue que[], int i, int size) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < size && que[left].priority > que[largest].priority) {
        largest = left;
    }
    if (right < size && que[right].priority > que[largest].priority) {
        largest = right;
    }
    if (largest != i) {
        PQue temp = que[i];
        que[i] = que[largest];
        que[largest] = temp;
        heapify(que, largest, size);
    }
}

void add(PQue que[], int job, int priority, int *size) {
    if (*size >= MAX_LEN) {
        printf("-1\n");
        return;
    }
    que[*size].ID = job;
    que[*size].priority = priority;
    (*size)++;
    int i = *size / 2 - 1; 
    while (i >= 0) {
        heapify(que, i, *size);
        i--;
    }
}

void next_job(PQue que[], int size) {
    if (size == 0) {
        printf("-1\n");
        return;
    }
    printf("%d\n", que[0].ID);
}
void build_max_heap(PQue que[], int size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(que, i, size);
    }
}
void replace_priority(PQue que[], int size, int id, int np) {
    for (int i = 0; i < size; i++) {
        if (que[i].ID == id) {
            que[i].priority = np;
            
            build_max_heap(que, size);
            return;
        }
    }
    printf("-1\n");
}

void display(PQue que[], int size) {
    if (size == 0) {
        printf("-1\n");
        return;
    }
    for (int i = 0; i < size; i++) {
        printf("%d %d\n", que[i].ID, que[i].priority);
    }
}

void schedule(PQue que[], int *size) {
    if (*size == 0) {
        printf("-1\n");
        return;
    }
    printf("%d\n", que[0].ID);
    que[0] = que[*size - 1];
    (*size)--;
    heapify(que, 0, *size);
}

int main() {
    int job, priority, newPriority;
    char choice;

    PQue que[MAX_LEN];
    int size = 0;
    do {
        scanf(" %c", &choice); 
        switch (choice) {
            case 'a':
                scanf("%d %d", &job, &priority);
                add(que, job, priority, &size);
                break;
            case 's':
                schedule(que, &size);
                break;
            case 'd':
                display(que, size);
                break;
            case 'n':
                next_job(que, size);
                break;
            case 'r':
                scanf("%d %d", &job, &newPriority);
                replace_priority(que, size, job, newPriority);
                break;
            case 'e':
                return 0;
                break;
            default:
                break;
        }
    } while (1);

    return 0;
}
