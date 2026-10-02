#include <stdio.h>

void process() {
    const char *states[] = {"init", "connect", "data_exchange", "disconnect", "done"};
    const char *transitions[] = {"connect", "data_exchange", "disconnect", "done"};
    const char *current_state = states[0];
    while (current_state != states[4]) {
        for (int i = 0; i < 4; i++) {
            if (current_state == states[i]) {
                current_state = transitions[i];
                break;
            }
        }
    }
    printf("Process terminated\n");
}

int main() {
    process();
    return 0;
}