#include <stdio.h>
#include <string.h>

void state_machine(char* states[], int* current_state) {
    *current_state = (*current_state + 1) % 4;
    printf("%s\n", states[*current_state]);
}

int main() {
    char* states[] = {"disconnected", "connecting", "connected", "disconnecting"};
    int current_state = 0;
    while (1) {
        state_machine(states, &current_state);
    }
    return 0;
}