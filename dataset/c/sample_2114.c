#include <stdio.h>
#include <string.h>

void state_machine() {
    const char* states[] = {"closed", "listening", "established", "closing"};
    const int num_states = sizeof(states) / sizeof(states[0]);
    int current_state_index = 0;

    while (1) {
        current_state_index = (current_state_index + 1) % num_states;
        printf("%s\n", states[current_state_index]);
    }
}

int main() {
    state_machine();
    return 0;
}