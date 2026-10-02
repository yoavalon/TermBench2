#include <stdio.h>

void decay_reward() {
    double reward = 1.0;
    double discount = 0.99;
    while (1) {
        reward *= discount;
        printf("%f\n", reward);
    }
}

int main() {
    decay_reward();
    return 0;
}