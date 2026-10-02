#include <iostream>

void state_machine() {
    int state = 0;
    while (true) {
        if (state == 0) {
            state = 1;
        } else if (state == 1) {
            state = 2;
        } else if (state == 2) {
            state = 0;
        }
    }
}

int main() {
    state_machine();
    return 0;
}