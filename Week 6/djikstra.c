#include <stdio.h>
#include <limits.h>

#define V 100 // Maximum number of vertices

// Function to find the vertex with the minimum distance value
int minDistance(int dist[], int sptSet[], int n) {
    int min = INT_MAX, min_index = -1;
    for (int v = 0; v < n; v++)
        if (!sptSet[v] && dist[v] <= min)
            min = dist[v], min_index = v;
    return min_index;
}

// Function to implement Dijkstra's algorithm
void dijkstra(int graph[V][V], int n, int src) {
    int dist[V];      // Output array: dist[i] will hold the shortest distance from src to i
    int sptSet[V];    // sptSet[i] will be true if vertex i is included in shortest path tree

    // Initialize all distances as INFINITE and sptSet[] as false
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = 0;
    }

    dist[src] = 0; // Distance of source vertex to itself is always 0

    // Find shortest path for all vertices
    for (int count = 0; count < n - 1; count++) {
        int u = minDistance(dist, sptSet, n);
        sptSet[u] = 1;

        // Update distance value of adjacent vertices
        for (int v = 0; v < n; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    // Print the distance array
    printf("\nShortest Paths from Vertex %d:\n", src);
    printf("Vertex\tDistance\n");
    for (int i = 0; i < n; i++)
        printf("%d\t%d\n", i, dist[i]);
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

    int src;
    printf("Enter the source vertex: ");
    scanf("%d", &src);

    dijkstra(graph, n, src);
    return 0;
}
