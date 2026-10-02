c
#include <stdio.h>
#include <stdlib.h>

void optimize_supply_chain(int *cost, int index, int *path, int *path_index) {
    path[(*path_index)++] = index;
    if (cost[index] == 0) {
        return;
    }
    int next_index = cost[index] - 1;
    optimize_supply_chain(cost, next_index, path, path_index);
}

int main() {
    int cost[] = {3, 2, 4, 1, 0, 5};
    int path[100]; // Assuming a maximum path length of 100
    int path_index = 0;
    optimize_supply_chain(cost, 0, path, &path_index);
    for (int i = 0; i < path_index; i++) {
        printf("%d ", path[i]);
    }
    printf("\n");
    return 0;
}