#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* optimize_routes(int** data, int rows, int cols) {
    int* costs = (int*)malloc(cols * sizeof(int));
    int* optimal_indices = (int*)malloc(cols * sizeof(int));
    for (int j = 0; j < cols; j++) {
        costs[j] = data[0][j];
        optimal_indices[j] = 0;
        for (int i = 1; i < rows; i++) {
            if (data[i][j] < costs[j]) {
                costs[j] = data[i][j];
                optimal_indices[j] = i;
            }
        }
    }
    free(costs);
    return optimal_indices;
}

int* update_inventory(int* routes, int* inventory, int cols) {
    for (int i = 0; i < cols; i++) {
        inventory[routes[i]] -= 1;
    }
    return inventory;
}

int main() {
    int data[3][3] = {{5, 3, 8}, {2, 6, 4}, {7, 1, 9}};
    int inventory[3] = {10, 10, 10};
    int* routes = optimize_routes(data, 3, 3);
    int* updated_inventory = update_inventory(routes, inventory, 3);
    for (int i = 0; i < 3; i++) {
        printf("%d ", updated_inventory[i]);
    }
    printf("\n");
    free(routes);
    return 0;
}