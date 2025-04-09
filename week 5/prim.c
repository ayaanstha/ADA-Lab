#include <stdio.h>
#include <limits.h>

#define V 100 // Max number of vertices

int minKey(int key[], int mstSet[], int n) {
int min = INT_MAX, minIndex;

for (int v = 0; v < n; v++)
if (!mstSet[v] && key[v] < min)
min = key[v], minIndex = v;

return minIndex;
}

void primMST(int graph[V][V], int n) {
int parent[V], key[V], mstSet[V];

for (int i = 0; i < n; i++)
key[i] = INT_MAX, mstSet[i] = 0;

key[0] = 0;
parent[0] = -1;

for (int count = 0; count < n - 1; count++) {
int u = minKey(key, mstSet, n);
mstSet[u] = 1;

for (int v = 0; v < n; v++)
if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v])
parent[v] = u, key[v] = graph[u][v];
}

int cost = 0;
printf("Edge \tWeight\n");
for (int i = 1; i < n; i++) {
printf("%d - %d\t%d\n", parent[i], i, graph[i][parent[i]]);
cost += graph[i][parent[i]];
}
printf("Total cost: %d\n", cost);
}

int main() {
int n;
printf("Enter number of vertices: ");
scanf("%d", &n);

int graph[V][V];
printf("Enter the adjacency matrix (0 for no edge):\n");
for (int i = 0; i < n; i++)
for (int j = 0; j < n; j++)
scanf("%d", &graph[i][j]);

primMST(graph, n);
return 0;
}
