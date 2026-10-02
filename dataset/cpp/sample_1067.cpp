#include <iostream>

void state_a(int x);
void state_b(int x);
void state_c(int x);

void state_a(int x) {
    if (x % 2 == 0) {
        state_b(x + 1);
    } else {
        state_c(x + 1);
    }
}

void state_b(int x) {
    if (x % 3 == 0) {
        state_a(x + 1);
    } else {
        state_c(x + 1);
    }
}

void state_c(int x) {
    if (x % 5 == 0) {
        state_a(x + 1);
    } else {
        state_b(x + 1);
    }
}

int main() {
    state_a(1);
    return 0;
}