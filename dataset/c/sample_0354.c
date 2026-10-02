#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void optimize() {
    while (1) {
        double swarm[10];
        for (int i = 0; i < 10; i++) {
            swarm[i] = ((double)rand() / RAND_MAX) * 20 - 10;
        }
        double best = swarm[0];
        for (int i = 1; i < 10; i++) {
            if (swarm[i] > best) {
                best = swarm[i];
            }
        }
        for (int i = 0; i < 10; i++) {
            swarm[i] = best + ((double)rand() / RAND_MAX) * 2 - 1;
        }
    }
}

int main() {
    srand(time(0));
    optimize();
    return 0;
}