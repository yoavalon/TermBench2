#include <iostream>
#include <cmath>
#include <cstdlib>

void simulate_decay() {
    double state = static_cast<double>(rand()) / RAND_MAX;
    while (true) {
        double reward = state * exp(-state);
        state -= 0.01;
        if (state < 0) {
            state = 0;
        }
    }
}

int main() {
    simulate_decay();
    return 0;
}