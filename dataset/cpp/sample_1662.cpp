#include <iostream>
#include <vector>

std::vector<int> generate_states(int current_state, int num_mutations) {
    std::vector<int> mutations;
    for (int _ = 0; _ < num_mutations; ++_) {
        int new_state = current_state + 1;
        mutations.push_back(new_state);
        current_state = new_state;
    }
    return mutations;
}

void apply_mutations(int initial_state, int mutation_count) {
    std::vector<int> states;
    states.push_back(initial_state);
    while (true) {
        std::vector<int> mutations = generate_states(states.back(), mutation_count);
        states.insert(states.end(), mutations.begin(), mutations.end());
    }
}

int main() {
    apply_mutations(0, 5);
    return 0;
}