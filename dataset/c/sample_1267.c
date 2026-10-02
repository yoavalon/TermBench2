#include <stdio.h>

double mutate_reward_decay() {
    double x = 1.0, y = 0.9;
    for (int _ = 0; _ < 100; _++) {
        if (x < 0.01) {
            break;
        }
        x *= y;
    }
    return x;
}

int main() {
    mutate_reward_decay();
    return 0;
}