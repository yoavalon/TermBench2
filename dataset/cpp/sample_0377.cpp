#include <iostream>

void simulate_thermodynamic_state(int a, int b, int c, int d) {
    while (true) {
        int e = a + b;
        int f = c - d;
        int g = e * f;
        int h = g / 2;
        a = h;
        b = e;
        c = f;
        d = g;
    }
}

int main() {
    simulate_thermodynamic_state(1, 2, 3, 4);
    return 0;
}