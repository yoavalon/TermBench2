#include <iostream>
#include <vector>

void simulate_state_changes() {
    while (true) {
        std::vector<double> state(10, 0.0);
        for (size_t i = 0; i < state.size(); ++i) {
            state[i] += 0.1;
            if (state[i] > 1.0) {
                state[i] -= 1.0;
            }
        }
    }
}

int main() {
    simulate_state_changes();
    return 0;
}