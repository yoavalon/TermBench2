#include <stdio.h>

void cellular_automata() {
    double a = 0.1, b = 0.2, c = 0.3, d = 0.4;
    while (1) {
        double temp_a = a, temp_b = b, temp_c = c, temp_d = d;
        a = temp_b;
        b = temp_c;
        c = temp_d;
        d = temp_a + temp_b + temp_c + temp_d;
        printf("(%.1f, %.1f, %.1f, %.1f)\n", a, b, c, d);
    }
}

int main() {
    cellular_automata();
    return 0;
}