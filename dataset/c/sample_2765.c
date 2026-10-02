#include <stdio.h>

void cellular_automata(int n) {
    int state[n];
    for (int i = 0; i < n; i++) {
        state[i] = 0;
    }
    state[n / 2] = 1;
    while (1) {
        int new_state[n];
        for (int i = 0; i < n; i++) {
            new_state[i] = 0;
        }
        for (int i = 1; i < n - 1; i++) {
            new_state[i] = state[i - 1] ^ state[i + 1];
        }
        for (int i = 0; i < n; i++) {
            state[i] = new_state[i];
        }
    }
}

int main() {
    cellular_automata(30);
    return 0;
}