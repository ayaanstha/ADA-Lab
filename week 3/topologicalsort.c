#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

int adj[MAX_VERTICES][MAX_VERTICES], inDegree[MAX_VERTICES], vertices;

void initGraph(int v) {
    vertices = v;
    for (int i = 0; i < vertices; i++) {
        inDegree[i] = 0;
        for (int j = 0; j < vertices; j++) adj[i][j] = 0;
    }
}

void addEdge(int start, int end) {
    adj[start][end] = 1;
    inDegree[end]++;
}

void topologicalSort() {
    int queue[MAX_VERTICES], front = 0, rear = 0, count = 0;
    for (int i = 0; i < vertices; i++) {
        if (inDegree[i] == 0) queue[rear++] = i;
    }

    printf("Topological Order: ");
    while (front < rear) {
        int v = queue[front++];
        printf("%d ", v);
        count++;

        for (int i = 0; i < vertices; i++) {
            if (adj[v][i] == 1 && --inDegree[i] == 0) queue[rear++] = i;
        }
    }

    if (count == vertices) printf("\nTopological sorting completed.");
    else printf("\nCycle detected in the graph!");
}

int main() {
    int edges, start, end;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    initGraph(vertices);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        printf("Enter edge (start end): ");
        scanf("%d %d", &start, &end);
        addEdge(start, end);
    }

    topologicalSort();
    return 0;
}
