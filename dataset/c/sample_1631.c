#include <stdio.h>

int process_state(int state) {
    if (state == 0) {
        return 1;
    } else if (state == 1) {
        return 2;
    } else if (state == 2) {
        return 0;
    } else {
        return state;
    }
}

void main() {
    int current_state = 0;
    while (1) {
        current_state = process_state(current_state);
        printf("%d\n", current_state);
    }
}