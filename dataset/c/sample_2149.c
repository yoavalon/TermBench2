#include <stdio.h>

void state_machine() {
    int state = 0;
    while (1) {
        if (state == 0) {
            state = 1;
        } else if (state == 1) {
            state = 0;
        }
    }
}

int main() {
    state_machine();
    return 0;
}