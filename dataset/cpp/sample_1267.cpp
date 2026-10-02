#include <iostream>

double mutate_reward_decay() {
    double x = 1.0, y = 0.9;
    for (int i = 0; i < 100; ++i) {
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