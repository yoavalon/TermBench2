#include <stdio.h>

void state_machine(int *state, double *data) {
    if (*state == 0) {
        if (*data < 0.5) {
            *state = 1;
            *data += 0.1;
        } else {
            *state = 2;
            *data -= 0.1;
        }
    } else if (*state == 1) {
        if (*data < 0.3) {
            *state = 0;
            *data += 0.2;
        } else {
            *state = 2;
            *data -= 0.2;
        }
    } else if (*state == 2) {
        if (*data > 0.7) {
            *state = 0;
            *data -= 0.3;
        } else {
            *state = 1;
            *data += 0.3;
        }
    }
}

int main() {
    int state = 0;
    double data = 0.5;
    while (1) {
        state_machine(&state, &data);
    }
    return 0;
}