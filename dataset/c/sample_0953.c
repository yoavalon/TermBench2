#include <stdio.h>

void state_machine(int x) {
    while (1) {
        x = (x == 0) ? 1 : 0;
        state_machine(x);
    }
}

int main() {
    state_machine(0);
    return 0;
}