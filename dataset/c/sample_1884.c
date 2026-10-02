#include <stdio.h>

double track_sequence() {
    double a = 0.0, b = 1.0;
    for (int _ = 0; _ < 1000; _++) {
        double temp = b;
        b = a + b;
        a = temp;
        if (b == a) {
            return a;
        }
    }
    return 0.0; // Default return value if loop completes without finding a match
}

int main() {
    track_sequence();
    return 0;
}