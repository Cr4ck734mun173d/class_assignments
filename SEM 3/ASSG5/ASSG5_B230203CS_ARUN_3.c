#include <stdio.h>
#include <stdlib.h>

#define MAX 1001

int adj[MAX][MAX], temp[MAX][MAX]; 
int visited[MAX];                  
int n, m;                          
int top, stack[MAX];               


void addEdge(int u, int v) {
    adj[u][v] = 1;
}


void printAdjMatrix() {
    printf("Adjacency Matrix:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}


void dfs(int v) {
    visited[v] = 1;
    for (int i = 1; i <= n; i++) {
        if (adj[v][i] && !visited[i]) {
            dfs(i);
        }
    }
    stack[top++] = v; 
}


void dfs_scc(int v) {
    visited[v] = 1;
    for (int i = 1; i <= n; i++) {
        if (temp[v][i] && !visited[i]) {
            dfs_scc(i);
        }
    }
}


int isCyclicUtil(int v, int recStack[]) {
    if (!visited[v]) {
        visited[v] = recStack[v] = 1; 
        
        for (int i = 1; i <= n; i++) {
            if (adj[v][i]) {
                if (!visited[i] && isCyclicUtil(i, recStack))
                    return 1; 
                else if (recStack[i])
                    return 1; 
            }
        }
    }
    recStack[v] = 0; 
    return 0;
}


int isDAG() {
    int recStack[MAX] = {0}; 
    for (int i = 1; i <= n; i++) {
        visited[i] = 0; 
    }
    
    for (int i = 1; i <= n; i++) {
        if (isCyclicUtil(i, recStack)) {
            return -1; 
        }
    }
    return 1; 
}


int countSCC() {
    
    top = 0;
    for (int i = 1; i <= n; i++) {
        visited[i] = 0;
        for (int j = 1; j <= n; j++) {
            temp[i][j] = 0; 
        }
    }
    
    
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i); 
        }
    }
    
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (adj[i][j]) {
                temp[j][i] = 1; 
            }
        }
    }
    
    
    for (int i = 1; i <= n; i++) {
        visited[i] = 0;
    }
    
    int count = 0; 
    
    
    while (top > 0) {
        int v = stack[--top]; 
        if (!visited[v]) {
            dfs_scc(v); 
            count++; 
        }
    }
    
    return count; 
}

int main() {
    scanf("%d %d", &n, &m); 
    
    
    for (int i = 1; i <= n; i++) {
        int node;
        scanf("%d", &node); 
        
        int adj_node;
        char ch = getchar(); 
        while (ch != '\n' && ch != EOF) { 
            scanf("%d", &adj_node); 
            addEdge(node, adj_node); 
            ch = getchar(); 
        }
    }
    
    
   // printAdjMatrix();
    
    char op;
    while (scanf(" %c", &op) == 1 && op != 'x') { 
        if (op == 'a') {
            printf("%d\n", isDAG()); 
        } else if (op == 'b') {
            printf("%d\n", countSCC()); 
        }
    }
    
    return 0;
}
