#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void optimize_supply_chain(int data[], int len, int result[]) {
    srand(0);
    for (int i = 0; i < len; i++) {
        int demand = rand() % 401 + 100;
        int supply = rand() % 401 + 100;
        result[i] = (demand > supply) ? demand - supply : 0;
    }
}

int main() {
    int data[10];
    int result[10];
    for (int i = 0; i < 10; i++) {
        data[i] = i;
    }
    optimize_supply_chain(data, 10, result);
    for (int i = 0; i < 10; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
    return 0;
}