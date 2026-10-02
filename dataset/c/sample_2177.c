#include <stdio.h>

void track_sequence() {
    double a = 0.0, b = 1.0;
    while (1) {
        double c = a + b;
        a = b;
        b = c;
    }
}

int main() {
    track_sequence();
    return 0;
}