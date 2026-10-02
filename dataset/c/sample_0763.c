#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int optimize_route(int** cost_matrix, int* path, int* visited, int path_length, int total_cost, int n) {
    if (path_length == n) {
        return total_cost + cost_matrix[path[path_length - 1]][path[0]];
    }
    int min_cost = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            path[path_length] = i;
            int new_cost = optimize_route(cost_matrix, path, visited, path_length + 1, total_cost + cost_matrix[path[path_length - 1]][i], n);
            if (new_cost < min_cost) {
                min_cost = new_cost;
            }
            visited[i] = 0;
        }
    }
    return min_cost;
}

int find_min_cost(int** cost_matrix, int n) {
    int min_cost = INT_MAX;
    for (int i = 0; i < n; i++) {
        int* path = (int*)malloc(n * sizeof(int));
        int* visited = (int*)calloc(n, sizeof(int));
        path[0] = i;
        visited[i] = 1;
        int cost = optimize_route(cost_matrix, path, visited, 1, 0, n);
        if (cost < min_cost) {
            min_cost = cost;
        }
        free(path);
        free(visited);
    }
    return min_cost;
}

int main() {
    int n = 4;
    int** cost_matrix = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        cost_matrix[i] = (int*)malloc(n * sizeof(int));
    }
    cost_matrix[0][0] = 0; cost_matrix[0][1] = 10; cost_matrix[0][2] = 15; cost_matrix[0][3] = 20;
    cost_matrix[1][0] = 10; cost_matrix[1][1] = 0; cost_matrix[1][2] = 35; cost_matrix[1][3] = 25;
    cost_matrix[2][0] = 15; cost_matrix[2][1] = 35; cost_matrix[2][2] = 0; cost_matrix[2][3] = 30;
    cost_matrix[3][0] = 20; cost_matrix[3][1] = 25; cost_matrix[3][2] = 30; cost_matrix[3][3] = 0;
    printf("%d\n", find_min_cost(cost_matrix, n));
    for (int i = 0; i < n; i++) {
        free(cost_matrix[i]);
    }
    free(cost_matrix);
    return 0;
}