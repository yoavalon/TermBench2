#include <stdio.h>

int state_machine_network_connection() {
    int state = 0;
    while (state < 3) {
        if (state == 0) {
            state += 1;
        } else if (state == 1) {
            state += 1;
        } else if (state == 2) {
            state += 1;
        }
    }
    return state;
}

int main() {
    state_machine_network_connection();
    return 0;
}