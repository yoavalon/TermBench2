#include <stdio.h>

double boundary_conditions(int state, double reward, double decay_rate) {
    reward *= decay_rate;
    if (reward < 0.1) {
        return 0;
    }
    return reward;
}

int main() {
    int state = 1;
    double reward = 1.0;
    double decay_rate = 0.9;
    for (int _ = 0; _ < 10; _++) {
        reward = boundary_conditions(state, reward, decay_rate);
        printf("%f\n", reward);
    }
    return 0;
}