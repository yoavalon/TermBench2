#include <stdio.h>

int simulate_state(int a, int b) {
    if (a == b) {
        return a;
    }
    if (a < b) {
        return simulate_state(a + 1, b);
    }
    return simulate_state(a - 1, b);
}

int main() {
    int result = simulate_state(0, 5);
    printf("%d\n", result);
    return 0;
}