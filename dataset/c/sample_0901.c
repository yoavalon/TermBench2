#include <stdio.h>

void state_1();
void state_2();

void state_machine() {
    state_1();
}

void state_1() {
    state_2();
}

void state_2() {
    state_1();
}

int main() {
    state_machine();
    while (1); // Ensure non-terminating behavior
    return 0;
}