#include <stdio.h>
#include <limits.h>

#define MAX 10

int graph[MAX][MAX];
int n;

int calculateDistance(int route[]) {
    int totalDistance = 0;
    for (int i = 0; i < n - 1; i++) {
        totalDistance += graph[route[i]][route[i + 1]];
    }
    totalDistance += graph[route[n - 1]][route[0]];
    return totalDistance;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void findShortestRoute(int route[], int start, int* minDistance, int bestRoute[]) {
    if (start == n) {
        int currentDistance = calculateDistance(route);
        if (currentDistance < *minDistance) {
            *minDistance = currentDistance;
            for (int i = 0; i < n; i++) {
                bestRoute[i] = route[i];
            }
        }
        return;
    }
    for (int i = start; i < n; i++) {
        swap(&route[start], &route[i]);
        findShortestRoute(route, start + 1, minDistance, bestRoute);
        swap(&route[start], &route[i]);
    }
}

int main() {
    printf("Enter the number of cities: ");
    scanf("%d", &n);

    printf("Enter the distance matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int route[MAX], bestRoute[MAX];
    for (int i = 0; i < n; i++) {
        route[i] = i;
    }

    int minDistance = INT_MAX;
    findShortestRoute(route, 1, &minDistance, bestRoute);

    printf("\nThe shortest route is: ");
    for (int i = 0; i < n; i++) {
        printf("%d -> ", bestRoute[i]);
    }
    printf("%d\n", bestRoute[0]);
    printf("Minimum Distance: %d\n", minDistance);

    return 0;
}
