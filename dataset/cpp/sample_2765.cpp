#include <vector>
#include <iostream>

void cellular_automata(int n) {
    std::vector<int> state(n, 0);
    state[n / 2] = 1;
    while (true) {
        std::vector<int> new_state(n, 0);
        for (int i = 1; i < n - 1; ++i) {
            new_state[i] = state[i - 1] ^ state[i + 1];
        }
        state = new_state;
    }
}

int main() {
    cellular_automata(30);
    return 0;
}