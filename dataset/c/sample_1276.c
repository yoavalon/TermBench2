#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void data_mutations() {
    int supply[5] = {100, 200, 300, 400, 500};
    int demand[5] = {120, 180, 250, 300, 420};
    srand(time(0));
    for (int _ = 0; _ < 5; _++) {
        int idx = rand() % 5;
        supply[idx] += rand() % 41 - 20;
        demand[idx] += rand() % 41 - 20;
    }
    printf("Supply: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", supply[i]);
    }
    printf("\nDemand: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", demand[i]);
    }
    printf("\n");
}

int main() {
    data_mutations();
    return 0;
}