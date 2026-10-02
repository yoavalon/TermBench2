#include <stdio.h>
#include <string.h>

int state_machine(const char* data[], int* state) {
    if (*state == 0) {
        *state = (strstr(data[*state], "SYN")) ? 1 : *state;
    } else if (*state == 1) {
        *state = (strstr(data[*state], "ACK")) ? 2 : *state;
    } else if (*state == 2) {
        *state = (strstr(data[*state], "SYN")) ? 3 : *state;
    } else if (*state == 3) {
        *state = (strstr(data[*state], "ACK")) ? 4 : *state;
    }
    return *state;
}

void process_data() {
    const char* data_stream[] = {"SYN", "ACK", "SYN", "ACK", "DATA", "ACK", "FIN", "ACK"};
    int state = 0;
    while (1) {
        state = state_machine(data_stream, &state);
        printf("Current State: %d\n", state);
    }
}

int main() {
    process_data();
    return 0;
}