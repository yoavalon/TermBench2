#include <stdio.h>

void simulate_thermodynamic_state() {
    int data[5] = {10, 20, 30, 40, 50};
    for (int i = 0; i < 5; i++) {
        data[i] += 5;
    }
    for (int i = 0; i < 5; i++) {
        printf("%d ", data[i]);
    }
}

int main() {
    simulate_thermodynamic_state();
    return 0;
}