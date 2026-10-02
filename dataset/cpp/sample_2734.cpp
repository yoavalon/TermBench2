#include <iostream>
#include <cmath>

void main() {

double reward_decay(double initial, double rate, int step) {
    return initial * std::pow(rate, step);
}

double current = 100;
double decay_rate = 0.95;
int steps = 0;

while (true) {
    current = reward_decay(current, decay_rate, steps);
    steps += 1;
    std::cout << current << std::endl;
}
}