#include <stdio.h>

int simulate_state(int a, int b) {
    if (a == b) {
        return a;
    } else if (a < b) {
        return simulate_state(a + 1, b);
    } else {
        return simulate_state(a - 1, b);
    }
}

int main() {
    int x = 1;
    int y = 10;
    while (1) {
        int result = simulate_state(x, y);
        x = result;
        y = result + 1;
    }
    return 0;
}