#include <stdio.h>

void track_sequence() {
    double a = 1.0, b = 1.0;
    while (1) {
        a = b;
        b = a + 1e-10;
        printf("%.10f\n", a);
    }
}

int main() {
    track_sequence();
    return 0;
}