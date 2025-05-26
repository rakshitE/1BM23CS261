#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int u, v, weight;
} Edge;

int find(int parent[], int x) {
    if (parent[x] != x) parent[x] = find(parent, parent[x]);
    return parent[x];
}

void unionSets(int parent[], int rank[], int x, int y) {
    int rootX = find(parent, x);
    int rootY = find(parent, y);
    if (rootX != rootY) {
        if (rank[rootX] > rank[rootY]) parent[rootY] = rootX;
        else if (rank[rootX] < rank[rootY]) parent[rootX] = rootY;
        else { parent[rootY] = rootX; rank[rootX]++; }
    }
}

int compareEdges(const void *a, const void *b) {
    return ((Edge*)a)->weight - ((Edge*)b)->weight;
}

void kruskal(Edge edges[], int E, int V) {
    int parent[V], rank[V];
    for (int i = 0; i < V; i++) parent[i] = i, rank[i] = 0;

    qsort(edges, E, sizeof(Edge), compareEdges);

    int mstWeight = 0;
    printf("Edges in MST:\n");
    for (int i = 0; i < E; i++) {
        int u = edges[i].u, v = edges[i].v, weight = edges[i].weight;
        if (find(parent, u) != find(parent, v)) {
            printf("%d - %d: %d\n", u, v, weight);
            unionSets(parent, rank, u, v);
            mstWeight += weight;
        }
    }
    printf("Total weight of MST: %d\n", mstWeight);
}

int main() {
    int V, E;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    Edge edges[E];
    printf("Enter edges (u v weight):\n");
    for (int i = 0; i < E; i++) scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);

    kruskal(edges, E, V);
    return 0;
}
