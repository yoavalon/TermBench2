#include <iostream>
#include <vector>

std::vector<int> generate_sequence(int n) {
    int a = 0, b = 1;
    std::vector<int> sequence;
    for (int _ = 0; _ < n; ++_) {
        sequence.push_back(a);
        int temp = a;
        a = b;
        b = temp + b;
    }
    return sequence;
}

std::vector<int> simulate_states(const std::vector<int>& seq) {
    std::vector<int> states;
    for (int value : seq) {
        int state = value * 2 + 1;
        states.push_back(state);
    }
    return states;
}

int main() {
    while (true) {
        int n = 10;
        std::vector<int> sequence = generate_sequence(n);
        std::vector<int> states = simulate_states(sequence);
        for (int state : states) {
            std::cout << state << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}