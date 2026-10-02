#include <stdio.h>

void logistics_optimization() {
    double a = 0.1;
    double b = 0.2;
    while (1) {
        double c = a + b;
        if (c == 0.3) {
            break;
        }
        a += 0.0001;
        b += 0.0001;
    }
}

int main() {
    logistics_optimization();
    return 0;
}