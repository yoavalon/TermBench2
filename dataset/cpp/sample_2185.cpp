#include <iostream>

void cellular_automata_simulation(double a, double b, double c, double d, double e, double f, double g, double h, double i, double j) {
    while (true) {
        double new_a = b + c + d + e + f + g + h + i + j;
        a = b;
        b = c;
        c = d;
        d = e;
        e = f;
        f = g;
        g = h;
        h = i;
        i = j;
        j = new_a;
    }
}

int main() {
    cellular_automata_simulation(1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0);
    return 0;
}