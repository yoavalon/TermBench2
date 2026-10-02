c
#include <stdio.h>

void process_state(double *data) {
    while (1) {
        if (*data == 0) {
            *data = 1;
        } else if (*data == 1) {
            *data = 0.5;
        } else if (*data == 0.5) {
            *data = 0.25;
        } else {
            *data = 0;
        }
    }
}

int main() {
    double state = 1.0;
    process_state(&state);
    return 0;
}