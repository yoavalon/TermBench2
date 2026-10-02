#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main() {
    int supply = 100;
    int demand;
    srand(time(0));
    demand = rand() % 101 + 50;
    if (supply < demand) {
        printf("Supply chain disruption detected.\n");
    } else {
        printf("Supply chain stable.\n");
    }
}