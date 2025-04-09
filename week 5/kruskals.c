#include <stdio.h>
#include <stdlib.h>

#define V 100

struct Edge {
int u, v, w;
};

int parent[V];

int find(int i) {
if (parent[i] == i)
return i;
return parent[i] = find(parent[i]); // Path compression
}

void unionSet(int x, int y) {
parent[find(x)] = find(y);
}

int compare(const void* a, const void* b) {
return ((struct Edge*)a)->w - ((struct Edge*)b)->w;
}

void kruskalFromMatrix(int graph[V][V], int n) {
struct Edge edges[V * V];
int e = 0;

// Convert adjacency matrix to edge list
for (int i = 0; i < n; i++)
for (int j = i + 1; j < n; j++)
if (graph[i][j] != 0) {
edges[e].u = i;
edges[e].v = j;
edges[e].w = graph[i][j];
e++;
}

for (int i = 0; i < n; i++)
parent[i] = i;

qsort(edges, e, sizeof(edges[0]), compare);

int cost = 0;
printf("Edge \tWeight\n");

for (int i = 0, count = 0; count < n - 1 && i < e; i++) {
int u = edges[i].u;
int v = edges[i].v;
int w = edges[i].w;

if (find(u) != find(v)) {
printf("%d - %d\t%d\n", u, v, w);
cost += w;
unionSet(u, v);
count++;
}
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

kruskalFromMatrix(graph, n);
return 0;
}
