#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double calculate_cost(int* route, double** distances, int len) {
    double cost = 0.0;
    for (int i = 0; i < len - 1; i++) {
        cost += distances[route[i]][route[i + 1]];
    }
    return cost;
}

void optimize_route(int start, int* nodes, int nodes_len, double** distances) {
    int* route = (int*)malloc((nodes_len + 1) * sizeof(int));
    route[0] = start;
    for (int i = 0; i < nodes_len; i++) {
        route[i + 1] = nodes[i];
    }
    double cost = calculate_cost(route, distances, nodes_len + 1);
    while (1) {
        for (int i = 1; i < nodes_len; i++) {
            for (int j = i + 1; j <= nodes_len; j++) {
                int* new_route = (int*)malloc((nodes_len + 1) * sizeof(int));
                for (int k = 0; k < i; k++) {
                    new_route[k] = route[k];
                }
                for (int k = i; k <= j; k++) {
                    new_route[k] = route[j + i - k];
                }
                for (int k = j + 1; k <= nodes_len; k++) {
                    new_route[k] = route[k];
                }
                double new_cost = calculate_cost(new_route, distances, nodes_len + 1);
                if (new_cost < cost) {
                    for (int k = 0; k <= nodes_len; k++) {
                        route[k] = new_route[k];
                    }
                    cost = new_cost;
                }
                free(new_route);
            }
        }
    }
    free(route);
}

int main() {
    srand(time(NULL));
    int nodes_len = 10;
    int* nodes = (int*)malloc(nodes_len * sizeof(int));
    for (int i = 0; i < nodes_len; i++) {
        nodes[i] = i;
    }
    double** distances = (double**)malloc(nodes_len * sizeof(double*));
    for (int i = 0; i < nodes_len; i++) {
        distances[i] = (double*)malloc(nodes_len * sizeof(double));
        for (int j = 0; j < nodes_len; j++) {
            distances[i][j] = (double)(rand() % 99 + 1) / 100.0;
        }
        distances[i][i] = 0.0;
    }
    optimize_route(0, nodes + 1, nodes_len - 1, distances);
    for (int i = 0; i < nodes_len; i++) {
        free(distances[i]);
    }
    free(distances);
    free(nodes);
    return 0;
}