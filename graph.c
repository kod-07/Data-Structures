#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* graph[MAX];
int time = 0;

Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void addEdge(int u, int v) {
    Node* newNode = createNode(v);
    newNode->next = graph[u];
    graph[u] = newNode;

    newNode = createNode(u);
    newNode->next = graph[v];
    graph[v] = newNode;
}

void DFS(int u, bool visited[], int disc[], int low[], int parent[], bool ap[]) {
    visited[u] = true;
    disc[u] = low[u] = ++time;
    int children = 0;

    Node* temp = graph[u];
    while (temp != NULL) {
        int v = temp->vertex;
        if (!visited[v]) {
            children++;
            parent[v] = u;
            DFS(v, visited, disc, low, parent, ap);
            low[u] = (low[u] < low[v]) ? low[u] : low[v];
            if (parent[u] == -1 && children > 1) ap[u] = true;
            if (parent[u] != -1 && low[v] >= disc[u]) ap[u] = true;
        } else if (v != parent[u]) {
            low[u] = (low[u] < disc[v]) ? low[u] : disc[v];
        }
        temp = temp->next;
    }
}

void findArticulationPoints(int V) {
    bool visited[MAX];
    int disc[MAX], low[MAX], parent[MAX];
    bool ap[MAX];

    for (int i = 0; i < V; i++) {
        visited[i] = false;
        disc[i] = low[i] = parent[i] = -1;
        ap[i] = false;
    }

    for (int i = 0; i < V; i++) {
        if (!visited[i]) DFS(i, visited, disc, low, parent, ap);
    }

    printf("Articulation points in the graph are: ");
    for (int i = 0; i < V; i++) {
        if (ap[i]) printf("%d ", i);
    }
    printf("\n");
}

int main() {
    int V = 5;
    for (int i = 0; i < MAX; i++) graph[i] = NULL;

    addEdge(0, 1);
    addEdge(1, 2);
    addEdge(2, 0);
    addEdge(1, 3);
    addEdge(3, 4);

    findArticulationPoints(V);

    return 0;
}
