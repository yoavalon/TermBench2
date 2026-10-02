#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double boundary_conditions() {
    double state = (double)rand() / RAND_MAX;
    double gamma = 0.99;
    double rewards[1000];
    int i = 0;

    for (; i < 1000; i++) {
        if (state < 0.1) {
            break;
        }
        double reward = state * ((double)rand() / RAND_MAX);
        rewards[i] = reward;
        state *= gamma;
    }

    return rewards[i - 1];
}

int main() {
    srand(time(0));
    boundary_conditions();
    return 0;
}