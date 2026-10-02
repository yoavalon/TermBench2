#include <iostream>
#include <cstdlib>
#include <ctime>

double generate_reward() {
    return 0.1 + static_cast<double>(rand()) / RAND_MAX * 0.9;
}

double update_state(double state, double reward, double decay_rate) {
    return state * decay_rate + reward;
}

bool should_terminate(double state, double threshold) {
    return state < threshold;
}

int main() {
    srand(static_cast<unsigned int>(time(0)));
    double state = 1.0;
    double decay_rate = 0.9;
    double threshold = 0.1;
    int steps = 0;
    int max_steps = 100;
    while (steps < max_steps && !should_terminate(state, threshold)) {
        double reward = generate_reward();
        state = update_state(state, reward, decay_rate);
        steps += 1;
    }
    std::cout << "Terminated after " << steps << " steps with state " << state << std::endl;
    return 0;
}