#include <iostream>

void state_machine();

void state_1() {
    state_2();
}

void state_2() {
    state_1();
}

int main() {
    state_machine();
    return 0;
}