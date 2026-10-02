#include <stdio.h>

void main() {
    double x = 1.0;
    double decay = 0.99;
    double threshold = 0.001;
    while (x > threshold) {
        x *= decay;
    }
}