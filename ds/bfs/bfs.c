#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

struct Queue {
    int items[MAX_VERTICES];
    int front, rear;
};

void initQueue(struct Queue* q) {
    q->front = -1;
    q->rear = -1;
}

int isQueueEmpty(struct Queue* q) {
    return (q->front == -1);
}

int isQueueFull(struct Queue* q) {
    return (q->rear == MAX_VERTICES - 1);
}

void enqueue(struct Queue* q, int value) {
    if (isQueueFull(q)) {
        printf("Queue is full!\n");
        return;
    }
    if (q->front == -1)
        q->front = 0;
    q->rear++;
    q->items[q->rear] = value;
}

int dequeue(struct Queue* q) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    int item = q->items[q->front];
    q->front++;
    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }
    return item;
}

void bfs(int graph[MAX_VERTICES][MAX_VERTICES], int startVertex, int n) {
    struct Queue q;
    initQueue(&q);
    int visited[MAX_VERTICES] = {0};

    enqueue(&q, startVertex);
    visited[startVertex] = 1;

    printf("BFS Traversal starting from vertex %d: ", startVertex);

    while (!isQueueEmpty(&q)) {
        int currentVertex = dequeue(&q);
        printf("%d ", currentVertex);

        for (int i = 0; i < n; i++) {
            if (graph[currentVertex][i] == 1 && !visited[i]) {
                enqueue(&q, i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

int main() {
    int graph[MAX_VERTICES][MAX_VERTICES] = {0};
    int n, m, u, v, startVertex;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &m);

    printf("Enter the edges (u v) representing an undirected graph:\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;  // Since it's an undirected graph
    }

    printf("Enter the starting vertex for BFS: ");
    scanf("%d", &startVertex);

    bfs(graph, startVertex, n);

    return 0;
}
