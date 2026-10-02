#include <stdio.h>

void generate_trajectory() {
    int x = 0;
    double y = 10000;
    while (1) {
        printf("Altitude: %.2f meters, Distance: %d km\n", y, x);
        x += 1;
        y = 10000 - 0.1 * x * x;
        if (y < 0) {
            y = 0;
        }
    }
}

int main() {
    generate_trajectory();
    return 0;
}