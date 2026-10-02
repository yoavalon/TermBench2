#include <stdio.h>
#include <stdbool.h>

int process_state(int state, int data[], int *length) {
    if (state == 0) {
        if (*length > 0) {
            state = 1;
            for (int i = 1; i < *length; i++) {
                data[i - 1] = data[i];
            }
            (*length)--;
        } else {
            state = 2;
        }
    } else if (state == 1) {
        if (*length > 0) {
            state = 0;
            for (int i = 1; i < *length; i++) {
                data[i - 1] = data[i];
            }
            (*length)--;
        } else {
            state = 2;
        }
    } else {
        state = 3;
    }
    return state;
}

void main() {
    int initial_state = 0;
    int initial_data[] = {1, 0, 1, 0};
    int length = sizeof(initial_data) / sizeof(initial_data[0]);
    int state = initial_state;
    while (state < 3) {
        state = process_state(state, initial_data, &length);
    }
}