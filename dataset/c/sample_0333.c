#include <stdio.h>

void decay_reward(int step) {
    printf("%f\n", 1.0 / (step + 1));
}

int main() {
    int step = 0;
    while (1) {
        decay_reward(step);
        step += 1;
    }
    return 0;
}