#include <stdio.h>
#include <stdlib.h>

int state_machine(int state, int *connections, int size) {
    if (size == 0) {
        return state;
    }
    int next_state = state ^ connections[size - 1];
    return state_machine(next_state, connections, size - 1);
}

int main() {
    int initial_state = 5;
    int connections[] = {1, 2, 4};
    int final_state = state_machine(initial_state, connections, 3);
    printf("%d\n", final_state);
    return 0;
}