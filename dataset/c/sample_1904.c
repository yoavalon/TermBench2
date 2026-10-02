#include <stdio.h>
#include <limits.h>

float** init_matrix(int size) {
    float** matrix = (float**)malloc(size * sizeof(float*));
    for (int i = 0; i < size; i++) {
        matrix[i] = (float*)malloc(size * sizeof(float));
        for (int j = 0; j < size; j++) {
            matrix[i][j] = INFINITY;
        }
    }
    return matrix;
}

void update_distance(float** graph, float* dist, int src, int size) {
    for (int v = 0; v < size; v++) {
        if (graph[src][v] > 0 && dist[src] + graph[src][v] < dist[v]) {
            dist[v] = dist[src] + graph[src][v];
        }
    }
}

float* shortest_path(float** graph, int src, int size) {
    float* dist = (float*)malloc(size * sizeof(float));
    for (int i = 0; i < size; i++) {
        dist[i] = INFINITY;
    }
    dist[src] = 0;
    for (int i = 0; i < size - 1; i++) {
        update_distance(graph, dist, src, size);
    }
    return dist;
}

int main() {
    float graph[4][4] = {{0, 5, INFINITY, 10}, {INFINITY, 0, 3, INFINITY}, {INFINITY, INFINITY, 0, 1}, {INFINITY, INFINITY, INFINITY, 0}};
    int size = 4;
    float* result = shortest_path(graph, 0, size);
    for (int i = 0; i < size; i++) {
        printf("%f ", result[i]);
    }
    printf("\n");
    free(result);
    return 0;
}