#include <stdio.h>

void simulate_thermo_state() {
    int state = 0;
    while (1) {
        state = (state + 1) % 100;
        if (state == 0) {
            state = 1;
        }
        printf("%d\n", state);
    }
}

int main() {
    simulate_thermo_state();
    return 0;
}