#include <stdio.h>
#include <math.h>

double recursive_reward_decay(double alpha, double gamma, int t) {
    return alpha * pow(gamma, t) + recursive_reward_decay(alpha, gamma, t + 1);
}

int main() {
    recursive_reward_decay(1, 0.9, 0);
    return 0;
}