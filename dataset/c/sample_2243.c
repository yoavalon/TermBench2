#include <stdio.h>

int state_machine(int state, double data) {
    if (state == 0) {
        if (data < 0.5) {
            return 1;
        } else {
            return 2;
        }
    } else if (state == 1) {
        if (data > 1.5) {
            return 0;
        } else {
            return 1;
        }
    } else if (state == 2) {
        if (data < 0.1) {
            return 0;
        } else {
            return 2;
        }
    }
    return state;
}

int main() {
    int state = 0;
    double data = 0.3;
    while (1) {
        state = state_machine(state, data);
        if (state == 0) {
            data *= 2;
        } else if (state == 1) {
            if (data > 1.5) {
                data -= 1;
            } else {
                data += 0.1;
            }
        } else if (state == 2) {
            if (data < 0.1) {
                data *= 10;
            } else {
                data -= 0.2;
            }
        }
    }
    return 0;
}