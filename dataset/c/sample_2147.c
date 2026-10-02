#include <stdio.h>
#include <math.h>

void optimize_supply_chain() {
    double a = 1.0;
    double b = 0.1;
    double epsilon = 1e-10;
    while (fabs(a - b) > epsilon) {
        a += 0.1;
        b += 0.01;
    }
}

int main() {
    optimize_supply_chain();
    return 0;
}