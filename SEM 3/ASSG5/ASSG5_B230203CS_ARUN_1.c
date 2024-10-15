#include <stdio.h>
#include <string.h>

#define MAX_VAL 100
int dfs(int graph[MAX_VAL][MAX_VAL], int v, int V, int visited[])
{
    int size = 1;
    visited[v] = 1;
    for (int i = 0; i < V; i++)
    {
        if (graph[v][i] == 1 & !visited[i])
        {
            size += dfs(graph, i, V, visited);
        }
    }
    return size;
}
int noOfConnectedComps(int n, int graph[MAX_VAL][MAX_VAL])
{
    int visited[MAX_VAL] = {0};
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(graph, i, n, visited);
            count++;
        }
    }
    return count;
}
void sizeOfComponents(int n, int graph[MAX_VAL][MAX_VAL])
{
    int visited[MAX_VAL] = {0};
    int componentSizes[MAX_VAL], componentCount = 0;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            componentSizes[componentCount] = dfs(graph, i, n, visited);
            componentCount++;
        }
    }

    for (int i = 0; i < componentCount - 1; i++)
    {
        for (int j = 0; j < componentCount - i - 1; j++)
        {
            if (componentSizes[j] > componentSizes[j + 1])
            {
                int temp = componentSizes[j];
                componentSizes[j] = componentSizes[j + 1];
                componentSizes[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < componentCount; i++)
    {
        printf("%d ", componentSizes[i]);
    }
    printf("\n");
}
void dfsBridge(int u, int parent, int n, int graph[MAX_VAL][MAX_VAL], int *visited, int *disc, int *low, int *bridgeCount, int *timeCount)
{

    visited[u] = 1;
    disc[u] = low[u] = ++(*timeCount);
    for (int i = 0; i < n; i++)
    {
        if (graph[u][i] == 1)
        {
            if (!visited[i])
            {
                dfsBridge(i, u, n, graph, visited, disc, low, bridgeCount, timeCount);

                if (low[i] < low[u])
                {
                    low[u] = low[i];
                }
                if (low[i] > disc[u])
                {
                    (*bridgeCount)++;
                }
            }
            else if (i != parent)
            {
                if (disc[i] < low[u])
                {
                    low[u] = disc[i];
                }
            }
        }
    }
}

void dfsB(int u, int parent, int n, int graph[MAX_VAL][MAX_VAL], int *visited, int *disc, int *low, int *bridgeCount, int *timeCount)
{
    visited[u] = 1;
    disc[u] = low[u] = ++(*timeCount);

    for (int v = 0; v < n; v++)
    {
        if (graph[u][v] == 1)
        {
            if (!visited[v])
            {
                dfsB(v, u, n, graph, visited, disc, low, bridgeCount, timeCount);

                low[u] = (low[v] < low[u]) ? low[v] : low[u];
                if (low[v] > disc[u])
                {
                    (*bridgeCount)++;
                }
            }
            else if (v != parent)
            {
                low[u] = (disc[v] < low[u]) ? disc[v] : low[u];
            }
        }
    }
}

void noOfBridges(int n, int graph[MAX_VAL][MAX_VAL])
{
    int visited[MAX_VAL] = {0};
    int disc[MAX_VAL];
    int low[MAX_VAL];
    int bridgeCount = 0, timecount = 0;
    for (int i = 0; i < MAX_VAL; i++)
    {
        disc[i] = -1;
    }
    for (int i = 0; i < MAX_VAL; i++)
    {
        low[i] = -1;
    }


    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfsBridge(i, -1, n, graph, visited, disc, low, &bridgeCount, &timecount);
        }
    }
    printf("%d\n", bridgeCount);
}
void dfsArt(int u, int parent, int n, int graph[MAX_VAL][MAX_VAL], int visited[MAX_VAL], int disc[MAX_VAL], int low[MAX_VAL], int *time, int *artPoint, int *artCount)
{

    visited[u] = 1;
    disc[u] = low[u] = ++(*time);
    int children = 0;
    for (int v = 0; v < n; v++)
    {
        if (graph[u][v])
        {
            if (!visited[v])
            {
                children++;
                dfsArt(v, u, n, graph, visited, disc, low, time, artPoint, artCount);

                low[u] = (low[v] < low[u]) ? low[v] : low[u];

                if (parent == -1 && children > 1)
                {
                    artPoint[u] = 1;
                }

                if (parent != -1 && low[v] >= disc[u])
                {
                    artPoint[u] = 1;
                }
            }
            else if (v != parent)
            {
                low[u] = (disc[v] < low[u]) ? disc[v] : low[u];
            }
        }
    }
}
void noOfArticulationPoints(int n, int graph[MAX_VAL][MAX_VAL])
{
    int visited[MAX_VAL] = {0};
    int disc[MAX_VAL];
    int low[MAX_VAL];
    int artPoint[MAX_VAL] = {0};

    int artCount = 0;
    int time = 0;

    for (int i = 0; i < MAX_VAL; i++)
    {
        disc[i] = -1;
    }
    for (int i = 0; i < MAX_VAL; i++)
    {
        low[i] = -1;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfsArt(i, -1, n, graph, visited, disc, low, &time, artPoint, &artCount);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (artPoint[i])
        {
            artCount++;
        }
    }
    printf("%d\n", artCount);
}
int main()
{
    int n, graph[MAX_VAL][MAX_VAL];
    scanf("%d", &n);

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
        scanf("%c", &choice);
        switch (choice)
        {
        case 'a':
            printf("%d\n", noOfConnectedComps(n, graph));
            break;
        case 'b':
            sizeOfComponents(n, graph);
            break;
        case 'c':
            noOfBridges(n, graph);
            break;
        case 'd':
            noOfArticulationPoints(n, graph);
            break;
        case 'x':
            return 0;
            break;
        default:
            break;
        }
    }

    return 0;
}