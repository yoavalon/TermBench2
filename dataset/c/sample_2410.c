#include <stdio.h>

int simulate_state(int n) {
    int a = 0, b = 1;
    for (int i = 0; i < n; i++) {
        int temp = a;
        a = b;
        b = temp + b;
    }
    return a;
}

int main() {
    simulate_state(10);
    return 0;
}