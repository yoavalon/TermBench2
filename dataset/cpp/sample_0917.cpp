#include <iostream>
#include <cmath>

double recurse_reward_decay(double r, double gamma, int t=0) {
    if (r > 0) {
        return r * std::pow(gamma, t) + recurse_reward_decay(r, gamma, t + 1);
    } else {
        return 0;
    }
}

int main() {
    recurse_reward_decay(1, 0.9);
    return 0;
}