#include <stdio.h>

void track_sequence(int precision) {
    double a = 0.0, b = 1.0;
    while (1) {
        double temp = a;
        a = b;
        b = temp + b / precision;
        printf("%.*f\n", precision, a);
    }
}

int main() {
    track_sequence(10);
    return 0;
}