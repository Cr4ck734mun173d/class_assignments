#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VAL 100


typedef struct Queue {
    int arr[MAX_VAL];
    int front;
    int rear;
} Queue;

void initQ(Queue *q) {
    q->front = 0;
    q->rear = 0;
}

int isEmpty(Queue *q) {
    return q->front == q->rear;
}

void enqueue(Queue *q, int value) {
    q->arr[q->rear++] = value;
}

int dequeue(Queue *q) {
    return q->arr[q->front++];
}


int isBipartite(int n, int graph[MAX_VAL][MAX_VAL]) {
    int color[MAX_VAL];
    for (int i = 0; i < MAX_VAL; i++) {
        color[i] = -1;  
    }
    Queue q;
    initQ(&q);
    for (int start = 0; start < n; start++) {
        if (color[start] == -1) { 
            color[start] = 0;     
            enqueue(&q, start);
            while (!isEmpty(&q)) {
                int u = dequeue(&q);
                for (int v = 0; v < n; v++) {
                    if (graph[u][v]) {
                        if (color[v] == -1) { 
                            color[v] = 1 - color[u]; 
                            enqueue(&q, v);
                        } else if (color[u] == color[v]) {
                            return -1; 
                        }
                    }
                }
            }
        }
    }
    return 1; 
}


int hasCycle(int n, int graph[MAX_VAL][MAX_VAL]) {
    int visited[MAX_VAL] = {0};
    Queue q;
    initQ(&q);

    for (int start = 0; start < n; start++) {
        if (!visited[start]) {
            enqueue(&q, start);
            visited[start] = 1;

            int parent[MAX_VAL];
            memset(parent, -1, sizeof(parent));
            parent[start] = -1;

            while (!isEmpty(&q)) {
                int u = dequeue(&q);
                for (int v = 0; v < n; v++) {
                    if (graph[u][v]) {
                        if (!visited[v]) {
                            visited[v] = 1;
                            parent[v] = u;
                            enqueue(&q, v);
                        } else if (parent[u] != v) {
                            return 1; 
                        }
                    }
                }
            }
        }
    }
    return -1; 
}


int isConnected(int n, int graph[MAX_VAL][MAX_VAL]) {
    int visited[MAX_VAL] = {0};
    Queue q;
    initQ(&q);

    enqueue(&q, 0); 
    visited[0] = 1;
    int visitedNodes = 1;

    while (!isEmpty(&q)) {
        int u = dequeue(&q);
        for (int v = 0; v < n; v++) {
            if (graph[u][v] && !visited[v]) {
                visited[v] = 1;
                enqueue(&q, v);
                visitedNodes++;
            }
        }
    }

    return visitedNodes == n; 
}


int getEdgeCount(int n, int graph[MAX_VAL][MAX_VAL]) {
    int edge = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j]) {
                edge++;
            }
        }
    }
    return edge / 2; 
}


int isTree(int n, int graph[MAX_VAL][MAX_VAL]) {
    int edges = getEdgeCount(n, graph);
    if (edges != n - 1 || hasCycle(n, graph) == 1 || !isConnected(n, graph)) {
        return -1; 
    }
    return 1; 
}

int main()
{
    int n;
    scanf("%d", &n); 
    int graph[MAX_VAL][MAX_VAL];

    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    while (1)
    {
        char choice;
        scanf(" %c", &choice); 
        switch (choice)
        {
        case 'a':
            printf("%d\n", isBipartite(n, graph));
            break;
        case 'b':
            printf("%d\n", hasCycle(n, graph));
            break;
        case 'c':
            printf("%d\n", isTree(n, graph));
            break;
        case 'x':
            return 0;
        default:
            break;
        }
    }

    return 0;
}
