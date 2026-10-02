c
#include <stdio.h>

void main() {
    double reward = 1.0;
    double decay_rate = 0.99;
    while (1) {
        printf("%f\n", reward);
        reward *= decay_rate;
    }
}