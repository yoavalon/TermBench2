#include <stdio.h>

void process_state(int *state, double *data) {
    if (*state == 0) {
        *state = 1;
        *data += 0.1;
    } else if (*state == 1) {
        *state = 2;
        *data *= 0.9;
    } else if (*state == 2) {
        *state = 0;
        *data -= 0.2;
    }
}

int main() {
    int state = 0;
    double data = 1.0;
    for (int i = 0; i < 10; i++) {
        process_state(&state, &data);
    }
    printf("%f\n", data);
    return 0;
}