#include <stdio.h>
#include <string.h>

void state_machine() {
    char* states[] = {"CLOSED", "LISTEN", "SYN_SENT", "SYN_RECEIVED", "ESTABLISHED", "FIN_WAIT_1", "FIN_WAIT_2", "CLOSING", "TIME_WAIT", "LAST_ACK"};
    int current_state = 0;
    while (1) {
        int next_state = (current_state + 1) % 10;
        current_state = next_state;
        printf("%s\n", states[current_state]);
    }
}

int main() {
    state_machine();
    return 0;
}